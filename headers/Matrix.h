#pragma once
#include <iostream>
#include "Vector.h"

using namespace std;

template<typename T>
class TMatrix : public TVector<T>
{
	size_t width = 0;
	size_t height = 0;
public:
	TMatrix() : TVector<T>() {}
	TMatrix(size_t w, size_t h) : TVector<T>(w* h), width(w), height(h) {}
	TMatrix(const TMatrix<T>& p) { *this = p; }
	~TMatrix() {}

	size_t getWidth() const { return width; }
	size_t getHeight() const { return height; }

	bool operator == (const TMatrix<T>& p) const;
	bool operator != (const TMatrix<T>& p) const { return !(*this == p); }

	TMatrix<T>& operator = (const TMatrix<T>& p);
	TMatrix<T> operator + (const TMatrix<T>& p) const;
	TMatrix<T> operator - (const TMatrix<T>& p) const;
	TMatrix<T> operator += (const TMatrix<T>& p);
	TMatrix<T> operator * (const TMatrix<T>& p) const;
	TMatrix<T> operator / (const TMatrix<T>& p) const;
	TVector<T> operator *(TVector<T>& vector) const;

	TVector<T> operator[](const size_t i) const {
		return TVector<T>(this->getData() + i * width, width);
	}

	template <class T>
	friend ostream& operator<<(ostream& os, const TMatrix<T>& A);
	template<class T>
	friend istream& operator>>(istream& in, TMatrix<T>& mat);

};

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& p) const
{
	if (p.width != width || p.height != height) {
		return false;
	}
	return *(static_cast<TVector<T>*>(this)) == *(static_cast<TVector<T>*>(&p));
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& p)
{
	if (this == &p)
		return *this;
	width = p.width;
	height = p.height;
	*(static_cast<TVector<T>*>(this)) = *(static_cast<const TVector<T>*>(&p));
	return *this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& p) const
{
	if (getWidth() != p.getWidth() || getHeight() != p.getHeight())
		throw runtime_error("Shape of summarized matrices must be the same");
	TMatrix<T> result(getWidth(), getHeight());
	*(static_cast<TVector<T>*>(&result)) = *(static_cast<const TVector<T>*>(this)) + *(static_cast<const TVector<T>*>(&p));
	return result;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& p) const
{
	if (getWidth() != p.getWidth() || getHeight() != p.getHeight())
		throw runtime_error("Shape of subtracted matrices must be the same");
	TMatrix<T> result(getWidth(), getHeight());
	*(static_cast<TVector<T>*>(&result)) = *(static_cast<const TVector<T>*>(this)) - *(static_cast<const TVector<T>*>(&p));
	return result;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+=(const TMatrix<T>& p)
{
	*this = *this + p;
	return *this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& p) const
{
	if (getWidth() == p.getHeight())
	{
		TMatrix<T> result(getHeight(), p.getWidth());
		for (int i = 0; i < result.width; i++)
			for (int j = 0; j < result.height; j++)
			{
				result[i][j] = 0;
				for (int k = 0; k < height; k++)
					result[i][j] = result[i][j] + ((*this)[i][j] * p[i][j]);
			}
		return result;
	}
	else
		throw runtime_error("Shape of multiplied matrices must be the same");
}

template<typename T>
inline TMatrix<T> TMatrix<T>::operator/(const TMatrix<T>& p) const
{
	if (getWidth() != p.getWidth() || getHeight() != p.getHeight())
		throw runtime_error("Shape of divided matrices must be the same");
	TMatrix<T> result(getWidth(), getHeight());
	*(static_cast<TVector<T>*>(&result)) = *(static_cast<const TVector<T>*>(this)) / *(static_cast<const TVector<T>*>(&p));
	return result;
}

template<typename T>
inline TVector<T> TMatrix<T>::operator*(TVector<T>& vector) const
{
	if (getWidth() != vector.size())
	{
		throw - 1;
	}
	TVector<T> result(vector.size());
	for (int i = 0; i < vector.size(); i++)
		for (int j = 0; j < getWidth(); j++)
			for (int k = 0; k < vector.size(); k++)
				result[i] += (*this)[i][k] * vector[k];
	return result;
}

template<class T>
inline ostream& operator<<(ostream& B, const TMatrix<T>& A)
{
	for (int i = 0; i < A.width; i++)
	{
		for (int j = 0; j < A.height; j++)
			B << A[i][j] << " ";
		cout << endl;
	}
	return B;
}

template<class T>
inline istream& operator>>(istream& in, TMatrix<T>& mat)
{
	cout << "Enter width: ";
	in >> mat.width;
	cout << "Enter height: ";
	in >> mat.height;
	TMatrix<T> temp(mat.height, mat.width);
	for (int i = 0; i < mat.width; i++)
		for (int j = 0; j < mat.height; j++)
			in >> temp[i][j];
	mat = temp;
	return in;
}


