// passingVectortoAfunction.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "matrix.h"

void MatrixText(int n);
void BuildMatrix(int n);
void PrintMatrix(int n);

double matrix[9][9];

using namespace std;

int main() 
{
	
	Matrix a(4,4);
	a(0,0) = 13;
	a(0,1) = -4;
	a(0,2) = -3;
	a(0,3) = -6;
	a(1,0) = -4;
	a(1,1) = 17;
	a(1,2) = -2;
	a(1,3) = 0;
	a(2,0) = -3;
	a(2,1) = -2;
	a(2,2) = 11;
	a(2,3) = -2;
	a(3,0) = -6;
	a(3,1) = 0;
	a(3,2) = -2;
	a(3,3) = 12;
	

	/*
	Matrix a(2,2);
	a(0,0) = 4;
	a(0,1) = 3;
	a(1,0) = 6;
	a(1,1) = 3;
	*/
	cout << a << endl;
	a.factor();
	/*
	// UPPER MATRIX
	double multiplier[9][9];
	double Umatrix[9][9];
	for (int row = 0; row < n; row++)
		for (int col = 0; col < n; col++)
			Umatrix[row][col] = matrix[row][col];
	
	for (int iteration = 0; iteration < n; iteration++)
	{
		for (int row = iteration + 1; row < n; row++)
		{
		// save temporary values for multiplier
		multiplier[row][iteration] = Umatrix[row][iteration]/Umatrix[iteration][iteration];

		// performing row operations
		for (int col = 0; col < n; col++)
			Umatrix[row][col] = Umatrix[row][col] - (multiplier[row][iteration] * Umatrix[iteration][col]);
		}

		cout << "After iteration " << iteration << ":\n";
		for (int row = 0; row < n; row++)
		{
		for (int col = 0; col < n; col++)
		cout << Umatrix[row][col] << " ";
		cout << endl;
		}
		}
		cout << "Upper matrix: \n";
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			cout << Umatrix[row][col] << " ";
			cout << endl;

		}

	// LOWER MATRIX
	double Lmatrix[9][9];
	for (int row = 0; row < n; row++)
	for (int col = 0; col < n; col++)
	{
		if (row == col)
			Lmatrix[row][col] = 1;
		else if (col < row)
			Lmatrix[row][col] = multiplier[row][col];
		else
			Lmatrix[row][col] = 0;
	}

	cout << "\nLower matrix:\n";
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		cout << Lmatrix[row][col] << " ";
		cout << endl;
	}

	// Find determinent
	double det = 1;
	for (int row = 0; row < n; row++)
	det = det * Umatrix[row][row];
	cout << "\nDeterminent of matrix = " << det << "\n\n";

	// Solving for x
	*/
}

void MatrixText(int n)
{
	string fname;
	cout << "\nInput File name:";
	cin >> fname;
	ifstream ifile(fname.c_str());
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ifile >> matrix[i][j];
	
	ifile.close();   // close the diskfile
}

void BuildMatrix(int n)
{
	cout << "\nPlease insert values into the matrix:\n";
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
			cin >> matrix[row][col];
		cout << endl;
	}
}

void PrintMatrix(int n)
{
	cout << "\nYour array is:\n";
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
			cout << matrix[row][col] << " ";
		cout << endl;
	}
	cout << endl << endl;
}