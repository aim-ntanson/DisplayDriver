#ifndef __DISPLAY_WRAPPER_H__
#define __DISPLAY_WRAPPER_H__

#include <stdint.h>

static void display_write_command(uint8_t cmd);
void display_init(void);
void display_clear(void);
void display_print(const char* str);

#endif // __DISPLAY_WRAPPER_H__
