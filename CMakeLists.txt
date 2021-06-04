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

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F411VETX_FLASH.ld Core/Src/Main/Main.cpp Core/Src/Main/Main.h Core/Src/Core/ui/display/Display.h Core/Src/STM32F411Disco-drivers/display/Nokia5510Display.cpp Core/Src/STM32F411Disco-drivers/display/Nokia5510Display.h Core/Src/STM32F411Disco-drivers/display/DisplayConfig.h Core/Src/Core/ui/display/PixelColor.h Core/Src/Core/ui/display/display-data/DisplayData.h Core/Src/Core/ui/display/display-refresher/DisplayRefresher.cpp Core/Src/Core/ui/display/display-refresher/DisplayRefresher.h Core/Src/Core/ui/display/drawable/Drawable.h Core/Src/Core/ui/display/pixel/Pixel.cpp Core/Src/Core/ui/display/pixel/Pixel.h Core/Src/Core/common/Vec2d/Vec2d.cpp Core/Src/Core/common/Vec2d/Vec2d.h Core/Src/Core/ui/display/drawable/texture.h Core/Src/Core/common/observers/ChangeObserver.h Core/Src/Core/ui/display/drawable/sprite/Sprite.cpp Core/Src/Core/ui/display/drawable/sprite/Sprite.h Core/Src/Core/ui/display/scene/Scene.cpp Core/Src/Core/ui/display/scene/Scene.h Core/Src/Core/ui/display/display-data-manager/DisplayDataManager.h Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.cpp Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.h Core/Src/Core/ui/display/drawable/texture-loader/TextureLoader.h Core/Src/STM32F411Disco-drivers/texture-loader/Stm32TextureLoader.cpp Core/Src/STM32F411Disco-drivers/texture-loader/Stm32TextureLoader.h Core/Src/Core/assets/egg.texture.h Core/Src/Core/assets/texture-asset.h Core/Src/Core/ui/display/drawable/text/Text.cpp Core/Src/Core/ui/display/drawable/text/Text.h Core/Src/Core/assets/text/standard-font.texture.h Core/Src/Core/runtime/context/Context.cpp Core/Src/Core/runtime/context/Context.h Core/Src/Core/runtime/stage/Stage.cpp Core/Src/Core/runtime/stage/Stage.h Core/Src/Core/common/observers/OnInput.h Core/Src/Core/stages/initial-loading/InitialLoading.cpp Core/Src/Core/stages/initial-loading/InitialLoading.h Core/Src/Core/time/time-monitor/TimeMonitor.cpp Core/Src/Core/time/time-monitor/TimeMonitor.h Core/Src/STM32F411Disco-drivers/time-monitor/Stm32TimeMonitor.cpp Core/Src/STM32F411Disco-drivers/time-monitor/Stm32TimeMonitor.h Core/Src/Core/sound/tone/Tone.h Core/Src/Core/sound/sound-player/SoundPlayer.cpp Core/Src/Core/sound/sound-player/SoundPlayer.h Core/Src/Core/sound/SoundPlayingStrategy.h Core/Src/STM32F411Disco-drivers/sound-playing-strategy/Stm32SoundPlayingStrategy.h Core/Src/Core/runtime/stage/Stage.cpp Core/Src/Core/runtime/stage/Stage.h Core/Src/Core/input/Input.cpp Core/Src/Core/input/Input.h Core/Src/STM32F411Disco-drivers/input/Stm32Input.cpp Core/Src/STM32F411Disco-drivers/input/Stm32Input.h Core/Src/Core/input/button.h Core/Src/Core/assets/common/icon-bar-background.texture.h Core/Src/Core/assets/common/icon-bar-big-icons.texture.h Core/Src/Core/store/services-store/ServicesStore.cpp Core/Src/Core/store/services-store/ServicesStore.h Core/Src/STM32F411Disco-drivers/stm32-services-store/Stm32ServicesStore.cpp Core/Src/STM32F411Disco-drivers/stm32-services-store/Stm32ServicesStore.h Core/Src/Core/game/model/datetime/Datetime.cpp Core/Src/Core/game/model/datetime/Datetime.h Core/Src/Core/game/model/datetime/date/Date.cpp Core/Src/Core/game/model/datetime/date/Date.h Core/Src/Core/game/model/datetime/time/Time.cpp Core/Src/Core/game/model/datetime/time/Time.h Core/Src/Core/game/model/pet-data/PetData.cpp Core/Src/Core/game/model/pet-data/PetData.h Core/Src/Core/game/model/pet-data/gender/gender.enum.h Core/Src/Core/game/model/pet-data/pet-phase/pet-phase.enum.h Core/Src/Core/game/model/pet-data/breed/breed.enum.h Core/Src/Core/game/model/game-state/GameState.cpp Core/Src/Core/game/model/game-state/GameState.h Core/Src/Core/stages/name-selection/NameSelection.cpp Core/Src/Core/stages/name-selection/NameSelection.h Core/Src/Core/common/util/displayPlacementUtils.h Core/Src/Core/common/util/displayPlacementUtils.cpp Core/Src/Core/assets/egg.texture.cpp Core/Src/Core/assets/common/icon-bar-big-icons.texture.cpp Core/Src/Core/assets/common/icon-bar-background.texture.cpp Core/Src/Core/stages/initial/time-selection/TimeSelection.cpp Core/Src/Core/stages/initial/time-selection/TimeSelection.h Core/Src/Core/ui/common-components/menu/Menu.cpp Core/Src/Core/ui/common-components/menu/Menu.h Core/Src/Core/assets/menu-cursor.texture.h Core/Src/Core/assets/menu-cursor.texture.cpp Core/Src/Core/assets/pet/first-male/baby/fir.st-male-baby.texture.h Core/Src/Core/assets/pet/first-male/baby/first-male-baby.texture.cpp Core/Src/Core/stages/main/Home.cpp Core/Src/Core/stages/main/Home.h Core/Src/Core/ui/common-components/action-icons/ActionIcons.cpp Core/Src/Core/ui/common-components/action-icons/ActionIcons.h Core/Src/Core/stages/menu/wash/Wash.cpp Core/Src/Core/stages/menu/wash/Wash.h Core/Src/Core/assets/menu/wash/wash.texture.h Core/Src/Core/assets/menu/wash/wash.texture.cpp Core/Src/Core/stages/menu/eat/Eat.cpp Core/Src/Core/stages/menu/eat/Eat.h Core/Src/Core/time/time-monitor/time-monitor-creator/TimeMonitorCreator.cpp Core/Src/Core/time/time-monitor/time-monitor-creator/TimeMonitorCreator.h Core/Src/STM32F411Disco-drivers/time-monitor/Stm32TimeMonitorCreator.cpp Core/Src/STM32F411Disco-drivers/time-monitor/Stm32TimeMonitorCreator.h Core/Src/Core/stages/menu/play/menu/PlayMenu.cpp Core/Src/Core/stages/menu/play/menu/PlayMenu.h Core/Src/Core/stages/menu/play/jumping-game/JumpingGame.cpp Core/Src/Core/stages/menu/play/jumping-game/JumpingGame.h Core/Src/Core/game/pet-db/pet-textures.h Core/Src/Core/game/pet-db/pet-identifier.h Core/Src/Core/game/pet-db/PetDb.cpp Core/Src/Core/game/pet-db/PetDb.h Core/Src/Core/game/model/pet-texture/PetTexture.cpp Core/Src/Core/game/model/pet-texture/PetTexture.h Core/Src/Core/game/pet-db/pet-texture-variant.h Core/Src/Core/assets/menu/eat/meal/meal.texture.h Core/Src/Core/assets/menu/eat/meal/meal.texture.cpp Core/Src/Core/stages/menu/eat/pick-food/PickFood.cpp Core/Src/Core/stages/menu/eat/pick-food/PickFood.h Core/Src/Core/stages/menu/eat/meal-type.h Core/Src/Core/stages/menu/eat/pick-food/eat-food-state.h Core/Src/Core/assets/pet/misc/misc.texture.h Core/Src/Core/assets/pet/misc/misc.texture.cpp Core/Src/Core/ui/common-components/happy-jump/HappyJump.cpp Core/Src/Core/ui/common-components/happy-jump/HappyJump.h Core/Src/Core/stages/menu/stats/page-one/PageOne.cpp Core/Src/Core/stages/menu/stats/page-one/PageOne.h Core/Src/Core/stages/menu/stats/page-two/PageTwo.cpp Core/Src/Core/stages/menu/stats/page-two/PageTwo.h Core/Src/Core/game/random-events-generator/RandomEventsGenerator.cpp Core/Src/Core/game/random-events-generator/RandomEventsGenerator.h Core/Src/Core/stages/menu/heal/Heal.cpp Core/Src/Core/stages/menu/heal/Heal.h Core/Src/Core/assets/menu/heal/heal.texture.h Core/Src/Core/assets/menu/heal/heal.texture.cpp Core/Src/Core/stages/menu/lamp/Lamp.cpp Core/Src/Core/stages/menu/lamp/Lamp.h Core/Src/Core/stages/time/TimeView.cpp Core/Src/Core/stages/time/TimeView.h)

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
