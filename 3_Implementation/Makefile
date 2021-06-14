#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out -lm
   endif
endif

TEST_PROJ_NAME = Aspriration_Level_Model_TEST

COVERAGE_PROJ_NAME=COVERAGE_$(TEST_PROJ_NAMEPROJ_NAME)

PROJ_NAME= Aspriration_Level_Model

BUILD_DIR=Build

# All include folders with header files
INC =-Iinc -Iunity

# All source code files
SRC = src/decision_making.c src/factorial.c src/parameters.c src/possible_number_of_charging_piles.c src/queue_parameters.c

# All test source files
TEST=test/test_cases_ALM.c
UNITY=unity/unity.c

# Main source code file
PROJECT=project_main.c

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

	
# Call 'make execute' to run the main program
	
execute:
	gcc $(SRC) $(PROJECT) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

# Call `make test` to run the test cases
test:
	gcc $(SRC) $(TEST) $(UNITY) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	
#Call 'make cpp' for static code analysis
cpp:
	cppcheck enable=all $(SRC) $(TEST) $(PROJECT)
# Call 'make coverage' for code coverage
coverage:
	gcc $(INC) -fprofile-arcs -ftest-coverage $(SRC) $(TEST) $(UNITY) -o $(call FixPath,$(BUILD_DIR)/$(COVERAGE_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(COVERAGE_PROJ_NAME).$(EXEC))
	gcov -a $(SRC) $(TEST) $(UNITY)

memcheck:
	valgrind ./$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
	
clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/* *.gcda *.gcov *.gcno)

$(BUILD_DIR):
			mkdir $(BUILD_DIR)