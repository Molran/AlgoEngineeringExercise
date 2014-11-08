#include "stdafx.h"
#include <iostream>
#include <vector>
#include <gtest\gtest.h>
using namespace std;

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

int fib4(int x){
	if (x == 0) return 1;
	//TODO if (x == 1) 
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
	if (x % 2 == 0){
		for (x; x > 1; x / 2){	//we shouldn't need odd or even evaluation if we use the "<"
			resMatrix = resMatrix.mult(resMatrix);
		}
	}
	resMatrix = resMatrix.mult(helpMatrix2);
	return resMatrix.getElement(0, 0);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int input;
	testing::InitGoogleTest(&argc, argv);

	//TESTING GROUND
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

	//cout << testV[0][0] << testV[0][1] << testV[1][0] << testV[1][1];		//reassuring that building a vector works as i wish

	Matrix testM (testV);
	Matrix testM2(testV2);
	//cout << testM2.toString();
	cout << testM.mult(testM2).toString();
	//cout << testM.toString();		//reassuring the Matrix works, too

	//TESTING GROUND

	/*for (int i = 1; i > 0;){
		cout << "Bitte geben sie die Nummer der zu berechnenden Fibonacci-Zahl an: ";
		cin >> input;
		cout << "Das Ergebnis von fib ist " << fib(input) << ".\n";
		cout << "Das Ergebnis von fib2 ist " << fib2(input) << ".\n";
		cout << "Das Ergebnis von fib3 ist " << fib3(input) << ".\n";
		cout << "Das Ergebnis von fib4 ist " << fib4(input) << ".\n";
	}*/

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