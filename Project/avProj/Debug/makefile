################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Rte/subdir.mk
-include Config/subdir.mk
-include Bsw/Sys/Tm/subdir.mk
-include Bsw/Sys/Os/subdir.mk
-include Bsw/Sys/EcuM/subdir.mk
-include Bsw/Sys/BswM/subdir.mk
-include Bsw/Mem/NvM/subdir.mk
-include Bsw/Mem/Ea/subdir.mk
-include Bsw/MCal/Uart/subdir.mk
-include Bsw/MCal/Spi/subdir.mk
-include Bsw/MCal/Pwr/subdir.mk
-include Bsw/MCal/Mcu/subdir.mk
-include Bsw/MCal/Int/subdir.mk
-include Bsw/MCal/I2c/subdir.mk
-include Bsw/MCal/Gpt/subdir.mk
-include Bsw/MCal/Fls/subdir.mk
-include Bsw/MCal/Dma/subdir.mk
-include Bsw/MCal/Dio/subdir.mk
-include Bsw/MCal/Adc/subdir.mk
-include Bsw/Cdd/Cdd_Servo/subdir.mk
-include Asw/Steering/subdir.mk
-include Asw/Lights/RearLights/subdir.mk
-include Asw/Lights/InteriorLights/subdir.mk
-include Asw/Lights/FrontLights/subdir.mk
-include Asw/Lights/Blinker/subdir.mk
-include Asw/LED/subdir.mk
-include Asw/Engine/subdir.mk
-include Asw/Brakes/subdir.mk
-include Asw/Access/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := avProj
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
avProj.elf \

MAP_FILES += \
avProj.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
avProj.list \


# All Target
all: main-build

# Main-build Target
main-build: avProj.elf secondary-outputs

# Tool invocations
avProj.elf avProj.map: $(OBJS) $(USER_OBJS) C:\Work\Embedded\avProj\Config\STM32F303RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "avProj.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Work\Embedded\avProj\Config\STM32F303RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="avProj.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

avProj.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "avProj.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) avProj.elf avProj.list avProj.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
