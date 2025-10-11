#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "./../display_config.h"
#include "lcd1602_hd4470.h"

#ifdef TI_CHIPSET
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#endif // TI_CHIPSET

static void lcd_delay_ms(uint32_t ms) 
{
    // Implement delay
}

uint8_t lcd_read(void)
{
    

}

void lcd_write(uint16_t data)
{
    gpio_write(HD4470_RS_PORT, HD4470_RS_PIN, 0); // Command mode
    gpio_write(HD4470_RW_PORT, HD4470_RW_PIN, 0); // Write mode

    // Write high nibble
    gpio_write(HD4470_DATA_7_PORT, HD4470_DATA_7_PIN, data_7(data));
    gpio_write(HD4470_DATA_6_PORT, HD4470_DATA_6_PIN, data_6(data));
    gpio_write(HD4470_DATA_5_PORT, HD4470_DATA_5_PIN, data_5(data));
    gpio_write(HD4470_DATA_4_PORT, HD4470_DATA_4_PIN, data_4(data));

    // Pulse Enable
    gpio_write(HD4470_E_PORT, HD4470_E_PIN, HD4470_E_PIN);
    lcd_delay_ms(1);
    gpio_write(HD4470_E_PORT, HD4470_E_PIN, 0);

    // Write low nibble
    gpio_write(HD4470_DATA_7_PORT, HD4470_DATA_7_PIN, data_2(data));
    gpio_write(HD4470_DATA_6_PORT, HD4470_DATA_6_PIN, data_2(data));
    gpio_write(HD4470_DATA_5_PORT, HD4470_DATA_5_PIN, data_1(data));
    gpio_write(HD4470_DATA_4_PORT, HD4470_DATA_4_PIN, data_0(data));

    // Pulse Enable
    gpio_write(HD4470_E_PORT, HD4470_E_PIN, HD4470_E_PIN);
    lcd_delay_ms(1);
    gpio_write(HD4470_E_PORT, HD4470_E_PIN, 0);

    lcd_delay_ms(2); // Wait for command to complete
    
}

void lcd1602_init(void) 
{
    // Initialize GPIO pins for RS, RW, E, and data lines
    // Send initialization commands to LCD1602
    lcd_delay_ms(50); // Wait for LCD to power up
    lcd_write(0x28); // Function set: 4-bit, 2 lines, 5x8 dots
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
