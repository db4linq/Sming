/*
 * Copyright (c) 2001, Swedish Institute of Computer Science.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 * 3. Neither the name of the Institute nor the names of its contributors 
 *    may be used to endorse or promote products derived from this software 
 *    without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE. 
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

// Override c_types.h include and remove buggy espconn
#define _C_TYPES_H_
#include <espinc/c_types_compatible.h>
#include "eagle_soc.h"

//prevent inclusion of user_config.h here
#define __USER_CONFIG_H__
#include "osapi.h"
#include <stdarg.h>
#include "m_printf.h"

#define EFAULT 14

#ifdef USE_MAX_IRAM
#define LWIP_DATA_IRAM_ATTR __attribute__((aligned(4), section(".iram.data")))
#else
#define LWIP_DATA_IRAM_ATTR
#endif

//#define LWIP_PROVIDE_ERRNO

#if (1)
#define BYTE_ORDER LITTLE_ENDIAN
#else
#define BYTE_ORDER BIG_ENDIAN
#endif


typedef unsigned   char    u8_t;
typedef signed     char    s8_t;
typedef unsigned   short   u16_t;
typedef signed     short   s16_t;
typedef unsigned   long    u32_t;
typedef signed     long    s32_t;
typedef unsigned long   mem_ptr_t;

#define S16_F "d"
#define U16_F "d"
#define X16_F "x"

#define S32_F "d"
#define U32_F "d"
#define X32_F "x"



//#define PACK_STRUCT_FIELD(x) x __attribute__((packed))
#define PACK_STRUCT_FIELD(x) x
#define PACK_STRUCT_STRUCT __attribute__((packed))
#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_END

#ifdef LWIP_DEBUG
#include "debug_progmem.h"
#define LWIP_PLATFORM_DIAG(x) LOG_I x
#define LWIP_PLATFORM_ASSERT(x) m_printf("ASSERT: %s %s %d", (x), __FUNCTION__, __LINE__)


#else
#define LWIP_PLATFORM_DIAG(x)
#define LWIP_PLATFORM_ASSERT(x)
#endif

#define SYS_ARCH_DECL_PROTECT(x)
#define SYS_ARCH_PROTECT(x)
#define SYS_ARCH_UNPROTECT(x)

#define LWIP_PLATFORM_BYTESWAP 1
#define LWIP_PLATFORM_HTONS(_n)  ((u16_t)((((_n) & 0xff) << 8) | (((_n) >> 8) & 0xff)))
#define LWIP_PLATFORM_HTONL(_n)  ((uint32_t)((((_n) & 0xff) << 24) | (((_n) & 0xff00) << 8) | (((_n) >> 8)  & 0xff00) | (((_n) >> 24) & 0xff)))

#if LWIP_RAW
extern u8_t memp_memory_RAW_PCB_base[];
#endif /* LWIP_RAW */

#if LWIP_UDP
extern u8_t memp_memory_UDP_PCB_base[];
#endif /* LWIP_UDP */

#if LWIP_TCP
extern u8_t memp_memory_TCP_PCB_base[];
extern u8_t memp_memory_TCP_PCB_LISTEN_base[];
extern u8_t memp_memory_TCP_SEG_base[] SHMEM_ATTR;
#endif /* LWIP_TCP */

#if (!NO_SYS || (NO_SYS && !NO_SYS_NO_TIMERS)) /* LWIP_TIMERS */
extern u8_t memp_memory_SYS_TIMEOUT_base[];
#endif /* LWIP_TIMERS */

extern u8_t memp_memory_PBUF_base[];
extern u8_t memp_memory_PBUF_POOL_base[];



#endif /* __ARCH_CC_H__ */
