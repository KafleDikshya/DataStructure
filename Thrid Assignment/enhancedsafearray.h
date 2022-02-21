#ifndef ENHANCEDSAFEARRAY_H
#define ENHANCEDSAFEARRAY_H

#include "safearray.h"

using namespace std;

template <typename T>
class EnhancedSafeArray: public SafeArray<T>
{
public:
	EnhancedSafeArray(void);
	EnhancedSafeArray(int);
	EnhancedSafeArray(const EnhancedSafeArray<T> & eArray);
	int size(void) const;
	EnhancedSafeArray<T> & operator= (EnhancedSafeArray<T> & eArray);
	bool operator== (EnhancedSafeArray<T> & eArray) const;
};

template <typename T>
EnhancedSafeArray<T>::EnhancedSafeArray(void){} 

template <typename T>
EnhancedSafeArray<T>::EnhancedSafeArray(int size) : SafeArray<T>(size){} 

template <typename T>
EnhancedSafeArray<T>::EnhancedSafeArray(const EnhancedSafeArray<T> & eArray) 
{
	this->count = eArray.count;
	delete [] this->storage;
	this->storage = new T[this->count];
	for (int i = 0; i < this->count; i++)
	{
		this->storage[i] = eArray.storage[i];
	}
}

template <typename T>
int EnhancedSafeArray<T>::size() const   
{
	return this->count;
}

template <typename T>
EnhancedSafeArray<T> & EnhancedSafeArray<T>::operator= (EnhancedSafeArray<T> & eArray)
{                               
	if (*this == eArray)
	{
		return *this;
	}
	this->count = eArray.size();
	delete [] this->storage;
	this->storage = new T[this->count];
	for(int i = 0; i < this->count; i++)
	{
		this->storage[i] = eArray.storage[i];
	}
	return *this;
}

template <typename T>
bool EnhancedSafeArray<T>::operator == (EnhancedSafeArray<T> & eArray) const
{                               
	if(this->count != eArray.size())
	{
		return false;
	}
	for(int i = 0; i < this->count; i++)
	{
		if(this->storage[i] != eArray[i])
		{
			return false;
		}
		return true;
	}
}
#endif
