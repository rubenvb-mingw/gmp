/* POWER9 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 2018 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#define GMP_LIMB_BITS 64
#define GMP_LIMB_BYTES 8

/* 3700MHz POWER9 */

/* Generated by tuneup.c, 2018-11-30, gcc 4.8 */

#define MOD_1_NORM_THRESHOLD                 0  /* always */
#define MOD_1_UNNORM_THRESHOLD               0  /* always */
#define MOD_1N_TO_MOD_1_1_THRESHOLD          8
#define MOD_1U_TO_MOD_1_1_THRESHOLD          6
#define MOD_1_1_TO_MOD_1_2_THRESHOLD        20
#define MOD_1_2_TO_MOD_1_4_THRESHOLD         0  /* never mpn_mod_1s_2p */
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD     12
#define USE_PREINV_DIVREM_1                  0
#define DIV_QR_1N_PI1_METHOD                 2
#define DIV_QR_1_NORM_THRESHOLD              3
#define DIV_QR_1_UNNORM_THRESHOLD            2
#define DIV_QR_2_PI2_THRESHOLD              13
#define DIVEXACT_1_THRESHOLD                 0  /* always (native) */
#define BMOD_1_TO_MOD_1_THRESHOLD           21

#define DIV_1_VS_MUL_1_PERCENT             359

#define MUL_TOOM22_THRESHOLD                34
#define MUL_TOOM33_THRESHOLD               105
#define MUL_TOOM44_THRESHOLD               450
#define MUL_TOOM6H_THRESHOLD               517
#define MUL_TOOM8H_THRESHOLD               608

#define MUL_TOOM32_TO_TOOM43_THRESHOLD     114
#define MUL_TOOM32_TO_TOOM53_THRESHOLD     279
#define MUL_TOOM42_TO_TOOM53_THRESHOLD     204
#define MUL_TOOM42_TO_TOOM63_THRESHOLD     211
#define MUL_TOOM43_TO_TOOM54_THRESHOLD     185

#define SQR_BASECASE_THRESHOLD               0  /* always (native) */
#define SQR_TOOM2_THRESHOLD                 46
#define SQR_TOOM3_THRESHOLD                158
#define SQR_TOOM4_THRESHOLD                686
#define SQR_TOOM6_THRESHOLD                  0  /* always */
#define SQR_TOOM8_THRESHOLD                866

#define MULMID_TOOM42_THRESHOLD             66

#define MULMOD_BNM1_THRESHOLD               19
#define SQRMOD_BNM1_THRESHOLD               26

#define MUL_FFT_MODF_THRESHOLD             530  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    530, 5}, {     25, 6}, {     13, 5}, {     27, 6}, \
    {     27, 7}, {     14, 6}, {     29, 7}, {     15, 6}, \
    {     31, 7}, {     25, 8}, {     13, 7}, {     28, 8}, \
    {     15, 7}, {     32, 8}, {     17, 7}, {     36, 8}, \
    {     19, 7}, {     39, 8}, {     27, 9}, {     15, 8}, \
    {     35, 9}, {     19, 8}, {     41, 9}, {     23, 8}, \
    {     49, 9}, {     27,10}, {     15, 9}, {     31, 8}, \
    {     63, 9}, {     39,10}, {     23, 9}, {     51,11}, \
    {     15,10}, {     31, 9}, {     67,10}, {     39, 9}, \
    {     79,10}, {     47, 9}, {     95,10}, {     55,11}, \
    {     31,10}, {     79,11}, {     47,10}, {     95,12}, \
    {     31,11}, {     63,10}, {    135,11}, {     79,10}, \
    {    159,11}, {     95,10}, {    191,12}, {     63,11}, \
    {    143,10}, {    287,11}, {    159,12}, {     95,11}, \
    {    191,13}, {   8192,14}, {  16384,15}, {  32768,16}, \
    {  65536,17}, { 131072,18}, { 262144,19}, { 524288,20}, \
    {1048576,21}, {2097152,22}, {4194304,23}, {8388608,24} }
#define MUL_FFT_TABLE3_SIZE 68
#define MUL_FFT_THRESHOLD                 5248

#define SQR_FFT_MODF_THRESHOLD             496  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    496, 5}, {     23, 6}, {     12, 5}, {     25, 6}, \
    {     13, 5}, {     27, 6}, {     29, 7}, {     15, 6}, \
    {     31, 7}, {     16, 6}, {     33, 7}, {     28, 8}, \
    {     15, 7}, {     32, 8}, {     17, 7}, {     36, 8}, \
    {     19, 7}, {     39, 8}, {     29, 9}, {     15, 8}, \
    {     35, 9}, {     19, 8}, {     41, 9}, {     23, 8}, \
    {     47, 9}, {     27,10}, {     15, 9}, {     31, 8}, \
    {     63, 9}, {     39,10}, {     23, 9}, {     51,11}, \
    {     15,10}, {     31, 9}, {     67,10}, {     39, 9}, \
    {     79,10}, {     47, 9}, {     95,10}, {     55,11}, \
    {     31,10}, {     79,11}, {     47,10}, {     95,12}, \
    {     31,11}, {     63,10}, {    135,11}, {     79,10}, \
    {    159,11}, {     95,12}, {     63,11}, {    127,10}, \
    {    255,11}, {    143,10}, {    287,11}, {    159,12}, \
    {     95,11}, {    191,13}, {   8192,14}, {  16384,15}, \
    {  32768,16}, {  65536,17}, { 131072,18}, { 262144,19}, \
    { 524288,20}, {1048576,21}, {2097152,22}, {4194304,23}, \
    {8388608,24} }
#define SQR_FFT_TABLE3_SIZE 69
#define SQR_FFT_THRESHOLD                 4224

#define MULLO_BASECASE_THRESHOLD             3
#define MULLO_DC_THRESHOLD                  40
#define MULLO_MUL_N_THRESHOLD            10323
#define SQRLO_BASECASE_THRESHOLD             6
#define SQRLO_DC_THRESHOLD                  40
#define SQRLO_SQR_THRESHOLD               8397

#define DC_DIV_QR_THRESHOLD                 30
#define DC_DIVAPPR_Q_THRESHOLD              91
#define DC_BDIV_QR_THRESHOLD                36
#define DC_BDIV_Q_THRESHOLD                 63

#define INV_MULMOD_BNM1_THRESHOLD           78
#define INV_NEWTON_THRESHOLD                11
#define INV_APPR_THRESHOLD                  13

#define BINV_NEWTON_THRESHOLD              272
#define REDC_1_TO_REDC_2_THRESHOLD           8
#define REDC_2_TO_REDC_N_THRESHOLD          79

#define MU_DIV_QR_THRESHOLD               1589
#define MU_DIVAPPR_Q_THRESHOLD            1589
#define MUPI_DIV_QR_THRESHOLD                0  /* always */
#define MU_BDIV_QR_THRESHOLD              1652
#define MU_BDIV_Q_THRESHOLD               2089

#define POWM_SEC_TABLE  3,16,139,852

#define GET_STR_DC_THRESHOLD                 9
#define GET_STR_PRECOMPUTE_THRESHOLD        17
#define SET_STR_DC_THRESHOLD               406
#define SET_STR_PRECOMPUTE_THRESHOLD       956

#define FAC_DSC_THRESHOLD                  181
#define FAC_ODD_THRESHOLD                   44

#define MATRIX22_STRASSEN_THRESHOLD         21
#define HGCD_THRESHOLD                      41
#define HGCD_APPR_THRESHOLD                 50
#define HGCD_REDUCE_THRESHOLD             3389
#define GCD_DC_THRESHOLD                   379
#define GCDEXT_DC_THRESHOLD                293
#define JACOBI_BASE_METHOD                   4
