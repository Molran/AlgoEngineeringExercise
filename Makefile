LIBDIR = "C:\workspace2\AlgoEngineeringExercise\Fibonacci\Fibonacci\lib\gtest"
CXX = g++
CXXFLAGS = -Wall -I$(LIBDIR) 

.PHONY: all
all: build

.PHONY: build
build: Fibonacci.cpp = Fibonacci.obj
	$(CXX) Fibonacci.cpp = Fibonacci.obj $(CXXFLAGS) -o Fibonacci

.PHONY: clean
clean:
	-del Fibonacci.obj Fibonacci.exe
