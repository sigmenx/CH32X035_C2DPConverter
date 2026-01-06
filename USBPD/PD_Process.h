/********************************** (C) COPYRIGHT *******************************
* File Name          : PD_Process.h
* Author             : WCH
* Version            : V1.0.0
* Date               : 2023/04/06
* Description        : This file contains all the functions prototypes for the
*                      PD library.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

#ifndef USBPD_PD_PROCESS_H_
#define USBPD_PD_PROCESS_H_

#ifdef __cplusplus
 extern "C" {
#endif

extern UINT8 PD_Ack_Buf[ ];

extern __attribute__ ((aligned(4))) UINT8 PD_Rx_Buf[ 34 ];
extern __attribute__ ((aligned(4))) UINT8 PD_Tx_Buf[ 34 ];

/* Function extensibility */
extern void PD_Message_Process(void);
extern void PD_Main_Proc( void );
void PD_PHY_TX_DPAttention_Table(void);
void PD_PHY_TX_DPAttention_Table_1(void);

#ifdef __cplusplus
}
#endif

#endif /* USER_PD_PROCESS_H_ */
