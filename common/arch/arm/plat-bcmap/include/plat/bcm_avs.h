/*******************************************************************************
* Copyright 2010 Broadcom Corporation.  All rights reserved.
*
* 	@file	arch/arm/plat-bcmap/include/plat/bcm_avs.h
*
* Unless you and Broadcom execute a separate written software license agreement
* governing use of this software, this software is licensed to you under the
* terms of the GNU General Public License version 2, available at
* http://www.gnu.org/copyleft/gpl.html (the "GPL").
*
* Notwithstanding the above, under no circumstances may you combine this
* software in any way with any other Broadcom software provided under a license
* other than the GPL, without Broadcom's express prior written consent.
*******************************************************************************/

/*
*
*****************************************************************************
*
*  bcm_lcdc.h
*
*  PURPOSE:
*
*     This file contains platform data structures for Broadcom AVS driver
*
*  NOTES:
*
*****************************************************************************/

#ifndef __PLAT_BCM_AVS_H
#define __PLAT_BCM_AVS_H

enum
{
	SILICON_TYPE_SLOW = 0,
	SILICON_TYPE_TYPICAL,
	SILICON_TYPE_FAST,
	SILICON_TYPE_UNKNOWN
};

struct silicon_type_info
{
	/* LPM voltage. Pass -1 if no update needed */
	int lpm_voltage;
	/* NM voltage. Pass -1 if no update needed */
	int nm_voltage;
	/* NM2 osuper mode voltage. Pass -1 if no update needed */
	int nm2_osuper_voltage;
	/* NM2 super mode voltage. Pass -1 if no update needed */
	int nm2_super_voltage;
	/* NM2 turbo mode voltage. Pass -1 if no update needed */
	int nm2_turbo_voltage;
	/* NM2 higher mode voltage. Pass -1 if no update needed */
	int nm2_heigher_voltage;
	/* NM2 omedium mode voltage. Pass -1 if no update needed */
	int nm2_omedium_voltage;
	/* NM2 umedium mode voltage. Pass -1 if no update needed */
	int nm2_umedium_voltage;
	/* NM2 normal mode voltage. Pass -1 if no update needed */
	int nm2_normal_voltage;
	/* NM2 starter mode voltage. Pass -1 if no update needed */
	int nm2_starter_voltage;
	/* NM2 lower mode voltage. Pass -1 if no update needed */
	int nm2_lower_voltage;
};

struct bcm_avs_platform_data_t
{
	/* Name of the regulator to control core LPM voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_lpm_regl;

	/* Name of the regulator to control core normal mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_nml_regl;

	/* Name of the regulator to control core lower mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_lower_regl;

	/* Name of the regulator to control core starter mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_starter_regl;

	/* Name of the regulator to control core normal mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_normal_regl;

	/* Name of the regulator to control core umedium mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_umedium_regl;

	/* Name of the regulator to control core omedium mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_omedium_regl;

	/* Name of the regulator to control core higher mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_heigher_regl;

	/* Name of the regulator to control core turbo mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_turbo_regl;

	/* Name of the regulator to control core super mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_super_regl;

	/* Name of the regulator to control core osuper mode voltage
	 * Pass NULL if not supported/need not update
	 */
	char *core_osuper_regl;

	/* OTP params to idenltify silicon type.
	 * Assumption : total number of bits <=32
	 */
	int otp_bit_lsb;
	int otp_bit_msb;

	/* OTP value ranges:
	 * > fast_silicon_thold => fast silicon
	 * < slow_silicon_thold => slow silicon
	 * (> slow_silicon_thold && <= fast_silicon_thold) ==> typical silicon
	 */
	u32 fast_silicon_thold;
	u32 slow_silicon_thold;

	/* Pass NULL if not supported */
	struct silicon_type_info *fast_silicon;
	/* Pass NULL if not supported */
	struct silicon_type_info *typical_silicon;
	/* Pass NULL if not supported */
	struct silicon_type_info *slow_silicon;

	/* Silicon type notification callback - can be NULL */
	void (*notify_silicon_type) (int type);
};

#endif	/* __PLAT_BCM_AVS_H */
