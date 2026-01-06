################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_adc.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_awu.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_dbgmcu.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_dma.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_exti.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_flash.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_gpio.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_i2c.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_iwdg.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_misc.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_opa.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_pwr.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_rcc.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_spi.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_tim.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_usart.c \
C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_wwdg.c 

OBJS += \
./Peripheral/src/ch32x035_adc.o \
./Peripheral/src/ch32x035_awu.o \
./Peripheral/src/ch32x035_dbgmcu.o \
./Peripheral/src/ch32x035_dma.o \
./Peripheral/src/ch32x035_exti.o \
./Peripheral/src/ch32x035_flash.o \
./Peripheral/src/ch32x035_gpio.o \
./Peripheral/src/ch32x035_i2c.o \
./Peripheral/src/ch32x035_iwdg.o \
./Peripheral/src/ch32x035_misc.o \
./Peripheral/src/ch32x035_opa.o \
./Peripheral/src/ch32x035_pwr.o \
./Peripheral/src/ch32x035_rcc.o \
./Peripheral/src/ch32x035_spi.o \
./Peripheral/src/ch32x035_tim.o \
./Peripheral/src/ch32x035_usart.o \
./Peripheral/src/ch32x035_wwdg.o 

C_DEPS += \
./Peripheral/src/ch32x035_adc.d \
./Peripheral/src/ch32x035_awu.d \
./Peripheral/src/ch32x035_dbgmcu.d \
./Peripheral/src/ch32x035_dma.d \
./Peripheral/src/ch32x035_exti.d \
./Peripheral/src/ch32x035_flash.d \
./Peripheral/src/ch32x035_gpio.d \
./Peripheral/src/ch32x035_i2c.d \
./Peripheral/src/ch32x035_iwdg.d \
./Peripheral/src/ch32x035_misc.d \
./Peripheral/src/ch32x035_opa.d \
./Peripheral/src/ch32x035_pwr.d \
./Peripheral/src/ch32x035_rcc.d \
./Peripheral/src/ch32x035_spi.d \
./Peripheral/src/ch32x035_tim.d \
./Peripheral/src/ch32x035_usart.d \
./Peripheral/src/ch32x035_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/ch32x035_adc.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_awu.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_awu.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_dbgmcu.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_dbgmcu.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_dma.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_dma.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_exti.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_flash.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_gpio.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_i2c.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_i2c.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_iwdg.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_iwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_misc.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_misc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_opa.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_opa.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_pwr.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_rcc.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_rcc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_spi.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_tim.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_tim.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_usart.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_usart.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_wwdg.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Peripheral/src/ch32x035_wwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

