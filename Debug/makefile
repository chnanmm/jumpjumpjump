################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
jumpjumpjump.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
jumpjumpjump.list \


# All Target
all: jumpjumpjump.elf secondary-outputs

# Tool invocations
jumpjumpjump.elf: $(OBJS) $(USER_OBJS) C:\Users\nannapatchsorn_l\STM32CubeIDE\workspace_1.1.0\jumpjumpjump\STM32F411RETX_FLASH.ld
	arm-none-eabi-gcc -o "jumpjumpjump.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\nannapatchsorn_l\STM32CubeIDE\workspace_1.1.0\jumpjumpjump\STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="jumpjumpjump.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

jumpjumpjump.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "jumpjumpjump.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
