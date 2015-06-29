
# Help variables
RM := rm -rf
CC := g++
PROJ_NAME := stood_chess
SRC_DIR := ./chess
BUILD_DIR := build
OBJ_DIR := ${BUILD_DIR}/obj
BIN_DIR := ${BUILD_DIR}/bin
TEST_OBJ_DIR := ${OBJ_DIR}/test
GTEST_DIR := /Users/mac/Projects/gtest_1_7_0

OBJS +=

TEST_OBJS += \
	${TEST_OBJ_DIR}/main.o\
	${TEST_OBJ_DIR}/game.o\
	${TEST_OBJ_DIR}/piece.o\
	${TEST_OBJ_DIR}/piece_box.o\
	$(TEST_OBJ_DIR)/test_piece.o\
	$(TEST_OBJ_DIR)/board.o\
	$(TEST_OBJ_DIR)/pos.o\
	$(TEST_OBJ_DIR)/move.o\
	$(TEST_OBJ_DIR)/test_board.o\
	$(TEST_OBJ_DIR)/board_filler.o

# Include paths for building release version
INC_PATHS +=

# Include paths for building test version
TEST_INC_PATHS = ${INC_PATHS}\
	-I${GTEST_DIR}/include

# Librarys for building release version
LIBS :=

# Librarys for building test version
TEST_LIBS := ${LIBS} -lgtest

# Library paths for building release version
LIB_PATHS +=

# Library paths for building test version
TEST_LIB_PATHS = ${LIB_PATHS}\
	-L${GTEST_DIR}

DEFS :=

TEST_DEFS = ${DEFS}\
	-D__GOOGLE_TEST__

${TEST_OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++  ${TEST_DEFS} ${TEST_INC_PATHS} -O0 -g3 -Wall -c -fmessage-length=0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Build
all: test

init:
	mkdir -p ${BUILD_DIR}
	mkdir -p ${BIN_DIR}
	mkdir -p ${OBJ_DIR}

init_test: init
	mkdir -p ${TEST_OBJ_DIR}

# Build test version
test: init_test $(TEST_OBJS)
	@echo 'Building target: ${PROJ_NAME}_test'
	@echo 'Invoking: GCC C++ Linker'
	g++ ${TEST_LIB_PATHS} -o "${BIN_DIR}/${PROJ_NAME}_test" $(TEST_OBJS) $(TEST_LIBS)
	@echo 'Finished building target: ${PROJ_NAME}_test'
	-@echo ' '


# Other Targets
clean:
	-$(RM) build
	-@echo ' '

