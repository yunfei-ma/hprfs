#include <stdint.h>
#include <SAM3S.H>
#include "trace.h"

void mpu_setup(void)
{


    /* Set up MPU:
         * - Region 0: 0x00000000 - 0x0007FFFF --- on-chip non-volatile memory
         *              + Size: 128kB
         *              + XN=0: enable instruction fetch
         *              + AP=b111: read only
         *              + TEX=0, S=1, C=1, B=1
         * - Region 1: 0x20000000 - 0x20010000 --- on-chip SRAM
         *              + Size: 64kB
         *              + XN=1: disable instruction fetch
         *              + AP=b011: full access
         *              + TEX=0, S=1, C=1, B=1
         * - Region 2:  0x24000000 - 0x40000000 --- bit band alias
         *              + Size: 4MB
         *              + XN=1: disable instruction fetch
         *              + AP=b011: full access
         *              + TEX=0, S=1, C=0, B=1
         * - Region 3: 0x40000000 - 0x5FFFFFFF --- AHB peripheral
         *              + Size: 2MB
         *              + XN=1: disable instruction fetch
         *              + AP=b011: full access
         *              + TEX=0, S=1, C=0, B=1
         * - Region 4: 0xE0000000 - 0xFFFFFFF --- System control
         *              + Size: 256MB
         *              + XN=1: disable instruction fetch
         *              + AP=b011: full access
         *              + TEX=0, S=1, C=0, B=1
         */
    MPU->RNR = 0;           //indicate MPU region 0
    MPU->RBAR = 0x00400000; // update the base address for the region 0
    MPU->RASR = 0x07070021;
    MPU->RNR = 1;
    MPU->RBAR = 0x20000000; // update the base address for the region 1
    MPU->RASR = 0x1307001F;
    MPU->RNR = 2;
    MPU->RBAR = 0x24000000; // update the base address for the region 2
    MPU->RASR = 0x1305012b;
    MPU->RNR = 3;
    MPU->RBAR = 0x40000000; // update the base address for the region 3
    MPU->RASR = 0x13050029;
    MPU->RNR = 4;
    MPU->RBAR = 0xE0000000; // update the base address for the region 4
    MPU->RASR = 0x13070037;
    
    TRACE_INFO("Setup MPU: \n\r"
           "This provide 5 regions: \n\r"
           "Region 0 - Privileged code: 0x00000000 - 0x0007FFFF(512kB)n\r"
           "Region 1 - Privileged data: 0x10000000 - 0x10007FFF(32kB)\n\r"
           "Region 2 - APB Peripheral:  0x40000000 - 0x400FFFFF(1MB)\n\r"
           "Region 3 - AHB peripheral:  0x50000000 - 0x501FFFFF(2MB)\n\r"
           "Region 4 - System control:  0xE0000000 - 0xE00FFFFF(1MB)\n\r");
    
    SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk; //Enable Memory management fault
    MPU->CTRL |= MPU_CTRL_ENABLE_Msk; //Enable the MPU
    TRACE_INFO("Enable MPU!\n\r");
}

extern void memmanage_handler_c(unsigned int *hardfault_args)
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

    TRACE_ERROR ("\r\n[memory manage fault] SP=0x%x\r\n", hardfault_args);
    cfsr = SCB->CFSR;
    TRACE_ERROR ("CFSR = 0x%x\r\n", cfsr);
    if (SCB_CFSR_MEMFAULTSR_Msk & cfsr) {
        TRACE_ERROR("\tmemory fault\r\n");
    }
    if (SCB_CFSR_BUSFAULTSR_Msk & cfsr) {
        TRACE_ERROR("\tBUS fault\r\n");
    }
    if (SCB_CFSR_USGFAULTSR_Msk & cfsr) {
        TRACE_ERROR("\tusage fault\r\n");
    }
    TRACE_ERROR ("HFSR = 0x%x - hard fault\r\n", SCB->HFSR);
    TRACE_ERROR ("DFSR = 0x%x - debug fault\r\n", SCB->DFSR);
    TRACE_ERROR ("AFSR = 0x%x - auxiliary fault\r\n", SCB->AFSR);
    TRACE_ERROR ("SHCSR = %x - system hard control and status\r\n", SCB->SHCSR);
    TRACE_ERROR ("MMFAR = 0x%x - memory fault address\r\n", SCB->MMFAR);
    TRACE_ERROR ("BFAR = 0x%x - bus fault address\r\n", SCB->BFAR);

    stacked_r0 = hardfault_args[0];
    stacked_r1 = hardfault_args[1];
    stacked_r2 = hardfault_args[2];
    stacked_r3 = hardfault_args[3];
    
    stacked_r12 = hardfault_args[4];
    stacked_lr = hardfault_args[5];
    stacked_pc = hardfault_args[6];
    stacked_psr = hardfault_args[7];
    
    TRACE_ERROR ("R0 = 0x%x\r\n", stacked_r0);
    TRACE_ERROR ("R1 = 0x%x\r\n", stacked_r1);
    TRACE_ERROR ("R2 = 0x%x\r\n", stacked_r2);
    TRACE_ERROR ("R3 = 0x%x\r\n", stacked_r3);
    TRACE_ERROR ("R12 = 0x%x\r\n", stacked_r12);
    TRACE_ERROR ("LR [R14] = 0x%x  subroutine call return address\r\n", stacked_lr);
    TRACE_ERROR ("PC [R15] = 0x%x  program counter\r\n", stacked_pc);
    TRACE_ERROR ("PSR = 0x%x\r\n", stacked_psr);
    
    while (1);
}
