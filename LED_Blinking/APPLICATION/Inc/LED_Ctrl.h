/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  LED_Ctrl.h
 *       Module:  LED_Ctrl
 *
 *  Description:  header file for LED_Ctrl Module    
 *  
 *********************************************************************************************************************/
#ifndef LED_Ctrl_H
#define LED_Ctrl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "LED.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define FREQUENCY 16000000
#define PRESS     READBIT(GPIODATA(_F), PinNum_0)
#define CLICKED   0
#define N_CLICKED 1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 /******************************************************************************
* \Syntax          : void App_SysTick_Init(Systick_ConfigType Config, uint16 TimeLd_ms);                                      
* \Description     : initialize systic configuration and enable timer to count.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Systick_ConfigType Config, uint16 TimeLd_ms    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void App_SysTick_Init(Systick_ConfigType Config, uint16 TimeLd_ms);

 /******************************************************************************
* \Syntax          : void SysTickLoadTime(uint16 TimeLd_ms)                                      
* \Description     : Loads the RELOAD SysTick register with the intial value.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint16 TimeLd_ms    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTickLoadTime(uint16 TimeLd_ms);

 /******************************************************************************
* \Syntax          : void Sw1_Check(void)
* \Description     : Checks the switch 1 if it's pressed to it's able to configure the time during runtime.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Sw1_Check(void);

 /******************************************************************************
* \Syntax          : void SysTick_ISR(void)
* \Description     : SysTick ISR the will be excuted when SysTick ISR is generated.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_ISR(void);

 /******************************************************************************
* \Syntax          : void PortF_ISR(void)
* \Description     : PortF ISR the will be excuted when the PortF ISR is generated.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void PortF_ISR(void);

 /******************************************************************************
* \Syntax          : void Int_Enable(User_Data_Type* Udt)
* \Description     : initalize the interrupt configurations for the app.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type* Udt    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Int_Enable(User_Data_Type* Udt);


#endif  /* LED_Ctrl_H */

/**********************************************************************************************************************
 *  END OF FILE: LED_Ctrl.h
 *********************************************************************************************************************/
