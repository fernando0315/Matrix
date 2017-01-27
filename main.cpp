// passingVectortoAfunction.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "matrix.h"

using namespace std;

bool getMatrixFromFile(Matrix&);


int main() 
{
	Matrix mat;
	getMatrixFromFile(mat); 
	cout << mat;
	mat.factor();
	mat.printUMatrix();
	mat.printLMatrix();
	cout << "Determinant: " << mat.findDet() << endl;
	double b[] = {500, 0, 0, 0};
	mat.solve(b);

	return 0;
}

bool getMatrixFromFile(Matrix &mat) 
{
	string fname;
	cout << "Input File name:";
	cin >> fname;
	
	ifstream ifile(fname.c_str());

	if(!ifile)
	{
		cout << "File not found" << endl;
		return NULL;
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

	mat = a;

	ifile.close();   // close the diskfile
}