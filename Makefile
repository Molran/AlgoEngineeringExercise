CXX = cl
CXXFLAGS = -Wall 

.PHONY all:
all: clean build

.PHONY build:
build: Fibonacci.cpp
	$(CXX) $(CXXFLAGS) Fibonacci.cpp
	
.PHONY clean:
clean:
	-del Fibonacci.obj Fibonacci.exe
