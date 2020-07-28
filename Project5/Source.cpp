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
	//so far this version
	size = (nsize < 0) ? 1 : nsize;
	array = (nsize==0)? nullptr : new T[size];
}
template<typename T>
Set<T>::~Set()
{
	delete[] array;
	array = NULL;
}
template<typename T>
const T* Set<T>::insert(const T& value)
{
	const T* r = find_it(value);
	if (r != nullptr) return nullptr;//the element already exists.
	busy++;
	T* array2 = array;
	if (size == busy)
	{
		size = (size == 0) ? 2 : size*2;
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
	std::copy(value.array, value.array + busy, array);
}
template<typename T>
Set<T>& Set<T>::operator=(const Set& value)
{
	if (this == &value) return *this;
	size = value.size;
	busy = value.busy;
	delete[] array;
	array = new T[size];
	std::copy(value.array, value.array + busy, array);
	return *this;
}
template<typename T>
bool Set<T>::find(const T& value) const
{
	if (find_it(value) != nullptr) return true;
	else return false;
}
template<typename T>
const T* Set<T>::find_it(const T& value) const
{
	if (busy != 0)
	{
		int left = 0, right = busy, mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (value < array[mid]) right = mid - 1;
			else if (value > array[mid]) left = mid + 1;
			else return (array + mid);
		}
	}
	return nullptr;
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
	array = nullptr;
}
template<typename T>
const T* Set<T>::erase(const T* it)
{
	//Will be soon
	//const T* r = find_it(*it);
	//if (r == nullptr) return nullptr;
	//if(busy==1) 
	//if(r==array+busy)
	//ссылается на след элемент
	//return r;
}
template<typename T>
const T* Set<T>::set_begin() const
{
	return array;
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