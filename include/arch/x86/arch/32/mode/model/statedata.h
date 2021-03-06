/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef __ARCH_MODEL_STATEDATA_32_H
#define __ARCH_MODEL_STATEDATA_32_H

#include <config.h>
#include <object/structures.h>
#include <arch/types.h>
#include <smp/smp.h>

extern pdpte_t ia32KSGlobalPDPT[BIT(PDPT_INDEX_BITS)];
extern pde_t ia32KSGlobalPD[BIT(PD_INDEX_BITS + PDPT_INDEX_BITS)];
extern pte_t ia32KSGlobalPT[BIT(PT_INDEX_BITS)];

#ifdef CONFIG_BENCHMARK_USE_KERNEL_LOG_BUFFER
extern pte_t ia32KSGlobalLogPT[BIT(PT_INDEX_BITS)];
#endif /* CONFIG_BENCHMARK_USE_KERNEL_LOG_BUFFER */

NODE_STATE_BEGIN(modeNodeState)
/* Current active page directory. This is really just a shadow of CR3 */
NODE_STATE_DECLARE(paddr_t, ia32KSCurrentPD);
NODE_STATE_END(modeNodeState);

#endif
