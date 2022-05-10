#include <iostream>
#include"../headers/Header.h"
#include "../headers/Matrix.h"
#include "../headers/Multi.h"

using namespace std;

int main()
{
	int* arr;
	arr = new int[3];
	for (int i = 0; i < 3; i++) arr[i] = i;
	int** arrm;
	arrm = new int* [3];
	for (int i = 0; i < 3; i++) arrm[i] = new int[3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			arrm[i][j] = i;
	TVector<int> V1;
	TVector<int> V2(3);
	TVector<int> V3(V2);
	TVector<int> V4(3, arr);
	TVector<int> V5;
	V5 = V4;
	cout << V5 << endl;
	V5 = V4 + V3;
	cout << V5 << endl;
	V5 = V4 - V3;
	cout << V5 << endl;
	V5 += V4;
	cout << V5 << endl;
	V5 = V4 / V2;
	cout << V5 << endl;
	V5 = V4 * V4;
	cout << V5 << endl;
	cout << V5[2] << endl;
	TMatrix<int> M1;
	TMatrix<int> M2(3);
	TMatrix<int> M3(3, 3);
	TMatrix<int> M4(M3);
	TMatrix<int> M5(3, 3, arrm);
	M1 = M5;
	cout << M1 << endl;
	M1 = M5 + M5;
	cout << M1 << endl;
	M1 = M5 - M5;
	cout << M1 << endl;
	M1 += M5;
	cout << M1 << endl;
	M1 = M5 * M5;
	cout << M1 << endl;
	cout << M1[2][2] << endl;

	V1 = M1 * V5;
	cout << V1 << endl;
	cout << V5 << "\n\n" << M1 << endl;
	M1 = V5 * M1;
	cout << M1 << endl;
	return 0;
}