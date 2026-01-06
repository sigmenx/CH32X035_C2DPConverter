################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Shen/Desktop/screen\ extender/SRC/Debug/debug.c 

OBJS += \
./Debug/debug.o 

C_DEPS += \
./Debug/debug.d 


# Each subdirectory must supply rules for building sources it contributes
Debug/debug.o: C:/Users/Shen/Desktop/screen\ extender/SRC/Debug/debug.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\screen extender\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\screen extender\SRC\Core" -I"C:\Users\Shen\Desktop\screen extender\SRC\Debug" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\screen extender\X035底板工程文件\X035PROJV1\TIM" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

