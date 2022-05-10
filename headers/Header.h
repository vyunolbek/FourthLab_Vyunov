#pragma once
#include <iostream>
#include <algorithm>
using namespace std;



template <class T>

class TVector
{
protected:
	int len;
	T* data;
public:
	TVector();
	TVector(int n);
	TVector(const TVector<T>& p);
	TVector(int n, const T* arr);
	~TVector();

	int GetW();
	void SetI(int index, T t);

	bool operator == (const TVector<T>& p);
	bool operator != (const TVector<T>& p);
	TVector<T> operator = (const TVector<T>& p);
	TVector<T> operator + (const TVector<T>& p);
	TVector<T> operator - (const TVector<T>& p);
	TVector<T> operator += (const TVector<T>& p);
	TVector<T> operator / (const TVector<T>& p);
	TVector<T> operator * (const TVector<T>& p);
	T operator [] (int i);

	template <class T>
	friend ostream& operator<<(ostream& os, const TVector<T>& p);
	template <class T>
	friend istream& operator>>(istream& in, TVector<T>& p);

	void Resize(int w, int l);

	void Print();
};

template<class T>
inline TVector<T>::TVector()
{
	len = 1;
	data = new T[len];
}

template<class T>
inline TVector<T>::TVector(int n)
{
	len = 1;
	data = new T[len];
	if (len > 0)
	{
		len = n;
		data = new T[len];
		for (int i = 0; i < len; i++)
			data[i] = 1;
	}
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
	len = p.len;
	data = new T[len];
	for (int i = 0; i < len; i++)
	{
		data[i] = p.data[i];
	}
}

template<class T>
inline TVector<T>::TVector(int n, const T* arr)
{
	len = n;
	data = new T[len];
	for (int i = 0; i < len; i++)
		data[i] = arr[i];
}

template<class T>
inline TVector<T>::~TVector()
{
	len = 0;
	delete[] data;
}

template<class T>
inline int TVector<T>::GetW()
{
	return len;
}

template<class T>
inline void TVector<T>::SetI(int index, T t)
{
	for (int i = 0; i < len; i++)
		if (i == index)
			data[i] = t;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
	if (len != p.len)
		return false;
	for (int i = 0; i < len; i++)
	{
		if (data[i] != p.data[i])
			return false;
	}
	return true;
}

template<class T>
inline bool TVector<T>::operator!=(const TVector<T>& p)
{
	return !(*this == p);
}

template<class T>
inline TVector<T> TVector<T>::operator=(const TVector<T>& p)
{
	if (*this == p)
		return *this;
	delete[] data;
	this->len = p.len;
	data = new T[len];
	for (int i = 0; i < len; i++)
		data[i] = p.data[i];
	return *this;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
	TVector<T> result(p.len);
	if (len == p.len && p.len > 0)
	{
		for (int i = 0; i < len; i++)
			result.data[i] = p.data[i] + this->data[i];
	}

	return result;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
	TVector<T> result(p.len);
	if (len == p.len && p.len > 0)
	{
		for (int i = 0; i < len; i++)
			result.data[i] = p.data[i] - this->data[i];
	}

	return result;
}

template<class T>
inline TVector<T> TVector<T>::operator+=(const TVector<T>& p)
{
	TVector<T> result(p);
	*this = *this + result;
	return *this;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
	TVector<T> result(p.len);
	if (len != p.len) throw "Error";
	for (int i = 0; i < len; i++)
		result.data[i] = this->data[i] / p.data[i];
	return result;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
	TVector<T> result(p.len);
	if (len != p.len) throw "Error";
	for (int i = 0; i < len; i++)
		result.data[i] = this->data[i] * p.data[i];
	return result;
}

template<class T>
inline T TVector<T>::operator[](int i)
{
	return data[i];
}

template<class T>
inline void TVector<T>::Resize(int w, int l)
{
	T* data1 = new TVector[w * l];
	for (int i = 0; i < min(w, this->width); i++)
		for (int j = 0; j < min(l, len); j++)
		{
			if (data[i][j] = this->data[i][j])
			{
				delete[] data;
				this->data = data1;
				this->len = l;
				width = w;
			}
		}
}

template<class T>
inline void TVector<T>::Print()
{
	for (int i = 0; i < len; i++)
		cout << data[i] << " ";
	cout << endl;
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
	in >> p.len;
	if (p.len != 0) delete[] p.data;
	p.data = new T[p.len];
	for (int i = 0; i < p.len; i++) in >> p.data[i];
	return in;
}
