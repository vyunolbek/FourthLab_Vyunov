#pragma once
#include "../headers/Matrix.h"
#include "../headers/Header.h"
template <class T>
TMatrix<T> operator * (TVector<T>& vector, TMatrix<T>& matrix)
{
	if ((matrix.GetL() == vector.GetW()))
	{
		T** arr = new T * [matrix.GetL()];
		for (int i = 0; i < vector.GetW(); i++)
			arr[i] = new T[vector.GetW()];
		TMatrix<T> result(matrix.GetL(), vector.GetW(), arr);

		for (int i = 0; i < result.GetW(); i++)

			for (int j = 0; j < result.GetL(); j++)
			{
				result.SetI(i, j, matrix[0][j] * vector[i]);
			}

		for (int i = 0; i < vector.GetW(); i++)
			delete[] arr[i];
		delete[] arr;
		return result;
	}
};

template <class T>
TVector<T> operator *(TMatrix<T>& matrix, TVector<T>& vector)
{
	if (matrix.GetW() == vector.GetW())
	{
		T* arr = new T[matrix.GetL()];
		TVector<T> result(matrix.GetL(), arr);


		for (int i = 0; i < result.GetW(); i++)
		{
			result.SetI(i, 0);
			for (int j = 0; j < vector.GetW(); j++)
			{
				result.SetI(i, result[i] + (matrix[i][j] * vector[j]));

			}
		}
		delete[] arr;
		return result;
	}
	else
		throw - 1;
};