#include <iostream>

using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(int m, int n);
	int getRow();
	int getCol();
	double& operator()(int, int);
	void factor();
	void printUMatrix();
	void printLMatrix();
	double findDet();
	friend ostream& operator<< (ostream& os, Matrix& m);
private:
	void init(int, int);
	int nrows, ncols;
	double *data;
	double *uMatrix, *lMatrix;
};
