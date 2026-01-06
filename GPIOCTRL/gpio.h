/*
 * gpio.h
 *
 *  Created on: 2023Äê11ÔÂ23ÈÕ
 *      Author: Shen
 */

#ifndef GPIOCTRL_GPIO_H_
#define GPIOCTRL_GPIO_H_

void MUX_INIT(void);                        //PROGRAM A0.1
void MUX_CONF(u8 val);                      //PROGRAM A0.2
void SWITCH_INIT(void);                     //PROGRAM A1.1
void SWITCH_CONF(u8 val);                   //PROGRAM A1.2
void SCRPOWER_INIT(void);                   //PROGRAM A2.1
void SCRPOWER_CONF(u8 val33,u8 val12);      //PROGRAM A2.2
/*******************************************************/   //PROGRAM A3.1
/*******************************************************/   //PROGRAM A3.2
void SCR_INIT(void);                        //PROGRAM A4.1
void SCR_CONF(u8 EN);                       //PROGRAM A4.2
void DPHPD_INIT(void);                      //PROGRAM A5.1
void DPHPD_CONF(u8 EN);                     //PROGRAM A5.2
void LED_INIT(void);                        //PROGRAM A6.1
void LED_TURN(u8 LEDC1,u8 LEDC2);           //PROGRAM A6.2

#endif /* GPIOCTRL_GPIO_H_ */
