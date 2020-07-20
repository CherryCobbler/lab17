//Задание: реализовать SET на массиве и методы: KK, operator=, insert, erase(выдает исключение при пустом множестве),
//size, operator<<, clear, find
#pragma once
#include <iostream>
template <typename T>
class Set {
private:
	size_t size;
	size_t busy=0;//сколько занято
	T* array;
public:
	Set();
	Set(const size_t nsize); //понятно, что по логике нормальному сету не задают размер,
//но нормальный set построен на списках и там нет проблемы с добавление элементов и выделение памяти под них
//поэтому логично дать возможность задать размер, чтобы операций перезаписи из одного массива в другой было меньше
//а не прихоидлось делать их каждый раз, как добавляется элемент
	~Set();
	bool insert(const T& value);
	Set(const Set& value);
	Set& operator= (const Set& value);
	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, const Set<T>& value);
	bool find(const T& value) const;
	size_t set_size() const;
	void clear();
	bool erase(const T& value);
};
int main();

