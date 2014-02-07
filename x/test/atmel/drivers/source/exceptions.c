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
 * \file
 * This file contains the default exception handlers.
 *
 * \note
 * The exception handler has extern aliases.
 * As they are extern aliases, any function with the same name will override
 * this definition.
 */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "chip.h"

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

/**
 * \brief Default interrupt handler for not used irq.
 */
__irq void IrqHandlerNotUsed( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for Supply Controller.
 */
extern __irq void SUPC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for Reset Controller.
 */
extern __irq void RSTC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for Real Time Clock.
 */
extern __irq void RTC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for Real Time Timer.
 */
extern __irq void RTT_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for Watchdog Timer.
 */
extern __irq void WDT_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for PMC.
 */
extern __irq void PMC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for EEFC.
 */
extern __irq void EEFC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for UART0.
 */
extern __irq void UART0_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for UART1.
 */
extern __irq void UART1_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for SMC.
 */
extern __irq void SMC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for PIOA Controller.
 */
extern __irq void PIOA_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for PIOB Controller.
 */
extern __irq void PIOB_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for PIOC Controller.
 */
extern __irq void PIOC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for USART0.
 */
extern __irq void USART0_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for USART1.
 */
extern __irq void USART1_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for MCI.
 */
extern __irq void MCI_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for TWI0.
 */
extern __irq void TWI0_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for TWI1.
 */
extern __irq void TWI1_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for SPI.
 */
extern __irq void SPI_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for SSC.
 */
extern __irq void SSC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for TC0.
 */
extern __irq void TC0_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for TC1.
 */
extern __irq void TC1_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default interrupt handler for TC2.
 */
extern __irq void TC2_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for TC3.
 */
extern __irq void TC3_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for TC4.
 */
extern __irq void TC4_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for TC5.
 */
extern __irq void TC5_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for ADC.
 */
extern __irq void ADC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for DAC.
 */
extern __irq void DAC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for PWM.
 */
extern __irq void PWM_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for CRCCU.
 */
extern __irq void CRCCU_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for ACC.
 */
extern __irq void ACC_IrqHandler( void )
{
    while ( 1 ) ;
}

/**
 * \brief Default SUPC interrupt handler for USBD.
 */
extern __irq void USBD_IrqHandler( void )
{
    while ( 1 ) ;
}
