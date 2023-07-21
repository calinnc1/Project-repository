################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
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
Bsw/MCal/Mcu/%.o Bsw/MCal/Mcu/%.su Bsw/MCal/Mcu/%.cyclo: ../Bsw/MCal/Mcu/%.c Bsw/MCal/Mcu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Mcu" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Adc" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Fls" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/I2c" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Pwr" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Spi" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Uart" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Dio" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Dma" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Gpt" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/EcuM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/BswM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Config" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Int" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Rte" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/Tm" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/Os" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Mem/NvM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Mem/Ea" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_Servo" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_Ultrasonic" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_DCMotor" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/LED" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Access" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Engine" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Steering" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Brakes" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/Blinker" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/FrontLights" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/RearLights" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/InteriorLights" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Mcu

clean-Bsw-2f-MCal-2f-Mcu:
	-$(RM) ./Bsw/MCal/Mcu/mcu.cyclo ./Bsw/MCal/Mcu/mcu.d ./Bsw/MCal/Mcu/mcu.o ./Bsw/MCal/Mcu/mcu.su ./Bsw/MCal/Mcu/stm32f3xx_hal.cyclo ./Bsw/MCal/Mcu/stm32f3xx_hal.d ./Bsw/MCal/Mcu/stm32f3xx_hal.o ./Bsw/MCal/Mcu/stm32f3xx_hal.su ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.cyclo ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.d ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.o ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.su ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.cyclo ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.d ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.o ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.su ./Bsw/MCal/Mcu/stm32f3xx_hal_msp.cyclo ./Bsw/MCal/Mcu/stm32f3xx_hal_msp.d ./Bsw/MCal/Mcu/stm32f3xx_hal_msp.o ./Bsw/MCal/Mcu/stm32f3xx_hal_msp.su ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.cyclo ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.d ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.o ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.su ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.cyclo ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.d ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.o ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.su ./Bsw/MCal/Mcu/stm32f3xx_it.cyclo ./Bsw/MCal/Mcu/stm32f3xx_it.d ./Bsw/MCal/Mcu/stm32f3xx_it.o ./Bsw/MCal/Mcu/stm32f3xx_it.su ./Bsw/MCal/Mcu/syscalls.cyclo ./Bsw/MCal/Mcu/syscalls.d ./Bsw/MCal/Mcu/syscalls.o ./Bsw/MCal/Mcu/syscalls.su ./Bsw/MCal/Mcu/sysmem.cyclo ./Bsw/MCal/Mcu/sysmem.d ./Bsw/MCal/Mcu/sysmem.o ./Bsw/MCal/Mcu/sysmem.su

.PHONY: clean-Bsw-2f-MCal-2f-Mcu

