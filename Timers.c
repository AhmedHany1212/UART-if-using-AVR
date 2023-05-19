/*
 * Timers.c
 *
 * Created: 9/2/2020 12:08:22 AM
 *  Author: mahmo
 */ 
#include "Timers.h"
/*Description: Timer/Counter Initialization
 * Input     : Timer_Configuration_S* Confg_S (Struct contain : Timer Channel, Prescaler, Timer mode , Mode as described in Struct)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*//*
extern uint8_t Timer_Init(Str_TimerConfiguration_t* Confg_S){
	if(Confg_S!=NULL)
	{
		switch(Confg_S->Timer_Channel)
		{
			case TIMER0:
							switch(Confg_S->Timer_Mode)
							{
							case timer0_Normal:
								break;
								
							case timer0_PhaseCorrect:
								break;
								
							case timer0_CTC:
							break;
							
							case timer0_FastPWM:
							break;
							
							default:
							break;	
								
							}
			
			
			
			
			
			break;
			case TIMER1:
			break;
			case TIMER2:
			break;
			default:
			/*error*/
			/*break;
			
		}
	}
	 else
	{
		/*error checking */
		
/*	}
	
}
	*/
static uint8_t Prescale_arr[3];
/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Initialization
 * Input     : Timer_Configuration_S* Confg_S (Struct contain : Timer Channel, Prescaler , Mode as described in Struct)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Init(Str_TimerConfiguration_t* Confg_S)
{
	/*Implement Your Code*/
		uint8_t Local_u8Error=ERROR_OK;
	if(Confg_S->Timer_Channel == (TIMER0 ))
	{ Prescale_arr[0]=Confg_S->Timer_Psc;
	 switch(Confg_S->Timer_Mode)
	{
	case Normal:
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM00);
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM01);
		break;
	case PWM_PhaseCorrect:
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM01);
		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM00);
		DIO_Init_PIN(PINB,3 ,Output );
		break;
	case CTC:
		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM01);
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM00);
	DIO_Init_PIN(PINB,3 ,Output );
		break;
	case FastPWM :
		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM00);
		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM01);
		DIO_Init_PIN(PINB,3 ,Output );
	break;
	}

	}
		else if(Confg_S->Timer_Channel == ( TIMER2))
	{     Prescale_arr[2]=Confg_S->Timer_Psc;
			switch(Confg_S->Timer_Mode)
	{
	case Normal:
		CLEAR_BIT(TIMER2_TCCR2,TIMER2_TCCR2_WGM20);
		CLEAR_BIT(TIMER2_TCCR2,TIMER2_TCCR2_WGM21);
		break;
	case PWM_PhaseCorrect:
		CLEAR_BIT(TIMER2_TCCR2,TIMER2_TCCR2_WGM21);
		SET_BIT(TIMER2_TCCR2,TIMER2_TCCR2_WGM20);
	DIO_Init_PIN(PINB,3 ,Output );
		break;
	case CTC:
		SET_BIT(TIMER2_TCCR2,TIMER2_TCCR2_WGM21);
		CLEAR_BIT(TIMER2_TCCR2,TIMER2_TCCR2_WGM20);
		DIO_Init_PIN(PINB,3 ,Output );
		break;
	case FastPWM :
		SET_BIT(TIMER2_TCCR2,TIMER2_TCCR2_WGM20);
		SET_BIT(TIMER2_TCCR2,TIMER2_TCCR2_WGM21);
		DIO_Init_PIN(PINB,3 ,Output );
	break;
	}

	}
		else if(Confg_S->Timer_Channel == (TIMER1 ))
		{
		Prescale_arr[1]=Confg_S->Timer_Psc;
	TIMER1_TCCR1A = 0;
	TIMER1_TCCR1B = 1;

		}


	else 

	{
		Local_u8Error=ERROR_NOK ;
	}



	return Local_u8Error;
	
}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Start
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), Tick Counting (Counts given by user)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Start(uint8_t Copy_uint8_TimerChannel,uint32_t Copy_uint32_TickCounts)
{
	/*Implement Your Code*/
		uint8_t Local_u8Error=ERROR_OK;
	if(Copy_uint8_TimerChannel == (TIMER0 ))
	{
	switch(Copy_uint32_TickCounts)
	{
	case NO_CLOCK_TIMER_0 : //0
		CLEAR_BIT(TIMER0_TCCR0,CS00);
		CLEAR_BIT(TIMER0_TCCR0,CS01);
		CLEAR_BIT(TIMER0_TCCR0,CS02);
		break;
	case F_CPU_CLOCK_TIMER_0 : //1
		SET_BIT(TIMER0_TCCR0,CS00);
		CLEAR_BIT(TIMER0_TCCR0,CS01);
		CLEAR_BIT(TIMER0_TCCR0,CS02);
		break;
	case F_CPU_CLOCK_8_TIMER_0 : //2
		CLEAR_BIT(TIMER0_TCCR0,CS00);
		SET_BIT(TIMER0_TCCR0,CS01);
		CLEAR_BIT(TIMER0_TCCR0,CS02);
		break;
	case F_CPU_CLOCK_64_TIMER_0: //3
		SET_BIT(TIMER0_TCCR0,CS00);
		SET_BIT(TIMER0_TCCR0,CS01);
		CLEAR_BIT(TIMER0_TCCR0,CS02);
		break;
	case F_CPU_CLOCK_256_TIMER_0: //4
		CLEAR_BIT(TIMER0_TCCR0,CS00);
		CLEAR_BIT(TIMER0_TCCR0,CS01);
		SET_BIT(TIMER0_TCCR0,CS02);
		break;
	case F_CPU_CLOCK_1024_TIMER_0: //5
		SET_BIT(TIMER0_TCCR0,CS00);
		CLEAR_BIT(TIMER0_TCCR0,CS01);
		SET_BIT(TIMER0_TCCR0,CS02);
		break;
	case F_EXTERNAL_CLOCK_FALLING_TIMER_0: //6
		CLEAR_BIT(TIMER0_TCCR0,CS00);
		SET_BIT(TIMER0_TCCR0,CS02);
		SET_BIT(TIMER0_TCCR0,CS01);

		break;
	case F_EXTERNAL_CLOCK_RISING_TIMER_0: //7
		SET_BIT(TIMER0_TCCR0,CS00);
		SET_BIT(TIMER0_TCCR0,CS01);
		SET_BIT(TIMER0_TCCR0,CS02);
		break;
	}

	}
	else if (Copy_uint8_TimerChannel == ( TIMER1 ))
	{
		
		switch(Copy_uint32_TickCounts)
	{
	case NO_CLOCK_TIMER_1 : //0
		CLEAR_BIT(TIMER1_TCCR1B,CS00);
		CLEAR_BIT(TIMER1_TCCR1B,CS01);
		CLEAR_BIT(TIMER1_TCCR1B,CS02);
		break;
	case F_CPU_CLOCK_TIMER_1 : //1
		SET_BIT(TIMER1_TCCR1B,CS00);
		CLEAR_BIT(TIMER1_TCCR1B,CS01);
		CLEAR_BIT(TIMER1_TCCR1B,CS02);
		break;
	case F_CPU_CLOCK_8_TIMER_1 : //2
		CLEAR_BIT(TIMER1_TCCR1B,CS00);
		SET_BIT(TIMER1_TCCR1B,CS01);
		CLEAR_BIT(TIMER1_TCCR1B,CS02);
		break;
	case F_CPU_CLOCK_64_TIMER_1: //3
		SET_BIT(TIMER1_TCCR1B,CS00);
		SET_BIT(TIMER1_TCCR1B,CS01);
		CLEAR_BIT(TIMER1_TCCR1B,CS02);
		break;
	case F_CPU_CLOCK_256_TIMER_1: //4
		CLEAR_BIT(TIMER1_TCCR1B,CS00);
		CLEAR_BIT(TIMER1_TCCR1B,CS01);
		SET_BIT(TIMER1_TCCR1B,CS02);
		break;
	case F_CPU_CLOCK_1024_TIMER_1: //5
		SET_BIT(TIMER1_TCCR1B,CS00);
		CLEAR_BIT(TIMER1_TCCR1B,CS01);
		SET_BIT(TIMER1_TCCR1B,CS02);
		break;
	case F_EXTERNAL_CLOCK_FALLING_TIMER_1: //6
		CLEAR_BIT(TIMER1_TCCR1B,CS00);
		SET_BIT(TIMER1_TCCR1B,CS02);
		SET_BIT(TIMER1_TCCR1B,CS01);

		break;
	case F_EXTERNAL_CLOCK_RISING_TIMER_1: //7
		SET_BIT(TIMER1_TCCR1B,CS00);
		SET_BIT(TIMER1_TCCR1B,CS01);
		SET_BIT(TIMER1_TCCR1B,CS02);
		break;
	}
	}

	else if (Copy_uint8_TimerChannel == ( TIMER2 ))
	{
		
		switch(Copy_uint32_TickCounts)
	{
	case NO_CLOCK_TIMER_2 : //0
		CLEAR_BIT(TIMER2_TCCR2,CS00);
		CLEAR_BIT(TIMER2_TCCR2,CS01);
		CLEAR_BIT(TIMER2_TCCR2,CS02);
		break;
	case F_CPU_CLOCK_TIMER_2 : //1
		SET_BIT(TIMER2_TCCR2,CS00);
		CLEAR_BIT(TIMER2_TCCR2,CS01);
		CLEAR_BIT(TIMER2_TCCR2,CS02);
		break;
	case F_CPU_CLOCK_8_TIMER_2 : //2
		CLEAR_BIT(TIMER2_TCCR2,CS00);
		SET_BIT(TIMER2_TCCR2,CS01);
		CLEAR_BIT(TIMER2_TCCR2,CS02);
		break;
	case F_CPU_CLOCK_64_TIMER_2: //3
		SET_BIT(TIMER2_TCCR2,CS00);
		SET_BIT(TIMER2_TCCR2,CS01);
		CLEAR_BIT(TIMER2_TCCR2,CS02);
		break;
	case F_CPU_CLOCK_256_TIMER_2: //4
		CLEAR_BIT(TIMER2_TCCR2,CS00);
		CLEAR_BIT(TIMER2_TCCR2,CS01);
		SET_BIT(TIMER2_TCCR2,CS02);
		break;
	case F_CPU_CLOCK_1024_TIMER_2: //5
		SET_BIT(TIMER2_TCCR2,CS00);
		CLEAR_BIT(TIMER2_TCCR2,CS01);
		SET_BIT(TIMER2_TCCR2,CS02);
		break;
	case F_CPU_CLOCK_32_TIMER_2: //6
		CLEAR_BIT(TIMER2_TCCR2,CS00);
		SET_BIT(TIMER2_TCCR2,CS02);
		SET_BIT(TIMER2_TCCR2,CS01);

		break;
	case F_CPU_CLOCK_128_TIMER_2: //7
		SET_BIT(TIMER2_TCCR2,CS00);
		SET_BIT(TIMER2_TCCR2,CS01);
		SET_BIT(TIMER2_TCCR2,CS02);
		break;
	}
	}	

	else 

	{
		Local_u8Error=ERROR_NOK ;
	}



	return Local_u8Error;
}
/*_______________________________________________________________________________________________________________________________*/


/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Stop
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern uint8_t Timer_Stop(uint8_t Copy_uint8_TimerChannel)
{
	/*Implement Your Code*/
	switch(Copy_uint8_TimerChannel)
	{
		case  TIMER0:
		TIMER0_TCCR0 &=CLR_PRE_SCALLER;
		break;
		case  TIMER1:
	    TIMER1_TCCR1B &=CLR_PRE_SCALLER;
		break;
		case  TIMER2:
		TIMER2_TCCR2 &=CLR_PRE_SCALLER;
		break;
		default:
		return ERROR_NOK;
	}
	return ERROR_OK;
}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer Reset
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Reset(uint8_t Copy_uint8_TimerChannel)
{
	/*Implement Your Code*/
	uint8_t Local_u8Error=ERROR_OK;

	if(Copy_uint8_TimerChannel == (TIMER0 || TIMER1 || TIMER2))
	{
		switch(Copy_uint8_TimerChannel)
		{
		case TIMER0:
			TIMER0_TCCR0 = 0x00;
			break;
		case TIMER1:
			TIMER1_TCCR1B = 0x00;
			break;
                case TIMER2:
			TIMER2_TCCR2 = 0x00;
			break;
		

		default:Local_u8Error=ERROR_NOK ;


		}
	}
	else
	{
		Local_u8Error=ERROR_NOK ;
	}



	return Local_u8Error;

}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Get Timer Tick Time value to use it by user
 * Input     : Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), *Timer_Time (Pointer to return Value)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Get_TickTime(uint8_t Copy_uint8_TimerChannel, uint32_t *Copy_uint8Ptr_TimerTickTime)
{
	/*Implement Your Code*/
	switch(Copy_uint8_TimerChannel)
		{
			case  TIMER0:
				*Copy_uint8Ptr_TimerTickTime=CPU_FREQ/Prescale_arr[0];
			break;
			case  TIMER1:
				*Copy_uint8Ptr_TimerTickTime=CPU_FREQ/Prescale_arr[1];
			break;
			case  TIMER2:
				*Copy_uint8Ptr_TimerTickTime=CPU_FREQ/Prescale_arr[2];
			break;
			default:
			return ERROR_NOK;
		}
		return ERROR_OK;
	}

/*_______________________________________________________________________________________________________________________________*/

void TIMER_voidWrite(uint8_t Copy_u8Int_DATA){
	TIMER0_TCNT0=Copy_u8Int_DATA;
}
void TIMER0_void_COMM(void){
	CLEAR_BIT(TIMER0_TCCR0,COM00);
	SET_BIT(TIMER0_TCCR0,COM01);
	}







void TIMER0_void_OCR0(uint8_t Copy_u8Int_d){

	TIMER0_OCR0=Copy_u8Int_d;
}





