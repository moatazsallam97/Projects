/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SW.c
 *        \brief  Switch Controller Driver
 *
 *      \details  The Driver Controls the Switch.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "SW.h"


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
* \Syntax          : void SW_Init(ConfigType* Config);                                      
* \Description     : initialize SW pins.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigType* Config                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SW_Init(ConfigType* Config, uint8 CONFIG_NUM){
    Port_Init(Config,CONFIG_NUM);
}


/**********************************************************************************************************************
 *  END OF FILE: SW.c
 *********************************************************************************************************************/