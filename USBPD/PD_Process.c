/********************************** (C) COPYRIGHT *******************************
* File Name          : PD_process.c
* Author             : trumx
* Version            : V1.0.0
* Date               : 2023/03/20
* Description        : PD信息流 主程序.
*********************************************************************************
* Copyright (c) 2023 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

#define EN_DPSIG 1  //1开启vdm dp信号获取通信

#include "debug.h"
#include <string.h>
//#include "PD_Process.h"
#include "PD_Basicfun.h"

void USBPD_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

__attribute__ ((aligned(4))) uint8_t PD_Rx_Buf[ 34 ];                           /* PD receive buffer */
__attribute__ ((aligned(4))) uint8_t PD_Tx_Buf[ 34 ];                           /* PD send buffer */

/******************************************************************************/
UINT8 PD_Ack_Buf[ 2 ];                                                          /* PD-ACK buffer */

/* SrcCap Table */
UINT8 SinkCap_5V1A_Tab[ 4 ] = { 0X64, 0X90, 0X01, 0X36 };
/* PD3.0 */
UINT8 SrcCap_Ext_Tab[ 28 ] =
{
    0X18, 0X80, 0X63, 0X00,
    0X00, 0X00, 0X00, 0X00,
    0X00, 0X00, 0X01, 0X00,
    0X00, 0X00, 0X07, 0X03,
    0X00, 0X00, 0X00, 0X00,
    0X00, 0X00, 0X00, 0X03,
    0X00, 0X12, 0X00, 0X00,
};

UINT8 Status_Ext_Tab[ 8 ] =
{
    0X06, 0X80, 0X16, 0X00,
    0X00, 0X00, 0X00, 0X00,
};


/*      Display VDM Message    */

//01 011 10 00 0 0  1110100000000
UINT8  ACK_Disc_Ident[ ] =
{
    0x5c,0x1d,0x00,0x6c,                              //01 011 10 00 0 0111010000000001 101100
    0x46,0x42,0x0f,0x00,
//01000110 01000010 00001111 00000000
    0x06,0x07,0x02,0x71,
    0xdb,0x00,0x00,0x11
};

UINT8  ACK_Disc_SVID[ ] = {0x00,0x00,0x01,0xff};      //00 000 00 00 0 000000 00000001 11111111


/* 四线，仅支持模式C */
#if 1
//01 0001 0 1 00000000 00000100
UINT8  ACK_Disc_Mode[ ] = {0x45,0x00,0x04,0x00};      //01 0001 0 1 00000000 00000100 00000000

UINT8  ACK_DP_Stat_Pos_1[ ] = {0x0a,0x00,0x00,0x00};  //00 001010

#else
/* 两线，支持C D模式，prefer D模式 */
UINT8  ACK_Disc_Mode[ ] = {0x05,0x0C,0x00,0x00};      //00 0001 0 1 00001100 00000000 00000000

UINT8  ACK_DP_Stat_Pos_1[ ] = {0x1a,0x00,0x00,0x00};  //00 011010

#endif
UINT8 DPAttention_Table[ ] =
{
    0x06,0x81,0x01,0xff,
    0x8a,0x00,0x00,0x00
};
UINT8 DPAttention_Table_1[ ] =
{
    0x06,0x81,0x01,0xff,
    0x0a,0x00,0x00,0x00
};
//static int alt_mode_ready = 0;
UINT8 Recv2 = 0;

void PD_PHY_TX_DPAttention_Table(void)
{
    //MsgID ++;
    if(PD_Ctl.Msg_ID>7){    PD_Ctl.Msg_ID =0;}
    PD_Tx_Buf[1]=((((PD_Rx_Buf[1] ^0x01)& 0x01)|0x20)|(PD_Ctl.Msg_ID<<1));
    PD_Tx_Buf[0] =(0x0F | (Recv2<<6));
    memcpy(&PD_Tx_Buf[2],DPAttention_Table,8);
    PD_Send_TXBUF(10);
}
void PD_PHY_TX_DPAttention_Table_1(void)
{

    if(PD_Ctl.Msg_ID>7){    PD_Ctl.Msg_ID =0;}
    PD_Tx_Buf[1]=((((PD_Rx_Buf[1] ^0x01)& 0x01)|0x20)|(PD_Ctl.Msg_ID<<1));
    PD_Tx_Buf[0] =(0x0F | (Recv2<<6));
    memcpy(&PD_Tx_Buf[2],DPAttention_Table_1,8);
    PD_Send_TXBUF(10);
}

/*********************************************************************
 * @fn      vdm_process
 * @brief   对vdm_header进行识别 并返回对应命令.
 *                               此函数在pd接收中断中，pd消息接受后，pd电压协商成功后运行。
 * @Date 20240319
 * @Author trumx
 *
 * @return  none
 */
void vdm_process()
{
    UINT8 vdm_command;

        vdm_command = PD_Rx_Buf[ 2 ] & 0x1F;  //VDM command
        Recv2 = PD_Rx_Buf[ 0 ] & 0xC0;
        //printf("in vdm \r\n");
        //printf("%hx\r\n",PD_Rx_Buf[ 0 ]);
        //printf("%hx\r\n",PD_Rx_Buf[ 1 ]);
        //printf("%hx\r\n",PD_Rx_Buf[ 2 ]);
        //printf("%hx\r\n",PD_Rx_Buf[ 3 ]);
        //printf("%hx\r\n",vdm_command);
        //printf(" ok \r\n");

        /* VDM message handling */
        switch(vdm_command){
   //DP主机发送Discover Identity信息获取连接设备的信息。
   //DP设备回复Discover IdentityACK信息，包含自己的设备信息。
        case DEF_VDM_DISC_IDENT://0x01 ;
            //MsgID++;
            printf("I2:Discover Identity received\r\n");
            PD_Tx_Buf[5] = PD_Rx_Buf[5];
            PD_Tx_Buf[4] = PD_Rx_Buf[4];
            PD_Tx_Buf[3] = PD_Rx_Buf[3];
            PD_Tx_Buf[2] = (PD_Rx_Buf[2] | (4<<4)); //01 0 000001 P131
            PD_Tx_Buf[1] =((((PD_Rx_Buf[1] ^0x01)& 0x01)|0x50)|(PD_Ctl.Msg_ID<<1));
            PD_Tx_Buf[0] =0x0F | (0xC0 & PD_Rx_Buf[0]);
            memcpy(&PD_Tx_Buf[6],ACK_Disc_Ident,16);
            PD_Send_TXBUF(22);
            break;
    //DP主机发送Discover SVIDs信息获取连接设备支持的厂商SVID列表。
    //DP设备端回复Discover SVIDs ACK信息，包含自己支持的SVIDG列表。
        case DEF_VDM_DISC_SVID://0x02;
            //MsgID++;
            printf("I2:Discover SVIDs received\r\n");
            PD_Tx_Buf[5] = PD_Rx_Buf[5];
            PD_Tx_Buf[4] = PD_Rx_Buf[4];
            PD_Tx_Buf[3] = PD_Rx_Buf[3];
            PD_Tx_Buf[2] = (PD_Rx_Buf[2] | (4<<4));
            PD_Tx_Buf[1]=((((PD_Rx_Buf[1] ^0x01)& 0x01)|0x20)|(PD_Ctl.Msg_ID<<1));
            PD_Tx_Buf[0] =0x0F | (0xC0 & PD_Rx_Buf[0]);
            memcpy(&PD_Tx_Buf[6],ACK_Disc_SVID,4);
            PD_Send_TXBUF(10);
            break;
    //DP主机收到回复后，发送Discover Modes获取DP设备的模式信息。此信息的数据头使用DP的VID,表示获取支持的DP模式的列表。
    //DP设备回复Discover Modes ACK信息，包含自己的模式列表。
        case DEF_VDM_DISC_MODE://0x03;
            //MsgID++;
            printf("I2:Discover Modes received\r\n");
            PD_Tx_Buf[5] = PD_Rx_Buf[5];
            PD_Tx_Buf[4] = PD_Rx_Buf[4];
            PD_Tx_Buf[3] = PD_Rx_Buf[3];
            PD_Tx_Buf[2] = (PD_Rx_Buf[2] | (4<<4));
            PD_Tx_Buf[1]=((((PD_Rx_Buf[1] ^0x01)& 0x01)|0x20)|(PD_Ctl.Msg_ID<<1));
            PD_Tx_Buf[0] =0x0F | (0xC0 & PD_Rx_Buf[0]);
            memcpy(&PD_Tx_Buf[6],ACK_Disc_Mode,4);
            PD_Send_TXBUF(10);
            break;
     //DP主机收到回复后，解析收到的所有模式，并从中选取一个合适的模式，作为Enter MODE的参数发送给对方。
     //DP投备收到，进入D模式，开始工作有DP模式
     //DP主机发送EnterMode成功后，也开始工作为DP模式
        case DEF_VDM_ENTER_MODE://0x04;
            //
            //MsgID++;
            printf("I2:EnterMode received\r\n");
            PD_Tx_Buf[5] = PD_Rx_Buf[5];
            PD_Tx_Buf[4] = PD_Rx_Buf[4];
            PD_Tx_Buf[3] = PD_Rx_Buf[3];
            PD_Tx_Buf[2] = (PD_Rx_Buf[2] | (4<<4));
            PD_Tx_Buf[1]=((((PD_Rx_Buf[1] ^0x01)& 0x01)|0x10)|(PD_Ctl.Msg_ID<<1));
            PD_Tx_Buf[0] =0x0F | (0xC0 & PD_Rx_Buf[0]);
            PD_Send_TXBUF(6);
            break;
        case DEF_VDM_EXIT_MODE://0x05
            printf("I2:vdm 05\r\n");
            break;
        case DEF_VDM_ATTENTION://0x06
            printf("I2:vdm 06\r\n");
            break;
     //Dp主机发送DpstasUpdate信息设置DP设备的状态
     //DP设备回复Dpstas Update ACK信息，包括DP上行端口功能连接状态（UIPD）和DP显示设备连接状态（HPD Staus）
        case DEF_VDM_DP_S_UPDATE://0x10 PD_PHY_STAT.SendingACK_DP_Stat_Pos_1 = 1;
            //MsgID++;
            printf("I2:DpstasUpdate received\r\n");
            PD_Tx_Buf[5] = PD_Rx_Buf[5];
            PD_Tx_Buf[4] = PD_Rx_Buf[4];
            PD_Tx_Buf[3] = PD_Rx_Buf[3];
            PD_Tx_Buf[2] = (PD_Rx_Buf[2] | (4<<4));
            PD_Tx_Buf[1]=((((PD_Rx_Buf[1] ^0x01)& 0x01)|0x20)|(PD_Ctl.Msg_ID<<1));
            PD_Tx_Buf[0] =0x0F | (0xC0 & PD_Rx_Buf[0]);
            memcpy(&PD_Tx_Buf[6],ACK_DP_Stat_Pos_1,4);
            PD_Send_TXBUF(10);
            break;
     //如果DP上行端口功能（UFPD）已经连接，DP主机发送DP Confgure配置设备端DP通信信号。

        case DEF_VDM_DP_CONFIG://0x11 PD_PHY_STAT.SendingACK_DP_Configure_Pos_1 = 1;
            //MsgID++;
            printf("I2:DP Confgure received\r\n");
            PD_Tx_Buf[5] = PD_Rx_Buf[5];
            PD_Tx_Buf[4] = PD_Rx_Buf[4];
            PD_Tx_Buf[3] = PD_Rx_Buf[3];
            PD_Tx_Buf[2] = (PD_Rx_Buf[2] | (4<<4));
            PD_Tx_Buf[1]=((((PD_Rx_Buf[1] ^0x01)& 0x01)|0x10)|(PD_Ctl.Msg_ID<<1));
            PD_Tx_Buf[0] =0x0F | (0xC0 & PD_Rx_Buf[0]);
            //alt_mode_ready = 1;
            PD_Ctl.Flag.Bit.Dpsig_Succ = 1; //dp信号请求成功
            PD_Send_TXBUF(6);
            break;
        }
     //如果DP显示设备已经连接，则开始 进行DP通信
             //如果DP上行端口功能没有连接，DP主机等待Attention信息报告 连接变化

            //DP设备会通过Atention通知自己的状态变化。
            //当收到Atention指示DP上行端口功能已经连接时，DP主机通过 DPConfigure配置DP通信信号。

            //如果DP显示设备没有连接，DP主机等待Auention信息报告连接 变化

            //DP设备会通过Auenion通知自己的状态变化。

            //当收到Atention指示DP显示设备已经连接（HPDState）时，开始进行DP通信。

}


/*********************************************************************
 * @fn      PD_Message_Process
 * @brief   对pd_header进行识别 并返回对应命令.
 *                               此函数在pd接收中断中，pd消息接受后运行。
 * @Date 20240319
 * @Author trumx
 *
 * @return  none
 */
void PD_Message_Process(void)
{

    UINT8  pd_header;
    UINT8  var;
    UINT16 Current,Voltage;

    /* Adapter communication idle timing */
    //        PD_Ctl.Adapter_Idle_Cnt = 0x00;    //未使用
    pd_header = PD_Rx_Buf[ 0 ] & 0x1F;
    switch( pd_header )
    {
        case DEF_TYPE_SRC_CAP:
            printf("I1:RECEIVE SRC_CAP\r\n");
            Delay_Ms( 5 );
            PD_Ctl.Flag.Bit.Stop_Det_Chk = 0;                         /* Enable PD disconnection detection */

            PD_Save_Adapter_SrcCap( );

            /* Analysis of the voltage and current of each PDO group */
            printf("SOURCE SUPPORT:\r\n");
            for (var = 1; var <= PDO_Len; ++var)
            {
                PD_PDO_Analyse( var, &PD_Rx_Buf[ 2 ], &Current, &Voltage );
                //printf("PDO:%d Current:%d mA Voltage:%d mV\r\n",var,Current,Voltage);
                printf("PDO:%d %dmV\r\n",var,Voltage);
            }
            /* Different PDO's for different voltages and currents */
            /* Default application for the first group of PDO, 5V */
            PDO_Request( PDO_INDEX_1 );
            break;

        case DEF_TYPE_ACCEPT:
            printf("I1:RECEIVE ACCEPT\r\n");
            /* ACCEPT received */
            PD_Ctl.PD_State = STA_RX_PS_RDY_WAIT;
            PD_Ctl.PD_Comm_Timer = 0;
            break;

        case DEF_TYPE_PS_RDY:
            printf("I1:RECEIVE PS_RDY\r\n");
            /* PS_RDY is received */
            PD_Ctl.Flag.Bit.Dppwr_Succ = 1;
            printf("power success\r\n");
            PD_Ctl.PD_State = STA_RX_PS_RDY;
            break;

        case DEF_TYPE_WAIT:
            printf("I1:RECEIVE WAIT\r\n");
            /* WAIT received, many requests may receive WAIT, need specific analysis */
            break;

        case DEF_TYPE_GET_SNK_CAP:  //���޸ģ����USB Power Delivery Specification Revision 3.0, Version 1.1(2017) Page 121
            printf("I1:RECEIVE GET_SNK_CAP\r\n");
            Delay_Ms( 1 );
            PD_Load_Header( 0x00, DEF_TYPE_SNK_CAP );
            PD_Send_Handle( SinkCap_5V1A_Tab, sizeof( SinkCap_5V1A_Tab ) );
            break;

        case DEF_TYPE_SOFT_RESET:
            printf("I1:RECEIVE SOFT_RESET\r\n");
            Delay_Ms( 1 );
            PD_Load_Header( 0x00, DEF_TYPE_ACCEPT );
            PD_Send_Handle( NULL, 0 );
            break;

        case DEF_TYPE_GET_SRC_CAP_EX:
            printf("I1:RECEIVE GET_SRC_CAP_EX\r\n");
            Delay_Ms( 1 );
            PD_Load_Header( 0x01, DEF_TYPE_SRC_CAP );
            PD_Send_Handle( SrcCap_Ext_Tab, sizeof( SrcCap_Ext_Tab ) );
            break;

        case DEF_TYPE_GET_STATUS:
            printf("I1:RECEIVE GET_STATUS\r\n");
            Delay_Ms( 1 );
            PD_Load_Header( 0x01, DEF_TYPE_GET_STATUS_R );
            PD_Send_Handle( Status_Ext_Tab, sizeof( Status_Ext_Tab ) );
            break;

        case DEF_TYPE_VCONN_SWAP:
            printf("I1:RECEIVE VCONN_SWAP\r\n");
            Delay_Ms( 1 );
            PD_Load_Header( 0x00, DEF_TYPE_REJECT );
            PD_Send_Handle( NULL, 0 );
            break;
        case DEF_TYPE_VENDOR_DEFINED:
            printf("I1:RECEIVE VENDOR_DEFINED\r\n");
            /* VDM message handling */
            if(EN_DPSIG){

                vdm_process();     //VDM DPģʽ���ݴ�������

            }else{
                if( ( PD_Rx_Buf[ 2 ] & 0xC0 ) == 0 )
                {
                    /* REQ */
                    Delay_Ms( 1 );

                    /* Data to be sent is cached to PD_Tx_Buf */
                    PD_Load_Header( 0x00, DEF_TYPE_VENDOR_DEFINED );

                    /* Return to NAK */
                    if( ( PD_Rx_Buf[ 3 ] & 0x60 ) == 0 )
                    {
                        PD_Ctl.Flag.Bit.VDM_Version = 0;
                    }
                    else
                    {
                        PD_Ctl.Flag.Bit.VDM_Version = 1;
                    }
                    PD_Rx_Buf[ 2 ] |= 0x80;
                    PD_Send_Handle( &PD_Rx_Buf[ 2 ], 4 );
                }
            }
            break;
        default:
            printf("Unsupported Command\r\n");
            break;
    }
}

/*********************************************************************
 * @fn      USBPD_IRQHandler
 *
 * @brief   This function handles USBPD interrupt.
 *
 * @return  none
 */
void USBPD_IRQHandler(void)
{
    if(USBPD->STATUS & IF_RX_ACT)
    {
        USBPD->STATUS |= IF_RX_ACT;
        if( ( USBPD->STATUS & MASK_PD_STAT ) == PD_RX_SOP0 )
        {
            if( USBPD->BMC_BYTE_CNT >= 6 )
            {
                /* If GOODCRC, do not answer and ignore this reception */
                if( ( USBPD->BMC_BYTE_CNT != 6 ) || ( ( PD_Rx_Buf[ 0 ] & 0x1F ) != DEF_TYPE_GOODCRC ) )
                {
                    Delay_Us(30);                       /* Delay 30us, answer GoodCRC */
                    PD_Ack_Buf[ 0 ] = 0x41;
                    PD_Ack_Buf[ 1 ] = ( PD_Rx_Buf[ 1 ] & 0x0E ) | PD_Ctl.Flag.Bit.Auto_Ack_PRRole;
                    USBPD->CONFIG |= IE_TX_END ;
                    PD_Phy_SendPack( 0, PD_Ack_Buf, 2, UPD_SOP0 );
                    printf("I0:ANSWER GOODCRC\r\n");
                }else{
                    printf("I0:RECEIVED GOODCRC\r\n");
                }
            }
        }
    }
    if(USBPD->STATUS & IF_TX_END)
    {
        /* Packet send completion interrupt (GoodCRC send completion interrupt only) */
        USBPD->PORT_CC1 &= ~CC_LVE;
        USBPD->PORT_CC2 &= ~CC_LVE;

        /* Interrupts are turned off and can be turned on after the main function has finished processing the data */
        NVIC_DisableIRQ(USBPD_IRQn);

        PD_Ctl.Flag.Bit.Msg_Recvd = 1;                                          /* Packet received flag */
        USBPD->STATUS |= IF_TX_END;
    }
    if(USBPD->STATUS & IF_RX_RESET)
    {
        USBPD->STATUS |= IF_RX_RESET;
        PD_SINK_Init( );
        printf("I0:IF_RX_RESET\r\n");
    }

    if(PD_Ctl.Flag.Bit.Connected)
    {
        if( PD_Ctl.Flag.Bit.Msg_Recvd )  //���յ�����Ϣ������֮ǰ������main_proc��
        {
            /* Receive message processing */
            PD_Message_Process();        //��Ҫ���ݴ������򣬿�����
            /* Message has been processed, interrupt reception is turned on again */
            PD_Rx_Mode( );
            PD_Ctl.Flag.Bit.Msg_Recvd = 0;                                    /* Clear the received flag */
            //PD_Ctl.PD_BusIdle_Timer = 0;                                      /* Idle time cleared */        //δ��
        }
    }

}
/*********************************************************************
 * @fn      PD_Main_Proc
 *
 * @brief   This function uses to process PD status.
 *
 * @return  none
 */
void PD_Main_Proc( )
{
    UINT8  status;
//    UINT8  pd_header;
//    UINT8  var;
//    UINT16 Current,Voltage;

    /* Receive idle timer count */
//    PD_Ctl.PD_BusIdle_Timer += Tmr_Ms_Dlt;   //未使用

    /* Status analysis processing */
    switch( PD_Ctl.PD_State )
    {
        case STA_DISCONNECT:
            /* Status: Disconnected */           //不会执行
            printf("M:Disconnect\r\n");
            PD_PHY_Reset( );
            break;

        case STA_SRC_CONNECT:
            //printf("M:SRC_CONNECT\r\n");
            /* Status: SRC access */
            /* If SRC_CAP is received within 1S, reset operation is performed */
            PD_Ctl.PD_Comm_Timer += Tmr_Ms_Dlt;
            if( PD_Ctl.PD_Comm_Timer > 999 )
            {
                /* Retry on exception (abort after 5 attempts) */
                PD_Ctl.Err_Op_Cnt++;
                if( PD_Ctl.Err_Op_Cnt > 5 )
                {
                    PD_Ctl.Err_Op_Cnt = 0;
                    PD_Ctl.PD_State = STA_IDLE;
                }
                else
                {
                    //PD_PHY_Reset( );  //暂时注释
                }
            }
            break;

        case STA_RX_ACCEPT_WAIT:
            /* Status: waiting to receive ACCEPT */
        case STA_RX_PS_RDY_WAIT:
            /* Status: waiting to receive PS_RDY */
            PD_Ctl.PD_Comm_Timer += Tmr_Ms_Dlt;
            if( PD_Ctl.PD_Comm_Timer > 499 )
            {
                PD_Ctl.Flag.Bit.Stop_Det_Chk = 0;                         /* Enable connection detection*/
                PD_Ctl.PD_State = STA_TX_SOFTRST;
                PD_Ctl.PD_Comm_Timer = 0;
            }
            break;

        case STA_RX_PS_RDY:
            /* Status: PS_RDY received */
            PD_Ctl.PD_State = STA_IDLE;
            if( PD_Ctl.PD_State == STA_RX_APD_PS_RDY_WAIT )
            {
                PD_Ctl.PD_State = STA_RX_APD_PS_RDY;
            }
            break;

        case STA_TX_SOFTRST:
            /* Status: send software reset */
            /* Send soft reset, if sent successfully, mode unchanged, count +1 for retry */
            PD_Load_Header( 0x00, DEF_TYPE_SOFT_RESET );
            status = PD_Send_Handle( NULL, 0 );
            if( status == DEF_PD_TX_OK )
            {
                /* current mode unchanged, jump to initial state of current mode, mode retry count, switch mode if exceeded */
                PD_Ctl.PD_State = STA_IDLE;
            }
            else
            {
                PD_Ctl.PD_State = STA_TX_HRST;
            }
            PD_Ctl.PD_Comm_Timer = 0;
            break;

        case STA_TX_HRST:
            /* Status: Sending a hardware reset */
            /* Sending a hard reset */
            PD_Ctl.Flag.Bit.Stop_Det_Chk = 1;
            PD_Phy_SendPack( 0x01, NULL, 0, UPD_HARD_RESET );                   /* send HRST */
            PD_Rx_Mode( );                                                      /* switch to rx mode */
            PD_Ctl.PD_State = STA_IDLE;
            PD_Ctl.PD_Comm_Timer = 0;
            break;

        default:
            break;
    }
//之前放在这里的
//    if( PD_Ctl.Flag.Bit.Msg_Recvd )
//    {
//
//        PD_Message_Process();
//
//        /* Message has been processed, interrupt reception is turned on again */
//        PD_Rx_Mode( );
//        PD_Ctl.Flag.Bit.Msg_Recvd = 0;                                    /* Clear the received flag */
//        //PD_Ctl.PD_BusIdle_Timer = 0;                                      /* Idle time cleared */        //δ��
//    }
}

