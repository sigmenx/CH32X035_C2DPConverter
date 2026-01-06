################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32x035_it.c \
../User/main.c \
../User/system_ch32x035.c 

OBJS += \
./User/ch32x035_it.o \
./User/main.o \
./User/system_ch32x035.o 

C_DEPS += \
./User/ch32x035_it.d \
./User/main.d \
./User/system_ch32x035.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\USBPD" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\GPIOCTRL" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Core" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Debug" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Ld" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Peripheral\inc" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Peripheral\src" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\TIM" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\ADC" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

