################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.cpp 

OBJS += \
./Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.o 

CPP_DEPS += \
./Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.o: ../Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../USB_HOST/App -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

