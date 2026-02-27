#include "display_wrapper.h"
#include "LCD1602_HD44780/lcd1602_hd4470.h"
#include "display_config.h"

#ifdef LCD16x2_HD44780
#include "./LCD1602_HD44780/lcd1602_hd4470.h"
#endif // LCD16x2_HD44780

#ifdef OLED_SSD1306
#include "./ODED/ssd1306.h"
#endif // OLED_SSD1306

void display_init(void) {
#ifdef LCD16x2_HD44780
    lcd1602_init();
#endif // LCD16x2_HD44780

#ifdef OLED_SSD1306
    ssd1306_init();
#endif // OLED_SSD1306
}

void display_clear(void) {

#ifdef OLED_SSD1306
    ssd1306_clear();
#endif // OLED_SSD1306
}

void display_print(const char *str) {
#ifdef LCD16x2_HD44780
    lcd1602_clear();
    lcd1602_set_cursor(0, 0);
    lcd1602_write_data(str);

#endif // LCD16x2_HD44780

#ifdef OLED_SSD1306
    ssd1306_set_cursor(0, 0);
    ssd1306_print(str);
#endif // OLED_SSD1306
}
