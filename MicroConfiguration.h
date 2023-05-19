/*
 * MicroConfiguration.h
 *
 * Created: 8/31/2020 2:03:20 PM
 *  Author: mahmo
 */ 


#ifndef MICROCONFIGURATION_H_
#define MICROCONFIGURATION_H_
#include "Common_Macros.h"
#include "Std_Types.h"


/******************************* CPU Related Defines *******************************************************/
/**********************************/
/******************************* CPU Internal Registers <SFRs & GPRs> **************************************/
#define IO_OFFSET  (0x20)
/*****************************/
typedef union {
	uint8_t Fullbits;
	struct {
		uint8_t b0:1;
			uint8_t b1:1;
			uint8_t b2:1;
			uint8_t b3:1;
			uint8_t b4:1;
			uint8_t b5:1;
			uint8_t b6:1;
			uint8_t b7:1;
		}Bits;
	
	
	}reg;
	
	
	typedef struct {
	
		reg PIN;
		reg DDR;
		reg port;
		}DIO_Configure;


		/*typedef enum
		{
			FALSE,
			TRUE,
		}Bool;*/

typedef enum {
	LOW=0,
	HIGH=1,
}digitalState;

/*typedef enum {
	PIN0=0,PIN1=1,PIN2=2,PIN3=3,PIN4=4,PIN5=5,PIN6=6,PIN7=7,
}pinNumber;*/
uint8_t pinNum;

#endif /* MICROCONFIGURATION_H_ */
