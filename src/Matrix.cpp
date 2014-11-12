#include "stdafx.h"
#include "Matrix.h"


Matrix::Matrix(vector<vector<long long int>> x){
	mat = x;
}

int Matrix::getHeight(){	//methods to make dimensions of matrix more clear
	return mat.size();
}

int Matrix::getWidth(){
	return mat[0].size();
}

long long int Matrix::getElement(int height, int width){
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
	vector<vector<long long int> > res;

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