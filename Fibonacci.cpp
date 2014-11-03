// Fibonacci.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

int fib(int x){		//code derived from definition
	if (x == 0) return 0;
	if (x == 1) return 1;
	return fib(x - 1) + fib(x - 2);
}

int fib2(int x){	//linear running time and memory
	vector<int> fibs;

	fibs.push_back(0);
	fibs.push_back(1);

	if (x == 0) return 0;

	for (int i = 2; i <= x; i++){
		fibs.push_back(fibs.at(i - 1) + fibs.at(i - 2));
	}

	return fibs.back();
}

int fib3(int x){	//linear time, constant memory
	if (x <= 1) return x;

	int fibs[3];
	fibs[0] = 0;
	fibs[1] = 1;

	for (int i = 2; i <= x; i++){
		fibs[2] = fibs[1] + fibs[0];
		fibs[0] = fibs[1];
		fibs[1] = fibs[2];
	}

	return fibs[2];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int input;

	assert(fib(3) == 2);
	assert(fib(4) == 3);
	assert(fib(5) == 5);
	assert(fib(6) == 8);
	assert(fib(7) == 13);
	assert(fib(8) == 21);
	assert(fib(9) == 34);


	for (int i = 1; i > 0;){
		cout << "Bitte geben sie die Nummer der zu berechnenden Fibonacci-Zahl an: ";
		cin >> input;
		cout << "Das Ergebnis von fib ist " << fib(input) << ".\n";
		cout << "Das Ergebnis von fib2 ist " << fib2(input) << ".\n";
		cout << "Das Ergebnis von fib3 ist " << fib3(input) << ".\n";

	}

	cin >> input;
	return 0;
}