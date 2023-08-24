/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"


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
* \Syntax          : void __attribute__((interrupt)) SVC_Handler(void)                                      
* \Description     : Turn on the privileged mode.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint8                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

/*void __attribute__((interrupt)) SVC_Handler(void){
        return;
}*/

/******************************************************************************
* \Syntax          : void PrivilegeOFF(void)                                      
* \Description     : Turn off the privileged mode.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint8                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

/*void PrivilegeOFF(void){
        return;
}*/

/******************************************************************************
* \Syntax          : void IntCtrl_Init(User_Data_Type* Config)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type* Config                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCtrl_Init(User_Data_Type* Config){
    uint8 Pri;
    Pri = GROUP_SUBGROUP;
    switch(Pri) {                                                                   // Setting desired group-supgroup priority set.
        case 0:
        APINT = (0x05FA << 16) | (0x0 << 8);
        break;
        case 1:
        APINT = (0x05FA << 16) | (0x5 << 8);
        break;
        case 2:
        APINT = (0x05FA << 16) | (0x6 << 8);
        break;
        case 3:
        APINT = (0x05FA << 16) | (0x7 << 8);
        break;
        default:
        break;
    }

	for (uint8 i = 0; i < INTERRUPTS_NUM; i++){
        SET_PRI(Config[i].InterruptType, Config[i].InterruptPriority);              // Setting the desired priority for the desired interrupt type.
        switch (Config[i].InterruptSetMode){
            case InterruptSetMode_Enable:
                ENX(Config[i].InterruptType) |= (1 << Config[i].InterruptType);     // Enabling the configured interrupts.
                break;
            case InterruptSetMode_Disable:
                DISX(Config[i].InterruptType) |= (1 << Config[i].InterruptType);    // Disabling the configured interrupts.
                break;
            default:
                break;
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
