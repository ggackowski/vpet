#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.17)

# specify cross compilers and tools
set(CMAKE_C_COMPILER /home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/compilers/tools/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/compilers/tools/bin/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  /home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/compilers/tools/bin/arm-none-eabi-gcc)
set(CMAKE_AR /home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/compilers/tools/bin/arm-none-eabi-ar)
set(CMAKE_OBJCOPY /home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/compilers/tools/bin/arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP /home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/compilers/tools/bin/arm-none-eabi-objdump)
set(SIZE /home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/compilers/tools/bin/arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# project settings
project(vpet C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

#Uncomment for hardware floating point
#add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
#add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
#add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

#Uncomment for software floating point
#add_compile_options(-mfloat-abi=soft)

add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

# uncomment to mitigate c++17 absolute addresses warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()

include_directories(USB_HOST/App USB_HOST/Target Core/Inc Drivers/STM32F4xx_HAL_Driver/Inc Drivers/STM32F4xx_HAL_Driver/Inc/Legacy Middlewares/ST/STM32_USB_Host_Library/Core/Inc Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc Drivers/CMSIS/Device/ST/STM32F4xx/Include Drivers/CMSIS/Include)

add_definitions(-DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG)

file(GLOB_RECURSE SOURCES "USB_HOST/*.*" "Core/*.*" "Middlewares/*.*" "Drivers/*.*")

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F411VETX_FLASH.ld Core/Src/Main/Main.cpp Core/Src/Main/Main.h Core/Src/Core/ui/display/Display.h Core/Src/STM32F411Disco-drivers/display/Nokia5510Display.cpp Core/Src/STM32F411Disco-drivers/display/Nokia5510Display.h Core/Src/STM32F411Disco-drivers/display/DisplayConfig.h Core/Src/Core/ui/display/PixelColor.h Core/Src/Core/ui/display/display-data/DisplayData.h Core/Src/Core/ui/display/display-refresher/DisplayRefresher.cpp Core/Src/Core/ui/display/display-refresher/DisplayRefresher.h Core/Src/Core/ui/display/drawable/Drawable.h Core/Src/Core/ui/display/pixel/Pixel.cpp Core/Src/Core/ui/display/pixel/Pixel.h Core/Src/Core/common/Vec2d/Vec2d.cpp Core/Src/Core/common/Vec2d/Vec2d.h Core/Src/Core/ui/display/drawable/texture.h Core/Src/Core/common/observers/ChangeObserver.h Core/Src/Core/ui/display/drawable/sprite/Sprite.cpp Core/Src/Core/ui/display/drawable/sprite/Sprite.h Core/Src/Core/ui/display/scene/Scene.cpp Core/Src/Core/ui/display/scene/Scene.h Core/Src/Core/ui/display/display-data-manager/DisplayDataManager.h Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.cpp Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.h Core/Src/Core/ui/display/drawable/texture-loader/TextureLoader.h Core/Src/STM32F411Disco-drivers/texture-loader/Stm32TextureLoader.cpp Core/Src/STM32F411Disco-drivers/texture-loader/Stm32TextureLoader.h Core/Src/Core/assets/egg.texture.h Core/Src/Core/assets/texture-asset.h Core/Src/Core/ui/display/drawable/text/Text.cpp Core/Src/Core/ui/display/drawable/text/Text.h Core/Src/Core/assets/text/standard-font.texture.h Core/Src/Core/runtime/context/Context.cpp Core/Src/Core/runtime/context/Context.h Core/Src/Core/runtime/stage/Stage.cpp Core/Src/Core/runtime/stage/Stage.h Core/Src/Core/common/observers/OnInput.h Core/Src/Core/stages/initial-loading/InitialLoading.cpp Core/Src/Core/stages/initial-loading/InitialLoading.h Core/Src/Core/time/time-monitor/TimeMonitor.cpp Core/Src/Core/time/time-monitor/TimeMonitor.h Core/Src/STM32F411Disco-drivers/time-monitor/Stm32TimeMonitor.cpp Core/Src/STM32F411Disco-drivers/time-monitor/Stm32TimeMonitor.h Core/Src/Core/sound/tone/Tone.h Core/Src/Core/sound/sound-player/SoundPlayer.cpp Core/Src/Core/sound/sound-player/SoundPlayer.h Core/Src/Core/sound/SoundPlayingStrategy.h Core/Src/STM32F411Disco-drivers/sound-playing-strategy/Stm32SoundPlayingStrategy.h Core/Src/Core/runtime/stage/Stage.cpp Core/Src/Core/runtime/stage/Stage.h Core/Src/Core/input/Input.cpp Core/Src/Core/input/Input.h Core/Src/STM32F411Disco-drivers/input/Stm32Input.cpp Core/Src/STM32F411Disco-drivers/input/Stm32Input.h Core/Src/Core/input/button.h)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")
