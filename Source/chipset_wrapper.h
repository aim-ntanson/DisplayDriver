#ifndef __CHIPSET_WRAPPER_H__
#define __CHIPSET_WRAPPER_H__

#include "display_config.h"

#include <stdint.h>
#include <stdbool.h>

#ifdef TI_CHIPSET
// #include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "sysctl.h"
#endif // TI_CHIPSET

// extern volatile uint32_t g_ui32SysTickCount;

/**
 * @brief Write a value to GPIO pin(s) in a chipset-agnostic way.
 *
 * @param ui32Port The GPIO port base address or identifier.
 * @param ui8Pins The GPIO pin(s) to write to.
 * @param ui8Val The value to write to the pin(s) (typically 0 or 1).
 */
static inline void write_gpio(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val) {
#ifdef TI_CHIPSET
    GPIOPinWrite(ui32Port, ui8Pins, ui8Val);
#elif defined(STM_CHIPSET)
    HAL_GPIO_WritePin((GPIO_TypeDef*)ui32Port, ui8Pins, ui8Val);
#else
    #error "No supported chipset defined"
#endif
}

static inline void delay(uint32_t ms) {
#ifdef TI_CHIPSET
    // Reset counter
    // g_ui32SysTickCount = 0;
    
    // while(g_ui32SysTickCount < ms)
    // {
    // }
    // SysCtlDelay(15000000);
#elif defined(STM_CHIPSET)
    HAL_Delay(ms);
#else
    #error "No supported chipset defined"
#endif
}


#endif //__CHIPSET_WRAPPER__
