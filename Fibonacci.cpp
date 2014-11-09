#include "stdafx.h"	//visual studio created file. it's meant to decrease compiling time, but this program is short, so it's empty
#include <iostream>
#include <vector>	//for fib4
#include <gtest\gtest.h>
#include <math.h>	//for fib5
#include <iostream>	//for fibToText
#include <fstream>
using namespace std;

long long int fibLUT [90];

class Matrix{
	vector<vector<int>> mat;
public:
	Matrix(vector<vector<int>>);
	Matrix mult(Matrix);
	string toString();
	int getHeight();
	int getWidth();
	int getElement(int, int);
};

Matrix::Matrix(vector<vector<int>> x){
	mat = x;
}

int Matrix::getHeight(){	//methods to make dimensions of matrix more clear
	return mat.size();
}

int Matrix::getWidth(){
	return mat[0].size();
}

int Matrix::getElement(int height, int width){
	return mat[height][width];
}

string Matrix::toString(){
	string x = "";
	for (int height = 0; height < getHeight(); height++){
		for (int width = 0; width < getWidth(); width++){
			x.append(to_string(getElement(height, width)) + " ");
		}
		x.append("\n");
	}
	return x;
}

Matrix Matrix::mult(Matrix x){	//multiplication of given matrix * x, simple implementation just for fibonacci-calculation purposes
	vector<vector<int> > res;

	res.resize(getHeight());		//build new pre-matrix to be filled with values next
	for (int i = 0; i < getHeight(); ++i)
		res[i].resize(x.getWidth());

	for (int height = 0; height < res.size(); height++){		//run through the new pre-matrix
		for (int width = 0; width < res[0].size(); width++){
			res[height][width] = 0;								//initialise every member of res with 0, to add up multiplications until everything has been added up
			for (int i = 0; i < getWidth(); i++){
				res[height][width] += getElement(height, i) * x.getElement(i, width);
			}
		}
	}
	Matrix resM = Matrix(res);
	return resM;
}

long long int fib(int x){		//code derived from definition
	if (x == 0) return 0;
	if (x == 1) return 1;
	return fib(x - 1) + fib(x - 2);
}

long long int fib2(int x){	//linear running time and memory
	vector<long long int> fibs;

	fibs.push_back(0);
	fibs.push_back(1);

	if (x == 0) return 0;

	for (int i = 2; i <= x; i++){
		fibs.push_back(fibs.at(i - 1) + fibs.at(i - 2));
	}

	return fibs.back();
}

long long int fib3(int x){	//linear time, constant memory
	if (x <= 1) return x;

	long long int fibs[3];
	fibs[0] = 0;
	fibs[1] = 1;

	for (int i = 2; i <= x; i++){
		fibs[2] = fibs[1] + fibs[0];
		fibs[0] = fibs[1];
		fibs[1] = fibs[2];
	}

	return fibs[2];
}

long long int fib4(int x){	//logarithmic running time
	if (x == 0) return 0;
	if (x == 1) return 1;

	vector<vector<int>> helpV1;	//the vector we will use for the 2x2 matrix
	vector<vector<int>> helpV2;	//the vector we will use for the 2x1 matrix
	vector<int> tempV;
	tempV.push_back(0);
	helpV2.push_back(tempV);
	tempV.push_back(1);
	helpV1.push_back(tempV);
	tempV.clear();
	tempV.push_back(1);
	tempV.push_back(1);
	helpV1.push_back(tempV);
	tempV.clear();
	tempV.push_back(1);
	helpV2.push_back(tempV);

	Matrix helpMatrix1(helpV1);
	Matrix resMatrix(helpV1);
	Matrix helpMatrix2(helpV2);
	int oddcount = 0;


	/*for (x; x >= 1;){
		if (x == 1){
			resMatrix = helpMatrix1.mult(resMatrix);
			x--;
		}else if ((x % 2) == 0){
			resMatrix = resMatrix.mult(resMatrix);
			x = x / 2;
		}else if ((x % 2) == 1){
			resMatrix = resMatrix.mult(resMatrix.mult(resMatrix));
			x = (x - 1) / 2;
			oddcount++;
		}
	}*/

	/*for (oddcount; oddcount > 0; oddcount--){
		resMatrix = helpMatrix1.mult(resMatrix);
	}*/

	resMatrix = resMatrix.mult(helpMatrix2);
	return resMatrix.getElement(0, 0);
}

int fib5(int x){	//formula derived from lecture, no matrix needed
	double res = floor((1.0 / pow(5.0, 0.5)) * pow(((1.0 + pow(5.0, 0.5)) / 2.0), x) + 0.5);
	return res;
}

int fib6(int x){	//taking information from lookup table, if not, use fib5() to calculate
	if(x< sizeof(fibLUT))return fibLUT[x];
	return fib5(x);
}

void fibToText(){	//creates a txt file with 90 fibonacci numbers, you can read it in linear time with getline()
	ofstream fibText;
	fibText.open("fibNumbers.txt");
	for (int i = 0; i <= 90; i++) fibText << fib3(i) << "\n";
	fibText.close();
}

void initFibLUT(){	//open textfile, read the strings, convert them to int, then save them to fibLUT
	ifstream fibText;
	fibText.open("fibNumbers.txt");	
	string fibString;
	int fibNum;
	for (int i = 0; i < 90; i++){
		getline(fibText, fibString);
		stringstream conv(fibString);
		conv >> fibNum;
		fibLUT[i] = fibNum;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int input;
	initFibLUT();
	testing::InitGoogleTest(&argc, argv);

	//TESTING GROUND
	/*
	vector<vector<int>> testV;
	vector<vector<int>> testV2;
	vector<int> tempV;
	tempV.push_back(0);
	tempV.push_back(1);
	testV.push_back(tempV);
	tempV.clear();
	tempV.push_back(2);
	tempV.push_back(3);
	testV.push_back(tempV);
	tempV.clear();

	tempV.push_back(0);
	testV2.push_back(tempV);
	tempV.clear();
	tempV.push_back(1);
	testV2.push_back(tempV);

	Matrix testM (testV);
	Matrix testM2(testV2);
	//cout << testM2.toString();
	//cout << testM.mult(testM2).toString();
	//cout << testM.toString();		//reassuring the Matrix works, too

	*/
	//TESTING GROUND END

	for (int i = 1; i > 0;){
		cout << "Bitte geben sie die Nummer der zu berechnenden Fibonacci-Zahl an: ";
		cin >> input;
		cout << "Das Ergebnis von fib ist " << fib(input) << ".\n";
		cout << "Das Ergebnis von fib2 ist " << fib2(input) << ".\n";
		cout << "Das Ergebnis von fib3 ist " << fib3(input) << ".\n";
		cout << "Das Ergebnis von fib4 ist " << fib4(input) << ".\n";
		cout << "Das Ergebnis von fib4 ist " << fib5(input) << ".\n";
	}

	//RUN_ALL_TESTS();
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

TEST(fib5Test, TestCorrectComputation){
	EXPECT_EQ(0, fib5(0));
	EXPECT_EQ(1, fib5(1));
	EXPECT_EQ(1, fib5(2));
	EXPECT_EQ(2, fib5(3));
	EXPECT_EQ(55, fib5(10));
	EXPECT_EQ(6765, fib5(20));
	EXPECT_EQ(832040, fib5(30));
}