/*
 * gpio.c
 *
 *  Created on: 2023年11月23日
 *      Author: Shen
 */


#ifndef GPIOCTRL_GPIO_C_
#define GPIOCTRL_GPIO_C_


#include "ch32x035.h"

/*******************************************************/   //PROGRAM A0.1
//MUX (VL170)初始化
void MUX_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    GPIO_SetBits(GPIOA, GPIO_Pin_0);
    GPIO_SetBits(GPIOA, GPIO_Pin_1);
    GPIO_SetBits(GPIOA, GPIO_Pin_2);
}
/*******************************************************/   //PROGRAM A0.2
//MUX (VL170)信号切换
//val=0 CC1/信号正接
//val=1 CC2/信号翻转
void MUX_CONF(u8 val)
{
    if(val==1){GPIO_SetBits(GPIOA, GPIO_Pin_2);}
    else{GPIO_ResetBits(GPIOA, GPIO_Pin_2);}
}
/*******************************************************/   //PROGRAM A1.1
//SWITCH（TS3DV642)初始化
void SWITCH_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_SetBits(GPIOB, GPIO_Pin_10);
    GPIO_ResetBits(GPIOB, GPIO_Pin_11);
}
/*******************************************************/   //PROGRAM A1.2
//SWITCH（TS3DV642)信号切换
//val=0 DP信号接通
//val=1 TYPEC信号接通
void SWITCH_CONF(u8 val)
{
    if(val==1){GPIO_SetBits(GPIOB, GPIO_Pin_11);}
    else{GPIO_ResetBits(GPIOB, GPIO_Pin_11);}
}

/*******************************************************/   //PROGRAM A2.1
//屏幕的12V和3.3V供电模块初始化
void SCRPOWER_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_ResetBits(GPIOB, GPIO_Pin_5);
    GPIO_ResetBits(GPIOB, GPIO_Pin_6);
}
/*******************************************************/   //PROGRAM A2.2
//屏幕的12V和3.3V供电模块控制
//val33=0/1 3.3V供电失能/使能
//val12=0/1 12供电失能/使能
void SCRPOWER_CONF(u8 val33,u8 val12)
{
    if(val33 ==1)
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_5);
    }else{
        GPIO_ResetBits(GPIOB, GPIO_Pin_5);
    }

    if(val12 ==1)
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_6);
    }else{
        GPIO_ResetBits(GPIOB, GPIO_Pin_6);
    }
}
/*******************************************************/   //PROGRAM A3.1还没写
//转接板控制-初始化

/*******************************************************/   //PROGRAM A3.2还没写
//转接板控制
//输入部分 BO_ADD1 BO_CHGIN BO_LIGUP BO_LIGDOWN BO_ONOFF
//        未定义      信号切换     屏幕亮度+  屏幕亮度-  屏幕开关
//均为全局变量（见外部中断）
//输出部分 LEDR/LEDG/LEDB 0灭 1 亮

/*******************************************************/   //PROGRAM A4.1
//屏幕控制-初始化（SCR_PWM 亮度控制 见TIM.c）
void SCR_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_ResetBits(GPIOB, GPIO_Pin_8);
    GPIO_ResetBits(GPIOB, GPIO_Pin_9);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
/*******************************************************/   //PROGRAM A4.2
//屏幕控制-屏幕开关
//EN=0/1 屏幕关/开
void SCR_CONF(u8 EN)
{
    if(EN ==1)
        {
            GPIO_SetBits(GPIOB, GPIO_Pin_8);
        }else{
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
        }
}
//输入部分 SCR_HPD=0/1 屏幕插入/没插入（需要3.3V屏幕供电才有效）

/*******************************************************/   //PROGRAM A5.1
//DP_HPD-初始化
void DPHPD_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_ResetBits(GPIOA, GPIO_Pin_12);
}
/*******************************************************/   //PROGRAM A5.2
//DP_HPD控制
//EN=0/1 向source端不请求/请求视频信号
void DPHPD_CONF(u8 EN)
{
    if(EN ==1)
        {
            GPIO_SetBits(GPIOA, GPIO_Pin_12);
        }else{
            GPIO_ResetBits(GPIOA, GPIO_Pin_12);
        }
}
/*******************************************************/   //PROGRAM A6.1
//板载LED初始化
void LED_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15|GPIO_Pin_16;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_Pin_13);
    GPIO_SetBits(GPIOA, GPIO_Pin_14);
}
/*******************************************************/   //PROGRAM A6.2
//LEDC1=0/1 灭/亮        LEDC2=0/1 灭/亮
void LED_TURN(u8 LEDC1,u8 LEDC2)
{
    //GPIO_WriteBit(GPIOA, GPIO_Pin_13, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
        if (LEDC1==0){
            GPIO_SetBits(GPIOA, GPIO_Pin_13);
        }else{
            GPIO_ResetBits(GPIOA, GPIO_Pin_13);
        }

        if (LEDC2==0){
            GPIO_SetBits(GPIOA, GPIO_Pin_14);
        }else{
            GPIO_ResetBits(GPIOA, GPIO_Pin_14);
        }
}

#endif /* GPIOCTRL_GPIO_C_ */
