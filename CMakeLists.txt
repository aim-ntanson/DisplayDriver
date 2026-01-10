idf_component_register(SRCS "Source/display_wrapper.c"
                            "Source/LCD1602_HD44780/lcd1602_hd4470.c"
                            "Source/ODED/ssd1306.c"
                       INCLUDE_DIRS "Source"
                                    "Source/LCD1602_HD44780"
                                    "Source/ODED"
                       PRIV_REQUIRES esp_driver_gpio)
