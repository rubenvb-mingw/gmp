dnl  AMD64 mpn_copyi optimised for CPUs with fast AVX.

dnl  Contributed to the GNU project by Torbjörn Granlund.

dnl  Copyright 2003, 2005, 2007, 2011, 2012, 2013 Free Software Foundation,
dnl  Inc.

dnl  This file is part of the GNU MP Library.

dnl  The GNU MP Library is free software; you can redistribute it and/or modify
dnl  it under the terms of the GNU Lesser General Public License as published
dnl  by the Free Software Foundation; either version 3 of the License, or (at
dnl  your option) any later version.

dnl  The GNU MP Library is distributed in the hope that it will be useful, but
dnl  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
dnl  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
dnl  License for more details.

dnl  You should have received a copy of the GNU Lesser General Public License
dnl  along with the GNU MP Library.  If not, see http://www.gnu.org/licenses/.

include(`../config.m4')

C cycles/limb aligned	      unaligned	      best seen	     for cpu?
C AMD K8,K9	n/a
C AMD K10	n/a
C AMD bull	n/a
C AMD pile	 4.87		 4.87				N
C AMD steam	 ?		 ?
C AMD bobcat	n/a
C AMD jaguar	n/a
C Intel P4	n/a
C Intel core	n/a
C Intel NHM	n/a
C Intel SBR	 0.50		 0.91				N
C Intel IBR	 ?
C Intel HWL	 0.25		 0.30				Y
C Intel BWL	 ?
C Intel atom	n/a
C VIA nano	n/a

C We try to do as many 32-byte operations as possible.  The top-most and
C bottom-most writes might need 8-byte operations.  For the bulk copying, we
C write using aligned 32-byte operations, but we read with both aligned and
C unaligned 32-byte operations.

define(`rp', `%rdi')
define(`up', `%rsi')
define(`n',  `%rdx')

ABI_SUPPORT(DOS64)
ABI_SUPPORT(STD64)

dnl define(`vmovdqu', vlddqu)

ASM_START()
	TEXT
	ALIGN(32)
PROLOGUE(mpn_copyi)
	FUNC_ENTRY(3)

	cmp	$7, n
	jbe	L(bc)

	test	$8, R8(rp)		C is rp 16-byte aligned?
	jz	L(a2)			C jump if rp aligned
	mov	(up), %rax
	lea	8(up), up
	mov	%rax, (rp)
	lea	8(rp), rp
	dec	n
L(a2):	test	$16, R8(rp)		C is rp 32-byte aligned?
	jz	L(a3)			C jump if rp aligned
	vmovdqu	(up), %xmm0
	lea	16(up), up
	vmovdqa	%xmm0, (rp)
	lea	16(rp), rp
	sub	$2, n
L(a3):	sub	$16, n
	jc	L(sma)

	ALIGN(16)
L(top):	vmovdqu	(up), %ymm0
	vmovdqu	32(up), %ymm1
	vmovdqu	64(up), %ymm2
	vmovdqu	96(up), %ymm3
	lea	128(up), up
	vmovdqa	%ymm0, (rp)
	vmovdqa	%ymm1, 32(rp)
	vmovdqa	%ymm2, 64(rp)
	vmovdqa	%ymm3, 96(rp)
	lea	128(rp), rp
L(ali):	sub	$16, n
	jnc	L(top)

L(sma):	test	$8, R8(n)
	jz	1f
	vmovdqu	(up), %ymm0
	vmovdqu	32(up), %ymm1
	lea	64(up), up
	vmovdqa	%ymm0, (rp)
	vmovdqa	%ymm1, 32(rp)
	lea	64(rp), rp
1:
	test	$4, R8(n)
	jz	1f
	vmovdqu	(up), %ymm0
	lea	32(up), up
	vmovdqa	%ymm0, (rp)
	lea	32(rp), rp
1:
	test	$2, R8(n)
	jz	1f
	vmovdqu	(up), %xmm0
	lea	16(up), up
	vmovdqa	%xmm0, (rp)
	lea	16(rp), rp
1:
L(end):	test	$1, R8(n)
	jz	1f
	mov	(up), %r8
	mov	%r8, (rp)
1:
	FUNC_EXIT()
	ret

	ALIGN(16)
L(bc):	test	$4, R8(n)
	jz	1f
	mov	(up), %rax
	mov	8(up), %rcx
	mov	16(up), %r8
	mov	24(up), %r9
	lea	32(up), up
	mov	%rax, (rp)
	mov	%rcx, 8(rp)
	mov	%r8, 16(rp)
	mov	%r9, 24(rp)
	lea	32(rp), rp
1:
	test	$2, R8(n)
	jz	1f
	mov	(up), %rax
	mov	8(up), %rcx
	lea	16(up), up
	mov	%rax, (rp)
	mov	%rcx, 8(rp)
	lea	16(rp), rp
1:
	test	$1, R8(n)
	jz	1f
	mov	(up), %rax
	mov	%rax, (rp)
1:
	FUNC_EXIT()
	ret
EPILOGUE()