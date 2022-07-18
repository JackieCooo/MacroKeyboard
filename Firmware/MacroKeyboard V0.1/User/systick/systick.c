/**
  ******************************************************************************
  * @file    systick.c 
  * @author  Jackie
  * @version V1.0
  * @date    2022-07-08
  * @brief   SysTick������ʱ����
  ******************************************************************************
  */

#include "./systick/systick.h"

static __IO u32 TimingDelay = 0x00;
 
/**
  * @brief  ��ʼ��SysTick
  * @param  None
  * @retval None
  */
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms�ж�һ��
	 * SystemFrequency / 100000	 10us�ж�һ��
	 * SystemFrequency / 1000000 1us�ж�һ��
	 */
	if (SysTick_Config(SystemCoreClock / 1000))	// Ĭ��1ms�ж�һ��
	{ 
		/* Capture error */ 
		while (1);
	}
}

/**
  * @brief  ����ֵ��һ
  * @param  None
  * @retval None
  * @attention  �� SysTick �жϺ��� SysTick_Handler()����
  */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}

#if 0
// ��� �̼��⺯�� �� core_cm3.h��
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
  // reload �Ĵ���Ϊ24bit�����ֵΪ2^24
	if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);
  
  // ���� reload �Ĵ����ĳ�ʼֵ	
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;
	
	// �����ж����ȼ�Ϊ 1<<4-1 = 15�����ȼ�Ϊ���
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1); 
	
	// ���� counter ��������ֵ
  SysTick->VAL   = 0;
	
	// ����systick ��ʱ��Ϊ 72M
	// ʹ���ж�
	// ʹ��systick
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    
  return (0); 
}
#endif

// couter ��1��ʱ�� ���� 1/systick_clk
// ��counter �� reload ��ֵ��С��0��ʱ��Ϊһ��ѭ��������������ж���ִ���жϷ������
// ͬʱ CTRL �� countflag λ����1
// ��һ��ѭ����ʱ��Ϊ reload * (1/systick_clk)

/**
  * @brief ��ʱn*10 us
  * @param None
  * @retval None
  */
void SysTick_Delay_10Us( __IO uint32_t us)
{
	uint32_t i;
	SysTick_Config(SystemCoreClock / 100000);
	
	for(i=0;i<us;i++)
	{
		// ����������ֵ��С��0��ʱ��CRTL�Ĵ�����λ16����1	
		while( !((SysTick->CTRL)&(1<<16)) );
	}
	// �ر�SysTick��ʱ��
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}

/**
  * @brief ��ʱn ms
  * @param None
  * @retval None
  */
void SysTick_Delay_Ms( __IO uint32_t ms)
{
	uint32_t i;	
	SysTick_Config(SystemCoreClock / 1000);
	
	for(i=0;i<ms;i++)
	{
		// ����������ֵ��С��0��ʱ��CRTL�Ĵ�����λ16����1
		// ����1ʱ����ȡ��λ����0
		while( !((SysTick->CTRL)&(1<<16)) );
	}
	// �ر�SysTick��ʱ��
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}
