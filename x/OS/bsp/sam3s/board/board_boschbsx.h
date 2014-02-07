#ifndef BOARD_BOSCHBSX_H
#define BOARD_BOSCHBSX_H

#include "compiler.h"
#include "system_sam3s.h"
#include "exceptions.h"
#include "pio.h"


/** UART0 pins (UTXD0 and URXD0) definitions, PA9,10. */
#define PINS_UART0      (PIO_PA9A_URXD0 | PIO_PA10A_UTXD0)
#define PINS_UART0_FLAGS    (PIO_PERIPH_A | PIO_DEFAULT)

#define PINS_UART0_MASK PIO_PA9A_URXD0|PIO_PA10A_UTXD0
#define PINS_UART0_PIO PIOA
#define PINS_UART0_ID ID_PIOA
#define PINS_UART0_TYPE PIO_PERIPH_A
#define PINS_UART0_ATTR PIO_DEFAULT

#define CONSOLE_UART               UART0
#define CONSOLE_UART_ID            ID_UART0
/** Baudrate setting */
#define CONSOLE_UART_BAUDRATE      115200
/** Parity setting */
#define CONSOLE_UART_PARITY        UART_MR_PAR_NO

/** Board oscillator settings */
#define BOARD_FREQ_SLCK_XTAL        (32768U)
#define BOARD_FREQ_SLCK_BYPASS      (32768U)
#define BOARD_FREQ_MAINCK_XTAL      (12000000U)
#define BOARD_FREQ_MAINCK_BYPASS    (12000000U)

/** Master clock frequency */
#define BOARD_MCK                   CHIP_FREQ_CPU_MAX

/** board main clock xtal startup time */
#define BOARD_OSC_STARTUP_US        15625

void board_init(void);

#endif
