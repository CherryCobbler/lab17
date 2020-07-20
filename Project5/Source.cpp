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
		if (nsize == 0) throw -3;
		size = nsize;
		array = new T[size];
	}
	catch (int thr)
	{
		std::cout << "Error: " << thr <<"! You can't create a Set with zero elements! Created a Set for one element.";
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
bool Set<T>::insert(const T& value)
{
	if (busy == 0)
	{
		array[0] = value;
	}
	else if (busy == size)
	{
		bool flag = false;
		size+=10;
		T* array1 = new T[busy+1];
		int j = 0;
		for (size_t i = 0; i <= busy && j < busy; i++,j++)
		{
			if (array[i] == value)
			{
				delete[] array1;
				return false;
			}
			if (array[j] < value && i<busy)
			{
				array1[i] = array[j];
				continue;
			}
			else
			{ 
				if (!flag)
				{
					array1[i] = value;
					flag = true;
					j--;
				}
			}
			array1[i] = array[j];
		}
		if (!flag) array1[busy] = value;
		delete[] array;
		array = new T[size];
		for (size_t i = 0; i <= busy; i++)
		{
			array[i] = array1[i];
		}
		delete[] array1;
	}
	else
	{
		int i = 0;
		for (i; i < busy; i++)
		{
			if (array[i] == value)
			{
				return false;
			}
			if (array[i] > value)
			{
				break;
			}
		}
		if (i == busy) array[i] = value;
		else
		{
			T temp1 = array[i],temp2;
			array[i] = value;
			i++;
			for (i; i <= busy; i++)
			{
				temp2 = array[i];
				array[i] = temp1;
				temp1 = temp2;
			}
		}
	}
	busy++;
	return true;
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
	size = value.size;
	busy = value.busy;
	delete[] array;
	array = new T[size];
	for (int i = 0; i < busy; i++)
	{
		array[i] = value.array[i];
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
}
template<typename T>
bool Set<T>::erase(const T& value)
{
	try
	{
		if(busy==0) throw -2;
		else if (busy != 1)
		{
			size_t i = 0;
			bool flag = false;
			for (i; i < busy; i++)
			{
				if (array[i] == value) flag = true;
				if (flag && i != busy - 1)
				{
					array[i] = array[i + 1];//да фактически поселдний элемент никуда не денется, это статичн данные
					//и я не могу их удалить, но т.к. весь доступ к элементам офрмлен через busy эту память можно 
					//будет легко перезаписать и этот элемент не будет выведен на экран
				}
			}
			if (!flag) return false;
		}
		else 
		{
			if (array[0] != value) return false;
		}
	}
	catch (int thr)
	{
		std::cout << "Error: " << thr << " - Empty SET!";
		return false;
	}
	busy--;
	return true;
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