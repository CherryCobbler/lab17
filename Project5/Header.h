//Task: implement SET on an array and methods: CC, operator=, insert, erase(throws an exception if the set is empty),
//size, operator<<, clear, bool find (on the instructions)
//no UnitTests yet
#pragma once
#include <iostream>
template <typename T>
class Set {
private:
	size_t size;
	size_t busy=0;//how much space is used
	T* array;
public:
	Set();
	Set(const size_t nsize); 
	~Set();
	T* insert(const T& value);//if returned NULL - the element already exists
	Set(const Set& value);
	Set& operator= (const Set& value);
	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, const Set<T>& value);
	bool find(const T& value) const;//needed for a task
	T* find_it(const T& value) const;//needed for the insert function
	size_t set_size() const;
	void clear();
	int erase(const T& value);//If returned -2 - set empty, if -1 - element not found
};

