#ifndef LCD1602_HD4470_H
#define LCD1602_HD4470_H

#include <stdint.h>
#include <display_wrapper.h>

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

// Function prototypes
void lcd1602_init(void);
static void lcd_write_command(uint8_t cmd);
static void lcd_write_data(uint8_t data);

#endif // LCD1602_HD4470_H
