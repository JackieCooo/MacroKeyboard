#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"
#include "core_cm3.h"
#include "misc.h"

#define delay_ms(x) SysTick_Delay_Ms(x)
#define delay_10us(x) SysTick_Delay_Us( __IO uint32_t us);

void SysTick_Init(void);
void SysTick_Delay_10Us( __IO uint32_t us);
void SysTick_Delay_Ms( __IO uint32_t ms);
void TimingDelay_Decrement(void);

#endif /* __SYSTICK_H */
