/**
  ******************************************************************************
  * @file    usb_hal_config.h
  * @author  Jackie
  * @version V41.0
  * @date    2022-07-08
  * @brief   USB HID 初始化配置驱动
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_HAL_CONFIG_H
#define __USB_HAL_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "usb_type.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_pwr.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/

/* USB配置宏定义 */
#define USE_DETECT_PIN 0  // 是否使用插拔检测针脚

/* USB管脚定义 */
#define USB_PIN (GPIO_Pin_11 | GPIO_Pin_12)
#define USB_PIN_PORT GPIOA
#define USB_PIN_PORT_CLK RCC_APB2Periph_GPIOA
#define USB_PIN_PORT_CLK_FUNC RCC_APB2PeriphClockCmd

#if USE_DETECT_PIN
#define USB_DET_PIN GPIO_Pin_3
#define USB_DET_PIN_PORT GPIOB
#define USB_DET_PIN_PORT_CLK RCC_APB2Periph_GPIOB
#define USB_DET_PIN_PORT_CLK_FUNC RCC_APB2PeriphClockCmd
#endif

#define         ID1          (0x1FFFF7E8)
#define         ID2          (0x1FFFF7EC)
#define         ID3          (0x1FFFF7F0)

/* Exported functions ------------------------------------------------------- */
void USB_HIDDeviceConfig(void);
void USB_Cable_Config (FunctionalState NewState);
void Get_SerialNum(void);

#endif  /*__HW_CONFIG_H*/
