/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LED.c
 *        \brief  LED Controller Driver
 *
 *      \details  The Driver Control LED Light on or off or toggeling.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "LED.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void LED_Init(ConfigType* Config);                                      
* \Description     : initialize LED pins.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigType* Config                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_Init(ConfigType* Config, uint8 CONFIG_NUM){
    Port_Init(Config,CONFIG_NUM);
}

/******************************************************************************
* \Syntax          : void LED_On(LED_Type LED);                                      
* \Description     : Turns on a LED depending on the argument.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : LED_Type LED                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_On(LED_Type LED){
    switch (LED){
        case LED_Type_Red:
            GPIODATA(_F) |= (1 << LED_Type_Red);
            break;
        case LED_Type_Blue:
            GPIODATA(_F) |= (1 << LED_Type_Blue);
            break;
        case LED_Type_Green:
            GPIODATA(_F) |= (1 << LED_Type_Green);
            break;
        default:
            break;
    }   
}

/******************************************************************************
* \Syntax          : void LED_Off(LED_Type LED);                                      
* \Description     : Turns off a LED depending on the argument.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : LED_Type LED                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_Off(LED_Type LED){
    switch (LED){
        case LED_Type_Red:
            GPIODATA(_F) &= ~(1 << LED_Type_Red);
            break;
        case LED_Type_Blue:
            GPIODATA(_F) &= ~(1 << LED_Type_Blue);
            break;
        case LED_Type_Green:
            GPIODATA(_F) &= ~(1 << LED_Type_Green);
            break;
        default:
            break;
    }   
}

/******************************************************************************
* \Syntax          : void LED_Toggle(LED_Type LED);                                      
* \Description     : Toggles a LED depending on the argument.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : LED_Type LED                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_Toggle(LED_Type LED){
    switch (LED){
        case LED_Type_Red:
            GPIODATA(_F) ^= (1 << LED_Type_Red);
            break;
        case LED_Type_Blue:
            GPIODATA(_F) ^= (1 << LED_Type_Blue);
            break;
        case LED_Type_Green:
            GPIODATA(_F) ^= (1 << LED_Type_Green);
            break;
        default:
            break;
    }   
}

/**********************************************************************************************************************
 *  END OF FILE: LED.c
 *********************************************************************************************************************/
