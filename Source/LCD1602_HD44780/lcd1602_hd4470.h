#ifndef __LCD1602_HD4470_H__
#define __LCD1602_HD4470_H__

#include <stdint.h>

#include "./../display_wrapper.h"
#include "./../chipset_wrapper.h"

// LCD1602 PIN configuration
#define HD4470_V0_PORT      WRAPPER_V0_PORT  // Register Select pin
#define HD4470_V0_PIN       WRAPPER_V0_PIN  // Register Select pin

#define HD4470_RS_PORT      WRAPPER_RS_PORT  // Register Select pin
#define HD4470_RS_PIN       WRAPPER_RS_PIN  // Register Select pin

#define HD4470_RW_PORT      WRAPPER_RW_PORT  // Read/Write pin
#define HD4470_RW_PIN       WRAPPER_RW_PIN  // Read/Write pin

#define HD4470_E_PORT       WRAPPER_E_PORT  // Enable pin
#define HD4470_E_PIN        WRAPPER_E_PIN  // Enable pin

#define HD4470_DATA_4_PORT      WRAPPER_DATA_4_PORT     // cmt
#define HD4470_DATA_4_PIN       WRAPPER_DATA_4_PIN      // cmt

#define HD4470_DATA_5_PORT      WRAPPER_DATA_5_PORT     // cmt
#define HD4470_DATA_5_PIN       WRAPPER_DATA_5_PIN      // cmt

#define HD4470_DATA_6_PORT      WRAPPER_DATA_6_PORT     // cmt
#define HD4470_DATA_6_PIN       WRAPPER_DATA_6_PIN      // cmt

#define HD4470_DATA_7_PORT      WRAPPER_DATA_7_PORT     // cmt
#define HD4470_DATA_7_PIN       WRAPPER_DATA_7_PIN      // cmt

// LCD1602 commands
#define SET_V0_PIN (HD4470_V0_PIN | 0x00) 


//INTRUCSTIONS

// RS_RW DATA
#define RS_RW_CLEARDISPLAY                0x00    // 0000 0000
#define RS_RW_RETURNHOME                  0x00    // 0000 0000
#define RS_RW_ENTRYMODESET                0x00    // 0000 0000
#define RS_RW_DISPLAYCONTROL              0x00    // 0000 0000
#define RS_RW_CURSORSHIFT                 0x00    // 0000 0000
#define RS_RW_FUNCTIONSET                 0x00    // 0000 0000
#define RS_RW_SETCGRAMADDR                0x00    // 0000 0000
#define RS_RW_SETDDRAMADDR                0x00    // 0000 0000
#define RS_RW_READ_BUSYFLAG_ADDCOUNTER    0x00    // 0000 0000

#define RS_RW_WRITE                      0x02    // 0000 0000
#define RS_RW_READ                       0x03    // 0000 0100   


// ======================
// Instruction bit fields
// ======================

// Entry Mode Set (0x04 | I/D<<1 | S)
#define LCD_ENTRYMODE      0x04
#define LCD_ID_INC         0x02  // I/D = 1: Increment
#define LCD_ID_DEC         0x00  // I/D = 0: Decrement
#define LCD_S_SHIFT        0x01  // S = 1: Accompanies display shift
#define LCD_S_NOSHIFT      0x00  // S = 0: No shift

// Cursor / Display Shift (0x10 | S/C<<3 | R/L<<2)
#define LCD_SHIFT          0x10
#define LCD_SC_DISPLAY     0x08  // S/C = 1: Display shift
#define LCD_SC_CURSOR      0x00  // S/C = 0: Cursor move
#define LCD_RL_RIGHT       0x04  // R/L = 1: Shift right
#define LCD_RL_LEFT        0x00  // R/L = 0: Shift left

// Function Set (0x20 | DL<<4 | N<<3 | F<<2)
#define LCD_FUNCTION       0x20
#define LCD_DL_8BIT        0x10  // DL = 1: 8-bit
#define LCD_DL_4BIT        0x00  // DL = 0: 4-bit
#define LCD_N_2LINE        0x08  // N = 1: 2-line
#define LCD_N_1LINE        0x00  // N = 0: 1-line
#define LCD_F_5x10         0x04  // F = 1: 5x10 font
#define LCD_F_5x8          0x00  // F = 0: 5x8 font

// Display ON/OFF Control (0x08 | D<<2 | C<<1 | B)
#define LCD_DISPLAYCTRL    0x08
#define LCD_DISPLAY_ON     0x04
#define LCD_DISPLAY_OFF    0x00
#define LCD_CURSOR_ON      0x02
#define LCD_CURSOR_OFF     0x00
#define LCD_BLINK_ON       0x01
#define LCD_BLINK_OFF      0x00

// Clear / Home
#define LCD_CLEAR          0x01
#define LCD_HOME           0x02

// Busy Flag
#define LCD_BF_BUSY        0x80  // BF = 1: busy
#define LCD_BF_READY       0x00  // BF = 0: ready

// Function prototypes
void lcd1602_init(void);
static void lcd1602_clear(void);
static void lcd_write_command(uint8_t cmd_data);
static void lcd_write_data(uint8_t data);
static void lcd_delay_ms(uint32_t ms);
static void falling_edge(void);
static void send_4bit(uint8_t data); 
static void send_8bit(uint8_t data); 
#endif // LCD1602_HD4470_H
