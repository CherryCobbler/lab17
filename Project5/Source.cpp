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
	if (nsize == 0) array = nullptr;
	else
	{
		array = new T[nsize];
		size = nsize;
	}
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
	Set<int> a(5);
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	const int* t=a.erase(a.set_begin()+1);
	std::cout << a;
	return 0;
}