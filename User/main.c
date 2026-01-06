/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2023/12/26
 * Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
 *
 * PD SNK Sample code
 *
 * This sample code may have compatibility issues and is for learning purposes only.
 * If you want to develop a PD project, please contact FAE.
 
 * Make sure that the board is not powered on before use.
 * Be sure to pay attention to the voltage when changing the request
 * to prevent burning the board.
 *
 * There is no integrated 5.1K pull-down inside the chip,
 * CC_PD is only for status differentiation,
 * bit write 1 means SNK mode, write 0 means SCR mode
 *
 * Modify "PDO_Request( PDO_INDEX_1 )" in pd process.c, line 753, to modify the request voltage.
 *
 * According to the usage scenario of PD SNK, whether
 * it is removed or not should be determined by detecting
 * the Vbus voltage, this code only shows the detection
 * and the subsequent communication flow.
 */

#include "debug.h"
#include "PD_Process.h"
#include "PD_Basicfun.h"
#include "gpio.h"
#include "tim.h"
#include "ADC.h"

//#define SCR_HPD GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)
u16 HPD_VALUE = 0;//C-DP板用

UINT8  Tim_Ms_Cnt = 0x00;

UINT8 flg_a=0;
/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    USART_Printf_Init(115200);
    printf( "M SystemClk:%d\r\n", SystemCoreClock );
    printf( "M ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf( "M PD SNK TEST\r\n" );

    ADC_Function_Init();//C-DP板用
    LED_INIT();//C-DP板用
    MUX_INIT();//C-DP板用

//    SWITCH_INIT();       //PROGRAM A1.1
//    SCRPOWER_INIT();     //PROGRAM A2.1
//    SCR_INIT();          //PROGRAM A4.1
//    DPHPD_INIT();        //PROGRAM A5.1
//    LED_INIT();          //PROGRAM A6.1
//    TIM1_PWMOut_Init( 100-1, 4800-1, 1 );

    PD_Init( );
    TIM3_Init( 999, 48-1);

    //FOR TEST USE//
//    SWITCH_CONF(1);
//    SCR_PWMOut(70);
//    SCR_CONF(1);
//    SCRPOWER_CONF(1, 1);
    //FOR TEST USE//

    while(1)
    {


        Delay_Ms(1);
        /* Get the calculated timing interval value */
        TIM_ITConfig( TIM3, TIM_IT_Update , DISABLE );
        Tmr_Ms_Dlt = Tim_Ms_Cnt - Tmr_Ms_Cnt_Last;
        Tmr_Ms_Cnt_Last = Tim_Ms_Cnt;
        TIM_ITConfig( TIM3, TIM_IT_Update , ENABLE );
        PD_Ctl.Det_Timer += Tmr_Ms_Dlt;

        switch( flg_a )
        {
            case 0:
                if(PD_Ctl.Flag.Bit.Connected ==1)
                {
                    flg_a=1;

                }else{
                    printf( "M:CC NOT CONNECTED\r\n" );
                    PD_Ctl.Flag.Bit.Dppwr_Succ=0;//电压协商没成功
                    PD_Ctl.Flag.Bit.Dpsig_Succ=0;//视频协商没成功
                    PD_Det_Proc( );
                }
                break;
            case 1:
                if(PD_Ctl.Flag.Bit.Dppwr_Succ == 1){
                    printf( "M:PWR REQUEST SUCCESS\r\n" );
                    flg_a=2;
                }
                break;
            case 2:
                if(PD_Ctl.Flag.Bit.Dpsig_Succ == 1){
                    printf( "M:SIG REQUEST SUCCESS\r\n" );
                    flg_a=3;
                }
                break;
            case 3:
                HPD_VALUE=Get_ADC_Val(ADC_Channel_4);//C-DP板用
                printf("HPD_VALUE：%d\r\n",HPD_VALUE);//C-DP板用
                if(HPD_VALUE>3000)//C-DP板用//SCR_HPD == 1)//屏幕插入检测
                {
                    flg_a = 4;
                    PD_Ctl.Det_Timer=0;
                }
                break;
            case 4:
                if(PD_Ctl.Det_Timer>=100)
                {
                    PD_PHY_TX_DPAttention_Table();
                    printf("M:ENTER PD\n");
                    flg_a=5;
                }
                break;
            case 5:
                if(PD_Ctl.Det_Timer>=100)
                {
                    HPD_VALUE=Get_ADC_Val(ADC_Channel_4);
                    printf("HPD_VALUE：%d\r\n",HPD_VALUE);//C-DP板用
                    if(HPD_VALUE<2000)//C-DP板用 //SCR_HPD == 0)
                    {
                        PD_PHY_TX_DPAttention_Table_1();
                        //NVIC_SystemReset();
                        flg_a=3;
                    }else{
                        //此处应去检测DP信号是否正常连接
                    }
                }
                break;
            default:
                break;
        }
        if(flg_a != 0)
        {
            PD_Main_Proc( );
        }
        //printf( "POWER REQUEST FAIL\r\n" );
        //printf( "DP SIGNAL REQUEST FAIL,SOURCE ONLY SUPPORT POWER\r\n" );
    }
}

/*********************************************************************
 * @fn      TIM3_UP_IRQHandler
 *
 * @brief   This function handles TIM3 interrupt.
 *
 * @return  none
 */
void TIM3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void TIM3_IRQHandler(void)
{
    if( TIM_GetITStatus( TIM3, TIM_IT_Update ) != RESET )
    {

        Tim_Ms_Cnt++;

        TIM_ClearITPendingBit( TIM3, TIM_IT_Update );

    }
}
