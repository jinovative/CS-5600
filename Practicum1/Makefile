# Compiler (can be overridden via environment variable)
CC ?= cc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Directory and file configuration
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
TARGET = message_store

# Default build target
all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Run the program
run: $(TARGET)
	./$(TARGET)

# Create results directory
prepare:
	mkdir -p results

# Clean up build files and result contents (but keep the directory)
clean:
	rm -f $(TARGET)
	rm -f $(SRC_DIR)/*.o
	rm -f results/* 2>/dev/null || true

.PHONY: all clean run prepare
