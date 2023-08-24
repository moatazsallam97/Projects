/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  _Gpio.c
 *        \brief  GPIO Driver
 *
 *      \details  The Driver Configure All GPIO Features.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "_Gpio.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

GPIO_CB_Type PortF_CbPtr;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/*void DataReg(Dio_ChannelLevel ChannelLevel, uint8 BIT, Dio_PortType PortType){
	
	uint8 LOC;
	if 		(BIT == 0) LOC = 0b00000001;
	else if (BIT == 1) LOC = 0b00000010;
	else if (BIT == 2) LOC = 0b00000100;
	else if (BIT == 3) LOC = 0b00001000;
	else if (BIT == 4) LOC = 0b00010000;
	else if (BIT == 5) LOC = 0b00100000;
	else if (BIT == 6) LOC = 0b01000000;
	else if (BIT == 7) LOC = 0b10000000;
	if (ChannelLevel == STD_HIGH){
		GPIODATAW(PortType, LOC) = (1 << BIT);
	}
	else if(ChannelLevel == STD_LOW){
		GPIODATAW(PortType, LOC) = ~(1 << BIT);
	}
	
}*/
	
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Register_GPIO_Port_F(Callback_Type GPIO_Cb);
* \Description     : Register a function to the GPIO Port F ISR                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Callback_Type GPIO_Cb                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Register_GPIO_Port_F(GPIO_CB_Type Ptr){
	if (Ptr != NULL_PTR){
		PortF_CbPtr = Ptr;
	}
}

/******************************************************************************
* \Syntax          : void GPIOF_Handler(void)
* \Description     : GPIO Port F ISR                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPIOF_Handler(void){
	if (PortF_CbPtr != NULL_PTR){
		PortF_CbPtr();
	}
}

/******************************************************************************
* \Syntax          : void Gpio_Init(void)
* \Description     : Initalize GPIO.                                                                                                                
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpio_Init(void){
	/**************** Enabling PORTA Clock *****************/
	#if PORT_A == STD_ON  						
		SETBIT(RCGCGPIO,PORTA);												// Enabling Clock or Disabling Depending on The Config.
		GPIODIR(_A) = 0x00;													// Input bits as a default value.
		GPIODEN(_A) = 0xFF;													// All pins have the Digital Enabled.	       
	#else
		CLRBIT(RCGCGPIO,PORTA);
	#endif
	/**************** Enabling PORTB Clock *****************/
	#if PORT_B == STD_ON
		SETBIT(RCGCGPIO,PORTB);												// Enabling Clock or Disabling Depending on The Config.
		GPIODIR(_B) = 0x00;													// Input bits as a default value.
		GPIODEN(_B) = 0xFF;													// All pins have the Digital Enabled. 
	#else 
		CLRBIT(RCGCGPIO,PORTB);
	#endif
	/**************** Enabling PORTC Clock *****************/
	#if PORT_C == STD_ON 						
		SETBIT(RCGCGPIO,PORTC);												// Enabling Clock or Disabling Depending on The Config.
		GPIODIR(_C) = 0x00;													// Input bits as a default value.
		GPIODEN(_C) = 0xFF;													// All pins have the Digital Enabled. 
	#else
		 CLRBIT(RCGCGPIO,PORTC);
	#endif
	/**************** Enabling PORTD Clock *****************/
	#if PORT_D == STD_ON 						
		SETBIT(RCGCGPIO,PORTD);												// Enabling Clock or Disabling Depending on The Config.
		GPIODIR(_D) = 0x00;													// Input bits as a default value.
		GPIODEN(_D) = 0xFF;													// All pins have the Digital Enabled. 
	#else
		 CLRBIT(RCGCGPIO,PORTD);
	#endif
	/**************** Enabling PORTE Clock *****************/
	#if PORT_E == STD_ON 						
		SETBIT(RCGCGPIO,PORTE);												// Enabling Clock or Disabling Depending on The Config.
		GPIODIR(_E) = 0x00;													// Input bits as a default value.
		GPIODEN(_E) = 0xFF;													// All pins have the Digital Enabled. 
	#else
		 CLRBIT(RCGCGPIO,PORTD);
	#endif
	/**************** Enabling PORTF Clock *****************/
	#if PORT_F == STD_ON 						
		SETBIT(RCGCGPIO,PORTF);												// Enabling Clock or Disabling Depending on The Config.
		GPIODIR(_F) = 0x00;													// Input bits as a default value.
		GPIODEN(_F) = 0xFF;													// All pins have the Digital Enabled. 
	#else
		 CLRBIT(RCGCGPIO,PORTD);
	#endif
}

/******************************************************************************
* \Syntax          : Dio_ChannelLevel Dio_ReadChannel(Dio_ChannelType ChannelType);                                      
* \Description     : Reads a certain bit level (high or low).                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                        
* \Return value:   : None
*******************************************************************************/
Dio_ChannelLevel Dio_ReadChannel(Dio_ChannelType ChannelType){
	if (ChannelType <= PA7){											// Determining the port
		if (READBIT(GPIODIR(_A), ChannelType) == STD_LOW){				// Output checking
			if(READBIT(GPIODEN(_A), ChannelType) == STD_HIGH){			// Digital Enabling checking
				return READBIT(GPIODATA(_A),ChannelType);				// Reading the bit
			}
		}
	}

	else if((ChannelType > PA7)  && (ChannelType <= PB7)){				// Determining the port
		if (READBIT(GPIODIR(_B), (ChannelType - 8)) == STD_LOW){		// Output checking
			if(READBIT(GPIODEN(_B), (ChannelType - 8)) == STD_HIGH){	// Digital Enabling checking	
				return READBIT(GPIODATA(_B),(ChannelType - 8));			// Reading the bit
			}
		}
	}

	else if((ChannelType > PB7) && (ChannelType <= PC7)){				// Determining the port
		if (READBIT(GPIODIR(_C), (ChannelType - 16)) == STD_LOW){		// Output checking
			if(READBIT(GPIODEN(_C), (ChannelType - 16)) == STD_HIGH){	// Digital Enabling checking		
				return READBIT(GPIODATA(_C),(ChannelType - 16));		// Reading the bit
			}
		}
	}	

	else if((ChannelType > PC7) && (ChannelType <= PD7)){				// Determining the port
		if (READBIT(GPIODIR(_D), (ChannelType - 24)) == STD_LOW){		// Output checking
			if(READBIT(GPIODEN(_D), (ChannelType - 24)) == STD_HIGH){	// Digital Enabling checking	
				return READBIT(GPIODATA(_D),(ChannelType - 24));		// Reading the bit
			}
		}	
	}

	else if((ChannelType > PD7) && (ChannelType <= PE7)){				// Determining the port
		if (READBIT(GPIODIR(_E), (ChannelType - 32)) == STD_LOW){		// Output checking
			if(READBIT(GPIODEN(_E), (ChannelType - 32)) == STD_HIGH){	// Digital Enabling checking	
				return READBIT(GPIODATA(_E),(ChannelType - 32));		// Reading the bit
			}
		}	
	}

	else if((ChannelType > PE7) && (ChannelType <= PF7)){				// Determining the port
		if (READBIT(GPIODIR(_F), (ChannelType - 40)) == STD_LOW){		// Output checking
			if(READBIT(GPIODEN(_F), (ChannelType - 40)) == STD_HIGH){	// Digital Enabling checking	
				return READBIT(GPIODATA(_F),(ChannelType - 40));		// Reading the bit
			}
		}	
	}
	else return 4;
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelType, Dio_ChannelLevel ChannelLevel);                                      
* \Description     : writes on a certain bit.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Dio_ChannelType                     
* \Parameters (out): Dio_ChannelLevel                                                      
* \Return value:   : Dio_ChannelLevel
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelType, Dio_ChannelLevel ChannelLevel){
	if(ChannelType <= PA7){																// Determining the Port.
		if(READBIT(GPIODEN(_A), ChannelType) == STD_HIGH){								// Digital Enabling Check
			GPIODIR(_A) |= (1 << ChannelType);											// Makes the bit output
			if (ChannelLevel == STD_HIGH) GPIODATA(_A) |= (1 << ChannelType);	    	// Turns it high or low Depending on given data.
			else GPIODATA(_A) &= ~(1 << ChannelType);
		}
	}

	else if((ChannelType > PA7)  && (ChannelType <= PB7)){								// Determining the Port.
		if(READBIT(GPIODEN(_B), ChannelType - 8) == STD_HIGH){							// Digital Enabling Check
			GPIODIR(_B) |= (1 << (ChannelType - 8));									// Makes the bit output
			if (ChannelLevel == STD_HIGH) GPIODATA(_B) |= (1 << (ChannelType - 8));		// Turns it high or low Depending on given data.
			else GPIODATA(_B) &= ~(1 << (ChannelType - 8));								
		}
	}

	else if((ChannelType > PB7) && (ChannelType <= PC7)){								// Determining the Port.
		if(READBIT(GPIODEN(_C), ChannelType - 16) == STD_HIGH){							// Digital Enabling Check
			GPIODIR(_C) |= (1 << (ChannelType - 16));									// Makes the bit output	
			if (ChannelLevel == STD_HIGH) GPIODATA(_C) |= (1 << (ChannelType - 16));	// Turns it high or low Depending on given data.		
			else GPIODATA(_C) &= ~(1 << (ChannelType - 16));									
		}		
	}

	else if((ChannelType > PC7) && (ChannelType <= PD7)){								// Determining the Port.										
		if(READBIT(GPIODEN(_D), ChannelType - 24) == STD_HIGH){							// Digital Enabling Check								
			GPIODIR(_D) |= (1 << (ChannelType - 24));									// Makes the bit output												
			if (ChannelLevel == STD_HIGH) GPIODATA(_D) |= (1 << (ChannelType - 24));	// Turns it high or low Depending on given data.																
			else GPIODATA(_D) &= ~(1 << (ChannelType - 24));																	
		}
	}
	
	else if((ChannelType > PD7) && (ChannelType <= PE7)){								// Determining the Port.										
		if(READBIT(GPIODEN(_E), ChannelType - 32) == STD_HIGH){							// Digital Enabling Check								
			GPIODIR(_E) |= (1 << (ChannelType - 32));									// Makes the bit output												
			if (ChannelLevel == STD_HIGH) GPIODATA(_E) |= (1 << (ChannelType - 32));	// Turns it high or low Depending on given data.																
			else GPIODATA(_E) &= ~(1 << (ChannelType - 32));																	
		}
	}
	
	else if((ChannelType > PE7) && (ChannelType <= PF7)){								// Determining the Port.										
		if(READBIT(GPIODEN(_F), ChannelType - 40) == STD_HIGH){							// Digital Enabling Check								
			GPIODIR(_F) |= (1 << (ChannelType - 40));									// Makes the bit output												
			if (ChannelLevel == STD_HIGH) GPIODATA(_F) |= (1 << (ChannelType - 40));	// Turns it high or low Depending on given data.																
			else GPIODATA(_F) &= ~(1 << (ChannelType - 40));																	
		}
	}

}

/******************************************************************************
* \Syntax          : Dio_PortLevel Dio_ReadPort(Dio_PortLevel PortLevel);                                       
* \Description     : Read the whole port as a uint8                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Dio_ChannelLevel, Dio_ChannelType                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Dio_PortLevel Dio_ReadPort(Dio_PortType PortType){
	if (PortType == _A){
		if((GPIODEN(_A) == 0xFF) && (GPIODIR(_A) == 0xFF)) return GPIODATA(_A);
	}
	else if (PortType == _B){
		if((GPIODEN(_B) == 0xFF) && (GPIODIR(_B) == 0xFF)) return GPIODATA(_B);
	}
	else if (PortType == _C){
		if((GPIODEN(_C) == 0xFF) && (GPIODIR(_C) == 0xFF)) return GPIODATA(_C);
	}
	else if (PortType == _D){
		if((GPIODEN(_D) == 0xFF) && (GPIODIR(_D) == 0xFF)) return GPIODATA(_D);
	}
	else if (PortType == _E){
		if((GPIODEN(_E) == 0xFF) && (GPIODIR(_E) == 0xFF)) return GPIODATA(_E);
	}
	else if (PortType == _F){
		if((GPIODEN(_F) == 0xFF) && (GPIODIR(_F) == 0xFF)) return GPIODATA(_F);
	}
	else return 3;
}

/******************************************************************************
* \Syntax          : Dio_PortLevel Dio_ReadPort(Dio_PortLevel PortLevel);                                      
* \Description     :                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Dio_PortType                     
* \Parameters (out): Dio_PortLevel                                                      
* \Return value:   : Dio_PortLevel
*******************************************************************************/
void Dio_WritePort(Dio_PortLevel PortLevel, Dio_PortType PortType){
	if (PortType == _A){
		if (GPIODEN(_A) == 0xFF){
			GPIODIR(_A) = 0xFF;
		    GPIODATA(_A) = PortLevel;
		}
	}
	else if (PortType == _B){
		if (GPIODEN(_B) == 0xFF){
			GPIODIR(_B) = 0xFF;
		    GPIODATA(_B) = PortLevel;
		}
	}
	else if (PortType == _C){
		if (GPIODEN(_C) == 0xFF){
			GPIODIR(_C) = 0xFF;
		    GPIODATA(_C) = PortLevel;
		}
	}
	else if (PortType == _D){
		if (GPIODEN(_D) == 0xFF){
			GPIODIR(_D) = 0xFF;
		    GPIODATA(_D) = PortLevel;
		}
	}
	else if (PortType == _E){
		if (GPIODEN(_E) == 0xFF){
			GPIODIR(_E) = 0xFF;
		    GPIODATA(_E) = PortLevel;
		}
	}
	else if (PortType == _F){
		if (GPIODEN(_F) == 0xFF){
			GPIODIR(_F) = 0xFF;
		    GPIODATA(_F) = PortLevel;
		}
	}
}

/******************************************************************************
* \Syntax          : void Port_Init(const ConfigType* Config);                                      
* \Description     : Initialize the port.                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : *ConfigType                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(const ConfigType* Config, uint8 CONFIG_NUMS){
	for (uint8 i = 0; i < CONFIG_NUMS; i++){
		switch (Config[i].PinMode){
			case PinMode_Dio:																			// In case of Pin mode is DIO.
				GPIODEN(Config[i].PinType) |= (1 << Config[i].PinNum);									// Digital Enabling.
				break;
			case PinMode_Analog:																		// In case of Pin mode is ANALOG.
				GPIODEN(Config[i].PinType) &= (1 << Config[i].PinNum);									// Digital Disabling.
				GPIOAMSEL(Config[i].PinType) |= (1 << Config[i].PinNum);								// Analog Enabling.
				break;
			default:																					// In case of Pin Mode is Alternative Function.
				GPIODEN(Config[i].PinType) |= (1 << Config[i].PinNum);									// Digital Disabling.
				GPIOAFSEL(Config[i].PinType) |= (1 << Config[i].PinNum);								// Enabling Alternative Function
				switch (Config[i].PinNum){																// Choosing the Alternative Function.
					case PinNum_0:
						GPIOPCTL(Config[i].PinType) |= (Config[i].PinMode << AF_BitFiled0);
						break;
					case PinNum_1:
						GPIOPCTL(Config[i].PinType) |= (Config[i].PinMode << AF_BitFiled1);
						break;
					case PinNum_2:
						GPIOPCTL(Config[i].PinType) |= (Config[i].PinMode << AF_BitFiled2);
						break;
					case PinNum_3:
						GPIOPCTL(Config[i].PinType) |= (Config[i].PinMode << AF_BitFiled3);
						break;
					case PinNum_4:
						GPIOPCTL(Config[i].PinType) |= (Config[i].PinMode << AF_BitFiled4);
						break;
					case PinNum_5:
						GPIOPCTL(Config[i].PinType) |= (Config[i].PinMode << AF_BitFiled5);
						break;
					case PinNum_6:
						GPIOPCTL(Config[i].PinType) |= (Config[i].PinMode << AF_BitFiled6);
						break;
					case PinNum_7:
						GPIOPCTL(Config[i].PinType) |= (Config[i].PinMode << AF_BitFiled7);
						break;
					default:
						break;
				}
				break;
		}


		switch (Config[i].DirectionType){																// Applying Configured Direction Type
			case DirectionType_Output:
				GPIODIR(Config[i].PinType) |= (Config[i].DirectionType << Config[i].PinNum);
				break;
			case DirectionType_Input:
				GPIODIR(Config[i].PinType) &= ~(Config[i].DirectionType << Config[i].PinNum);
				break;
			default:
				break;
		}

		switch (Config[i].InternalAttach){																// Applying Configured Internal Attach
			case InternalAttach_Pullup:
				GPIOPUR(Config[i].PinType) |= (1 << Config[i].PinNum);									// GPIO PULL UP SELECT.		
				GPIOODR(Config[i].PinType) &= ~(1 << Config[i].PinNum);									// Disabling Open Drain.
				GPIOPDR(Config[i].PinType) &= ~(1 << Config[i].PinNum);									// Disabling PULL DOWN SELECT.
				break;
			case InternalAttach_PullDown:
				GPIOPUR(Config[i].PinType) &= ~(1 << Config[i].PinNum);									// Disabling PULL UP SELECT.		
				GPIOODR(Config[i].PinType) &= ~(1 << Config[i].PinNum);									// Disabling Open Drain.
				GPIOPDR(Config[i].PinType) |= (1 << Config[i].PinNum);									// GPIO PULL DOWN SELECT.
				break;
			case InternalAttach_OpenDrain:
				GPIOPUR(Config[i].PinType) &= ~(1 << Config[i].PinNum);									// Disabling PULL UP SELECT.		
				GPIOODR(Config[i].PinType) |= (1 << Config[i].PinNum);									// Open Drain SELECT.
				GPIOPDR(Config[i].PinType) &= ~(1 << Config[i].PinNum);									// Disabling PULL DOWN SELECT
				break;
			default:
				break;
		}

		switch (Config[i].OutputCurrentType){															// Setting the OutputCurrent.
			case OutputCurrentType_8:
				GPIODR8R(Config[i].PinType) |= (1 << Config[i].PinNum);									// Setting 8 mA
				break;
			case OutputCurrentType_4:
				GPIODR4R(Config[i].PinType) |= (1 << Config[i].PinNum);									// Setting 4 mA
				break;
			case OutputCurrentType_2:
				GPIODR2R(Config[i].PinType) |= (1 << Config[i].PinNum);									// Setting 2 mA
				break;
			default:
				break;	
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: _Gpio.c
 *********************************************************************************************************************/
