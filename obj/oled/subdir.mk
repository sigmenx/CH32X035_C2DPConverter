################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../oled/oled.c 

OBJS += \
./oled/oled.o 

C_DEPS += \
./oled/oled.d 


# Each subdirectory must supply rules for building sources it contributes
oled/%.o: ../oled/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\USBPD" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\GPIOCTRL" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Core" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Debug" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Ld" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Peripheral\inc" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Peripheral\src" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\TIM" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\ADC" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

