#include "stdafx.h"
#include <iostream>
#include <assert.h>
#include <vector>
#include <gtest\gtest.h>
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
	testing::InitGoogleTest(&argc, argv);

	/*for (int i = 1; i > 0;){
		cout << "Bitte geben sie die Nummer der zu berechnenden Fibonacci-Zahl an: ";
		cin >> input;
		cout << "Das Ergebnis von fib ist " << fib(input) << ".\n";
		cout << "Das Ergebnis von fib2 ist " << fib2(input) << ".\n";
		cout << "Das Ergebnis von fib3 ist " << fib3(input) << ".\n";

	}*/

	RUN_ALL_TESTS();
	cin >> input;
	return 0;
}

TEST(fibTest, TestCorrectComputation){
	EXPECT_EQ(0, fib(0));
	EXPECT_EQ(1, fib(1));
	EXPECT_EQ(1, fib(2));
	EXPECT_EQ(2, fib(3));
	EXPECT_EQ(55, fib(10));
	EXPECT_EQ(6765, fib(20));
	EXPECT_EQ(832040, fib(30));
}

TEST(fib2Test, TestCorrectComputation){
	EXPECT_EQ(0, fib2(0));
	EXPECT_EQ(1, fib2(1));
	EXPECT_EQ(1, fib2(2));
	EXPECT_EQ(2, fib2(3));
	EXPECT_EQ(55, fib2(10));
	EXPECT_EQ(6765, fib2(20));
	EXPECT_EQ(832040, fib2(30));
}

TEST(fib3Test, TestCorrectComputation){
	EXPECT_EQ(0, fib3(0));
	EXPECT_EQ(1, fib3(1));
	EXPECT_EQ(1, fib3(2));
	EXPECT_EQ(2, fib3(3));
	EXPECT_EQ(55, fib3(10));
	EXPECT_EQ(6765, fib3(20));
	EXPECT_EQ(832040, fib3(30));
}