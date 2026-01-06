################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PD/PD_Basicfun.c \
../PD/PD_Process.c 

OBJS += \
./PD/PD_Basicfun.o \
./PD/PD_Process.o 

C_DEPS += \
./PD/PD_Basicfun.d \
./PD/PD_Process.d 


# Each subdirectory must supply rules for building sources it contributes
PD/%.o: ../PD/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\Userr" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\GPIOCTRL" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\SRC\Core" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\SRC\Debug" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\SRC\Ld" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\SRC\Peripheral\inc" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\SRC\Peripheral\src" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\PD" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\TIM" -I"C:\Users\Shen\Desktop\新建文件夹 (6)\screen extender\CH32X035-TYPEC-DP测试板\X035PROJV1\ADC" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

