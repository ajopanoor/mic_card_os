/* * Copyright (c) Intel Corporation (2011).
*
* Disclaimer: The codes contained in these modules may be specific to the
* Intel Software Development Platform codenamed: Knights Ferry, and the 
* Intel product codenamed: Knights Corner, and are not backward compatible 
* with other Intel products. Additionally, Intel will NOT support the codes 
* or instruction set in future products.
*
* Intel offers no warranty of any kind regarding the code.  This code is
* licensed on an "AS IS" basis and Intel is not obligated to provide any support,
* assistance, installation, training, or other services of any kind.  Intel is 
* also not obligated to provide any updates, enhancements or extensions.  Intel 
* specifically disclaims any warranty of merchantability, non-infringement, 
* fitness for any particular purpose, and any other warranty.
*
* Further, Intel disclaims all liability of any kind, including but not
* limited to liability for infringement of any proprietary rights, relating
* to the use of the code, even if Intel is notified of the possibility of
* such liability.  Except as expressly stated in an Intel license agreement
* provided with this code and agreed upon with Intel, no license, express
* or implied, by estoppel or otherwise, to any intellectual property rights
* is granted herein.
*/

#ifndef _ASM_X86_XOR_64_H
#define _ASM_X86_XOR_64_H

#ifdef CONFIG_X86_EARLYMIC
#error "xor_64 unsupported for ML1OM and MK1OM"
#endif

static struct xor_block_template xor_block_sse = {
	.name = "generic_sse",
	.do_2 = xor_sse_2,
	.do_3 = xor_sse_3,
	.do_4 = xor_sse_4,
	.do_5 = xor_sse_5,
};


/* Also try the AVX routines */
#include <asm/xor_avx.h>

/* We force the use of the SSE xor block because it can write around L2.
   We may also be able to load into the L1 only depending on how the cpu
   deals with a load to a line that is being prefetched.  */
#undef XOR_TRY_TEMPLATES
#define XOR_TRY_TEMPLATES			\
do {						\
	AVX_XOR_SPEED;				\
	xor_speed(&xor_block_sse_pf64);		\
	xor_speed(&xor_block_sse);		\
} while (0)

#endif /* _ASM_X86_XOR_64_H */
