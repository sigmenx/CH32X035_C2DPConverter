################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USBPD/PD_Basicfun.c \
../USBPD/PD_Process.c 

OBJS += \
./USBPD/PD_Basicfun.o \
./USBPD/PD_Process.o 

C_DEPS += \
./USBPD/PD_Basicfun.d \
./USBPD/PD_Process.d 


# Each subdirectory must supply rules for building sources it contributes
USBPD/%.o: ../USBPD/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\USBPD" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\GPIOCTRL" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Core" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Debug" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Ld" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Peripheral\inc" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Peripheral\src" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\TIM" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\ADC" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

