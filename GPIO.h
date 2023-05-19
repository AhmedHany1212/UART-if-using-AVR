/*
 * GPIO.h
 *
 *  Created on: Sep 3, 2020
 *      Author: Eman
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "MicroConfiguration.h"
#include "Common_Macros.h"
#include "Std_Types.h"
#define  HIGH    1
#define  LOW    0

/******************************************* Defines for Port  **************************************/
#define  PINA    (DIO_Configure*)(0x19+IO_OFFSET)
#define  PINB   (DIO_Configure*)(0x16+IO_OFFSET)
#define  PINC    (DIO_Configure*)(0x13+IO_OFFSET)
#define  PIND   (DIO_Configure*)(0x10+IO_OFFSET)
/******************************************* User Types For AVR Input/Output MCU **************************************/
typedef enum {
InputPullup,
InputFloat,
Output,
	}Mode;
	/*********************/
	#define  PinsMAX   8
	/***************** Function drive IO ***********************/

	void DIO_Init_PORT(DIO_Configure *DIO ,Mode mode );
	void DIO_Init_PIN(DIO_Configure *DIO,uint8_t pinNum ,Mode mode);
	void	DIO_SetPortValue(DIO_Configure * DIO,uint8_t portValue);
	uint8_t	DIO_GetPortValue(DIO_Configure *DIO);//check input
	void DIO_SetPinValue(DIO_Configure *DIO,uint8_t PinNum,digitalState state );
		digitalState DIO_GetPinValue(DIO_Configure *DIO,uint8_t PinNum);




/* function Error */
void ERROR_DIO();


#endif /* GPIO_H_ */
