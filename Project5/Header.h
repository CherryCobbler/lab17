//�������: ����������� SET �� ������� � ������: KK, operator=, insert, erase(������ ���������� ��� ������ ���������),
//size, operator<<, clear, find
#pragma once
#include <iostream>
template <typename T>
class Set {
private:
	size_t size;
	size_t busy=0;//������� ������
	T* array;
public:
	Set();
	Set(const size_t nsize); //�������, ��� �� ������ ����������� ���� �� ������ ������,
//�� ���������� set �������� �� ������� � ��� ��� �������� � ���������� ��������� � ��������� ������ ��� ���
//������� ������� ���� ����������� ������ ������, ����� �������� ���������� �� ������ ������� � ������ ���� ������
//� �� ����������� ������ �� ������ ���, ��� ����������� �������
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

