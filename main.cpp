// passingVectortoAfunction.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "matrix.h"

using namespace std;

bool getMatrixFromFile(Matrix&, double*&);


int main() 
{
	Matrix mat;
	double *invMatrix, *x, *b;

	//Get data from file
	if(!getMatrixFromFile(mat, b)) return 1;

	//Creat Matrix and LU Matrix
	cout << mat;
	mat.factor();
	mat.printUMatrix();
	mat.printLMatrix();
	cout << "Determinant: " << mat.findDet() << endl;
	
	//Solver for x for Ax = B
	cout << "Ax = B, B:" << endl;
	for(int j=0;j < 4; j++)
		cout << setw(6) << right << fixed << setprecision(2) << b[j] << endl;
	cout << "value of x: " << endl;
	x = mat.solve(b);
	for(int j=0;j < 4; j++)
		cout << setw(7) << right <<setprecision(2) << x[j] << endl;

	//Solver for inverse matrix
	cout << "Inverse Matrix: " << endl;
	invMatrix = mat.findInv();
	int mval=mat.getRow();
	int nval=mat.getCol();
	for (int i=0; i<mval;i++){
		for(int j=0;j < nval ; j++)
			cout << setw(7) << right << fixed << setprecision(4) << invMatrix[i*nval+j] << ' ';
		cout << endl;
	}

	return 0;
}

bool getMatrixFromFile(Matrix &mat, double *&B) 
{
	string fname;
	cout << "Input File name:";
	cin >> fname;
	
	ifstream ifile(fname.c_str());

	if(!ifile)
	{
		cout << "File not found!!!" << endl;
		return false;
	}

	int nRows, nCols, val;
	ifile >> nRows >> nCols;

	Matrix a(nRows, nCols);
	
	for(int i = 0; i < nRows; i++)
		for(int j = 0; j < nCols; j++)
		{
			ifile >> val;
			a(i,j) = val;
		}
	
	B = new double[nRows];
	for(int i = 0; i < nRows; i++)
		ifile >> B[i];

	mat = a;

	ifile.close();   // close the diskfile

	return true;
}