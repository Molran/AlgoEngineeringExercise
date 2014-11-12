#pragma once
#include <vector>
#include <string>
using namespace std;

class Matrix{
	vector<vector<long long int>> mat;
public:
	Matrix(vector<vector<long long int>>);
	Matrix mult(Matrix);
	string toString();
	int getHeight();
	int getWidth();
	long long int getElement(int, int);
};