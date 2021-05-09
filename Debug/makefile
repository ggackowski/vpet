################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_HOST/Target/subdir.mk
-include USB_HOST/App/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/STM32F411Disco-drivers/time-monitor/subdir.mk
-include Core/Src/STM32F411Disco-drivers/texture-loader/subdir.mk
-include Core/Src/STM32F411Disco-drivers/stm32-services-store/subdir.mk
-include Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/subdir.mk
-include Core/Src/STM32F411Disco-drivers/input/subdir.mk
-include Core/Src/STM32F411Disco-drivers/display/subdir.mk
-include Core/Src/Main/subdir.mk
-include Core/Src/Core/ui/display/scene/subdir.mk
-include Core/Src/Core/ui/display/pixel/subdir.mk
-include Core/Src/Core/ui/display/drawable/text/subdir.mk
-include Core/Src/Core/ui/display/drawable/sprite/subdir.mk
-include Core/Src/Core/ui/display/display-refresher/subdir.mk
-include Core/Src/Core/time/time-monitor/subdir.mk
-include Core/Src/Core/store/services-store/subdir.mk
-include Core/Src/Core/stages/initial-loading/subdir.mk
-include Core/Src/Core/sound/sound-player/subdir.mk
-include Core/Src/Core/runtime/stage/subdir.mk
-include Core/Src/Core/runtime/context/subdir.mk
-include Core/Src/Core/input/subdir.mk
-include Core/Src/Core/game/model/pet-data/subdir.mk
-include Core/Src/Core/game/model/game-state/subdir.mk
-include Core/Src/Core/game/model/datetime/time/subdir.mk
-include Core/Src/Core/game/model/datetime/date/subdir.mk
-include Core/Src/Core/game/model/datetime/subdir.mk
-include Core/Src/Core/common/Vec2d/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
vpet.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
vpet.list \

OBJCOPY_BIN += \
vpet.bin \


# All Target
all: vpet.elf secondary-outputs

# Tool invocations
vpet.elf: $(OBJS) $(USER_OBJS) /home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/STM32F411VETX_FLASH.ld
	arm-none-eabi-g++ -o "vpet.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/grzegorz/STM32CubeIDE/workspace_1.4.0/vpet/STM32F411VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="vpet.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

vpet.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "vpet.list"
	@echo 'Finished building: $@'
	@echo ' '

vpet.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "vpet.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
