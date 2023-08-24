#include "LED.h"
#include "_Gpio.h"
#include "Systick.h"
#include "LED_Ctrl.h"
#include "IntCtrl.h"

extern const ConfigType LEDs[LEDCONF_NUM];
extern const ConfigType SW[SWCONF_NUM];
extern const Systick_ConfigType STConfig;
extern const User_Data_Type G_User_Data[INTERRUPTS_NUM];
extern uint16 Time_X_mSec;
extern uint8 On_Click;
extern uint8 Off_Click;
extern uint8 LED_Flag;


void SysTickISR(void){
	SysTick_ISR();
}

void PortfISR(void){
	PortF_ISR();
}

int main(void){
	Gpio_Init();
	Int_Enable(G_User_Data);
	LED_Init(LEDs, LEDCONF_NUM);
	Register_SysTick(SysTickISR);
	Register_GPIO_Port_F(PortfISR);
	LED_On(LED_Type_Red);							// initial state.
	App_SysTick_Init(STConfig, Time_X_mSec);		
	while(1){
		Sw1_Check();
	}
}
