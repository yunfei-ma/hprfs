#include "board_boschbsx.h"
#include "ioport.h"

void board_init(void)
{
	ioport_init();

	/* Configure UART pins */
	pio_configure_pin_group(PINS_UART0_PIO, PINS_UART0, PINS_UART0_FLAGS);

}

