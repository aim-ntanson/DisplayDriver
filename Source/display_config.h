#ifndef __DISPLAY_CONFIG_H__
#define __DISPLAY_CONFIG_H__

#include "hw_memmap.h"
/**
 * Config display is used
 * - LCD1602 with HD44780 controller: LCD16x2_HD44780
 * - OLED SSD1306 controller: OLED_SSD1306
 * 
 */
#define LCD16x2_HD44780 // replace this define for other display

/**
 * Config chipset
 * - TI_CHIPSET
 * - STM_CHIPSET
 */
#define TI_CHIPSET // replace this define for other chip set


#ifdef LCD16x2_HD44780
// Configuration for LCD1602 with HD44780 controller
#define LCD16x2_NUM_PINS_DATA 4 // 4 or 8 data pins

#define WRAPPER_V0_PIN      GPIO_PIN_3
#define WRAPPER_V0_PORT     GPIO_PORTE_BASE

#define WRAPPER_RS_PIN      GPIO_PIN_1
#define WRAPPER_RS_PORT     GPIO_PORTE_BASE

#define WRAPPER_RW_PIN      GPIO_PIN_2
#define WRAPPER_RW_PORT     GPIO_PORTE_BASE

#define WRAPPER_E_PIN       GPIO_PIN_3
#define WRAPPER_E_PORT      GPIO_PORTE_BASE

#if LCD16x2_NUM_PINS_DATA == 8
#define WRAPPER_DATA_0_PORT   GPIO_PIN_0
#define WRAPPER_DATA_0_PIN    GPIO_PIN_0

#define WRAPPER_DATA_1_PORT   GPIO_PIN_1
#define WRAPPER_DATA_1_PIN    GPIO_PIN_1

#define WRAPPER_DATA_2_PORT   GPIO_PIN_2
#define WRAPPER_DATA_2_PIN    GPIO_PIN_2

#define WRAPPER_DATA_3_PORT   GPIO_PIN_3
#define WRAPPER_DATA_3_PIN    GPIO_PIN_3

#define WRAPPER_DATA_4_PORT   GPIO_PIN_4
#define WRAPPER_DATA_4_PIN    GPIO_PIN_4

#define WRAPPER_DATA_5_PORT   GPIO_PIN_5
#define WRAPPER_DATA_5_PIN    GPIO_PIN_5

#define WRAPPER_DATA_6_PORT   GPIO_PIN_6
#define WRAPPER_DATA_6_PIN    GPIO_PIN_6

#define WRAPPER_DATA_7_PORT   GPIO_PIN_7
#define WRAPPER_DATA_7_PIN    GPIO_PIN_7

#else // 4-bit mode
#define WRAPPER_DATA_4_PORT   GPIO_PORTC_BASE
#define WRAPPER_DATA_4_PIN    GPIO_PIN_4

#define WRAPPER_DATA_5_PORT   GPIO_PORTC_BASE
#define WRAPPER_DATA_5_PIN    GPIO_PIN_5

#define WRAPPER_DATA_6_PORT   GPIO_PORTC_BASE
#define WRAPPER_DATA_6_PIN    GPIO_PIN_6

#define WRAPPER_DATA_7_PORT   GPIO_PORTC_BASE
#define WRAPPER_DATA_7_PIN    GPIO_PIN_7

#endif // LCD data pins mode
#endif // LCD16x2_HD44780

#endif // __DISPLAY_CONFIG_H__
