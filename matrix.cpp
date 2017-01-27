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

Matrix::~Matrix()
{
	if(uMatrix != NULL) delete[] uMatrix;
	//cout << "test" << endl;
	if(lMatrix != NULL) delete[] lMatrix;
	//cout << "test" << endl;
	//if(data != NULL) delete[] data;
	//cout << "test" << endl;
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
	lMatrix = NULL;
	uMatrix = NULL;

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
	if(!uMatrix)
		uMatrix = new double[nrows*ncols];
	
	if(!lMatrix)
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
	}
}

void Matrix::printUMatrix()
{
	if(!uMatrix) factor();

	cout << "Upper matrix: \n";
	for (int row = 0; row < nrows; row++)
	{
		for (int col = 0; col < ncols; col++)
			cout << setw(7) << fixed << setprecision(4) << uMatrix[row*ncols+col] << " ";
		cout << endl;
	}
}

void Matrix::printLMatrix()
{
	if(!lMatrix) factor();

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

double Matrix::findDet()
{
	double det = 1;

	for(int i = 0; i < nrows*ncols; i+=nrows+1)
		det *= uMatrix[i];

	return det;
}

double* Matrix::solve(double b[])
{
	double *x = new double[ncols];
	double *z = new double[ncols];

	//Calculate for z. Lz=B
	double totalPrev;
	for(int r = 0; r < nrows; r++)
	{
		totalPrev = 0;
		for(int c = 0; c < r; c++) totalPrev += z[c] * lMatrix[r*ncols+c];
		z[r] = b[r] - totalPrev;
	}

	//calculate for x from z. Ux=z
	for(int r = nrows-1; r >= 0; r--)
	{
		totalPrev = 0;
		for(int c = ncols-1; c > r; c--) totalPrev += x[c] * uMatrix[r*ncols+c];
		x[r] = (z[r] - totalPrev) / uMatrix[r*ncols+r];
	}

	/*
	cout << "Value of z:" << endl;
	for(int i = 0; i < ncols; i++)
		cout << z[i] << endl;

	//cout << endl;

	cout << "Value of x:" << endl;
	for(int i = 0; i < ncols; i++)
		cout << x[i] << endl;
	*/

	return x;
}

double* Matrix::findInv()
{
	double *invMatrix = new double[nrows * ncols];
	double *invRow = NULL;
	double *b = new double[nrows];
	b[0] = 1;

	for(int i = 0; i < ncols; i++)
	{
		if(i > 0)
		{
			b[i-1] = 0;
			b[i] = 1;
		}

		invRow = solve(b);

		for(int j = 0; j < nrows; j++)
		{
			invMatrix[j*ncols+i] = invRow[j]; 
		}
	}

	return invMatrix;
}