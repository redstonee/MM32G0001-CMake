cmake_minimum_required(VERSION 3.20)

# Set the toolchain location if using Windows
set(TOOLCHAIN_PREFIX "D:/SDKs/gcc-arm-5.4 2016q3")

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/toolchain-arm-none-eabi.cmake)

project(fuckMM32)

enable_language(ASM)
enable_language(C)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the include directories
include_directories(${CMAKE_CURRENT_LIST_DIR}/Device/CMSIS/Core/Include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/Device/MM32G0001/Include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/Device/MM32G0001/HAL_Lib/inc)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# Set the source directories
set(HAL_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/Device/MM32G0001/HAL_Lib/src)
set(USER_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)

# Add source files
set (HAL_SRCS
        ${HAL_SRC_DIR}/hal_adc.c
        ${HAL_SRC_DIR}/hal_crc.c
        ${HAL_SRC_DIR}/hal_dbg.c
        ${HAL_SRC_DIR}/hal_exti.c
        ${HAL_SRC_DIR}/hal_flash.c
        ${HAL_SRC_DIR}/hal_gpio.c
        ${HAL_SRC_DIR}/hal_i2c.c
        ${HAL_SRC_DIR}/hal_iwdg.c
        ${HAL_SRC_DIR}/hal_misc.c
        ${HAL_SRC_DIR}/hal_pwr.c
        ${HAL_SRC_DIR}/hal_rcc.c
        ${HAL_SRC_DIR}/hal_spi.c
        ${HAL_SRC_DIR}/hal_tim.c
        ${HAL_SRC_DIR}/hal_uid.c
        ${HAL_SRC_DIR}/hal_usart.c
)

set (USER_SRCS
        ${USER_SRC_DIR}/fuck.cpp
        ${USER_SRC_DIR}/mm32g0001_it.c
)

set(SYSTEM_SRC 
        ${CMAKE_CURRENT_LIST_DIR}/Device/MM32G0001/Source/system_mm32g0001.c
        ${CMAKE_CURRENT_LIST_DIR}/Device/MM32G0001/Source/startup_mm32g0001_gcc.s
        ${CMAKE_CURRENT_LIST_DIR}/Device/MM32G0001/Source/delay.c
)


add_executable(${CMAKE_PROJECT_NAME}.elf 
        ${HAL_SRCS}
        ${USER_SRCS}
        ${SYSTEM_SRC}
)

add_compile_definitions(
        USE_STDPERIPH_DRIVER
)

set(LD_SCRIPT_PATH ${CMAKE_CURRENT_LIST_DIR}/ldscript.ld)
get_filename_component(LD_SCRIPT_PATH_ABS ${LD_SCRIPT_PATH} ABSOLUTE)

set_target_properties(${CMAKE_PROJECT_NAME}.elf PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        LINK_DEPENDS ${LD_SCRIPT_PATH_ABS}
        LINK_FLAGS "-T \"${LD_SCRIPT_PATH_ABS}\""
)

add_custom_target(
        createBinFile ALL
        ${TOOLCHAIN_PREFIX}/bin/${TOOLCHAIN}-objcopy -Obinary
        "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf"
        "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.bin"
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf
)

add_custom_target(
        showSize ALL
        ${TOOLCHAIN_PREFIX}/bin/${TOOLCHAIN}-size "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf"
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf)