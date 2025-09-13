#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "display_config.h"
#include "lcd1602_hd4470.h"

#ifdef PLATFORM_TI
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#endif // PLATFORM_TI

void lcd1602_init(void) 
{
    // Initialize GPIO pins for RS, RW, E, and data lines
    // Send initialization commands to LCD1602
    lcd_delay_ms(50); // Wait for LCD to power up
    lcd_write_command(0x38); // Function set: 8-bit, 2 lines, 5x8 dots
    lcd_delay_ms(5);    // Wait
    lcd_write_command(0x0C); // Display ON, Cursor OFF
    lcd_delay_ms(5);    // Wait
    lcd_write_command(0x01); // Clear display
    lcd_delay_ms(5);    // Wait
    lcd_write_command(0x06); // Entry mode set: Increment cursor
    lcd_delay_ms(5);    // Wait


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
    write_gpio(GPIO_PORT_DATA, LCD_DATA_PINS, data);

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