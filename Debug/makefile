################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AMIT_FINAL.lss \

FLASH_IMAGE += \
AMIT_FINAL.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AMIT_FINAL.elf secondary-outputs

# Tool invocations
AMIT_FINAL.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AMIT_FINAL.map -mmcu=atmega32 -o "AMIT_FINAL.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AMIT_FINAL.lss: AMIT_FINAL.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AMIT_FINAL.elf  >"AMIT_FINAL.lss"
	@echo 'Finished building: $@'
	@echo ' '

AMIT_FINAL.hex: AMIT_FINAL.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AMIT_FINAL.elf  "AMIT_FINAL.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AMIT_FINAL.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AMIT_FINAL.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AMIT_FINAL.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
