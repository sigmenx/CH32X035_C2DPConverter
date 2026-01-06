################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include oled/subdir.mk
-include User/subdir.mk
-include USBPD/subdir.mk
-include TIM/subdir.mk
-include SRC/Startup/subdir.mk
-include SRC/Peripheral/src/subdir.mk
-include SRC/Debug/subdir.mk
-include SRC/Core/subdir.mk
-include GPIOCTRL/subdir.mk
-include ADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
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
SECONDARY_FLASH += \
C2DP-V1.1.hex \

SECONDARY_LIST += \
C2DP-V1.1.lst \

SECONDARY_SIZE += \
C2DP-V1.1.siz \


# 所有目标
all: C2DP-V1.1.elf secondary-outputs

# 工具调用
C2DP-V1.1.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"C2DP-V1.1.map" --specs=nano.specs --specs=nosys.specs -o "C2DP-V1.1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
C2DP-V1.1.hex: C2DP-V1.1.elf
	@	riscv-none-embed-objcopy -O ihex "C2DP-V1.1.elf"  "C2DP-V1.1.hex"
	@	@
C2DP-V1.1.lst: C2DP-V1.1.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "C2DP-V1.1.elf" > "C2DP-V1.1.lst"
	@	@
C2DP-V1.1.siz: C2DP-V1.1.elf
	@	riscv-none-embed-size --format=berkeley "C2DP-V1.1.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) C2DP-V1.1.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
