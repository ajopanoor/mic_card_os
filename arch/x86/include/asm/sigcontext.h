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

#ifndef _ASM_X86_SIGCONTEXT_H
#define _ASM_X86_SIGCONTEXT_H

#include <uapi/asm/sigcontext.h>

#ifdef __i386__
struct sigcontext {
	unsigned short gs, __gsh;
	unsigned short fs, __fsh;
	unsigned short es, __esh;
	unsigned short ds, __dsh;
	unsigned long di;
	unsigned long si;
	unsigned long bp;
	unsigned long sp;
	unsigned long bx;
	unsigned long dx;
	unsigned long cx;
	unsigned long ax;
	unsigned long trapno;
	unsigned long err;
	unsigned long ip;
	unsigned short cs, __csh;
	unsigned long flags;
	unsigned long sp_at_signal;
	unsigned short ss, __ssh;

	/*
	 * fpstate is really (struct _fpstate *) or (struct _xstate *)
	 * depending on the FP_XSTATE_MAGIC1 encoded in the SW reserved
	 * bytes of (struct _fpstate) and FP_XSTATE_MAGIC2 present at the end
	 * of extended memory layout. See comments at the definition of
	 * (struct _fpx_sw_bytes)
	 */
	void __user *fpstate;		/* zero when no FPU/extended context */
	unsigned long oldmask;
	unsigned long cr2;
};
#else /* __i386__ */
struct sigcontext {
	unsigned long r8;
	unsigned long r9;
	unsigned long r10;
	unsigned long r11;
	unsigned long r12;
	unsigned long r13;
	unsigned long r14;
	unsigned long r15;
	unsigned long di;
	unsigned long si;
	unsigned long bp;
	unsigned long bx;
	unsigned long dx;
	unsigned long ax;
	unsigned long cx;
	unsigned long sp;
	unsigned long ip;
	unsigned long flags;
	unsigned short cs;
	unsigned short gs;
	unsigned short fs;
	unsigned short __pad0;
	unsigned long err;
	unsigned long trapno;
	unsigned long oldmask;
	unsigned long cr2;

	/*
	 * fpstate is really (struct _fpstate *) or (struct _xstate *)
	 * depending on the FP_XSTATE_MAGIC1 encoded in the SW reserved
	 * bytes of (struct _fpstate) and FP_XSTATE_MAGIC2 present at the end
	 * of extended memory layout. See comments at the definition of
	 * (struct _fpx_sw_bytes)
	 */
	void __user *fpstate;		/* zero when no FPU/extended context */
	unsigned long reserved1[8];
};
#endif /* !__i386__ */
#endif /* _ASM_X86_SIGCONTEXT_H */
