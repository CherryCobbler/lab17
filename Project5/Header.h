#ifndef HEADER_H
#define HEADER_H
//Task: implement SET on an array and methods: CC, operator=, insert, erase,
//size, operator<<, clear, bool find (on the instructions)
//no UnitTests yet
#pragma once
#include <iostream>
template <typename T>
class Set {
private:
	size_t capasity = 0;
	size_t size = 0;
	T* array;
public:
	Set(const size_t ncapasity = 1);
	~Set();
	const T* insert(const T& value);//if returned NULL - the element already exists
	Set(const Set& value);
	Set& operator= (const Set& value);
	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, const Set<T>& value);
	bool find(const T& value) const;//needed for a task
	const T* find_it(const T& value) const;//needed for the insert function
	size_t set_size() const;
	void clear();
	const T* erase(const T* it);
	const T* set_begin() const;
};


#include "Source1.ipp"
#endif


