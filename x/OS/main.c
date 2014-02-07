#include <stdint.h>
#include "system_sam3s.h"
#include "sam3s.h"
#include "board_boschbsx.h"
#include "status_codes.h"
//#include "uart_serial.h"
#include "stdio_serial.h"


//! Pointer to the base of the USART module instance to use for stdio.
extern volatile void *volatile stdio_base;
//! Pointer to the external low level write function.
extern int (*ptr_put)(void volatile*, char);

//! Pointer to the external low level read function.
extern void (*ptr_get)(void volatile*, char*);

/**
 * \brief Sends a character with the USART.
 *
 * \param p_usart   Base address of the USART instance.
 * \param c       Character to write.
 *
 * \return Status.
 *   \retval 1  The character was written.
 *   \retval 0  The function timed out before the USART transmitter became
 * ready to send.
 */
int usart_serial_putchar(usart_if p_usart, const uint8_t c)
{
	while (uart_write((Uart*)p_usart, c)!=0);
	return 1;
}

/*! \brief Initializes the stdio in Serial Mode.
 *
 * \param usart       Base address of the USART instance.
 * \param opt         Options needed to set up RS232 communication (see \ref usart_options_t).
 *
 */
static inline void stdio_serial_init(volatile void *usart,
	const usart_serial_options_t *opt)
{
	stdio_base = (void *)usart;
	ptr_put = (int (*)(void volatile*,char))&uart_write;
	ptr_get = (void (*)(void volatile*,char*))&usart_serial_getchar;

	usart_serial_init((Usart *)usart,(usart_serial_options_t *)opt);

	// For AVR32 and SAM GCC
	// Specify that stdout and stdin should not be buffered.
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
}

static status_code_t usart_serial_write_packet(usart_if usart,
	const uint8_t *data, size_t len)
{
	size_t i = 0;

	for (i = 0; i < len; i++) {
		usart_serial_putchar(usart, data[i]);
	}
	return i;
}

static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONSOLE_UART_BAUDRATE,
		.paritytype = CONSOLE_UART_PARITY
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONSOLE_UART, &uart_serial_options);
}

static const uint8_t welcome_str[] = "->";
int main(void)
{
	usart_serial_putchar((usart_if)CONSOLE_UART, '-');
	usart_serial_putchar((usart_if)CONSOLE_UART, '.');
	usart_serial_putchar((usart_if)CONSOLE_UART, '-');
	usart_serial_write_packet((usart_if)CONSOLE_UART, welcome_str, 2);
	usart_serial_putchar((usart_if)CONSOLE_UART, '-');
//	SystemInit();
	usart_serial_putchar((usart_if)CONSOLE_UART, 'O');

//	WDT->WDT_MR = WDT_MR_WDDIS;

//	board_init();

	usart_serial_putchar((usart_if)CONSOLE_UART, 'K');
//	configure_console();

//	puts("I am born!\n");
	usart_serial_write_packet((usart_if)CONSOLE_UART, welcome_str,
		sizeof(welcome_str) - 1);

//	while(1)
	{
		usart_serial_putchar((usart_if)CONSOLE_UART, '.');
//		for(int i=0; i < 0x8fffff; i++);
	}

	return 0;
}
