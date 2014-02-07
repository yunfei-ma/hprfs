/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 *  \file
 *  Implement simple system tick usage.
 */

/*----------------------------------------------------------------------------
 *         Headers
 *----------------------------------------------------------------------------*/

#include "board.h"
#include "RTL.h"

/*----------------------------------------------------------------------------
 *         Local variables
 *----------------------------------------------------------------------------*/

/** Tick Counter united by ms */
volatile uint32_t dwCounter=0 ;
volatile Rtt *rtt = RTT;
/*----------------------------------------------------------------------------
 *         Exported Functions
 *----------------------------------------------------------------------------*/
/**
 *  \brief Handler for Sytem Tick interrupt.
 */
extern void RTT_IRQHandler( void )
{

    uint32_t status ;
    /* Get RTT status */
    status = rtt->RTT_SR;
    status = status;

    /* Time has changed, refresh display */
   // if ((status & RTT_SR_RTTINC) == RTT_SR_RTTINC)
    {
        dwCounter = rtt->RTT_VR;
    }
}


/**
 *  \brief Sync Wait for several ms
 */
extern void delay( volatile uint32_t dwMs )
{
/*
    uint32_t dwStart ;
    uint32_t dwCurrent ;

    dwStart = RTT->RTT_VR ;
    do
    {
        dwCurrent = RTT->RTT_VR ;
    } while ( dwCurrent - dwStart < dwMs ) ;
*/
    os_dly_wait(dwMs);
}

void RTT_SetPrescaler(Rtt *rtt, uint16_t prescaler)
{
    rtt->RTT_MR = (prescaler |  RTT_MR_RTTRST);
}

uint32_t RTT_GetTime(Rtt *rtt)
{
    return rtt->RTT_VR;
}

void RTT_EnableIT(Rtt *rtt, uint32_t sources)
{
    rtt->RTT_MR |= sources;
}


extern void ConfigureRTT( void )
{
    uint32_t previousTime ;

    /* Configure RTT for a 1 second tick interrupt */
    RTT_SetPrescaler( RTT, 32 ) ;
    previousTime = RTT_GetTime( RTT ) ;
    while ( previousTime == RTT_GetTime( RTT ) ) ;

    /* Enable RTT interrupt */
/*
    NVIC_DisableIRQ( RTT_IRQn ) ;
    NVIC_ClearPendingIRQ( RTT_IRQn ) ;
    NVIC_SetPriority( RTT_IRQn, 0 ) ;
    NVIC_EnableIRQ( RTT_IRQn ) ;
    RTT_EnableIT( RTT, RTT_MR_RTTINCIEN ) ;*/
}

