/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Systick.h
 *       Module:  Systick
 *
 *  Description:  header file for Systick Module    
 *  
 *********************************************************************************************************************/
#ifndef Systick_H
#define Systick_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "Std_Types.h"
#include "Systick_Cfg.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Register_SysTick(SysTick_CB_Type Ptr);
* \Description     : Register a function to the SysTick ISR                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : SysTick_CB_Type Ptr                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Register_SysTick(SysTick_CB_Type Ptr);

/******************************************************************************
* \Syntax          : void SysTick_Handler(void)
* \Description     : SysTick ISR                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Handler(void);

/******************************************************************************
* \Syntax          : void Systick_Init(Systick_ConfigType Config);                                      
* \Description     : initialize System Timer                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Systick_ConfigType Config                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Init(Systick_ConfigType Config);


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* Systick_H */

/**********************************************************************************************************************
 *  END OF FILE: Systick.h
 *********************************************************************************************************************/
