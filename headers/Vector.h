#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class TMatrix;

template <typename T>
class TVector
{
	bool is_own_memory = true;
	size_t len = 0;
	T* data = nullptr;
protected:
	T* getData() const { return data; }

public:
	TVector() {}
	explicit TVector(const size_t n);
	TVector(const TVector<T>& p) { *this = p; }
	TVector(T* data, const size_t n) : len(n), data(data), is_own_memory(false) {}
	~TVector() { if (is_own_memory) delete[] data; }

	size_t size() const { return len; }
	T& operator [] (const size_t i) const { return data[i]; }

	bool operator == (const TVector<T>& p) const;
	bool operator != (const TVector<T>& p) const { return !(*this == p); }
	TVector<T>& operator = (const TVector<T>& p);
	TVector<T> operator + (const TVector<T>& p) const;
	TVector<T> operator - (const TVector<T>& p) const;
	TVector<T> operator += (const TVector<T>& p);
	TVector<T> operator / (const TVector<T>& p) const;
	TVector<T> operator * (const TVector<T>& p) const;
	TVector<T> operator * (const TMatrix<T>& matrix) const;

	template <class T>
	friend ostream& operator<<(ostream& os, const TVector<T>& p);
	template <class T>
	friend istream& operator>>(istream& in, TVector<T>& p);
};

template<class T>
inline TVector<T>::TVector(const size_t n) : len(n)
{
	if (len < 1) {
		throw runtime_error("Vector len must be more than 0");
	}
	data = new T[len];
	fill_n(data, len, 0);
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p) const
{
	if (size() != p.size())
		return false;
	for (int i = 0; i < size(); i++)
	{
		if ((*this)[i] != p[i])
			return false;
	}
	return true;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
	if (this == &p) {
		return *this;
	}
	if (data) {
		delete[] data;
	}
	len = p.len;
	data = new T[len];
	copy_n(p.data, len, data);
	return *this;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p) const
{
	if (size() != p.size())
		throw runtime_error("Size of summarized vectors must be the same");
	TVector<T> result(size());
	for (int i = 0; i < result.size(); i++) {
		result[i] = (*this)[i] + p[i];
	}
	return result;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p) const
{
	if (size() != p.size())
		throw runtime_error("Size of subtracted vectors must be the same");
	TVector<T> result(size());
	for (int i = 0; i < result.size(); i++) {
		result[i] = (*this)[i] - p[i];
	}
	return result;
}

template<class T>
inline TVector<T> TVector<T>::operator+=(const TVector<T>& p)
{
	*this = *this + p;
	return *this;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p) const
{
	if (size() != p.size())
		throw runtime_error("Size of devided vectors must be the same");
	TVector<T> result(size());
	for (int i = 0; i < result.size(); i++) {
		result[i] = (*this)[i] / p[i];
	}
	return result;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p) const
{
	if (size() != p.size())
		throw runtime_error("Size of multiplied vectors must be the same");
	TVector<T> result(size());
	for (int i = 0; i < result.size(); i++) {
		result[i] = (*this)[i] * p[i];
	}
	return result;
}

template<typename T>
inline TVector<T> TVector<T>::operator*(const TMatrix<T>& matrix) const
{
	if (matrix.getWidth() != size())
	{
		throw runtime_error("Bebbeebebebbebebebebebebebeb");
	}
	TVector<T> result(size());
	for (int i = 0; i < size(); i++)
		for (int j = 0; j < matrix.getWidth(); j++)
			for (int k = 0; k < size(); k++)
				result[i] += (*this)[i] * matrix[k][i];
	return result;
}

template<class T>
inline ostream& operator<<(ostream& os, const TVector<T>& p)
{
	os << "(";
	for (int i = 0; i < p.len; i++)
	{
		os << p.data[i];
		if (i < p.len - 1)
			os << " ";
	}
	os << ")^T";
	return os;
}

template<class T>
inline istream& operator>>(istream& in, TVector<T>& p)
{
	cout << "Enter vector length: ";
	in >> p.len;
	cout << "Enter nums: ";
	if (p.len != 0) delete[] p.data;
	p.data = new T[p.len];
	for (int i = 0; i < p.len; i++) in >> p.data[i];
	return in;
}