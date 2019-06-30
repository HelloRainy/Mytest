#ifndef _ASM_X86_MSR_INDEX_H
#define _ASM_X86_MSR_INDEX_H

#include <linux/bits.h>

/* CPU model specific register (MSR) numbers */

/* x86-64 specific MSRs */
#define MSR_EFER		0xc0000080 /* extended feature register */
#define MSR_STAR		0xc0000081 /* legacy mode SYSCALL target */
#define MSR_LSTAR		0xc0000082 /* long mode SYSCALL target */
#define MSR_CSTAR		0xc0000083 /* compat mode SYSCALL target */
#define MSR_SYSCALL_MASK	0xc0000084 /* EFLAGS mask for syscall */
#define MSR_FS_BASE		0xc0000100 /* 64bit FS base */
#define MSR_GS_BASE		0xc0000101 /* 64bit GS base */
#define MSR_KERNEL_GS_BASE	0xc0000102 /* SwapGS GS shadow */
#define MSR_TSC_AUX		0xc0000103 /* Auxiliary TSC */

/* EFER bits: */
#define _EFER_SCE		0  /* SYSCALL/SYSRET */
#define _EFER_LME		8  /* Long mode enable */
#define _EFER_LMA		10 /* Long mode active (read-only) */
#define _EFER_NX		11 /* No execute enable */
#define _EFER_SVME		12 /* Enable virtualization */
#define _EFER_LMSLE		13 /* Long Mode Segment Limit Enable */
#define _EFER_FFXSR		14 /* Enable Fast FXSAVE/FXRSTOR */

#define EFER_SCE		(1<<_EFER_SCE)
#define EFER_LME		(1<<_EFER_LME)
#define EFER_LMA		(1<<_EFER_LMA)
#define EFER_NX			(1<<_EFER_NX)
#define EFER_SVME		(1<<_EFER_SVME)
#define EFER_LMSLE		(1<<_EFER_LMSLE)
#define EFER_FFXSR		(1<<_EFER_FFXSR)

/* Intel MSRs. Some also available on other CPUs */
#define MSR_IA32_SPEC_CTRL		0x00000048 /* Speculation Control */
#define SPEC_CTRL_IBRS_SHIFT		0	   /* Indirect Branch Restricted Speculation bit */
#define SPEC_CTRL_IBRS			BIT(SPEC_CTRL_IBRS_SHIFT)	   /* Indirect Branch Restricted Speculation */
#define SPEC_CTRL_STIBP_SHIFT		1	   /* Single Thread Indirect Branch Predictor (STIBP) bit */
#define SPEC_CTRL_STIBP			BIT(SPEC_CTRL_STIBP_SHIFT)	/* STIBP mask */
#define SPEC_CTRL_SSBD_SHIFT		2	   /* Speculative Store Bypass Disable bit */
#define SPEC_CTRL_SSBD			BIT(SPEC_CTRL_SSBD_SHIFT)	/* Speculative Store Bypass Disable */

#define MSR_IA32_PRED_CMD		0x00000049 /* Prediction Command */
#define PRED_CMD_IBPB			BIT(0)	   /* Indirect Branch Prediction Barrier */

#define MSR_IA32_PERFCTR0		0x000000c1
#define MSR_IA32_PERFCTR1		0x000000c2
#define MSR_FSB_FREQ			0x000000cd
#define MSR_NHM_PLATFORM_INFO		0x000000ce

#define MSR_NHM_SNB_PKG_CST_CFG_CTL	0x000000e2
#define NHM_C3_AUTO_DEMOTE		(1UL << 25)
#define NHM_C1_AUTO_DEMOTE		(1UL << 26)
#define ATM_LNC_C6_AUTO_DEMOTE		(1UL << 25)
#define SNB_C1_AUTO_UNDEMOTE		(1UL << 27)
#define SNB_C3_AUTO_UNDEMOTE		(1UL << 28)

#define MSR_PLATFORM_INFO		0x000000ce
#define MSR_MTRRcap			0x000000fe

#define MSR_IA32_ARCH_CAPABILITIES	0x0000010a
#define ARCH_CAP_RDCL_NO		BIT(0)	/* Not susceptible to Meltdown */
#define ARCH_CAP_IBRS_ALL		BIT(1)	/* Enhanced IBRS support */
#define ARCH_CAP_SKIP_VMENTRY_L1DFLUSH	BIT(3)	/* Skip L1D flush on vmentry */
#define ARCH_CAP_SSB_NO			BIT(4)	/*
						 * Not susceptible to Speculative Store Bypass
						 * attack, so no Speculative Store Bypass
						 * control required.
						 */
#define ARCH_CAP_MDS_NO			BIT(5)	/*
						 * Not susceptible to
						 * Microarchitectural Data
						 * Sampling (MDS) vulnerabilities.
						 */

#define MSR_IA32_FLUSH_CMD		0x0000010b
#define L1D_FLUSH			BIT(0)	/*
						 * Writeback and invalidate the
						 * L1 data cache.
						 */

#define MSR_IA32_BBL_CR_CTL		0x00000119
#define MSR_IA32_BBL_CR_CTL3		0x0000011e

#define MSR_IA32_SYSENTER_CS		0x00000174
#define MSR_IA32_SYSENTER_ESP		0x00000175
#define MSR_IA32_SYSENTER_EIP		0x00000176

#define MSR_IA32_MCG_CAP		0x00000179
#define MSR_IA32_MCG_STATUS		0x0000017a
#define MSR_IA32_MCG_CTL		0x0000017b

#define MSR_OFFCORE_RSP_0		0x000001a6
#define MSR_OFFCORE_RSP_1		0x000001a7
#define MSR_NHM_TURBO_RATIO_LIMIT	0x000001ad
#define MSR_IVT_TURBO_RATIO_LIMIT	0x000001ae

#define MSR_LBR_SELECT			0x000001c8
#define MSR_LBR_TOS			0x000001c9
#define MSR_LBR_NHM_FROM		0x00000680
#define MSR_LBR_NHM_TO			0x000006c0
#define MSR_LBR_CORE_FROM		0x00000040
#define MSR_LBR_CORE_TO			0x00000060

#define MSR_IA32_PEBS_ENABLE		0x000003f1
#define MSR_IA32_DS_AREA		0x00000600
#define MSR_IA32_PERF_CAPABILITIES	0x00000345
#define MSR_PEBS_LD_LAT_THRESHOLD	0x000003f6

#define MSR_MTRRfix64K_00000		0x00000250
#define MSR_MTRRfix16K_80000		0x00000258
#define MSR_MTRRfix16K_A0000		0x00000259
#define MSR_MTRRfix4K_C0000		0x00000268
#define MSR_MTRRfix4K_C8000		0x00000269
#define MSR_MTRRfix4K_D0000		0x0000026a
#define MSR_MTRRfix4K_D8000		0x0000026b
#define MSR_MTRRfix4K_E0000		0x0000026c
#define MSR_MTRRfix4K_E8000		0x0000026d
#define MSR_MTRRfix4K_F0000		0x0000026e
#define MSR_MTRRfix4K_F8000		0x0000026f
#define MSR_MTRRdefType			0x000002ff

#define MSR_IA32_CR_PAT			0x00000277

#define MSR_IA32_DEBUGCTLMSR		0x000001d9
#define MSR_IA32_LASTBRANCHFROMIP	0x000001db
#define MSR_IA32_LASTBRANCHTOIP		0x000001dc
#define MSR_IA32_LASTINTFROMIP		0x000001dd
#define MSR_IA32_LASTINTTOIP		0x000001de

/* DEBUGCTLMSR bits (others vary by model): */
#define DEBUGCTLMSR_LBR			(1UL <<  0) /* last branch recording */
#define DEBUGCTLMSR_BTF			(1UL <<  1) /* single-step on branches */
#define DEBUGCTLMSR_TR			(1UL <<  6)
#define DEBUGCTLMSR_BTS			(1UL <<  7)
#define DEBUGCTLMSR_BTINT		(1UL <<  8)
#define DEBUGCTLMSR_BTS_OFF_OS		(1UL <<  9)
#define DEBUGCTLMSR_BTS_OFF_USR		(1UL << 10)
#define DEBUGCTLMSR_FREEZE_LBRS_ON_PMI	(1UL << 11)

#define MSR_IA32_POWER_CTL		0x000001fc

#define MSR_IA32_MC0_CTL		0x00000400
#define MSR_IA32_MC0_STATUS		0x00000401
#define MSR_IA32_MC0_ADDR		0x00000402
#define MSR_IA32_MC0_MISC		0x00000403

/* C-state Residency Counters */
#define MSR_PKG_C3_RESIDENCY		0x000003f8
#define MSR_PKG_C6_RESIDENCY		0x000003f9
#define MSR_PKG_C7_RESIDENCY		0x000003fa
#define MSR_CORE_C3_RESIDENCY		0x000003fc
#define MSR_CORE_C6_RESIDENCY		0x000003fd
#define MSR_CORE_C7_RESIDENCY		0x000003fe
#define MSR_PKG_C2_RESIDENCY		0x0000060d
#define MSR_PKG_C8_RESIDENCY		0x00000630
#define MSR_PKG_C9_RESIDENCY		0x00000631
#define MSR_PKG_C10_RESIDENCY		0x00000632

/* Run Time Average Power Limiting (RAPL) Interface */

#define MSR_RAPL_POWER_UNIT		0x00000606

#define MSR_PKG_POWER_LIMIT		0x00000610
#define MSR_PKG_ENERGY_STATUS		0x00000611
#define MSR_PKG_PERF_STATUS		0x00000613
#define MSR_PKG_POWER_INFO		0x00000614

#define MSR_DRAM_POWER_LIMIT		0x00000618
#define MSR_DRAM_ENERGY_STATUS		0x00000619
#define MSR_DRAM_PERF_STATUS		0x0000061b
#define MSR_DRAM_POWER_INFO		0x0000061c

#define MSR_PP0_POWER_LIMIT		0x00000638
#define MSR_PP0_ENERGY_STATUS		0x00000639
#define MSR_PP0_POLICY			0x0000063a
#define MSR_PP0_PERF_STATUS		0x0000063b

#define MSR_PP1_POWER_LIMIT		0x00000640
#define MSR_PP1_ENERGY_STATUS		0x00000641
#define MSR_PP1_POLICY			0x00000642

#define MSR_CORE_C1_RES			0x00000660

#define MSR_AMD64_MC0_MASK		0xc0010044

#define MSR_IA32_MCx_CTL(x)		(MSR_IA32_MC0_CTL + 4*(x))
#define MSR_IA32_MCx_STATUS(x)		(MSR_IA32_MC0_STATUS + 4*(x))
#define MSR_IA32_MCx_ADDR(x)		(MSR_IA32_MC0_ADDR + 4*(x))
#define MSR_IA32_MCx_MISC(x)		(MSR_IA32_MC0_MISC + 4*(x))

#define MSR_AMD64_MCx_MASK(x)		(MSR_AMD64_MC0_MASK + (x))

/* These are consecutive and not in the normal 4er MCE bank block */
#define MSR_IA32_MC0_CTL2		0x00000280
#define MSR_IA32_MCx_CTL2(x)		(MSR_IA32_MC0_CTL2 + (x))

#define MSR_P6_PERFCTR0			0x000000c1
#define MSR_P6_PERFCTR1			0x000000c2
#define MSR_P6_EVNTSEL0			0x00000186
#define MSR_P6_EVNTSEL1			0x00000187

#define MSR_KNC_PERFCTR0               0x00000020
#define MSR_KNC_PERFCTR1               0x00000021
#define MSR_KNC_EVNTSEL0               0x00000028
#define MSR_KNC_EVNTSEL1               0x00000029

/* Alternative perfctr range with full access. */
#define MSR_IA32_PMC0			0x000004c1

/* AMD64 MSRs. Not complete. See the architecture manual for a more
   complete list. */

#define MSR_AMD64_PATCH_LEVEL		0x0000008b
#define MSR_AMD64_TSC_RATIO		0xc0000104
#define MSR_AMD64_NB_CFG		0xc001001f
#define MSR_AMD64_PATCH_LOADER		0xc0010020
#define MSR_AMD64_OSVW_ID_LENGTH	0xc0010140
#define MSR_AMD64_OSVW_STATUS		0xc0010141
#define MSR_AMD64_LS_CFG		0xc0011020
#define MSR_AMD64_DC_CFG		0xc0011022
#define MSR_AMD64_BU_CFG2		0xc001102a
#define MSR_AMD64_IBSFETCHCTL		0xc0011030
#define MSR_AMD64_IBSFETCHLINAD		0xc0011031
#define MSR_AMD64_IBSFETCHPHYSAD	0xc0011032
#define MSR_AMD64_IBSFETCH_REG_COUNT	3
#define MSR_AMD64_IBSFETCH_REG_MASK	((1UL<<MSR_AMD64_IBSFETCH_REG_COUNT)-1)
#define MSR_AMD64_IBSOPCTL		0xc0011033
#define MSR_AMD64_IBSOPRIP		0xc0011034
#define MSR_AMD64_IBSOPDATA		0xc0011035
#define MSR_AMD64_IBSOPDATA2		0xc0011036
#define MSR_AMD64_IBSOPDATA3		0xc0011037
#define MSR_AMD64_IBSDCLINAD		0xc0011038
#define MSR_AMD64_IBSDCPHYSAD		0xc0011039
#define MSR_AMD64_IBSOP_REG_COUNT	7
#define MSR_AMD64_IBSOP_REG_MASK	((1UL<<MSR_AMD64_IBSOP_REG_COUNT)-1)
#define MSR_AMD64_IBSCTL		0xc001103a
#define MSR_AMD64_IBSBRTARGET		0xc001103b
#define MSR_AMD64_IBS_REG_COUNT_MAX	8 /* includes MSR_AMD64_IBSBRTARGET */

#define MSR_AMD64_VIRT_SPEC_CTRL	0xc001011f

/* Fam 16h MSRs */
#define MSR_F16H_L2I_PERF_CTL		0xc0010230
#define MSR_F16H_L2I_PERF_CTR		0xc0010231

/* Fam 15h MSRs */
#define MSR_F15H_PERF_CTL		0xc0010200
#define MSR_F15H_PERF_CTR		0xc0010201
#define MSR_F15H_NB_PERF_CTL		0xc0010240
#define MSR_F15H_NB_PERF_CTR		0xc0010241
#define MSR_F15H_IC_CFG			0xc0011021
#define MSR_F15H_IC_CFG_DIS_IND		BIT_ULL(14)

/* Fam 10h MSRs */
#define MSR_FAM10H_MMIO_CONF_BASE	0xc0010058
#define FAM10H_MMIO_CONF_ENABLE		(1<<0)
#define FAM10H_MMIO_CONF_BUSRANGE_MASK	0xf
#define FAM10H_MMIO_CONF_BUSRANGE_SHIFT 2
#define FAM10H_MMIO_CONF_BASE_MASK	0xfffffffULL
#define FAM10H_MMIO_CONF_BASE_SHIFT	20
#define MSR_FAM10H_NODE_ID		0xc001100c
#define MSR_F10H_DECFG			0xc0011029
#define MSR_F10H_DECFG_LFENCE_SERIALIZE_BIT	1
#define MSR_F10H_DECFG_LFENCE_SERIALIZE		BIT_ULL(MSR_F10H_DECFG_LFENCE_SERIALIZE_BIT)

/* K8 MSRs */
#define MSR_K8_TOP_MEM1			0xc001001a
#define MSR_K8_TOP_MEM2			0xc001001d
#define MSR_K8_SYSCFG			0xc0010010
#define MSR_K8_INT_PENDING_MSG		0xc0010055
/* C1E active bits in int pending message */
#define K8_INTP_C1E_ACTIVE_MASK		0x18000000
#define MSR_K8_TSEG_ADDR		0xc0010112
#define MSR_K8_TSEG_MASK		0xc0010113
#define K8_MTRRFIXRANGE_DRAM_ENABLE	0x00040000 /* MtrrFixDramEn bit    */
#define K8_MTRRFIXRANGE_DRAM_MODIFY	0x00080000 /* MtrrFixDramModEn bit */
#define K8_MTRR_RDMEM_WRMEM_MASK	0x18181818 /* Mask: RdMem|WrMem    */

/* K7 MSRs */
#define MSR_K7_EVNTSEL0			0xc0010000
#define MSR_K7_PERFCTR0			0xc0010004
#define MSR_K7_EVNTSEL1			0xc0010001
#define MSR_K7_PERFCTR1			0xc0010005
#define MSR_K7_EVNTSEL2			0xc0010002
#define MSR_K7_PERFCTR2			0xc0010006
#define MSR_K7_EVNTSEL3			0xc0010003
#define MSR_K7_PERFCTR3			0xc0010007
#define MSR_K7_CLK_CTL			0xc001001b
#define MSR_K7_HWCR			0xc0010015
#define MSR_K7_FID_VID_CTL		0xc0010041
#define MSR_K7_FID_VID_STATUS		0xc0010042

/* K6 MSRs */
#define MSR_K6_WHCR			0xc0000082
#define MSR_K6_UWCCR			0xc0000085
#define MSR_K6_EPMR			0xc0000086
#define MSR_K6_PSOR			0xc0000087
#define MSR_K6_PFIR			0xc0000088

/* Centaur-Hauls/IDT defined MSRs. */
#define MSR_IDT_FCR1			0x00000107
#define MSR_IDT_FCR2			0x00000108
#define MSR_IDT_FCR3			0x00000109
#define MSR_IDT_FCR4			0x0000010a

#define MSR_IDT_MCR0			0x00000110
#define MSR_IDT_MCR1			0x00000111
#define MSR_IDT_MCR2			0x00000112
#define MSR_IDT_MCR3			0x00000113
#define MSR_IDT_MCR4			0x00000114
#define MSR_IDT_MCR5			0x00000115
#define MSR_IDT_MCR6			0x00000116
#define MSR_IDT_MCR7			0x00000117
#define MSR_IDT_MCR_CTRL		0x00000120

/* VIA Cyrix defined MSRs*/
#define MSR_VIA_FCR			0x00001107
#define MSR_VIA_LONGHAUL		0x0000110a
#define MSR_VIA_RNG			0x0000110b
#define MSR_VIA_BCR2			0x00001147

/* Transmeta defined MSRs */
#define MSR_TMTA_LONGRUN_CTRL		0x80868010
#define MSR_TMTA_LONGRUN_FLAGS		0x80868011
#define MSR_TMTA_LRTI_READOUT		0x80868018
#define MSR_TMTA_LRTI_VOLT_MHZ		0x8086801a

/* Intel defined MSRs. */
#define MSR_IA32_P5_MC_ADDR		0x00000000
#define MSR_IA32_P5_MC_TYPE		0x00000001
#define MSR_IA32_TSC			0x00000010
#define MSR_IA32_PLATFORM_ID		0x00000017
#define MSR_IA32_EBL_CR_POWERON		0x0000002a
#define MSR_EBC_FREQUENCY_ID		0x0000002c
#define MSR_SMI_COUNT			0x00000034
#define MSR_IA32_FEATURE_CONTROL        0x0000003a
#define MSR_IA32_TSC_ADJUST             0x0000003b

#define FEATURE_CONTROL_LOCKED				(1<<0)
#define FEATURE_CONTROL_VMXON_ENABLED_INSIDE_SMX	(1<<1)
#define FEATURE_CONTROL_VMXON_ENABLED_OUTSIDE_SMX	(1<<2)

#define MSR_IA32_APICBASE		0x0000001b
#define MSR_IA32_APICBASE_BSP		(1<<8)
#define MSR_IA32_APICBASE_ENABLE	(1<<11)
#define MSR_IA32_APICBASE_BASE		(0xfffff<<12)

#define MSR_IA32_TSCDEADLINE		0x000006e0

#define MSR_IA32_UCODE_WRITE		0x00000079
#define MSR_IA32_UCODE_REV		0x0000008b

#define MSR_IA32_PERF_STATUS		0x00000198
#define MSR_IA32_PERF_CTL		0x00000199
#define MSR_AMD_PSTATE_DEF_BASE		0xc0010064
#define MSR_AMD_PERF_STATUS		0xc0010063
#define MSR_AMD_PERF_CTL		0xc0010062

#define MSR_IA32_MPERF			0x000000e7
#define MSR_IA32_APERF			0x000000e8

#define MSR_IA32_THERM_CONTROL		0x0000019a
#define MSR_IA32_THERM_INTERRUPT	0x0000019b

#define THERM_INT_HIGH_ENABLE		(1 << 0)
#define THERM_INT_LOW_ENABLE		(1 << 1)
#define THERM_INT_PLN_ENABLE		(1 << 24)

#define MSR_IA32_THERM_STATUS		0x0000019c

#define THERM_STATUS_PROCHOT		(1 << 0)
#define THERM_STATUS_POWER_LIMIT	(1 << 10)

#define MSR_THERM2_CTL			0x0000019d

#define MSR_THERM2_CTL_TM_SELECT	(1ULL << 16)

#define MSR_IA32_MISC_ENABLE		0x000001a0

#define MSR_IA32_TEMPERATURE_TARGET	0x000001a2

#define MSR_IA32_ENERGY_PERF_BIAS	0x000001b0
#define ENERGY_PERF_BIAS_PERFORMANCE	0
#define ENERGY_PERF_BIAS_NORMAL		6
#define ENERGY_PERF_BIAS_POWERSAVE	15

#define MSR_IA32_PACKAGE_THERM_STATUS		0x000001b1

#define PACKAGE_THERM_STATUS_PROCHOT		(1 << 0)
#define PACKAGE_THERM_STATUS_POWER_LIMIT	(1 << 10)

#define MSR_IA32_PACKAGE_THERM_INTERRUPT	0x000001b2

#define PACKAGE_THERM_INT_HIGH_ENABLE		(1 << 0)
#define PACKAGE_THERM_INT_LOW_ENABLE		(1 << 1)
#define PACKAGE_THERM_INT_PLN_ENABLE		(1 << 24)

/* Thermal Thresholds Support */
#define THERM_INT_THRESHOLD0_ENABLE    (1 << 15)
#define THERM_SHIFT_THRESHOLD0        8
#define THERM_MASK_THRESHOLD0          (0x7f << THERM_SHIFT_THRESHOLD0)
#define THERM_INT_THRESHOLD1_ENABLE    (1 << 23)
#define THERM_SHIFT_THRESHOLD1        16
#define THERM_MASK_THRESHOLD1          (0x7f << THERM_SHIFT_THRESHOLD1)
#define THERM_STATUS_THRESHOLD0        (1 << 6)
#define THERM_LOG_THRESHOLD0           (1 << 7)
#define THERM_STATUS_THRESHOLD1        (1 << 8)
#define THERM_LOG_THRESHOLD1           (1 << 9)

/* MISC_ENABLE bits: architectural */
#define MSR_IA32_MISC_ENABLE_FAST_STRING	(1ULL << 0)
#define MSR_IA32_MISC_ENABLE_TCC		(1ULL << 1)
#define MSR_IA32_MISC_ENABLE_EMON		(1ULL << 7)
#define MSR_IA32_MISC_ENABLE_BTS_UNAVAIL	(1ULL << 11)
#define MSR_IA32_MISC_ENABLE_PEBS_UNAVAIL	(1ULL << 12)
#define MSR_IA32_MISC_ENABLE_ENHANCED_SPEEDSTEP	(1ULL << 16)
#define MSR_IA32_MISC_ENABLE_MWAIT		(1ULL << 18)
#define MSR_IA32_MISC_ENABLE_LIMIT_CPUID	(1ULL << 22)
#define MSR_IA32_MISC_ENABLE_XTPR_DISABLE	(1ULL << 23)
#define MSR_IA32_MISC_ENABLE_XD_DISABLE		(1ULL << 34)

/* MISC_ENABLE bits: model-specific, meaning may vary from core to core */
#define MSR_IA32_MISC_ENABLE_X87_COMPAT		(1ULL << 2)
#define MSR_IA32_MISC_ENABLE_TM1		(1ULL << 3)
#define MSR_IA32_MISC_ENABLE_SPLIT_LOCK_DISABLE	(1ULL << 4)
#define MSR_IA32_MISC_ENABLE_L3CACHE_DISABLE	(1ULL << 6)
#define MSR_IA32_MISC_ENABLE_SUPPRESS_LOCK	(1ULL << 8)
#define MSR_IA32_MISC_ENABLE_PREFETCH_DISABLE	(1ULL << 9)
#define MSR_IA32_MISC_ENABLE_FERR		(1ULL << 10)
#define MSR_IA32_MISC_ENABLE_FERR_MULTIPLEX	(1ULL << 10)
#define MSR_IA32_MISC_ENABLE_TM2		(1ULL << 13)
#define MSR_IA32_MISC_ENABLE_ADJ_PREF_DISABLE	(1ULL << 19)
#define MSR_IA32_MISC_ENABLE_SPEEDSTEP_LOCK	(1ULL << 20)
#define MSR_IA32_MISC_ENABLE_L1D_CONTEXT	(1ULL << 24)
#define MSR_IA32_MISC_ENABLE_DCU_PREF_DISABLE	(1ULL << 37)
#define MSR_IA32_MISC_ENABLE_TURBO_DISABLE	(1ULL << 38)
#define MSR_IA32_MISC_ENABLE_IP_PREF_DISABLE	(1ULL << 39)

#define MSR_IA32_TSC_DEADLINE		0x000006E0

/* P4/Xeon+ specific */
#define MSR_IA32_MCG_EAX		0x00000180
#define MSR_IA32_MCG_EBX		0x00000181
#define MSR_IA32_MCG_ECX		0x00000182
#define MSR_IA32_MCG_EDX		0x00000183
#define MSR_IA32_MCG_ESI		0x00000184
#define MSR_IA32_MCG_EDI		0x00000185
#define MSR_IA32_MCG_EBP		0x00000186
#define MSR_IA32_MCG_ESP		0x00000187
#define MSR_IA32_MCG_EFLAGS		0x00000188
#define MSR_IA32_MCG_EIP		0x00000189
#define MSR_IA32_MCG_RESERVED		0x0000018a

/* Pentium IV performance counter MSRs */
#define MSR_P4_BPU_PERFCTR0		0x00000300
#define MSR_P4_BPU_PERFCTR1		0x00000301
#define MSR_P4_BPU_PERFCTR2		0x00000302
#define MSR_P4_BPU_PERFCTR3		0x00000303
#define MSR_P4_MS_PERFCTR0		0x00000304
#define MSR_P4_MS_PERFCTR1		0x00000305
#define MSR_P4_MS_PERFCTR2		0x00000306
#define MSR_P4_MS_PERFCTR3		0x00000307
#define MSR_P4_FLAME_PERFCTR0		0x00000308
#define MSR_P4_FLAME_PERFCTR1		0x00000309
#define MSR_P4_FLAME_PERFCTR2		0x0000030a
#define MSR_P4_FLAME_PERFCTR3		0x0000030b
#define MSR_P4_IQ_PERFCTR0		0x0000030c
#define MSR_P4_IQ_PERFCTR1		0x0000030d
#define MSR_P4_IQ_PERFCTR2		0x0000030e
#define MSR_P4_IQ_PERFCTR3		0x0000030f
#define MSR_P4_IQ_PERFCTR4		0x00000310
#define MSR_P4_IQ_PERFCTR5		0x00000311
#define MSR_P4_BPU_CCCR0		0x00000360
#define MSR_P4_BPU_CCCR1		0x00000361
#define MSR_P4_BPU_CCCR2		0x00000362
#define MSR_P4_BPU_CCCR3		0x00000363
#define MSR_P4_MS_CCCR0			0x00000364
#define MSR_P4_MS_CCCR1			0x00000365
#define MSR_P4_MS_CCCR2			0x00000366
#define MSR_P4_MS_CCCR3			0x00000367
#define MSR_P4_FLAME_CCCR0		0x00000368
#define MSR_P4_FLAME_CCCR1		0x00000369
#define MSR_P4_FLAME_CCCR2		0x0000036a
#define MSR_P4_FLAME_CCCR3		0x0000036b
#define MSR_P4_IQ_CCCR0			0x0000036c
#define MSR_P4_IQ_CCCR1			0x0000036d
#define MSR_P4_IQ_CCCR2			0x0000036e
#define MSR_P4_IQ_CCCR3			0x0000036f
#define MSR_P4_IQ_CCCR4			0x00000370
#define MSR_P4_IQ_CCCR5			0x00000371
#define MSR_P4_ALF_ESCR0		0x000003ca
#define MSR_P4_ALF_ESCR1		0x000003cb
#define MSR_P4_BPU_ESCR0		0x000003b2
#define MSR_P4_BPU_ESCR1		0x000003b3
#define MSR_P4_BSU_ESCR0		0x000003a0
#define MSR_P4_BSU_ESCR1		0x000003a1
#define MSR_P4_CRU_ESCR0		0x000003b8
#define MSR_P4_CRU_ESCR1		0x000003b9
#define MSR_P4_CRU_ESCR2		0x000003cc
#define MSR_P4_CRU_ESCR3		0x000003cd
#define MSR_P4_CRU_ESCR4		0x000003e0
#define MSR_P4_CRU_ESCR5		0x000003e1
#define MSR_P4_DAC_ESCR0		0x000003a8
#define MSR_P4_DAC_ESCR1		0x000003a9
#define MSR_P4_FIRM_ESCR0		0x000003a4
#define MSR_P4_FIRM_ESCR1		0x000003a5
#define MSR_P4_FLAME_ESCR0		0x000003a6
#define MSR_P4_FLAME_ESCR1		0x000003a7
#define MSR_P4_FSB_ESCR0		0x000003a2
#define MSR_P4_FSB_ESCR1		0x000003a3
#define MSR_P4_IQ_ESCR0			0x000003ba
#define MSR_P4_IQ_ESCR1			0x000003bb
#define MSR_P4_IS_ESCR0			0x000003b4
#define MSR_P4_IS_ESCR1			0x000003b5
#define MSR_P4_ITLB_ESCR0		0x000003b6
#define MSR_P4_ITLB_ESCR1		0x000003b7
#define MSR_P4_IX_ESCR0			0x000003c8
#define MSR_P4_IX_ESCR1			0x000003c9
#define MSR_P4_MOB_ESCR0		0x000003aa
#define MSR_P4_MOB_ESCR1		0x000003ab
#define MSR_P4_MS_ESCR0			0x000003c0
#define MSR_P4_MS_ESCR1			0x000003c1
#define MSR_P4_PMH_ESCR0		0x000003ac
#define MSR_P4_PMH_ESCR1		0x000003ad
#define MSR_P4_RAT_ESCR0		0x000003bc
#define MSR_P4_RAT_ESCR1		0x000003bd
#define MSR_P4_SAAT_ESCR0		0x000003ae
#define MSR_P4_SAAT_ESCR1		0x000003af
#define MSR_P4_SSU_ESCR0		0x000003be
#define MSR_P4_SSU_ESCR1		0x000003bf /* guess: not in manual */

#define MSR_P4_TBPU_ESCR0		0x000003c2
#define MSR_P4_TBPU_ESCR1		0x000003c3
#define MSR_P4_TC_ESCR0			0x000003c4
#define MSR_P4_TC_ESCR1			0x000003c5
#define MSR_P4_U2L_ESCR0		0x000003b0
#define MSR_P4_U2L_ESCR1		0x000003b1

#define MSR_P4_PEBS_MATRIX_VERT		0x000003f2

/* Intel Core-based CPU performance counters */
#define MSR_CORE_PERF_FIXED_CTR0	0x00000309
#define MSR_CORE_PERF_FIXED_CTR1	0x0000030a
#define MSR_CORE_PERF_FIXED_CTR2	0x0000030b
#define MSR_CORE_PERF_FIXED_CTR_CTRL	0x0000038d
#define MSR_CORE_PERF_GLOBAL_STATUS	0x0000038e
#define MSR_CORE_PERF_GLOBAL_CTRL	0x0000038f
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL	0x00000390

/* Geode defined MSRs */
#define MSR_GEODE_BUSCONT_CONF0		0x00001900

/* Intel VT MSRs */
#define MSR_IA32_VMX_BASIC              0x00000480
#define MSR_IA32_VMX_PINBASED_CTLS      0x00000481
#define MSR_IA32_VMX_PROCBASED_CTLS     0x00000482
#define MSR_IA32_VMX_EXIT_CTLS          0x00000483
#define MSR_IA32_VMX_ENTRY_CTLS         0x00000484
#define MSR_IA32_VMX_MISC               0x00000485
#define MSR_IA32_VMX_CR0_FIXED0         0x00000486
#define MSR_IA32_VMX_CR0_FIXED1         0x00000487
#define MSR_IA32_VMX_CR4_FIXED0         0x00000488
#define MSR_IA32_VMX_CR4_FIXED1         0x00000489
#define MSR_IA32_VMX_VMCS_ENUM          0x0000048a
#define MSR_IA32_VMX_PROCBASED_CTLS2    0x0000048b
#define MSR_IA32_VMX_EPT_VPID_CAP       0x0000048c
#define MSR_IA32_VMX_TRUE_PINBASED_CTLS  0x0000048d
#define MSR_IA32_VMX_TRUE_PROCBASED_CTLS 0x0000048e
#define MSR_IA32_VMX_TRUE_EXIT_CTLS      0x0000048f
#define MSR_IA32_VMX_TRUE_ENTRY_CTLS     0x00000490

/* VMX_BASIC bits and bitmasks */
#define VMX_BASIC_VMCS_SIZE_SHIFT	32
#define VMX_BASIC_64		0x0001000000000000LLU
#define VMX_BASIC_MEM_TYPE_SHIFT	50
#define VMX_BASIC_MEM_TYPE_MASK	0x003c000000000000LLU
#define VMX_BASIC_MEM_TYPE_WB	6LLU
#define VMX_BASIC_INOUT		0x0040000000000000LLU

/* MSR_IA32_VMX_MISC bits */
#define MSR_IA32_VMX_MISC_VMWRITE_SHADOW_RO_FIELDS (1ULL << 29)
#define MSR_IA32_VMX_MISC_PREEMPTION_TIMER_SCALE   0x1F
/* AMD-V MSRs */

#define MSR_VM_CR                       0xc0010114
#define MSR_VM_IGNNE                    0xc0010115
#define MSR_VM_HSAVE_PA                 0xc0010117

#endif /* _ASM_X86_MSR_INDEX_H */
