/******************************************************************************

 @file  osal_memory_icall.c

 @brief OSAL Heap Memory management functions implemented on top of
        ICall primitive service.

 Group: WCS, LPC, BTS
 Target Device: CC2650, CC2640, CC1350

 ******************************************************************************
 
 Copyright (c) 2013-2016, Texas Instruments Incorporated
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 *  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

 *  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 *  Neither the name of Texas Instruments Incorporated nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ******************************************************************************
 Release Name: ble_sdk_2_02_00_31
 Release Date: 2016-06-16 18:57:29
 *****************************************************************************/

/* ------------------------------------------------------------------------------------------------
 *                                          Includes
 * ------------------------------------------------------------------------------------------------
 */

#include "comdef.h"
#include "OSAL.h"
#include "OSAL_Memory.h"

#include <ICall.h>

/**************************************************************************************************
 * @fn          osal_mem_alloc
 *
 * @brief       This function implements the OSAL dynamic memory allocation functionality.
 *
 * input parameters
 *
 * @param size - the number of bytes to allocate from the HEAP.
 *
 * output parameters
 *
 * None.
 *
 * @return      None.
 */
#ifdef DPRINTF_OSALHEAPTRACE
void *osal_mem_alloc_dbg( uint16 size, const char *fname, unsigned lnum )
#else /* DPRINTF_OSALHEAPTRACE */
void *osal_mem_alloc( uint16 size )
#endif /* DPRINTF_OSALHEAPTRACE */
{
  return ICall_malloc(size);
}

/**************************************************************************************************
 * @fn          osal_mem_free
 *
 * @brief       This function implements the OSAL dynamic memory de-allocation functionality.
 *
 * input parameters
 *
 * @param ptr - A valid pointer (i.e. a pointer returned by osal_mem_alloc()) to the memory to free.
 *
 * output parameters
 *
 * None.
 *
 * @return      None.
 */
#ifdef DPRINTF_OSALHEAPTRACE
void osal_mem_free_dbg(void *ptr, const char *fname, unsigned lnum)
#else /* DPRINTF_OSALHEAPTRACE */
void osal_mem_free(void *ptr)
#endif /* DPRINTF_OSALHEAPTRACE */
{
  ICall_free(ptr);
}

/**************************************************************************************************
*/