CXX = g++
CXXFLAGS = -Wall -o
LDFLAGS =

.PHONY: all
all: build

.PHONY: build
build: Fibonacci.cpp = Fibonacci.obj
	$(CXX) Fibonacci.cpp = Fibonacci.obj $(LDFLAGS) $(CXXFLAGS) -o Fibonacci
	
.PHONY: clean
clean:
	-del Fibonacci.obj Fibonacci.exe
