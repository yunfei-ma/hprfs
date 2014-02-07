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
 * Interface for default exception handlers.
 */

#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_

#define __irq
/*----------------------------------------------------------------------------
 *        Types
 *----------------------------------------------------------------------------*/

/* Function prototype for exception table items (interrupt handler). */
typedef void( *IntFunc )( void ) ;

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

/* Default empty handler */
extern __irq void IrqHandlerNotUsed( void ) ;

/* Cortex-M3 core handlers */
extern __irq void NMI_Handler( void );
extern __irq void HardFault_Handler( void );
extern __irq void MemManage_Handler( void );
extern __irq void BusFault_Handler( void );
extern __irq void UsageFault_Handler( void );
extern __irq void SVC_Handler( void );
extern __irq void DebugMon_Handler( void );
extern __irq void PendSV_Handler( void );
//extern __irq void SysTick_Handler( void );

/* Peripherals handlers */
extern __irq void ACC_IrqHandler( void ) ;
extern __irq void ADC_IrqHandler( void ) ;
extern __irq void CRCCU_IrqHandler( void ) ;
extern __irq void DAC_IrqHandler( void ) ;
extern __irq void EEFC_IrqHandler( void ) ;
extern __irq void MCI_IrqHandler( void ) ;
extern __irq void PIOA_IrqHandler( void ) ;
extern __irq void PIOB_IrqHandler( void ) ;
extern __irq void PIOC_IrqHandler( void ) ;
extern __irq void PMC_IrqHandler( void ) ;
extern __irq void PWM_IrqHandler( void ) ;
extern __irq void RSTC_IrqHandler( void ) ;
extern __irq void RTC_IrqHandler( void ) ;
//extern __irq void RTT_IrqHandler( void ) ;
extern __irq void SMC_IrqHandler( void ) ;
extern __irq void SPI_IrqHandler( void ) ;
extern __irq void SSC_IrqHandler( void ) ;
extern __irq void SUPC_IrqHandler( void ) ;
extern __irq void TC0_IrqHandler( void ) ;
extern __irq void TC1_IrqHandler( void ) ;
extern __irq void TC2_IrqHandler( void ) ;
extern __irq void TC3_IrqHandler( void ) ;
extern __irq void TC4_IrqHandler( void ) ;
extern __irq void TC5_IrqHandler( void ) ;
extern __irq void TWI0_IrqHandler( void ) ;
extern __irq void TWI1_IrqHandler( void ) ;
extern __irq void UART0_IrqHandler( void ) ;
extern __irq void UART1_IrqHandler( void ) ;
extern __irq void USART0_IrqHandler( void ) ;
extern __irq void USART1_IrqHandler( void ) ;
extern __irq void USBD_IrqHandler(void);
extern __irq void WDT_IrqHandler( void ) ;
extern __irq void RTT_IrqHandler( void );

#endif /* _EXCEPTIONS_ */
