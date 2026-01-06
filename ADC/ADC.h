/*
 * ADC.h
 *
 *  Created on: 2023Äê12ÔÂ20ÈÕ
 *      Author: Shen
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

void ADC_Function_Init(void) ;
u16 Get_ADC_Val(u8 ch);
void DMA_Tx_Init(DMA_Channel_TypeDef *DMA_CHx, u32 ppadr, u32 memadr, u16 bufsize);

#endif /* ADC_ADC_H_ */
