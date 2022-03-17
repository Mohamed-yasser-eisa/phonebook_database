################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
PhoneBook.obj: ../PhoneBook.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv4 --code_state=32 --include_path="H:/4th year, second term/Embedded/Task 3" --include_path="C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --check_misra="6.2,6.3,6.4,6.5,8.1,8.5,8.7,8.8,8.11,8.12,9.1,9.3,10.1,11.1,11.2,11.4,11.5,12.1,12.2,12.4,12.6,12.7,12.8,13.1,13.2,13.3,13.5,13.6,14.1,14.2,14.4,14.5,14.7,14.9,14.10,15.2,15.3,16.5,16.7,17.4,17.5,19.4,19.11,19.15" --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv4 --code_state=32 --include_path="H:/4th year, second term/Embedded/Task 3" --include_path="C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --check_misra="6.2,6.3,6.4,6.5,8.1,8.5,8.7,8.8,8.11,8.12,9.1,9.3,10.1,11.1,11.2,11.4,11.5,12.1,12.2,12.4,12.6,12.7,12.8,13.1,13.2,13.3,13.5,13.6,14.1,14.2,14.4,14.5,14.7,14.9,14.10,15.2,15.3,16.5,16.7,17.4,17.5,19.4,19.11,19.15" --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


