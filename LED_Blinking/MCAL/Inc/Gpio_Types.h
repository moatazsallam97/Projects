/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define PinType_A 0u
#define PinType_B 1u
#define PinType_C 2u
#define PinType_D 3u
#define PinType_E 4u
#define PinType_F 5u

#define PinNum_0 0u
#define PinNum_1 1u
#define PinNum_2 2u
#define PinNum_3 3u
#define PinNum_4 4u
#define PinNum_5 5u
#define PinNum_6 6u
#define PinNum_7 7u

#define DirectionType_Output 1u 
#define DirectionType_Input  0u


#define PinMode_Dio     0u
#define PinMode_Analog  15u

/*************************** PORT A ************************/
                                                    
/* Port A Pin 0 */
#define PinMode_PA0_U0Rx        1u
#define PinMode_PA0_CAN1Rx      8u
/* Port A Pin 1 */  
#define PinMode_PA1_U0Tx        1u
#define PinMode_PA1_CAN1Tx      8u
/* Port A Pin 2 */  
#define PinMode_PA2_SSI0Clk     2u
/* Port A Pin 3 */  
#define PinMode_PA3_SSI0Fss     2u
/* Port A Pin 4 */  
#define PinMode_PA4_SSI0Rx      2u
/* Port A Pin 5 */  
#define PinMode_PA5_SSI0Tx      2u
/* Port A Pin 6 */  
#define PinMode_PA6_I2C1SCL     3u
#define PinMode_PA6_M1PWM2      5u
/* Port A Pin 7 */  
#define PinMode_PA7_I2C1SDA     3u
#define PinMode_PA7_M1PWM3      5u

/*************************** PORT B ************************/

/* Port B Pin 0 */
#define PinMode_PB0_U1RX        1u
#define PinMode_PB0_T2CCP0      7u
/* Port B Pin 1 */  
#define PinMode_PB1_U1Tx        1u
#define PinMode_PB1_T2CCP1      7u
/* Port B Pin 2 */  
#define PinMode_PB2_I2C0SCL     3u
#define PinMode_PB2_T3CCP0      7u
/* Port B Pin 3 */  
#define PinMode_PB3_I2C0SDA     3u
#define PinMode_PB3_T3CCP1      7u
/* Port B Pin 4 */  
#define PinMode_PB4_SSI2Clk     2u
#define PinMode_PB4_M0PWM2      4u
#define PinMode_PB4_T1CCP0      7u
#define PinMode_PB4_CAN0Rx      8u
/* Port B Pin 5 */  
#define PinMode_PB5_SSI2Fss     2u
#define PinMode_PB5_M0PWM3      4u
#define PinMode_PB5_T1CCP1      7u
#define PinMode_PB5_CAN0Tx      8u
/* Port B Pin 6 */  
#define PinMode_PB6_SSI2Rx      2u
#define PinMode_PB6_M0PWM0      4u
#define PinMode_PB6_T0CCP0      7u
/* Port B Pin 7 */  
#define PinMode_PB7_SSI2Tx      2u
#define PinMode_PB7_M0PWM1      4u
#define PinMode_PB7_T0CCP1      7u

/*************************** PORT C ************************/

/* Port C Pin 0 */
#define PinMode_PC0_TCK_SWCLK   1u
#define PinMode_PC0_T4CCP0      7u
/* Port C Pin 1 */
#define PinMode_PC1_TMS_SWDIO   1u
#define PinMode_PC1_T4CCP1      7u
/* Port C Pin 2 */
#define PinMode_PC2_TDI         1u
#define PinMode_PC2_T5CCP0      7u
/* Port C Pin 3 */
#define PinMode_PC3_TDO_SWO     1u
#define PinMode_PC3_T5CCP1      7u
/* Port C Pin 4 */
#define PinMode_PC4_U4Rx        1u
#define PinMode_PC4_U1Rx        2u
#define PinMode_PC4_M0PWM6      4u
#define PinMode_PC4_IDX1        6u
#define PinMode_PC4_WT0CCP0     7u
#define PinMode_PC4_U1RTS       8u
/* Port C Pin 5 */
#define PinMode_PC5_U4Tx        1u
#define PinMode_PC5_U1Tx        2u
#define PinMode_PC5_M0PWM7      4u
#define PinMode_PC5_PhA1        6u
#define PinMode_PC5_WT0CCP1     7u
#define PinMode_PC5_U1CTS       8u
/* Port C Pin 6 */
#define PinMode_PC6_U3Rx        1u
#define PinMode_PC6_PhB1        6u
#define PinMode_PC6_WT1CCP0     7u
#define PinMode_PC6_USB0EPEN    8u
/* Port C Pin 7 */
#define PinMode_PC7_U3Tx        1u
#define PinMode_PC7_WT1CCP1     7u
#define PinMode_PC7_USB0PFLT    8u

/*************************** PORT D ************************/

/* Port D Pin 0 */
#define PinMode_PD0_SSI3Clk     1u
#define PinMode_PD0_SSI1Clk     2u
#define PinMode_PD0_I2C3SCL     3u
#define PinMode_PD0_M0PWM6      4u
#define PinMode_PD0_M1PWM0      5u
#define PinMode_PD0_WT2CCP0     7u
/* Port D Pin 1 */  
#define PinMode_PD1_SSI3Fss     1u
#define PinMode_PD1_SSI1Fss     2u
#define PinMode_PD1_I2C3SDA     3u
#define PinMode_PD1_M0PWM7      4u
#define PinMode_PD1_M1PWM1      5u
#define PinMode_PD1_WT2CCP1     7u
/* Port D Pin 2 */
#define PinMode_PD2_SSI3Rx      1u
#define PinMode_PD2_SSI1Rx      2u
#define PinMode_PD2_M0FAULT0    4u
#define PinMode_PD2_WT3CCP0     7u
#define PinMode_PD2_USB0EPEN    8u
/* Port D Pin 3 */
#define PinMode_PD3_SSI3Tx      1u
#define PinMode_PD3_SSI1Tx      2u
#define PinMode_PD3_IDX0        6u
#define PinMode_PD3_WT3CCP1     7u
#define PinMode_PD3_USB0PFLT    8u
/* Port D Pin 4 */
#define PinMode_PD4_U6Rx        1u
#define PinMode_PD4_WT4CCP0     7u
/* Port D Pin 5 */
#define PinMode_PD5_U6Tx        1u
#define PinMode_PD5_WT4CCP1     7u
/* Port D Pin 6 */
#define PinMode_PD6_U2Rx        1u
#define PinMode_PD6_M0FAULT0    4u
#define PinMode_PD6_PhA0        6u
#define PinMode_PD6_WT5CCP0     7u
/* Port D Pin 7 */
#define PinMode_PD7_U2Tx        1u
#define PinMode_PD7_PhB0        6u
#define PinMode_PD7_WT5CCP1     7u
#define PinMode_PD7_NMI         8u

/*************************** PORT E ************************/

/* Port E Pin 0 */
#define PinMode_PE0_U7Rx        1u
/* Port E Pin 1 */
#define PinMode_PE1_U7Tx        1u
/* Port E Pin 2 */
/* Port E Pin 3 */
/* Port E Pin 4 */
#define PinMode_PE4_U5Rx        1u
#define PinMode_PE4_I2C2SCL     3u
#define PinMode_PE4_M0PWM4      4u
#define PinMode_PE4_M1PWM2      5u
#define PinMode_PE4_CAN0Rx      8u
/* Port E Pin 5 */
#define PinMode_PE5_U5Tx        1u
#define PinMode_PE5_I2C2SDA     3u
#define PinMode_PE5_M0PWM5      4u
#define PinMode_PE5_M1PWM3      5u
#define PinMode_PE5_CAN0Tx      8u
/* Port E Pin 6 */
/* Port E Pin 7 */
/*************************** PORT F ************************/

/* Port F Pin 0 */
#define PinMode_PF0_U1RTS       1u
#define PinMode_PF0_SSI1Rx      2u
#define PinMode_PF0_CAN0Rx      3u
#define PinMode_PF0_M1PWM4      5u
#define PinMode_PF0_PhA0        6u
#define PinMode_PF0_T0CCP0      7u
#define PinMode_PF0_NMI         8u
#define PinMode_PF0_C0o         9u
/* Port F Pin 1 */
#define PinMode_PF1_U1CTS       1u
#define PinMode_PF1_SSI1Tx      2u
#define PinMode_PF1_M1PWM5      4u
#define PinMode_PF1_PhB0        5u
#define PinMode_PF1_T0CCP1      6u
#define PinMode_PF1_C1o         9u
#define PinMode_PF1_TRD1        14u
/* Port F Pin 2 */
#define PinMode_PF2_SSI1Clk     3u
#define PinMode_PF2_M0FAULT0    5u
#define PinMode_PF2_M1PWM6      6u
#define PinMode_PF2_T1CCP0      8u
#define PinMode_PF2_TRD0        14u
/* Port F Pin 3 */
#define PinMode_PF3_SSI1Fss     2u
#define PinMode_PF3_CAN0Tx      3u
#define PinMode_PF3_M1PWM7      5u
#define PinMode_PF3_T1CCP1      7u
#define PinMode_PF3_TRCLK       14u
/* Port F Pin 4 */
#define PinMode_PF4_M1FAULT0    5u
#define PinMode_PF4_IDX0        6u
#define PinMode_PF4_T2CCP0      7u
#define PinMode_PF4_USB0EPEN    8u
/* Port F Pin 5 */
/* Port F Pin 6 */
/* Port F Pin 7 */

#define InternalAttach_Pullup    0u
#define InternalAttach_PullDown  1u
#define InternalAttach_OpenDrain 2u

#define OutputCurrentType_2 2u
#define OutputCurrentType_4 4u
#define OutputCurrentType_8 8u

#define AF_BitFiled0 0
#define AF_BitFiled1 4
#define AF_BitFiled2 8
#define AF_BitFiled3 12
#define AF_BitFiled4 16
#define AF_BitFiled5 20
#define AF_BitFiled6 24
#define AF_BitFiled7 28


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
        /* DIO TYPES */

typedef uint8 Dio_PortLevel;        // From 0 to 255  
typedef uint8 Dio_PortType;         // A B C or D
typedef uint8 Dio_ChannelLevel;     // 1 or 0 >> High or low
typedef uint8 Dio_ChannelType;      // PA1 PA2 ....

typedef enum{
    PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7              // 7
}PA;

typedef enum{
    PB0 = 8, PB1, PB2, PB3, PB4, PB5, PB6, PB7          // 15
}PB;

typedef enum{
    PC0 = 16, PC1, PC2, PC3, PC4, PC5, PC6, PC7         // 23
}PC;

typedef enum{
    PD0 = 24, PD1, PD2, PD3, PD4, PD5, PD6, PD7         //  31
}PD;

typedef enum{
    PE0 = 32, PE1, PE2, PE3, PE4, PE5, PE6, PE7         //  39
}PE;

typedef enum{
    PF0 = 40, PF1, PF2, PF3, PF4, PF5, PF6, PF7         //  47
}PF;

        /* PORT TYPES */

typedef uint8 Port_PinType;                                 // A B C D E F
typedef uint8 Port_PinNum;                                  // 0 >> 7
typedef uint8 Port_DirectionType;                           // Output or Input
typedef uint8 Port_PinMode;                                 // Dio or something else
typedef uint8 Port_InternalAttach;                          // PullUp PullDown OpenDrain
typedef uint8 Port_OutputCurrentType;                       // 2 , 4 or 8 mA
typedef void (*GPIO_CB_Type)(void);

typedef struct{
    Port_PinType PinType;          
    Port_PinNum PinNum;           
    Port_DirectionType DirectionType;    
    Port_PinMode PinMode;          
    Port_InternalAttach InternalAttach;  
    Port_OutputCurrentType OutputCurrentType;
}ConfigType;
 
#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Types.h
 *********************************************************************************************************************/
