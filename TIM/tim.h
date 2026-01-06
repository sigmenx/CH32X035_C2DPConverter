/*
 * tim.h
 *
 *  Created on: 2023Äê11ÔÂ6ÈÕ
 *      Author: Shen
 */

#ifndef USER_TIM_H_
#define USER_TIM_H_

void TIM3_Init( u16 arr, u16 psc );
void TIM1_PWMOut_Init(u16 arr, u16 psc, u16 ccp);
void SCR_PWMOut(u16 ccp);

#endif /* USER_TIM_H_ */
