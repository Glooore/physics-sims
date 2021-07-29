CC := clang
CXX := clang++

BUILD_DIR := ./build
SRC_DIR := ./src
# SRCS := $(shell find $(SRC_DIR) -name "*.cpp" -or -name "*.c")
# SRCS := 

OBJ_DIR := ./obj
_OBJS := Object.o
OBJS := $(_OBJS:%=$(OBJ_DIR)/%)

INC_DIR := ./include
LIBS := -lm

CFLAGS := -Wall 
CFLAGS += -I$(INC_DIR)

main: $(OBJS) $(OBJ_DIR)/main.o
	$(CXX) $^ $(CFLAGS) $(LIBS) -o $(BUILD_DIR)/$@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) -c $< $(CFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CXX) -c $< $(CFLAGS) -o $@

debug: $(OBJS)
	$(CXX) $(OBJS) $(CFLAGS) $(LIBS) -g -o $(BUILD_DIR)/debug

.PHONY: print
print:
	echo $(OBJS)
