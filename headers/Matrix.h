#pragma once
#include "Header.h"
#include <iostream>

using namespace std;

template<class T>
class TMatrix : public TVector<TVector<T>>
{
protected:
	int width = 0;
	T** matr;
public:
	TMatrix();
	TMatrix(int n);
	TMatrix(int w, int l);
	TMatrix(const TMatrix<T>& p);
	TMatrix(int l, int w, T** arr);
	~TMatrix();

	void SetM(int i, int j, T value);
	void SetI(int index1, int index2, T t);
	int GetL();

	bool operator == (const TMatrix<T>& p);
	bool operator != (const TMatrix<T>& p);

	TMatrix<T> operator = (const TMatrix<T>& p);
	TMatrix<T> operator + (const TMatrix<T>& p);
	TMatrix<T> operator - (const TMatrix<T>& p);
	TMatrix<T> operator += (const TMatrix<T>& p);
	TMatrix<T> operator * (const TMatrix<T>& p);
	T*& operator[](const int _n);
	template <class T>
	friend ostream& operator<<(ostream& os, const TMatrix<T>& A);
	template<class T>
	friend istream& operator>>(istream& in, TMatrix<T>& mat);

	void Print();
};

template<class T>
inline TMatrix<T>::TMatrix()
{
	this->len = 2;
	width = 2;
	matr = new T*[len];
	for (int i = 0; i < len; i++)
		matr[i] = new T[width];
	for (int i = 0; i < width; i++)
		for (int j = 0; j < len; j++)
			matr[i][j] = 0;
}

template<class T>
inline TMatrix<T>::TMatrix(int n)
{
	len = width = n;
	matr = new T*[len];
	for (int i = 0; i < len; i++)
		matr[i] = new T[width];
	for (int i = 0; i < width; i++)
		for (int j = 0; j < len; j++)
			matr[i][j] = 0;
}

template<class T>
inline TMatrix<T>::TMatrix(int w, int l)
{
	width = w;
	len = l;
	matr = new T*[len];
	for (int i = 0; i < len; i++)
		matr[i] = new T[width];
	for (int i = 0; i < width; i++)
		for (int j = 0; j < len; j++)
			matr[i][j] = 0;
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& p)
{
	len = p.len;
	width = p.width;
	matr = new T*[len];
	for (int k = 0; k < len; k++) matr[k] = new T[width];
	if (p.len > 0 && p.width > 0)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < len; j++)
				matr[i][j] = p.matr[i][j];
	}
}

template<class T>
inline TMatrix<T>::TMatrix(int l, int w, T** arr)
{
	width = w;
	len = l;
	matr = new T * [len];
	for (int i = 0; i < len; i++) matr[i] = new T[width];
	for (int i = 0; i < width; i++)
		for (int j = 0; j < len; j++)
			matr[i][j] = arr[i][j];
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
	width = 0;
	len = 0;
	delete[] matr;
}

template<class T>
inline void TMatrix<T>::SetM(int i, int j, T value)
{
	if ((width >= i) && (len >= j) && (i >= 0) && (j >= 0))
		matr[i][j] = value;
}

template<class T>
inline void TMatrix<T>::SetI(int index1, int index2, T t)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < len; j++)
			if (i == index1 && j == index2)
				matr[i][j] = t;
}

template<class T>
inline int TMatrix<T>::GetL()
{
	return width;
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& p)
{
	if (p.len == len || width == p.width)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < len; j++)
			{
				if (matr[i][j] != p.matr[i][j])
				{
					return false;
					break;
				}
				break;
			}
	}
	else return false;
	return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix<T>& p)
{
	return !(*this == p);
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator=(const TMatrix<T>& p)
{
	for (int i = 0; i < len; i++)
		delete[] matr[i];
	delete[] matr;
	width = p.width;
	len = p.len;
	matr = new T * [len];
	for (int i = 0; i < len; i++) matr[i] = new T[width];
	for (int i = 0; i < width; i++)
		for (int j = 0; j < len; j++)
		{
			matr[i][j] = p.matr[i][j];
		}
	return *this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& p)
{
	TMatrix<T> result;
	result.len = len;
	result.width = width;
	result.matr = new T * [len];
	for (int i = 0; i < len; i++) result.matr[i] = new T[width];
	if (len == p.len && width == p.width)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < len; j++)
			{
				result.matr[i][j] = matr[i][j] + p.matr[i][j];
			}
	}
	else throw "Error";
	return result;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& p)
{
	TMatrix<T> result;
	result.len = len;
	result.width = width;
	result.matr = new T * [len];
	for (int i = 0; i < len; i++) result.matr[i] = new T[width];
	if (len == p.len && width == p.width)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < len; j++)
			{
				result.matr[i][j] = matr[i][j] - p.matr[i][j];
			}
	}
	else throw "Error";
	return result;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+=(const TMatrix<T>& p)
{
	TMatrix<T> result(p);
	*this = *this + result;
	return result;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& p)
{
	TMatrix<T> result(p.width);
	if (width == p.len && len == p.width)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < len; j++)
				for (int k = 0; k < this->len; k++)
				{
					result.matr[i][j] += (matr[i][k] * p.matr[k][j]);
				}
	}
	return result;
}

template<class T>
inline T*& TMatrix<T>::operator[](const int _n)
{
	return matr[_n];
}

template<class T>
inline void TMatrix<T>::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < len; j++)
			cout << matr[i][j] << " ";
		cout << endl;
	}
}

template<class T>
inline ostream& operator<<(ostream& B, const TMatrix<T>& A)
{
	for (int i = 0; i < A.width; i++)
	{
		for (int j = 0; j < A.len; j++)
			B << A.matr[i][j] << " ";
		cout << endl;
	}
		return B;
}

template<class T>
inline istream& operator>>(istream& in, TMatrix<T>& mat)
{
	for (int i = 0; i < mat.width; i++)
		delete[] mat.matr[i];
	delete[] mat.matr;

	cout << "Enter size" << endl << "width = ";
	in >> mat.width;
	cout << "long = ";
	in >> mat.len;
	T** temp;
	temp = new T * [mat.width];
	for (int i = 0; i < mat.width; i++)
		temp[i] = new T[mat.len];


	for (int i = 0; i < mat.width; i++)
	{
		cout << "Enter " << i + 1 << " line" << endl;
		for (int j = 0; j < mat.len; j++)
			in >> temp[i][j];
	}

	mat.matr = new T * [mat.width];
	for (int i = 0; i < mat.width; i++)
		mat.matr[i] = new T[mat.len];

	for (int i = 0; i < mat.width; i++)
		for (int j = 0; j < mat.len; j++)
			mat.SetM(i, j, temp[i][j]);

	for (int i = 0; i < mat.width; i++)
		delete[] temp[i];
	delete[] temp;
	return in;
}
