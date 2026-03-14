################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./ft81x_driver/Bridgetek_EVE2.obj" \
"./ft81x_driver/EVE_API.obj" \
"./ft81x_driver/EVE_HAL.obj" \
"./ft81x_driver/EVE_MCU.obj" \
"./hal_driver/can.obj" \
"./hal_driver/esm.obj" \
"./hal_driver/gio.obj" \
"./hal_driver/rti.obj" \
"./hal_driver/sci.obj" \
"./hal_driver/spi.obj" \
"./source/dashboard.obj" \
"./source/data.obj" \
"./source/pages.obj" \
"./source/sys_main.obj" \
"./source/test_main_ecu.obj" \
"./source/ui_buttons.obj" \
"./source/ui_rpm_bar.obj" \
"./source/ui_touch.obj" \
"./sys/dabort.obj" \
"./sys/errata_SSWF021_45.obj" \
"./sys/notification.obj" \
"./sys/pinmux.obj" \
"./sys/sys_core.obj" \
"./sys/sys_dma.obj" \
"./sys/sys_intvecs.obj" \
"./sys/sys_mpu.obj" \
"./sys/sys_pcr.obj" \
"./sys/sys_phantom.obj" \
"./sys/sys_pmm.obj" \
"./sys/sys_pmu.obj" \
"./sys/sys_selftest.obj" \
"./sys/sys_startup.obj" \
"./sys/sys_vim.obj" \
"./sys/system.obj" \
"../sys/sys_link.cmd" \
$(GEN_CMDS__FLAG) \
-lrtsv7R4_T_be_v3D16_eabi.lib \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include ft81x_driver/subdir_vars.mk
-include hal_driver/subdir_vars.mk
-include source/subdir_vars.mk
-include sys/subdir_vars.mk
-include ft81x_driver/subdir_rules.mk
-include hal_driver/subdir_rules.mk
-include source/subdir_rules.mk
-include sys/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
tms570_on_board_ecu.out 

EXE_OUTPUTS__QUOTED += \
"tms570_on_board_ecu.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "tms570_on_board_ecu.out"

# Tool invocations
tms570_on_board_ecu.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 -g --c11 --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi -z -m"tms570_on_board_ecu.map" --heap_size=0x800 --stack_size=0x800 -i"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" -i"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="tms570_on_board_ecu_linkInfo.xml" --rom_model --be32 -o "tms570_on_board_ecu.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "ft81x_driver\Bridgetek_EVE2.obj" "ft81x_driver\EVE_API.obj" "ft81x_driver\EVE_HAL.obj" "ft81x_driver\EVE_MCU.obj" "hal_driver\can.obj" "hal_driver\esm.obj" "hal_driver\gio.obj" "hal_driver\rti.obj" "hal_driver\sci.obj" "hal_driver\spi.obj" "source\dashboard.obj" "source\data.obj" "source\pages.obj" "source\sys_main.obj" "source\test_main_ecu.obj" "source\ui_buttons.obj" "source\ui_rpm_bar.obj" "source\ui_touch.obj" "sys\dabort.obj" "sys\errata_SSWF021_45.obj" "sys\notification.obj" "sys\pinmux.obj" "sys\sys_core.obj" "sys\sys_dma.obj" "sys\sys_intvecs.obj" "sys\sys_mpu.obj" "sys\sys_pcr.obj" "sys\sys_phantom.obj" "sys\sys_pmm.obj" "sys\sys_pmu.obj" "sys\sys_selftest.obj" "sys\sys_startup.obj" "sys\sys_vim.obj" "sys\system.obj" 
	-$(RM) "ft81x_driver\EVE_API.d" "ft81x_driver\EVE_HAL.d" "hal_driver\can.d" "hal_driver\esm.d" "hal_driver\gio.d" "hal_driver\rti.d" "hal_driver\sci.d" "hal_driver\spi.d" "sys\errata_SSWF021_45.d" "sys\notification.d" "sys\pinmux.d" "sys\sys_dma.d" "sys\sys_pcr.d" "sys\sys_phantom.d" "sys\sys_pmm.d" "sys\sys_selftest.d" "sys\sys_startup.d" "sys\sys_vim.d" "sys\system.d" 
	-$(RM) "ft81x_driver\Bridgetek_EVE2.d" "ft81x_driver\EVE_MCU.d" "source\dashboard.d" "source\data.d" "source\pages.d" "source\sys_main.d" "source\test_main_ecu.d" "source\ui_buttons.d" "source\ui_rpm_bar.d" "source\ui_touch.d" 
	-$(RM) "sys\dabort.d" "sys\sys_core.d" "sys\sys_intvecs.d" "sys\sys_mpu.d" "sys\sys_pmu.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

