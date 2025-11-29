#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "./../display_config.h"
#include "lcd1602_hd4470.h"
#include "chipset_wrapper.h"

static void lcd_delay_ms(uint32_t ms) 
{
    delay(ms);
}

void falling_edge(void)
{
    write_gpio(HD4470_E_PORT, HD4470_E_PIN, 0);
    write_gpio(HD4470_E_PORT, HD4470_E_PIN, HD4470_E_PIN);
    write_gpio(HD4470_E_PORT, HD4470_E_PIN, 0);
    // lcd_delay_ms(1);
}

void send_4bit(uint8_t data)
{
    write_gpio(HD4470_DATA_4_PORT, HD4470_DATA_4_PIN,  (data << 4u) & 0x10);
    write_gpio(HD4470_DATA_5_PORT, HD4470_DATA_5_PIN,  (data << 4u) & 0x20);
    write_gpio(HD4470_DATA_6_PORT, HD4470_DATA_6_PIN,  (data << 4u) & 0x40);
    write_gpio(HD4470_DATA_7_PORT, HD4470_DATA_7_PIN,  (data << 4u) & 0x80);

}

void send_8bit(uint8_t data)
{
    //todo
}

uint8_t lcd_read(void)
{
    //todo

}

static void lcd_write_command(uint8_t RS_RW_cmd, uint8_t cmd_data)
{
    write_gpio(HD4470_RS_PORT, HD4470_RS_PIN, RS_RW_cmd & 0x01); // Command mode
    write_gpio(HD4470_RW_PORT, HD4470_RW_PIN, RS_RW_cmd & 0x02); // Command mode

#if LCD16x2_NUM_PINS_DATA == 4
    send_4bit(cmd_data >> 4);    
    send_4bit(cmd_data);
#endif

}


void lcd_write_data(uint8_t data)
{
    write_gpio(HD4470_RS_PORT, HD4470_RS_PIN, 1); // Command mode
    write_gpio(HD4470_RS_PORT, HD4470_RW_PIN, 0); // Command mode

#if LCD16x2_NUM_PINS_DATA == 4
    send_4bit(data >> 4);
    send_4bit(data);
#endif

}


void lcd1602_init(void) 
{
    

    write_gpio(HD4470_E_PORT,  HD4470_E_PIN,  0);
    write_gpio(HD4470_RS_PORT, HD4470_RS_PIN, 0);
    lcd_delay_ms(50); // Wait for LCD to power up
     falling_edge();
#if LCD16x2_NUM_PINS_DATA == 4
    send_4bit(0x03);
    lcd_delay_ms(4);
    send_4bit(0x03);
    lcd_delay_ms(1);
    send_4bit(0x03);
        
//     falling_edge();
     send_4bit(0x02);
//     falling_edge();
#endif

    lcd_write_command(RS_RW_MODE_FUCTION, FUNCTION_SET | DL_4BIT | N_2LINE | F_5x8);
    lcd_delay_ms(7);

    lcd_write_command(RS_RW_MODE_FUCTION, DISPLAY_CTRL | DISPLAY_ON | CURSOR_OFF);
    lcd_delay_ms(1);

    lcd1602_clear();

    lcd_write_command(RS_RW_MODE_FUCTION, ENTRYMODE | ID_INCREASE | S_SHIFT);
    lcd_delay_ms(5);


    falling_edge();

}

void lcd1602_clear(void) 
{
    falling_edge();
    lcd_write_command(RS_RW_MODE_FUCTION, LCD_CLEAR);
    lcd_delay_ms(5);
}

void lcd1602_set_cursor(uint8_t row, uint8_t col) 
{
    uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    lcd_write_command(RS_RW_MODE_FUCTION, SET_DDRAM_ADDR | (row_offsets[row] + col));
    lcd_delay_ms(5);
}

void lcd1602_return_home(void) 
{
    lcd_write_command(RS_RW_MODE_FUCTION, LCD_HOME);
}
