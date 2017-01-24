// passingVectortoAfunction.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "matrix.h"

double matrix[9][9]; // max size is 9x9 matrix

void MatrixText(int n);
void BuildMatrix(int n);
void PrintMatrix(int n);

using namespace std;

int main() 
{
	cout << "checking" << endl;

	/*
	// INITIALIZING ARRAY
	cout << "Constructing an nxn matrix. Please insert a value for n: ";
	int n; // number of rows/columns
	cin >> n;

	cout << "\nWould you like to\n\t(A) Get matrix from text file\n\t(B) Build your own matrix\n\nPlease input 'A' or 'B'\n";
	char select;
	int check;
	do {
		check = 0;
		cin >> select; 
		if (select == 'A')
			MatrixText(n);
		else if (select == 'B')
			BuildMatrix(n);
		else
		{
			cout << "\nPlease enter a valid character. 'A' or 'B'\n";
			check = 1;
		}
	} while (check == 1);
	PrintMatrix(n);

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