#include "Header.h"
template<typename T>
Set<T>::Set()
{
	size = 1;
	array = new T[1];
}
template<typename T>
Set<T>::Set(const size_t nsize)
{
	try
	{
		if (nsize < 0) throw -3;
		size = nsize;
		array = new T[size];
	}
	catch (int thr)
	{
		std::cout << "Error: " << thr <<"! You can't create a Set with "<<nsize<< " elements! Created a Set for one element.";
		size = 1;
		array = new T[1];
	}
}
template<typename T>
Set<T>::~Set()
{
	delete[] array;
}
template<typename T>
T* Set<T>::insert(const T& value)
{
	T* r = find_it(value);
	if (r != NULL) return NULL;//the element already exists.
	busy++;
	T* array2 = array;
	if (size == busy)
	{
		size *= 2;
		array2 = new T[size];
	}
	size_t i=busy-1;
	for (i; i > 0 && (value < array[i-1]); i--)
	{
		array2[i] = array[i - 1];
	}
	array2[i] = value;
	if (array==array2) return array2+i;
	std::copy(array, array + i, array2);
	delete[] array;
	array = array2;
	return array+i;
}
template<typename T>
Set<T>::Set(const Set& value)
{
	size = value.size;
	busy = value.busy;
	array = new T[size];
	for (int i = 0; i < busy; i++)
	{
		array[i] = value.array[i];
	}
}
template<typename T>
Set<T>& Set<T>::operator=(const Set& value)
{
	if (this != &value)
	{
		size = value.size;
		busy = value.busy;
		delete[] array;
		array = new T[size];
		for (int i = 0; i < busy; i++)
		{
			array[i] = value.array[i];
		}
	}
	return *this;
}
template<typename T>
bool Set<T>::find(const T& value) const
{
	for (int i = 0; i < busy; i++)
	{
		if (array[i] == value) return true;
	}
	return false;
}
template<typename T>
T* Set<T>::find_it(const T& value) const
{
	for (size_t i = 0; i < busy; i++)
	{
		if (array[i] == value)
		{
			return &array[i];
		}
	}
	return NULL;
}
template<typename T>
size_t Set<T>::set_size() const
{
	return size;
}
template<typename T>
void Set<T>::clear()
{
	size = 0;
	busy = 0;
	delete[] array;
	array = NULL;
}
template<typename T>
int Set<T>::erase(const T& value)
{	
	int rez = 0;
	try
	{
		if(busy==0) throw -2;
		else if (busy != 1)
		{
			int i = 0;
			bool flag = false;
			for (i; i < busy; i++)
			{
				if (array[i] == value)
				{
					flag = true;
					rez = i;
				}
				if (flag && i != busy - 1)
				{
					array[i] = array[i + 1];
				}
			}
			if (!flag) return -1;
		}
		else 
		{
			if (array[0] != value) return -1;
		}
	}
	catch (int thr)
	{
		return thr;
	}
	busy--;
	return rez;
}
template<typename T>
std::ostream& operator<< (std::ostream& out, const Set<T>& value)
{
	if (value.busy == 0)
	{
		out << "SET is empty!";
	}
	else 
	{
		for (int i = 0; i < value.busy; i++)
		{
			out << "array[" << i << "]= " << value.array[i] << "\n";
		}
	}
	return out;
}
int main()
{

	return 0;
}