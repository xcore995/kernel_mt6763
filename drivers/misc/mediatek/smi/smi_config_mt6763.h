/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __SMI_CONFIG_MT6765_H__
#define __SMI_CONFIG_MT6765_H__

#include <soc/mediatek/smi.h>
#include "smi_reg.h"

#define SMI_LARB_NUM_MAX	8
#define SMI_PORT_NUM_MAX	32

#define SMI_LARB_NUM		4
#define SMI_COMM_SCEN_NUM	((SMI_LARB_NUM)+1)	/* COMM */

#define SMI_LARB0_PORT_NUM	10	/* MMSYS */
#define SMI_LARB1_PORT_NUM	10	/* IMGSYS */
#define SMI_LARB2_PORT_NUM	18	/* CAMSYS */
#define SMI_LARB3_PORT_NUM	11	/* CODEC */

#define SMI_SCEN_NUM		2	/* init, icfp */
#define SMI_ESL_INIT		0
#define SMI_ESL_VPWFD		(SMI_ESL_INIT)
#define SMI_ESL_VR4K		(SMI_ESL_INIT)
#define SMI_ESL_ICFP		1

static unsigned int smi_larb_cmd_gr_en_port[SMI_LARB_NUM][2] = {
	{0, 5}, {0, 0}, {0, 0}, {0, 0}
};

static unsigned int smi_larb_bw_thrt_en_port[SMI_LARB_NUM][2] = { /* non-HRT */
	{6, SMI_LARB0_PORT_NUM}, {0, SMI_LARB1_PORT_NUM}, {0, 0},
	{0, SMI_LARB3_PORT_NUM},
};

static unsigned int smi_scen_map[SMI_BWC_SCEN_CNT] = {
	SMI_ESL_INIT, SMI_ESL_INIT, SMI_ESL_INIT, SMI_ESL_INIT, SMI_ESL_INIT,
	SMI_ESL_INIT, SMI_ESL_VPWFD, SMI_ESL_VR4K, SMI_ESL_VPWFD, SMI_ESL_VPWFD,
	SMI_ESL_VPWFD, SMI_ESL_VPWFD, SMI_ESL_VR4K, SMI_ESL_VR4K, SMI_ESL_VR4K,
	SMI_ESL_ICFP, SMI_ESL_ICFP, SMI_ESL_ICFP, SMI_ESL_INIT
};

/* scen: init */
struct mtk_smi_pair smi_comm_init_pair[SMI_COMM_SCEN_NUM] = {
	{SMI_L1ARB(0), 0x1ba5}, {SMI_L1ARB(1), 0x15d3},
	{SMI_L1ARB(2), 0x1000}, {SMI_L1ARB(3), 0x1000},
	{SMI_BUS_SEL, 0x4}
};

struct mtk_smi_pair smi_larb0_init_pair[SMI_LARB0_PORT_NUM] = {
	{SMI_LARB_OSTDL_PORT(0), 0x1f}, {SMI_LARB_OSTDL_PORT(1), 0x1f},
	{SMI_LARB_OSTDL_PORT(2), 0x1f}, {SMI_LARB_OSTDL_PORT(3), 0x1f},
	{SMI_LARB_OSTDL_PORT(4), 0x1f}, {SMI_LARB_OSTDL_PORT(5), 0x7},
	{SMI_LARB_OSTDL_PORT(6), 0x7}, {SMI_LARB_OSTDL_PORT(7), 0x4},
	{SMI_LARB_OSTDL_PORT(8), 0x4}, {SMI_LARB_OSTDL_PORT(9), 0x1f},
};

struct mtk_smi_pair smi_larb1_init_pair[SMI_LARB1_PORT_NUM] = {
	{SMI_LARB_OSTDL_PORT(0), 0xc}, {SMI_LARB_OSTDL_PORT(1), 0x1},
	{SMI_LARB_OSTDL_PORT(2), 0x4}, {SMI_LARB_OSTDL_PORT(3), 0x4},
	{SMI_LARB_OSTDL_PORT(4), 0x1}, {SMI_LARB_OSTDL_PORT(5), 0x1},
	{SMI_LARB_OSTDL_PORT(6), 0x1}, {SMI_LARB_OSTDL_PORT(7), 0x1},
	{SMI_LARB_OSTDL_PORT(8), 0x1}, {SMI_LARB_OSTDL_PORT(9), 0x1},
};

struct mtk_smi_pair smi_larb2_init_pair[SMI_LARB2_PORT_NUM] = {
	{SMI_LARB_OSTDL_PORT(0), 0x16}, {SMI_LARB_OSTDL_PORT(1), 0x14},
	{SMI_LARB_OSTDL_PORT(2), 0x2}, {SMI_LARB_OSTDL_PORT(3), 0x2},
	{SMI_LARB_OSTDL_PORT(4), 0x2}, {SMI_LARB_OSTDL_PORT(5), 0x2},
	{SMI_LARB_OSTDL_PORT(6), 0x2}, {SMI_LARB_OSTDL_PORT(7), 0x4},
	{SMI_LARB_OSTDL_PORT(8), 0x4}, {SMI_LARB_OSTDL_PORT(9), 0x4},
	{SMI_LARB_OSTDL_PORT(10), 0x2}, {SMI_LARB_OSTDL_PORT(11), 0x2},
	{SMI_LARB_OSTDL_PORT(12), 0x2}, {SMI_LARB_OSTDL_PORT(13), 0x4},
	{SMI_LARB_OSTDL_PORT(14), 0x2}, {SMI_LARB_OSTDL_PORT(15), 0x2},
	{SMI_LARB_OSTDL_PORT(16), 0x2}, {SMI_LARB_OSTDL_PORT(17), 0x2},
};

struct mtk_smi_pair smi_larb3_init_pair[SMI_LARB3_PORT_NUM] = {
	{SMI_LARB_OSTDL_PORT(0), 0x3}, {SMI_LARB_OSTDL_PORT(1), 0x1},
	{SMI_LARB_OSTDL_PORT(2), 0x1}, {SMI_LARB_OSTDL_PORT(3), 0x1},
	{SMI_LARB_OSTDL_PORT(4), 0x1}, {SMI_LARB_OSTDL_PORT(5), 0x5},
	{SMI_LARB_OSTDL_PORT(6), 0x3}, {SMI_LARB_OSTDL_PORT(7), 0x1},
	{SMI_LARB_OSTDL_PORT(8), 0x1}, {SMI_LARB_OSTDL_PORT(9), 0x1},
	{SMI_LARB_OSTDL_PORT(10), 0x6},
};

/* scen: icfp */
struct mtk_smi_pair smi_comm_icfp_pair[SMI_COMM_SCEN_NUM] = {
	{SMI_L1ARB(0), 0x1327}, {SMI_L1ARB(1), 0x1241},
	{SMI_L1ARB(2), 0x12e6}, {SMI_L1ARB(3), 0x119e},
	{SMI_BUS_SEL, 0x54},
};

struct mtk_smi_pair smi_larb0_icfp_pair[SMI_LARB0_PORT_NUM] = {
	{SMI_LARB_OSTDL_PORT(0), 0x1f}, {SMI_LARB_OSTDL_PORT(1), 0x1f},
	{SMI_LARB_OSTDL_PORT(2), 0x1f}, {SMI_LARB_OSTDL_PORT(3), 0xe},
	{SMI_LARB_OSTDL_PORT(4), 0xe}, {SMI_LARB_OSTDL_PORT(5), 0x7},
	{SMI_LARB_OSTDL_PORT(6), 0x7}, {SMI_LARB_OSTDL_PORT(7), 0xb},
	{SMI_LARB_OSTDL_PORT(8), 0x1}, {SMI_LARB_OSTDL_PORT(9), 0x1f},
};
/* {disp_rmda0(3), 0x1f}, {disp_rdma1(4), 0x1f}, */
/* {mdp_wrot0(7), 0x4}, {mdp_wdma(8), 0x4} */

struct mtk_smi_pair smi_larb1_icfp_pair[SMI_LARB1_PORT_NUM] = {
	{SMI_LARB_OSTDL_PORT(0), 0x6}, {SMI_LARB_OSTDL_PORT(1), 0x1},
	{SMI_LARB_OSTDL_PORT(2), 0x2}, {SMI_LARB_OSTDL_PORT(3), 0x3},
	{SMI_LARB_OSTDL_PORT(4), 0x1}, {SMI_LARB_OSTDL_PORT(5), 0x1},
	{SMI_LARB_OSTDL_PORT(6), 0x1}, {SMI_LARB_OSTDL_PORT(7), 0x1},
	{SMI_LARB_OSTDL_PORT(8), 0x1}, {SMI_LARB_OSTDL_PORT(9), 0x1},
};
/* {imgi(0), 0xc}, {img3o(2), 0x4}, {vipi(3), 0x4} */

struct mtk_smi_pair smi_larb2_icfp_pair[SMI_LARB2_PORT_NUM] = {
	{SMI_LARB_OSTDL_PORT(0), 0x14}, {SMI_LARB_OSTDL_PORT(1), 0x6},
	{SMI_LARB_OSTDL_PORT(2), 0x2}, {SMI_LARB_OSTDL_PORT(3), 0x2},
	{SMI_LARB_OSTDL_PORT(4), 0x2}, {SMI_LARB_OSTDL_PORT(5), 0x2},
	{SMI_LARB_OSTDL_PORT(6), 0x2}, {SMI_LARB_OSTDL_PORT(7), 0x4},
	{SMI_LARB_OSTDL_PORT(8), 0x4}, {SMI_LARB_OSTDL_PORT(9), 0x4},
	{SMI_LARB_OSTDL_PORT(10), 0x2}, {SMI_LARB_OSTDL_PORT(11), 0x2},
	{SMI_LARB_OSTDL_PORT(12), 0x2}, {SMI_LARB_OSTDL_PORT(13), 0x4},
	{SMI_LARB_OSTDL_PORT(14), 0x2}, {SMI_LARB_OSTDL_PORT(15), 0x2},
	{SMI_LARB_OSTDL_PORT(16), 0x2}, {SMI_LARB_OSTDL_PORT(17), 0x2},
};
/* {imgo(0), 0x16}, {rrzo(1), 0x14} */

/* scen: all */
unsigned int smi_scen_pair_num[SMI_LARB_NUM + 1] = {
	SMI_LARB0_PORT_NUM, SMI_LARB1_PORT_NUM, SMI_LARB2_PORT_NUM,
	SMI_LARB3_PORT_NUM, SMI_COMM_SCEN_NUM
};

struct mtk_smi_pair *smi_comm_scen_pair[SMI_SCEN_NUM] = {
	smi_comm_init_pair, smi_comm_icfp_pair
};

struct mtk_smi_pair *smi_larb0_scen_pair[SMI_SCEN_NUM] = {
	smi_larb0_init_pair, smi_larb0_icfp_pair
};

struct mtk_smi_pair *smi_larb1_scen_pair[SMI_SCEN_NUM] = {
	smi_larb1_init_pair, smi_larb1_icfp_pair
};

struct mtk_smi_pair *smi_larb2_scen_pair[SMI_SCEN_NUM] = {
	smi_larb2_init_pair, smi_larb2_icfp_pair
};

struct mtk_smi_pair *smi_larb3_scen_pair[SMI_SCEN_NUM] = {
	smi_larb3_init_pair, smi_larb3_init_pair
};

struct mtk_smi_pair **smi_scen_pair[SMI_LARB_NUM + 1] = {
	smi_larb0_scen_pair, smi_larb1_scen_pair, smi_larb2_scen_pair,
	smi_larb3_scen_pair, smi_comm_scen_pair
};

/* config */
#define SMI_COMM_CONFIG_NUM	8
struct mtk_smi_pair smi_comm_config_pair[SMI_COMM_CONFIG_NUM] = {
	{SMI_L1LEN, 0xb}, {SMI_WRR_REG0, 0x208208}, {SMI_DCM, 0x4f1},
	{SMI_Mx_RWULTRA_WRRy(1, 0, 0), 0x208208},
	{SMI_Mx_RWULTRA_WRRy(1, 1, 0), 0x208208},
	{SMI_Mx_RWULTRA_WRRy(2, 0, 0), 0x208208},
	{SMI_Mx_RWULTRA_WRRy(2, 1, 0), 0x208208},
	{SMI_DUMMY, 0x1}
};

#define SMI_LARB0_CONFIG_NUM	7
struct mtk_smi_pair smi_larb0_config_pair[SMI_LARB0_CONFIG_NUM] = {
	{SMI_LARB_SW_FLAG, 0x1}, {SMI_LARB_SPM_ULTRA_MASK, 0xffffffc0},
	{SMI_LARB_WRR_PORT(0), 0x7}, {SMI_LARB_WRR_PORT(1), 0x7},
	{SMI_LARB_WRR_PORT(2), 0x7}, {SMI_LARB_WRR_PORT(3), 0x7},
	{SMI_LARB_WRR_PORT(4), 0x7}
};

#define SMI_LARB1_CONFIG_NUM	1
struct mtk_smi_pair smi_larb1_config_pair[SMI_LARB1_CONFIG_NUM] = {
	{SMI_LARB_SW_FLAG, 0x1}
};

#define SMI_LARB2_CONFIG_NUM	2
struct mtk_smi_pair smi_larb2_config_pair[SMI_LARB2_CONFIG_NUM] = {
	{SMI_LARB_SW_FLAG, 0x1}, {SMI_LARB_SPM_ULTRA_MASK, 0xffffc000}
};

unsigned int smi_config_pair_num[SMI_LARB_NUM + 1] = {
	SMI_LARB0_CONFIG_NUM, SMI_LARB1_CONFIG_NUM, SMI_LARB2_CONFIG_NUM,
	SMI_LARB1_CONFIG_NUM, SMI_COMM_CONFIG_NUM
};

struct mtk_smi_pair *smi_config_pair[SMI_LARB_NUM + 1] = {
	smi_larb0_config_pair, smi_larb1_config_pair, smi_larb2_config_pair,
	smi_larb1_config_pair, smi_comm_config_pair
};

/* debug */
#define SMI_COMM_DEBUG_NUM	((SMI_LARB_NUM_MAX)*3+20)
unsigned int smi_comm_debug_offset[SMI_COMM_DEBUG_NUM] = {
	SMI_L1LEN,
	SMI_L1ARB(0), SMI_L1ARB(1), SMI_L1ARB(2), SMI_L1ARB(3),
	SMI_L1ARB(4), SMI_L1ARB(5), SMI_L1ARB(6), SMI_L1ARB(7),
	SMI_MON_AXI_ENA, SMI_MON_AXI_CLR, SMI_MON_AXI_ACT_CNT,
	SMI_BUS_SEL, SMI_WRR_REG0, SMI_WRR_REG1,
	SMI_READ_FIFO_TH, SMI_M4U_TH, SMI_FIFO_TH1, SMI_FIFO_TH2,
	SMI_DCM, SMI_ELA,
	SMI_Mx_RWULTRA_WRRy(1, 0, 0), SMI_Mx_RWULTRA_WRRy(1, 0, 1),
	SMI_Mx_RWULTRA_WRRy(1, 1, 0), SMI_Mx_RWULTRA_WRRy(1, 1, 1),
	SMI_Mx_RWULTRA_WRRy(2, 0, 0), SMI_Mx_RWULTRA_WRRy(2, 0, 1),
	SMI_Mx_RWULTRA_WRRy(2, 1, 0), SMI_Mx_RWULTRA_WRRy(2, 1, 1),
	SMI_COMMON_CLAMP_EN, SMI_COMMON_CLAMP_EN_SET, SMI_COMMON_CLAMP_EN_CLR,
	SMI_DEBUG_S(0), SMI_DEBUG_S(1), SMI_DEBUG_S(2), SMI_DEBUG_S(3),
	SMI_DEBUG_S(4), SMI_DEBUG_S(5), SMI_DEBUG_S(6), SMI_DEBUG_S(7),
	SMI_DEBUG_M0, SMI_DEBUG_M1, SMI_DEBUG_MISC, SMI_DUMMY
};

#define SMI_LARB_DEBUG_NUM	((SMI_PORT_NUM_MAX)*5+26)
unsigned int smi_larb_debug_offset[SMI_LARB_DEBUG_NUM] = {
	SMI_LARB_STAT, SMI_LARB_IRQ_STATUS, SMI_LARB_SLP_CON,
	SMI_LARB_CON, SMI_LARB_CON_SET, SMI_LARB_CMD_THRT_CON,
	SMI_LARB_SW_FLAG, SMI_LARB_BWL_EN, SMI_LARB_OSTDL_EN,
	SMI_LARB_ULTRA_DIS, SMI_LARB_SPM_ULTRA_MASK, SMI_LARB_SPM_STA,
	SMI_LARB_EXT_GREQ_VIO, SMI_LARB_INT_GREQ_VIO,
	SMI_LARB_OSTD_UDF_VIO, SMI_LARB_OSTD_CRS_VIO,
	SMI_LARB_FIFO_STAT, SMI_LARB_BUS_STAT, SMI_LARB_CMD_THRT_STAT,
	SMI_LARB_MON_REQ, SMI_LARB_REQ_MASK,
	SMI_LARB_EXT_ONGOING, SMI_LARB_INT_ONGOING,
	SMI_LARB_WRR_PORT(0), SMI_LARB_WRR_PORT(1), SMI_LARB_WRR_PORT(2),
	SMI_LARB_WRR_PORT(3), SMI_LARB_WRR_PORT(4), SMI_LARB_WRR_PORT(5),
	SMI_LARB_WRR_PORT(6), SMI_LARB_WRR_PORT(7), SMI_LARB_WRR_PORT(8),
	SMI_LARB_WRR_PORT(9), SMI_LARB_WRR_PORT(10), SMI_LARB_WRR_PORT(11),
	SMI_LARB_WRR_PORT(12), SMI_LARB_WRR_PORT(13), SMI_LARB_WRR_PORT(14),
	SMI_LARB_WRR_PORT(15), SMI_LARB_WRR_PORT(16), SMI_LARB_WRR_PORT(17),
	SMI_LARB_WRR_PORT(18), SMI_LARB_WRR_PORT(19), SMI_LARB_WRR_PORT(20),
	SMI_LARB_WRR_PORT(21), SMI_LARB_WRR_PORT(22), SMI_LARB_WRR_PORT(23),
	SMI_LARB_WRR_PORT(24), SMI_LARB_WRR_PORT(25), SMI_LARB_WRR_PORT(26),
	SMI_LARB_WRR_PORT(27), SMI_LARB_WRR_PORT(28), SMI_LARB_WRR_PORT(29),
	SMI_LARB_WRR_PORT(30), SMI_LARB_WRR_PORT(31),
	SMI_LARB_OSTDL_PORT(0), SMI_LARB_OSTDL_PORT(1), SMI_LARB_OSTDL_PORT(2),
	SMI_LARB_OSTDL_PORT(3), SMI_LARB_OSTDL_PORT(4), SMI_LARB_OSTDL_PORT(5),
	SMI_LARB_OSTDL_PORT(6), SMI_LARB_OSTDL_PORT(7), SMI_LARB_OSTDL_PORT(8),
	SMI_LARB_OSTDL_PORT(9), SMI_LARB_OSTDL_PORT(10),
	SMI_LARB_OSTDL_PORT(11), SMI_LARB_OSTDL_PORT(12),
	SMI_LARB_OSTDL_PORT(13), SMI_LARB_OSTDL_PORT(14),
	SMI_LARB_OSTDL_PORT(15), SMI_LARB_OSTDL_PORT(16),
	SMI_LARB_OSTDL_PORT(17), SMI_LARB_OSTDL_PORT(18),
	SMI_LARB_OSTDL_PORT(19), SMI_LARB_OSTDL_PORT(20),
	SMI_LARB_OSTDL_PORT(21), SMI_LARB_OSTDL_PORT(22),
	SMI_LARB_OSTDL_PORT(23), SMI_LARB_OSTDL_PORT(24),
	SMI_LARB_OSTDL_PORT(25), SMI_LARB_OSTDL_PORT(26),
	SMI_LARB_OSTDL_PORT(27), SMI_LARB_OSTDL_PORT(28),
	SMI_LARB_OSTDL_PORT(29), SMI_LARB_OSTDL_PORT(30),
	SMI_LARB_OSTDL_PORT(31),
	SMI_LARB_OSTD_MON_PORT(0), SMI_LARB_OSTD_MON_PORT(1),
	SMI_LARB_OSTD_MON_PORT(2), SMI_LARB_OSTD_MON_PORT(3),
	SMI_LARB_OSTD_MON_PORT(4), SMI_LARB_OSTD_MON_PORT(5),
	SMI_LARB_OSTD_MON_PORT(6), SMI_LARB_OSTD_MON_PORT(7),
	SMI_LARB_OSTD_MON_PORT(8), SMI_LARB_OSTD_MON_PORT(9),
	SMI_LARB_OSTD_MON_PORT(10), SMI_LARB_OSTD_MON_PORT(11),
	SMI_LARB_OSTD_MON_PORT(12), SMI_LARB_OSTD_MON_PORT(13),
	SMI_LARB_OSTD_MON_PORT(14), SMI_LARB_OSTD_MON_PORT(15),
	SMI_LARB_OSTD_MON_PORT(16), SMI_LARB_OSTD_MON_PORT(17),
	SMI_LARB_OSTD_MON_PORT(18), SMI_LARB_OSTD_MON_PORT(19),
	SMI_LARB_OSTD_MON_PORT(20), SMI_LARB_OSTD_MON_PORT(21),
	SMI_LARB_OSTD_MON_PORT(22), SMI_LARB_OSTD_MON_PORT(23),
	SMI_LARB_OSTD_MON_PORT(24), SMI_LARB_OSTD_MON_PORT(25),
	SMI_LARB_OSTD_MON_PORT(26), SMI_LARB_OSTD_MON_PORT(27),
	SMI_LARB_OSTD_MON_PORT(28), SMI_LARB_OSTD_MON_PORT(29),
	SMI_LARB_OSTD_MON_PORT(30), SMI_LARB_OSTD_MON_PORT(31),
	SMI_LARB_NON_SEC_CON(0), SMI_LARB_NON_SEC_CON(1),
	SMI_LARB_NON_SEC_CON(2), SMI_LARB_NON_SEC_CON(3),
	SMI_LARB_NON_SEC_CON(4), SMI_LARB_NON_SEC_CON(5),
	SMI_LARB_NON_SEC_CON(6), SMI_LARB_NON_SEC_CON(7),
	SMI_LARB_NON_SEC_CON(8), SMI_LARB_NON_SEC_CON(9),
	SMI_LARB_NON_SEC_CON(10), SMI_LARB_NON_SEC_CON(11),
	SMI_LARB_NON_SEC_CON(12), SMI_LARB_NON_SEC_CON(13),
	SMI_LARB_NON_SEC_CON(14), SMI_LARB_NON_SEC_CON(15),
	SMI_LARB_NON_SEC_CON(16), SMI_LARB_NON_SEC_CON(17),
	SMI_LARB_NON_SEC_CON(18), SMI_LARB_NON_SEC_CON(19),
	SMI_LARB_NON_SEC_CON(20), SMI_LARB_NON_SEC_CON(21),
	SMI_LARB_NON_SEC_CON(22), SMI_LARB_NON_SEC_CON(23),
	SMI_LARB_NON_SEC_CON(24), SMI_LARB_NON_SEC_CON(25),
	SMI_LARB_NON_SEC_CON(26), SMI_LARB_NON_SEC_CON(27),
	SMI_LARB_NON_SEC_CON(28), SMI_LARB_NON_SEC_CON(29),
	SMI_LARB_NON_SEC_CON(30), SMI_LARB_NON_SEC_CON(31),
	SMI_LARB_MON_EN, SMI_LARB_MON_CLR, SMI_LARB_MON_ACT_CNT,
	SMI_LARB_SEC_CON(0), SMI_LARB_SEC_CON(1), SMI_LARB_SEC_CON(2),
	SMI_LARB_SEC_CON(3), SMI_LARB_SEC_CON(4), SMI_LARB_SEC_CON(5),
	SMI_LARB_SEC_CON(6), SMI_LARB_SEC_CON(7), SMI_LARB_SEC_CON(8),
	SMI_LARB_SEC_CON(9), SMI_LARB_SEC_CON(10), SMI_LARB_SEC_CON(11),
	SMI_LARB_SEC_CON(12), SMI_LARB_SEC_CON(13), SMI_LARB_SEC_CON(14),
	SMI_LARB_SEC_CON(15), SMI_LARB_SEC_CON(16), SMI_LARB_SEC_CON(17),
	SMI_LARB_SEC_CON(18), SMI_LARB_SEC_CON(19), SMI_LARB_SEC_CON(20),
	SMI_LARB_SEC_CON(21), SMI_LARB_SEC_CON(22), SMI_LARB_SEC_CON(23),
	SMI_LARB_SEC_CON(24), SMI_LARB_SEC_CON(25), SMI_LARB_SEC_CON(26),
	SMI_LARB_SEC_CON(27), SMI_LARB_SEC_CON(28), SMI_LARB_SEC_CON(29),
	SMI_LARB_SEC_CON(30), SMI_LARB_SEC_CON(31)
};

#define SMI_MMSYS_DEBUG_NUM	((SMI_LARB_NUM_MAX)*1+5)
unsigned int smi_mmsys_debug_offset[SMI_MMSYS_DEBUG_NUM] = {
	MMSYS_CG_CON0, MMSYS_CG_CON1,
	MMSYS_HW_DCM_1ST_DIS0, MMSYS_HW_DCM_2ND_DIS0, MMSYS_SW0_RST_B,
	MMSYS_GALS_DBG(0), MMSYS_GALS_DBG(1), MMSYS_GALS_DBG(2),
	MMSYS_GALS_DBG(3), MMSYS_GALS_DBG(4), MMSYS_GALS_DBG(5),
	MMSYS_GALS_DBG(6), MMSYS_GALS_DBG(7)
};

#endif
