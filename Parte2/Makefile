# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -std=c++11
LDFLAGS := 

SHELL := /bin/bash

# Files and output
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
TARGET := test

# Targets
.PHONY: all debug release clean valgrind

# Default target
all: release

# Build without debugging information
release: CXXFLAGS += -O2
release: $(TARGET)

# Build with debugging information
debug: CXXFLAGS += -g
debug: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Valgrind target to run memory checks
valgrind: debug
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) | tee $(TARGET)-valgrind.log
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 2>&1 | tee $(TARGET)-valgrind.log
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) > $(TARGET)-valgrind.stdout.log 2> $(TARGET)-valgrind.stderr.log
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 2> >(tee $(TARGET)-valgrind.stderr.log >&2) | tee $(TARGET)-valgrind.stdout.log


valgrind-summary: debug
#	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) | tee $(TARGET)-valgrind-summary.log
#	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 2>&1 | tee $(TARGET)-valgrind-summary.log
#	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) > $(TARGET)-valgrind-summary.stdout.log 2> $(TARGET)-valgrind-summary.stderr.log
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 2> >(tee $(TARGET)-valgrind-summary.stderr.log >&2) | tee $(TARGET)-valgrind-summary.stdout.log