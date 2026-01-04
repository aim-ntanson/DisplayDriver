#include "ssd1306.h"
#include "../chipset_wrapper.h" // For write_gpio if supported, simplified assumption below
#include "../display_config.h"
#include <stdint.h>

// Externally defined helper functions (per requirements)
extern void ssd1306_send_command(uint8_t cmd);
extern void delay_us(uint32_t us);
extern void delay_ms(uint32_t ms);

void ssd1306_init(void) {
  // Hardware Power-On and Reset Sequence
  // Assume VDD is already enabled

  // Drive the RES# pin LOW for at least 3us
  write_gpio(SSD1306_RES_PORT, SSD1306_RES_PIN, 0);
  delay_us(3);

  // Drive the RES# pin HIGH
  write_gpio(SSD1306_RES_PORT, SSD1306_RES_PIN, 1);

  // Wait at least 3us before enabling VCC (internally controlled assumption)
  delay_us(3);

  // Wait until VCC is stable (Generic wait, standard init often uses 100ms for
  // power stabilization if unsure) Requirement says "Wait until VCC is stable
  // before sending any commands" - assume delay_ms(100) covers this or already
  // stable.
  delay_ms(100);

  // Software Initialization Command Sequence

  // Enable charge pump
  ssd1306_send_command(0x8D); // Charge pump setting
  ssd1306_send_command(0x14); // Enable charge pump

  // Panel configuration
  ssd1306_send_command(0xA8); // Set MUX Ratio
  ssd1306_send_command(0x3F); // 64 MUX
  ssd1306_send_command(0xD3); // Set Display Offset
  ssd1306_send_command(0x00); // Offset 0
  ssd1306_send_command(0x40); // Set Display Start Line to 0

  // Hardware configuration
  ssd1306_send_command(0xA1); // Set Segment Re-map: column 127 mapped to SEG0
  ssd1306_send_command(0xC8); // Set COM Output Scan Direction: remapped mode
  ssd1306_send_command(0xDA); // Set COM Pins Hardware Configuration
  ssd1306_send_command(
      0x12); // Sequential COM pin config, disable COM Left/Right remap

  // Display configuration
  ssd1306_send_command(0x81); // Set Contrast Control
  ssd1306_send_command(0x7F); // Default value
  ssd1306_send_command(
      0xA4); // Disable Entire Display On (Resume to RAM content)
  ssd1306_send_command(0xA6); // Set Normal Display Mode (non-inverted)

  // Clock configuration
  ssd1306_send_command(
      0xD5); // Set Display Clock Divide Ratio/Oscillator Frequency
  ssd1306_send_command(0x80); // Divide ratio = 1, Osc freq = default

  // Turn the display ON
  ssd1306_send_command(0xAF);

  // Wait at least 100ms after enabling the display
  delay_ms(100);
}
