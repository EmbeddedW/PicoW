cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_testproject C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico2_w)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK
pico_sdk_init()

add_subdirectory(rtos)
#add_subdirectory(include)
#add_subdirectory(src)

include_directories(include)

set(SOURCES
    src/main.c
)

add_executable(my_app ${SOURCES})

target_link_libraries(my_app 
        freertos 
        pico_stdlib 
        pico_cyw43_arch_none
        #pico_cyw43_arch_lwip_threadsafe_background  
        hardware_spi)

pico_add_extra_outputs(my_app)


add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )
pico_enable_stdio_usb(my_app 0)
pico_enable_stdio_uart(my_app 1)
