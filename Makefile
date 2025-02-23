# Define the compiler
CC = g++
CFLAGS = -O2 -Wall -Wextra

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executables
EXECUTABLES = main teste

# Create the object and binary directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target
all: $(EXECUTABLES)

# Rule for main executable
main: $(OBJ_DIR)/main.o $(OBJ_DIR)/sistemas.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

# Rule for teste executable
teste: $(OBJ_DIR)/teste.o $(OBJ_DIR)/sistemas.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

# Rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

# Run targets
run-main:
	./$(BIN_DIR)/main

run-teste:
	./$(BIN_DIR)/teste
