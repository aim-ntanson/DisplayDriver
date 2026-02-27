file(READ "${CMAKE_CURRENT_LIST_DIR}/Source/display_config.h" CONFIG_CONTENT)

set(SOURCES "Source/display_wrapper.c")

# Check for OLED_SSD1306 definition
string(REGEX MATCH "#define[ \t]+OLED_SSD1306" OLED_SSD1306_DEFINED "${CONFIG_CONTENT}")
if(OLED_SSD1306_DEFINED)
    list(APPEND SOURCES "Source/ODED/ssd1306.c")
    message(STATUS "DisplayDriver: Enabled OLED_SSD1306")
endif()

# Check for LCD16x2_HD44780 definition
string(REGEX MATCH "#define[ \t]+LCD16x2_HD44780" LCD16x2_HD44780_DEFINED "${CONFIG_CONTENT}")
if(LCD16x2_HD44780_DEFINED)
    list(APPEND SOURCES "Source/LCD1602_HD44780/lcd1602_hd4470.c")
    message(STATUS "DisplayDriver: Enabled LCD16x2_HD44780")
endif()

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS "Source"
                                    "Source/LCD1602_HD44780"
                                    "Source/ODED"
                       PRIV_REQUIRES esp_driver_gpio
                                     driver
                                     freertos)
