# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -std=c++11 -Wall

# Define the target executable
TARGET = wifi4_simulation

# Define the source files
SRC = main.cpp wifi4.cpp

# Define the header files (if needed for dependencies)
HEADER = wifi4.h

# Define the object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build the object files
%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
