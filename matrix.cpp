#include <iostream>
#include <cmath>
#include <iomanip>
#include "matrix.h"	

Matrix::Matrix() 
{
	init(1,1);
}

Matrix::Matrix(int m, int n) 
{
	init(m,n);
}

int Matrix::getRow() 
{
	return nrows;
}

int Matrix::getCol()
{
	return ncols;
}

void Matrix::init(int m, int n) 
{
	nrows = m;
	ncols = n;
	data = new double[m*n];

	for(int i=0; i<m*n; i++)
		data[i] = 0;
}

double& Matrix::operator()(int r, int c)
{
	if(r < 0 || r > nrows)
	{
		cout << "Illegal Row Index:";
		return data[0];
	}
	else if (c < 0 || c > ncols)
	{
		cout << "Illegal COlumn Index:";
		return data[0];
	}
	else
	{
		return data[r*ncols+c];
	}
}

void Matrix::factor()
{
	uMatrix = new double[nrows*ncols];
	lMatrix = new double[nrows*ncols];

	for(int i = 0; i < ncols*nrows; i++)
		uMatrix[i] = data[i];

	for(int r = 0; r < nrows; r++)
		for(int c = r; c < ncols; c++)
			lMatrix[r*ncols+c] = c > r ? 0 : 1;

	double multiplier;
	for (int iteration = 0; iteration < nrows - 1; iteration++)	//iteration is the pivot row
	{
		for (int row = iteration + 1; row < nrows; row++)
		{	
			// save temporary values for multiplier
			multiplier =  uMatrix[row*ncols+iteration]/uMatrix[iteration*ncols+iteration];
			//cout << uMatrix[iteration*ncols+row] << '|' << uMatrix[iteration*ncols+iteration] << endl;
			//Fill in the multiplier for lower matrix
			lMatrix[row*ncols+iteration] = multiplier;
			// performing row operations
			for (int col = iteration + 1; col < ncols; col++)
					uMatrix[row*ncols+col] = uMatrix[row*ncols+col] - (multiplier * uMatrix[iteration*ncols+col]);
		}

		for(int row = iteration + 1; row < nrows; row++)
			uMatrix[row*ncols+iteration] = 0; 

		/*
		cout << "After iteration " << iteration << ":\n";
		for (int row = 0; row < nrows; row++)
		{
			for (int col = 0; col < ncols; col++)
				cout << setw(7) << fixed << setprecision(4) << uMatrix[row*ncols+col] << " ";
			cout << endl;
		}
		*/
	}
	
	cout << "Upper matrix: \n";
	for (int row = 0; row < nrows; row++)
	{
		for (int col = 0; col < ncols; col++)
			cout << setw(7) << fixed << setprecision(4) << uMatrix[row*ncols+col] << " ";
		cout << endl;
	}

	cout << "lower matrix: \n";
	for (int row = 0; row < nrows; row++)
	{
		for (int col = 0; col < ncols; col++)
			cout << setw(7) << fixed << setprecision(4) << lMatrix[row*ncols+col] << " ";
		cout << endl;
	}
}

ostream& operator<<(ostream &os, Matrix &m)
{
	cout << "Matrix:" << endl;
	int mval=m.getRow();
	int nval=m.getCol();
	for (int i=0; i<mval;i++){
		for(int j=0;j < nval ; j++)
			os<< setw(2) << m(i,j) << ' ';
		os << endl;
	}
	return os;
}