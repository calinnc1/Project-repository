################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Mcu/mcu.c \
../Bsw/MCal/Mcu/stm32f3xx_hal.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_cortex.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_exti.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_msp.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_rcc.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.c \
../Bsw/MCal/Mcu/stm32f3xx_it.c \
../Bsw/MCal/Mcu/syscalls.c \
../Bsw/MCal/Mcu/sysmem.c 

OBJS += \
./Bsw/MCal/Mcu/mcu.o \
./Bsw/MCal/Mcu/stm32f3xx_hal.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_exti.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_msp.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.o \
./Bsw/MCal/Mcu/stm32f3xx_it.o \
./Bsw/MCal/Mcu/syscalls.o \
./Bsw/MCal/Mcu/sysmem.o 

C_DEPS += \
./Bsw/MCal/Mcu/mcu.d \
./Bsw/MCal/Mcu/stm32f3xx_hal.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_exti.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_msp.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.d \
./Bsw/MCal/Mcu/stm32f3xx_it.d \
./Bsw/MCal/Mcu/syscalls.d \
./Bsw/MCal/Mcu/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Mcu/%.o Bsw/MCal/Mcu/%.su: ../Bsw/MCal/Mcu/%.c Bsw/MCal/Mcu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Mcu" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Adc" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Fls" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/I2c" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Pwr" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Spi" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Uart" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Dio" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Dma" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Gpt" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/EcuM" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/BswM" -I"C:/Work/Embedded/SVN/avProj/Config" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Int" -I"C:/Work/Embedded/SVN/avProj/Rte" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/Tm" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/Os" -I"C:/Work/Embedded/SVN/avProj/Bsw/Mem/NvM" -I"C:/Work/Embedded/SVN/avProj/Bsw/Mem/Ea" -I"C:/Work/Embedded/SVN/avProj/Bsw/Cdd/Cdd_Servo" -I"C:/Work/Embedded/SVN/avProj/Asw/LED" -I"C:/Work/Embedded/SVN/avProj/Asw/Access" -I"C:/Work/Embedded/SVN/avProj/Asw/Engine" -I"C:/Work/Embedded/SVN/avProj/Asw/Steering" -I"C:/Work/Embedded/SVN/avProj/Asw/Brakes" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/Blinker" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/FrontLights" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/RearLights" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/InteriorLights" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Mcu

clean-Bsw-2f-MCal-2f-Mcu:
	-$(RM) ./Bsw/MCal/Mcu/mcu.d ./Bsw/MCal/Mcu/mcu.o ./Bsw/MCal/Mcu/mcu.su ./Bsw/MCal/Mcu/stm32f3xx_hal.d ./Bsw/MCal/Mcu/stm32f3xx_hal.o ./Bsw/MCal/Mcu/stm32f3xx_hal.su ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.d ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.o ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.su ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.d ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.o ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.su ./Bsw/MCal/Mcu/stm32f3xx_hal_msp.d ./Bsw/MCal/Mcu/stm32f3xx_hal_msp.o ./Bsw/MCal/Mcu/stm32f3xx_hal_msp.su ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.d ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.o ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.su ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.d ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.o ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.su ./Bsw/MCal/Mcu/stm32f3xx_it.d ./Bsw/MCal/Mcu/stm32f3xx_it.o ./Bsw/MCal/Mcu/stm32f3xx_it.su ./Bsw/MCal/Mcu/syscalls.d ./Bsw/MCal/Mcu/syscalls.o ./Bsw/MCal/Mcu/syscalls.su ./Bsw/MCal/Mcu/sysmem.d ./Bsw/MCal/Mcu/sysmem.o ./Bsw/MCal/Mcu/sysmem.su

.PHONY: clean-Bsw-2f-MCal-2f-Mcu

