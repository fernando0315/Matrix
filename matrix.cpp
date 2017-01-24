#include <iostream>
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

ostream& operator<<(ostream &os, Matrix &m)
{
	cout << "Matrix:" << endl;
	int mval=m.getRow();
	int nval=m.getCol();
	for (int i=0; i<mval;i++){
		for(int j=0;j < nval ; j++)
			os<< m(i,j) << ' ';
		os << endl;
	}
	return os;
}