/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LED_Ctrl_Ctrl.c
 *        \brief  LED_Ctrl Controller Driver
 *
 *      \details  The Driver Control LED_Ctrl Light and Timing for on and off processes
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "LED_Ctrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

#define INIT_ON_TIME  3
#define INIT_OFF_TIME 2

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/ 

uint8 On_Load = INIT_ON_TIME - 1;
uint8 Off_Load = INIT_OFF_TIME - 1;
uint8 On_Click = 0;
uint8 Off_Click = 0;
uint8 OnLoad_St = INIT_ON_TIME - 1;
uint8 OffLoad_St = INIT_OFF_TIME - 1;
uint8 LED_Flag = STD_ON;
uint8 SysTick_Flag = STD_ON;
uint16 Time_X_mSec = 1000;

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

 /******************************************************************************
* \Syntax          : void App_SysTick_Init(Systick_ConfigType Config, uint16 TimeLd_ms);                                      
* \Description     : initialize systic configuration and enable timer to count.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Systick_ConfigType Config, uint16 TimeLd_ms    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void App_SysTick_Init(Systick_ConfigType Config, uint16 TimeLd_ms){                                   // SysTick generates an interrupt every 1 second. >> default for this application depending on MC Frequency.
    if (TimeLd_ms > (16777215000 / FREQUENCY)){
        return;
    }
    uint32 LdTime = TimeLd_ms * (FREQUENCY / 1000);
    Systick_Init(Config);
    STRELOAD = LdTime;
    STCTRL |= (1 << SYSENABLE);
}

 /******************************************************************************
* \Syntax          : void SysTickLoadTime(uint16 TimeLd_ms)                                      
* \Description     : Loads the RELOAD SysTick register with the intial value.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint16 TimeLd_ms    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTickLoadTime(uint16 TimeLd_ms){
    if (TimeLd_ms > (16777215000 / FREQUENCY)){
        return;
    }
    uint32 LdTime = TimeLd_ms * (FREQUENCY / 1000);
    STCURRENT = 0x00;
    STRELOAD = LdTime;
}

 /******************************************************************************
* \Syntax          : void Sw1_Check(void)
* \Description     : Checks the switch 1 if it's pressed to it's able to configure the time during runtime.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Sw1_Check(void){
    if(PRESS == CLICKED){                                                            // Push button clicked. 
        while(PRESS == CLICKED);
        if (LED_Flag == STD_ON){
            On_Click++;
        }
        else if (LED_Flag == STD_OFF){
            Off_Click++;
        }
    }                                                               
}

 /******************************************************************************
* \Syntax          : void SysTick_ISR(void)
* \Description     : SysTick ISR the will be excuted when SysTick ISR is generated.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_ISR(void){
    if (SysTick_Flag == STD_ON){
        if (On_Load != 0){
            On_Load--;
        }
        else if(On_Load == 0){
            On_Load = OnLoad_St;
            TOGBIT(SysTick_Flag, 0);
            LED_Off(LED_Type_Red);
        }
    }
    else if (SysTick_Flag == STD_OFF){
        if (Off_Load != 0){
            Off_Load--;
        }
        else if (Off_Load == 0){
            Off_Load = OffLoad_St;
            TOGBIT(SysTick_Flag, 0);
            LED_On(LED_Type_Red);
        }
    }
}

 /******************************************************************************
* \Syntax          : void PortF_ISR(void)
* \Description     : PortF ISR the will be excuted when the PortF ISR is generated.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void PortF_ISR(void){
    if (LED_Flag == STD_ON){
        On_Load = On_Click - 1;
        OnLoad_St = On_Click - 1;
        On_Click = 0;
        TOGBIT(LED_Flag, 0);
    }
    else if (LED_Flag == STD_OFF){
        Off_Load = Off_Click - 1;
        OffLoad_St = Off_Click - 1;
        Off_Click = 0;
        TOGBIT(LED_Flag, 0);
    }
    GPIOICR(_F) |= (1 << 4);    
}

 /******************************************************************************
* \Syntax          : void Int_Enable(User_Data_Type* Udt)
* \Description     : initalize the interrupt configurations for the app.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type* Udt    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Int_Enable(User_Data_Type* Udt){
    IntCtrl_Init(Udt);
	GPIOIM(_F) |= (1 << 4);
	GPIOIS(_F) &= ~(1 << 4);
	GPIOIEV(_F) &= ~(1 << 4);
}

/**********************************************************************************************************************
 *  END OF FILE: LED_Ctrl.c
 *********************************************************************************************************************/
