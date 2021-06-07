cmake_minimum_required(VERSION 3.17)
project(Final_Project)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_BUILD_TYPE Debug)

SET(AVR_MCU "atmega32")
set(MCU_SPEED "16000000UL")

# Need To Add AVR8 Toolchains To Path, Located at AtmelStudio/Toolchains/avr8/bin
# Create & Use a New CMake Profile With Option -DCMAKE_TOOLCHAIN_FILE= AVR CMake File Found At @mkleemann/cmake-avr
SET(CMAKE_C_COMPILER avr-gcc)
SET(CMAKE_CXX_COMPILER avr-g++)
SET(CMAKE_C_FLAGS  "-Os -mmcu=${AVR_MCU} -DF_CPU=${MCU_SPEED}UL -std=gnu99 -Wl,--gc-sections")
SET(CMAKE_CXX_FLAGS "-Os -mmcu=${AVR_MCU} -DF_CPU=${MCU_SPEED}UL -Wl,--gc-sections")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

include_directories(Managers)
include_directories(Drivers)

SET(SOURCE_FILES
        main.c
        Drivers/ADC.c
        Drivers/DIO.c
        Drivers/Keypad.c
        Drivers/LCD.c
        Drivers/LED.c
        Drivers/LCD_config.h
        Drivers/Potentiometer.c
        Drivers/PWM.c
        Drivers/SPI.c
        Drivers/TC72.c
        Drivers/Timer.c
        Managers/DSP_Manager.c
        Managers/Heater_Control.c
        Managers/Mode_Config.c
        Managers/Schedular.c
        Managers/TMP_Manager.c
        )

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -R.eeprom ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load"  --change-section-lma .eeprom=0 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.eep)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-size ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} --mcu=${AVR_MCU} --format=avr)