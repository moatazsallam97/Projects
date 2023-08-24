/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define InterruptSetMode_Enable  1
#define InterruptSetMode_Disable 0

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Interrupt_SetMode;
typedef uint8 Interrupt_Priority;

typedef enum{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM_FAULT,
    PWM0_GENERATOR0,
    PWM0_GENERATOR1,
    PWM0_GENERATOR2,
    QEI0,
    ADC0_Sequence_0,
    ADC0_Sequence_1,
    ADC0_Sequence_2,
    ADC0_Sequence_3,
    WATCHDOG_TIMER,
    TIMER_0A,
    TIMER_0B,
    TIMER_1A,
    TIMER_1B,
    TIMER_2A,
    TIMER_2B,
    ANALOG_COMPARATOR0,
    ANALOG_COMPARATOR1,
    REVERSED_1,
    SYSTEM_CONTROL,
    EEPROM_CONTROL,
    GPIO_PORT_F,
    REVERSED_2,
    REVERSED_3,
    UART2,
    SSI1,
    TIMER_3A,
    TIMER_3B,
    I2C1,
    QEI1,
    CAN0,
    CAN1,
    REVERSED_4,
    REVERSED_5,
    HIBERNATION_MODULE,
    USB,
    PWN_GENERATOR3,
    DMA_SOFTWARE,
    DMA_ERROR,
    ADC1_Sequence_0,
    ADC1_Sequence_1,
    ADC1_Sequence_2,
    ADC1_Sequence_3,
    REVERSED_6,
    REVERSED_7,
    REVERSED_8,
    REVERSED_9,
    REVERSED_10,
    SSI2,
    SSI3,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,
    REVERSED_11,
    REVERSED_12,
    REVERSED_13,
    REVERSED_14,
    I2C2,
    I2C3,
    TIMER_4A,
    TIMER_4B,
    REVERSED_15,
    REVERSED_16,
    REVERSED_17,
    REVERSED_18,
    REVERSED_19,
    REVERSED_20,
    REVERSED_21,
    REVERSED_22,
    REVERSED_23,
    REVERSED_24,
    REVERSED_25,
    REVERSED_26,
    REVERSED_27,
    REVERSED_28,
    REVERSED_29,
    REVERSED_30,
    REVERSED_31,
    REVERSED_32,
    REVERSED_33,
    REVERSED_34,
    TIMER_5A,
    TIMER_5B,
    WIDE_TIMER_0A,
    WIDE_TIMER_0B,
    WIDE_TIMER_1A,
    WIDE_TIMER_1B,
    WIDE_TIMER_2A,
    WIDE_TIMER_2B,
    WIDE_TIMER_3A,
    WIDE_TIMER_3B,
    WIDE_TIMER_4A,
    WIDE_TIMER_4B,
    WIDE_TIMER_5A,
    WIDE_TIMER_5B,
    SYSTEM_EXCEPTION,
    REVERSED_35,
    REVERSED_36,
    REVERSED_37,
    REVERSED_38,
    REVERSED_39,
    REVERSED_40,
    REVERSED_41,
    REVERSED_42,
    REVERSED_43,
    REVERSED_44,
    REVERSED_45,
    REVERSED_46,
    REVERSED_47,
    REVERSED_48,
    REVERSED_49,
    REVERSED_50,
    REVERSED_51,
    REVERSED_52,
    REVERSED_53,
    REVERSED_54,
    REVERSED_55,
    REVERSED_56,
    REVERSED_57,
    REVERSED_58,
    REVERSED_59,
    REVERSED_60,
    REVERSED_61,
    PWM1_GENERATOR0,
    PWM1_GENERATOR1,
    PWM1_GENERATOR2,
    PWM1_GENERATOR3,
    PWM1_FAULT
}Interrupt_Type;

typedef struct{
    Interrupt_Type InterruptType;
    Interrupt_Priority InterruptPriority;
    Interrupt_SetMode InterruptSetMode;
}User_Data_Type;
 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
