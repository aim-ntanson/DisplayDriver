#include "display_wrapper.h"
#include "display_config.h"

#ifdef LCD16x2_HD44780
#include "./LCD1602_HD44780/lcd1602_hd4470.h"
#endif //LCD16x2_HD44780

void display_init(void) {
#ifdef LCD16x2_HD44780
    lcd1602_init();
#endif //LCD16x2_HD44780

}

void display_clear(void) {
    //todo
}

void display_print(const char *str) {
    //todo
}
