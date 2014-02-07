/*  $Date: 2008/10/07 18:33:57 $
 *  $Revision: 1.21 $
 */

/* Copyright (C) 2007 Bosch Sensortec GmbH
 *
 * Author:
 *
 * Disclaimer
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
 * (hereinafter called "Information") is provided free of charge for the sole purpose to support your 
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

/*! \file define.h 
    \brief Header file for all define, constants and function prototypes
*/ 
#ifndef __DEFINE_HEADER
#define __DEFINE_HEADER

/*-----------------------------------------------------------------------------------------------*/
/* Includes*/
																																																																																									/*-----------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------*/
/* Defines*/
/*-----------------------------------------------------------------------------------------------*/
#define _KEIL4_

#define INCLUDE_BMA250API
#define INCLUDE_BMP180API
#define INCLUDE_BMC050API
#define INCLUDE_BMG160API
#define INCLUDE_ECOMPASSALGO
#define INCLUDE_ALLINONEAPI
#define INCLUDE_GYROALGO

#define BMA150_CHIPID			0x02
#define U7155_CHIPID			0x03
#define U7155_BMA222			0x04
#define U7155_BMA250			0x05
#define BMA255_CHIPID			0x22
#define BMA220_CHIPID			0xDD
#define U7155_BMC022            0x0B
#define U7155_BMC050            0x0C
#define U7155_BMC055            0x0D

#ifndef NULL
 #ifdef __cplusplus              // EC++
   #define NULL   0
 #else
   #define NULL   ((void *) 0)
 #endif
#endif

typedef char					S8;
typedef unsigned char			U8;
typedef short					S16;
typedef unsigned short			U16;
typedef int						S32;
typedef unsigned int			U32;
typedef long long				S64;
typedef unsigned long long		U64;
typedef unsigned char			BIT;
typedef unsigned int			BOOL;
typedef float					F32;
typedef double					F64;


/**
 *\defgroup BOARD_DEFINES General Board Defines
 */
/*@{*/
#define CCLK		60000000		/**< CPU-Clock */
#define PCLK		60000000		/**< Peripheral Clock */
#define RINGBUFFERSIZE	256
/*@}*/

/**
 *\defgroup GENERAL_DEFINES	General Program Defines
 */
/*@{*/
//#define NULL		((void *)0)	/**< NULL Pointer */
#define ON			1						/**< Define for "ON" */
#define OFF			0						/**< Define for "OFF" */
#define TRUE		1						/**< Define for "TRUE" */
#define FALSE		0						/**< Define for "FALSE" */
#define ENABLE	    1						/**< Define for "ENABLE" */
#define DISABLE	    0						/**< Define for "DISABLE" */
#define LOW			0						/**< Define for "Low" */
#define HIGH		1						/**< Define for "High" */
#define INPUT		0						/**< Define for "Input" */
#define OUTPUT	    1						/**< Define for "Output" */

//#define UART0		0						/**< Define for "UART0" */
//#define UART1		1					  	/**< Define for "UART1" */
#define USB			2						/**< Define for "USB" */
#define SPI0		3						/**< Define for "SPI0" */
#define SPI1		4						/**< Define for "SPI1" */
#define I2C0		5						/**< Define for "I2C0" */
#define I2C1		6						/**< Define for "I2C1" */
#define FUSION		3						/**< Define for "FUSION" */
/*@}*/


#define 		C_Null_U8X								(U8)0
#define			C_Zero_U8X								(U8)0
#define 		C_One_U8X								(U8)1
#define			C_Two_U8X								(U8)2
#define         C_Three_U8X                             (U8)3
#define         C_Four_U8X                              (U8)4
#define         C_Five_U8X                              (U8)5
#define         C_Six_U8X                               (U8)6
#define			C_Seven_U8X								(U8)7
#define         C_Eight_U8X                             (U8)8
#define         C_Nine_U8X               				(U8)9
#define         C_Ten_U8X 			                 	(U8)10
#define     	C_Eleven_U8X                           	(U8)11
#define         C_Twelve_U8X                            (U8)12
#define		    C_Sixteen_U8X                			(U8)16
#define         C_TwentyFour_U8X 	                 	(U8)24
#define         C_ThirtyTwo_U8X                    		(U8)32
#define		    C_Hundred_U8X		                 	(U8)100
#define   		C_OneTwentySeven_U8X	                (U8)127
#define  		C_TwoFiftyFive_U8X	                 	(U8)255
#define		    C_TwoFiftySix_U16X              		(U16)256
/* Return type is True */
#define C_Successful_S8X			(S8)0
/* return type is False */
#define C_Unsuccessful_S8X			(S8)-1

/*-----------------------------------------------------------------------------------------------*/
/* Type definitions*/
/*-----------------------------------------------------------------------------------------------*/
/** Enumeration for function return values */
enum FUNCTION_RETURN_VALUES
{
	OK = 0,											/**< no Error occured */
    ERROR=-1,										/**< general error occured */
	PARAMETER_OUT_OF_RANGE=-2,	/**< one or more parameter out of range */
	MISSING_PARAMETER=-3,				/**< one or more parameter is missing */
	NO_DATA_AVAILABLE=-4,				/**< no data available */
	UNKNOWN_INSTRUCTION=-5,			/**< unknown instruction */
	UNKNOWN_SENSOR=-6,					/**< unknown sensor */
	WRONG_SENSOR=-7							/**< wrong sensor */
};

typedef enum
{
	E_False,
	E_True
} te_Boolean;


/** ringbuffer Struct 
	\brief Structure containing all ringbuffer datas
*/
typedef struct ringbufferStruct
{
	U16 array[RINGBUFFERSIZE];	/**< array to store the values */
	volatile S16 read;					/**< current read position */
	volatile S16 write;					/**< current write position */
	volatile S16 size;					/**< size of ringbuffer array */
	volatile S16 length;				/**< currently used memory places*/
} ringbuffer;

/** DAQ Struct 
	\brief Structure for Data Aquisition
*/
struct DAQSTRUCT 
{
	S32 Port:2;									/**< which port has received the DAQ command \see GENERAL_DEFINES */
	S32 BMA250running:1;			    /**< flag for DAQ of BMA250 */
	S32 BMA250selection:4;			/**< axis selection for BMA250 */
	S32 BMP180running:1;			    /**< flag for DAQ of BMP180 */
	S32 BMP180selection:4;			/**< axis selection for BMP180 */
	S32 BMC050running:1;			    /**< flag for DAQ of BMC050 */
	S32 BMC050selection:4;			/**< axis selection for BMC050 */
	S32 BMG160running:1;			    /**< flag for DAQ of BMG160 */
	S32 BMG160FIFOrunning:1;       	/**<Flag for DAQ of BMG160 FIFO */
	S32 BMG160selection:4;			/**< axis selection for BMG160 */
	S32 ECOMPASSrunning:1;			    /**< flag for DAQ of ECOMPASS */
	S32 ECOMPASSselection:4;			/**< axis selection for ECOMPASS */
	S32 ALLINONErunning:1;			    /**< flag for DAQ of ECOMPASS */
	S32 ALLINONEselection:4;			/**< axis selection for ECOMPASS */
};


/*-----------------------------------------------------------------------------------------------*/
/* Function Prototype Declaration*/
/*-----------------------------------------------------------------------------------------------*/
//S32 ringbuffer_init(ringbuffer *buffer);
//S32 ringbuffer_write(ringbuffer *buffer, U16 data);
//S32 ringbuffer_read(ringbuffer *buffer, U16 *data);
#define BUFFER_LEN		32
#define I2C_BUFFER_LEN	32	/**< I2C Buffer Length */



struct INTERFACESTRUCT
{
	U8 port;								/**< which port has received the command \see GENERAL_DEFINES */
	S8 string[BUFFER_LEN];	/**< char string containing ASCII Values */
};

//_declare_box(mpool_instruction, sizeof(struct COMMANDSTRUCT), 10); //MemoryPool-Declaration



typedef struct
{			
	U8 address;								/**< slave adress */
	U8 rw;											/**< type of transfer (write,read or readonly) \see I2C_TRANSFER_TYPE */
	U8 buffer[I2C_BUFFER_LEN];	/**< buffer for data transfer */
	U8 numberBytestoWrite;			/**< number of bytes to write Range 1..16*/
	U8 numberBytestoRead;			/**< number of bytes to read Range 1..16*/
	U8 busy;										/**< status of I2C-Interface (busy/free) */
} T_STI2C;

#endif /*  __DEFINE_HEADER */
