#include "Header.h"
#ifdef HEADER_H
template<typename T>
Set<T>::Set(const size_t ncapasity)
{
	if (ncapasity == 0) array = nullptr;
	else
	{
		array = new T[ncapasity];
		capasity = ncapasity;
	}
}
template<typename T>
Set<T>::~Set()
{
	delete[] array;
	array = nullptr;
}
template<typename T>
const T* Set<T>::insert(const T& value)
{
	const T* r = find_it(value);
	if (r != nullptr) return (array+capasity+1);//I think the returned values in two different situations should be different 
	//and if nullptr doesn't fit, then let it be end
	if (array == nullptr)
	{
		array = new T[1];
		capasity = 1;
	}
	size++;
	T* array2 = array;
	if (capasity == size)
	{
		capasity *= 2;
		array2 = new T[capasity];
	}
	size_t i = size - 1;
	for (i; i > 0 && (value < array[i - 1]); i--)
	{
		array2[i] = array[i - 1];
	}
	array2[i] = value;
	if (array == array2) return array2 + i;
	std::copy(array, array + i, array2);
	delete[] array;
	array = array2;
	return array + i;
}
template<typename T>
Set<T>::Set(const Set& value)
{
	capasity = value.capasity;
	size = value.size;
	array = new T[capasity];
	std::copy(value.array, value.array + size, array);
}
template<typename T>
Set<T>& Set<T>::operator=(const Set& value)
{
	if (this == &value) return *this;
	capasity = value.capasity;
	size = value.size;
	delete[] array;
	array = new T[capasity];
	std::copy(value.array, value.array + size, array);
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
	if (size != 0)
	{
		int left = 0, right = size, mid;
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
size_t Set<T>::set_capasity() const
{
	return capasity;
}
template<typename T>
inline size_t Set<T>::set_size() const
{
	return size;
}
template<typename T>
void Set<T>::clear()
{
	capasity = 0;
	size = 0;
	delete[] array;
	array = nullptr;
}
template<typename T>
const T* Set<T>::erase(const T* it)
{
	const T* r = find_it(*it); 
	if (r == nullptr) return r;
	size_t i=0;
	T* array2 = new T[capasity-1];
	for (i; i < size && &array[i] != it; i++)
	{
		array2[i] = array[i];
	}
	std::copy(array + i+1, array + size, array2 + i);
	delete[] array;
	array = array2;
	size--;
	capasity--;
	return (array+i+1);
}
template<typename T>
const T* Set<T>::set_begin() const
{
	return array;
}
template<typename T>
std::ostream& operator<< (std::ostream& out, const Set<T>& value)
{
	if (value.size == 0)
	{
		out << "SET is empty!";
	}
	else
	{
		for (int i = 0; i < value.size; i++)
		{
			out << "array[" << i << "]= " << value.array[i] << "\n";
		}
	}
	return out;
}
//When I finish sketching the point and finish tracing it, 
//I'll put it all in different files and everything will be beautiful. Honestly.
struct point {
	int x = 0;
	int y = 0;
	int z = 0;
	std::ostream& operator<<(std::ostream& out)
	{
		out << "(" << x << ";" << y << ";" << z << ")";
		return out;
	}
	bool operator<(const point& p) const
	{
		if (sqrt(x * x + y * y + z * z) < sqrt(p.x * p.x + p.y * p.y + p.z * p.z)) return true;
		else return false;
	}
};


#endif 