#ifndef __SSD1306_H__
#define __SSD1306_H__

#include <stdint.h>

#define I2C_MASTER_NUM I2C_NUM_0

static const uint8_t init_sequence[] = {
    0x8D, 0x14, // Enable charge pump
    0xA8, 0x3F, // Set MUX Ratio
    0xD3, 0x00, // Set Display Offset
    0x40,       // Set Display Start Line to 0
    0xA1,       // Set Segment Re-map
    0xC8,       // Set COM Output Scan Direction
    0xDA, 0x12, // Set COM Pins Hardware Configuration
    0x81, 0x7F, // Set Contrast Control
    0xA4,       // Disable Entire Display On
    0xA6,       // Set Normal Display Mode
    0xD5, 0x80, // Set Display Clock Divide Ratio
    0xAF        // Turn the display ON
};


void ssd1306_init(void);
void ssd1306_send_command(uint8_t cmd);
void ssd1306_send_data(uint8_t data);
void ssd1306_clear(void);
void ssd1306_print(const char *str);
void ssd1306_set_cursor(uint8_t page, uint8_t column);

#endif // __SSD1306_H__
