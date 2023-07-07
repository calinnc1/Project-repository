################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Gpt/Gpt.c \
../Bsw/MCal/Gpt/stm32f3xx_hal_tim.c \
../Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.c 

OBJS += \
./Bsw/MCal/Gpt/Gpt.o \
./Bsw/MCal/Gpt/stm32f3xx_hal_tim.o \
./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.o 

C_DEPS += \
./Bsw/MCal/Gpt/Gpt.d \
./Bsw/MCal/Gpt/stm32f3xx_hal_tim.d \
./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Gpt/%.o Bsw/MCal/Gpt/%.su Bsw/MCal/Gpt/%.cyclo: ../Bsw/MCal/Gpt/%.c Bsw/MCal/Gpt/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Mcu" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Adc" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Fls" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/I2c" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Pwr" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Spi" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Uart" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Dio" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Dma" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Gpt" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/EcuM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/BswM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Config" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Int" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Rte" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/Tm" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/Os" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Mem/NvM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Mem/Ea" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_Servo" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_Ultrasonic" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/LED" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Access" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Engine" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Steering" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Brakes" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/Blinker" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/FrontLights" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/RearLights" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/InteriorLights" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Gpt

clean-Bsw-2f-MCal-2f-Gpt:
	-$(RM) ./Bsw/MCal/Gpt/Gpt.cyclo ./Bsw/MCal/Gpt/Gpt.d ./Bsw/MCal/Gpt/Gpt.o ./Bsw/MCal/Gpt/Gpt.su ./Bsw/MCal/Gpt/stm32f3xx_hal_tim.cyclo ./Bsw/MCal/Gpt/stm32f3xx_hal_tim.d ./Bsw/MCal/Gpt/stm32f3xx_hal_tim.o ./Bsw/MCal/Gpt/stm32f3xx_hal_tim.su ./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.cyclo ./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.d ./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.o ./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Gpt

