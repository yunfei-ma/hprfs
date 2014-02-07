/*  $Date: 2008/10/07 18:33:58 $
 *  $Revision: 1.18 $
 */

/** \mainpage Development Board
 * Copyright (C) 2007 Bosch Sensortec GmbH
 *  \section intro_sec introduction
 * Firmware for Development Board
 * 
 * Author:	Alexander.Kaestner@tzm.de
 *
 * \section disclaimer_sec Disclaimer
 *
 * Common:
 * Bosch Sensortec products are developed for the consumer goods industry. They may only be used 
 * within the parameters of the respective valid product data sheet.  Bosch Sensortec products are 
 * provided with the express understanding that there is no warranty of fitness for a particular purpose. 
 * They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device 
 * that may lead to bodily harm or property damage if the system or device malfunctions. In addition, 
 * Bosch Sensortec products are not fit for use in products which interact with motor vehicle systems.  
 * The resale and/or use of products are at the purchaser’s own risk and his own responsibility. The 
 * examination of fitness for the intended use is the sole responsibility of the Purchaser. 
 *
 * The purchaser shall indemnify Bosch Sensortec from all third party claims, including any claims for 
 * incidental, or consequential damages, arising from any product use not covered by the parameters of 
 * the respective valid product data sheet or not approved by Bosch Sensortec and reimburse Bosch 
 * Sensortec for all costs in connection with such claims.
 *
 * The purchaser must monitor the market for the purchased products, particularly with regard to 
 * product safety and inform Bosch Sensortec without delay of all security relevant incidents.
 *
 * Engineering Samples are marked with an asterisk (*) or (e). Samples may vary from the valid 
 * technical specifications of the product series. They are therefore not intended or fit for resale to third 
 * parties or for use in end products. Their sole purpose is internal client testing. The testing of an 
 * engineering sample may in no way replace the testing of a product series. Bosch Sensortec 
 * assumes no liability for the use of engineering samples. By accepting the engineering samples, the 
 * Purchaser agrees to indemnify Bosch Sensortec from all claims arising from the use of engineering 
 * samples.
 *
 * Special:
 * This software module (hereinafter called "Software") and any information on application-sheets 
 * (hereinafter called "Information") is provided free of Charge for the sole purpose to support your 
 * application work. The Software and Information is subject to the following terms and conditions: 
 *
 * The Software is specifically designed for the exclusive use for Bosch Sensortec products by 
 * personnel who have special experience and training. Do not use this Software if you do not have the 
 * proper experience or training. 
 *
 * This Software package is provided `` as is `` and without any expressed or implied warranties, 
 * including without limitation, the implied warranties of merchantability and fitness for a particular 
 * purpose. 
 *
 * Bosch Sensortec and their representatives and agents deny any liability for the functional impairment 
 * of this Software in terms of fitness, performance and safety. Bosch Sensortec and their 
 * representatives and agents shall not be liable for any direct or indirect damages or injury, except as 
 * otherwise stipulated in mandatory applicable law.
 * 
 * The Information provided is believed to be accurate and reliable. Bosch Sensortec assumes no 
 * responsibility for the consequences of use of such Information nor for any infringement of patents or 
 * other rights of third parties which may result from its use. No license is granted by implication or 
 * otherwise under any patent or patent rights of Bosch. Specifications mentioned in the Information are 
 * subject to change without notice.
 *
 * It is not allowed to deliver the source code of the Software to any third party without permission of 
 * Bosch Sensortec.
 */

/*! \file main.c 
    \brief This file contains the main function for the Development Board
*/
 
/*-----------------------------------------------------------------------------------------------*/
/* Includes*/
/*-----------------------------------------------------------------------------------------------*/
#include "SAM3S.h"
#include "board.h"
#include "define.h"
#include "twi.h"
#include "timetick.h"


#include "stdio.h"
#include "string.h"




/*-----------------------------------------------------------------------------------------------*/
/* Defines*/
/*-----------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------*/
/* Type definitions*/
/*-----------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------*/
/* Variables*/
/*-----------------------------------------------------------------------------------------------*/
Twi *twi;
#define TWCK            100000

/** main routine
 */
extern void ConfigureRTT( void );
extern void SystemInit (void);
extern void mpu_setup(void);

S32 main(void)
{
    Pin pins[] = {PINS_TWI0};
    int i;

    SystemInit();
    for (i = 0; i < 500; i ++);

//    ConfigureRTT();

    /* Configure TWI pins. */
    PIO_Configure(pins, PIO_LISTSIZE(pins));
    twi = TWID_Initialize(ID_TWI0,TWI0,TWCK, BOARD_MCK);

//    mpu_setup();

    while(1);
}

extern void hard_fault_handler_c(unsigned int *hardfault_args)
{
    unsigned int stacked_r0;
    unsigned int stacked_r1;
    unsigned int stacked_r2;
    unsigned int stacked_r3;
    unsigned int stacked_r12;
    unsigned int stacked_lr;
    unsigned int stacked_pc;
    unsigned int stacked_psr;
    unsigned int cfsr;

    printf ("\r\n[Hard fault handler] SP=0x%x\r\n", hardfault_args);
    cfsr = SCB->CFSR;
    printf ("CFSR = 0x%x\r\n", cfsr);
    if (SCB_CFSR_MEMFAULTSR_Msk & cfsr) {
        printf("\tmemory fault\r\n");
    }
    if (SCB_CFSR_BUSFAULTSR_Msk & cfsr) {
        printf("\tBUS fault\r\n");
    }
    if (SCB_CFSR_USGFAULTSR_Msk & cfsr) {
        printf("\tusage fault\r\n");
    }
    printf ("HFSR = 0x%x - hard fault\r\n", SCB->HFSR);
    printf ("DFSR = 0x%x - debug fault\r\n", SCB->DFSR);
    printf ("AFSR = 0x%x - auxiliary fault\r\n", SCB->AFSR);
    printf ("SHCSR = %x - system hard control and status\r\n", SCB->SHCSR);
    printf ("MMFAR = 0x%x - memory fault address\r\n", SCB->MMFAR);
    printf ("BFAR = 0x%x - bus fault address\r\n", SCB->BFAR);

    stacked_r0 = hardfault_args[0];
    stacked_r1 = hardfault_args[1];
    stacked_r2 = hardfault_args[2];
    stacked_r3 = hardfault_args[3];
    
    stacked_r12 = hardfault_args[4];
    stacked_lr = hardfault_args[5];
    stacked_pc = hardfault_args[6];
    stacked_psr = hardfault_args[7];
    
    printf ("R0 = 0x%x\r\n", stacked_r0);
    printf ("R1 = 0x%x\r\n", stacked_r1);
    printf ("R2 = 0x%x\r\n", stacked_r2);
    printf ("R3 = 0x%x\r\n", stacked_r3);
    printf ("R12 = 0x%x\r\n", stacked_r12);
    printf ("LR [R14] = 0x%x  subroutine call return address\r\n", stacked_lr);
    printf ("PC [R15] = 0x%x  program counter\r\n", stacked_pc);
    printf ("PSR = 0x%x\r\n", stacked_psr);
    
    while (1);
}

