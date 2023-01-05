# STM32-LoRa-E5-stm32wle5jc
steps to implement LoRa-e5 as MCU

# Step-1 #
Markup : * Download required softwares
            * Arduino IDE
            * STM32CubeProgrammer
# Step-2 #
Markup : * Collecting required devices
            * ST-LINK/V2-1 (or any other STM32 nucleo board)
            * STM32WLE5JC
            * Jumber cables

# Step-3 #
Markup : * Removing Protection
            * Open STM32CubeProgrammer
            * ST-Link --> connect
            * Goto Option Bytes
            * Open Read Out Protection
            * select RDP value to "AA" then Apply
# Step-4 #
Markup : * Programming with Arduino IDE
            * set the preferances --> https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json
            * Boards manager --> stm32 MCU based Boards --> Install
            * select board as --> Generic STM32wl series
            * Board part number --> Generic Node SE (TTI)
            * select Port of ST-Link
            * upload the code
            
