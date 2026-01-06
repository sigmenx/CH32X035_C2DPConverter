################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/Peripheral/src/ch32x035_adc.c \
../SRC/Peripheral/src/ch32x035_awu.c \
../SRC/Peripheral/src/ch32x035_dbgmcu.c \
../SRC/Peripheral/src/ch32x035_dma.c \
../SRC/Peripheral/src/ch32x035_exti.c \
../SRC/Peripheral/src/ch32x035_flash.c \
../SRC/Peripheral/src/ch32x035_gpio.c \
../SRC/Peripheral/src/ch32x035_i2c.c \
../SRC/Peripheral/src/ch32x035_iwdg.c \
../SRC/Peripheral/src/ch32x035_misc.c \
../SRC/Peripheral/src/ch32x035_opa.c \
../SRC/Peripheral/src/ch32x035_pwr.c \
../SRC/Peripheral/src/ch32x035_rcc.c \
../SRC/Peripheral/src/ch32x035_spi.c \
../SRC/Peripheral/src/ch32x035_tim.c \
../SRC/Peripheral/src/ch32x035_usart.c \
../SRC/Peripheral/src/ch32x035_wwdg.c 

OBJS += \
./SRC/Peripheral/src/ch32x035_adc.o \
./SRC/Peripheral/src/ch32x035_awu.o \
./SRC/Peripheral/src/ch32x035_dbgmcu.o \
./SRC/Peripheral/src/ch32x035_dma.o \
./SRC/Peripheral/src/ch32x035_exti.o \
./SRC/Peripheral/src/ch32x035_flash.o \
./SRC/Peripheral/src/ch32x035_gpio.o \
./SRC/Peripheral/src/ch32x035_i2c.o \
./SRC/Peripheral/src/ch32x035_iwdg.o \
./SRC/Peripheral/src/ch32x035_misc.o \
./SRC/Peripheral/src/ch32x035_opa.o \
./SRC/Peripheral/src/ch32x035_pwr.o \
./SRC/Peripheral/src/ch32x035_rcc.o \
./SRC/Peripheral/src/ch32x035_spi.o \
./SRC/Peripheral/src/ch32x035_tim.o \
./SRC/Peripheral/src/ch32x035_usart.o \
./SRC/Peripheral/src/ch32x035_wwdg.o 

C_DEPS += \
./SRC/Peripheral/src/ch32x035_adc.d \
./SRC/Peripheral/src/ch32x035_awu.d \
./SRC/Peripheral/src/ch32x035_dbgmcu.d \
./SRC/Peripheral/src/ch32x035_dma.d \
./SRC/Peripheral/src/ch32x035_exti.d \
./SRC/Peripheral/src/ch32x035_flash.d \
./SRC/Peripheral/src/ch32x035_gpio.d \
./SRC/Peripheral/src/ch32x035_i2c.d \
./SRC/Peripheral/src/ch32x035_iwdg.d \
./SRC/Peripheral/src/ch32x035_misc.d \
./SRC/Peripheral/src/ch32x035_opa.d \
./SRC/Peripheral/src/ch32x035_pwr.d \
./SRC/Peripheral/src/ch32x035_rcc.d \
./SRC/Peripheral/src/ch32x035_spi.d \
./SRC/Peripheral/src/ch32x035_tim.d \
./SRC/Peripheral/src/ch32x035_usart.d \
./SRC/Peripheral/src/ch32x035_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/Peripheral/src/%.o: ../SRC/Peripheral/src/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\USBPD" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\GPIOCTRL" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Core" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Debug" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Ld" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Peripheral\inc" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\SRC\Peripheral\src" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\TIM" -I"E:\PP计划相关\screen extender\C2DP-V1.1-20240320\ADC" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

