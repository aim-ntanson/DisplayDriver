
## Write mode for IIC
- 8.1.5.2 Write mode for I2C

```mermaid
sequenceDiagram
participant mcu as MCU
participant oled as SSD306

mcu ->> oled: initiates the data communication
note over mcu, oled: start condition: SDA up --> down, CLK up

mcu ->> oled: slave address “b0111100” or “b0111101”




```

```mermaid
flowchart TD;




```