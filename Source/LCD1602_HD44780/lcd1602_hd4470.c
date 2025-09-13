#include "lcd1602_hd4470.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// Define GPIO operations for your platform here
// Example stub functions:

// LCD1602 commands


void lcd1602_init(void) 
{

}

void lcd1602_clear(void) 
{

}

void lcd1602_set_cursor(uint8_t row, uint8_t col) 
{

}

void lcd1602_write_char(char c) 
{
    
}

void lcd1602_write_string(const char *str) 
{

}

// Stub implementations for GPIO and delay (replace with your platform-specific code)
static void lcd_write_data(uint8_t data) 
{
    // Implement GPIO write for data
}

static void lcd_write_command(uint8_t cmd) 
{
    #if CHIP_USED == 1
    {
        //Set V0 pin
        GPIOPinSet(HD4470_V0_PORT, HD4470_V0_PIN);
        //Set RS pin
        GPIOPinSet(HD4470_RS_PORT, HD4470_RS_PIN);
        //Set RW pin
        GPIOPinSet(HD4470_RW_PORT, HD4470_RW_PIN);
        //Set E pin
        GPIOPinSet(HD4470_E_PORT, HD4470_E_PIN);

        //Set D4
        GPIOPinSet(HD4470_DATA_4_PORT, HD4470_DATA_4_PIN);
        //Set D5
        GPIOPinSet(HD4470_DATA_5_PORT, HD4470_DATA_5_PIN);
        //Set D6
        GPIOPinSet(HD4470_DATA_6_PORT, HD4470_DATA_6_PIN);
        //Set D7
        GPIOPinSet(HD4470_DATA_7_PORT, HD4470_DATA_7_PIN);
    }
    #else if CHIP_USED == 2
    {
        //DO NOTHING
    }
    #else
    {
        //DO NOTHING
    }
    #endif
}

static void lcd_delay_ms(uint32_t ms) 
{
    // Implement delay
}