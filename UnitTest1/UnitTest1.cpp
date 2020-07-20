#include "pch.h"
#include "CppUnitTest.h"
#include "../Project5/Source.cpp"//����� �� ����� ������� ���� � ������� ������� �������?

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethodInsert)
		{
			Set<int> int_s(100); bool flag_int;
			Set<char> char_s(100); bool flag_char;
			for (int i = 32; i < 132; i++)
			{
				//��������� ���������� �������
				flag_int = int_s.insert(i);
				Assert::AreEqual(true, flag_int);
				flag_char = char_s.insert(i);
				Assert::AreEqual(true, flag_char);
				//�������� �������� ��� ��������� �������
				flag_int = int_s.insert(i);
				Assert::AreEqual(false, flag_int);
				flag_char = char_s.insert(i);
				Assert::AreEqual(false, flag_char);
			}
		}
		TEST_METHOD(TestMethodErase)
		{
			Set<int> int_s(100); bool flag_int;
			Set<char> char_s(100); bool flag_char;
			//��������� set�
			for (int i = 32; i < 132; i++)
			{
				int_s.insert(i);
				char_s.insert(i);
			}
			for (int i = 32; i < 132; i++)
			{
				//�������� ������������ �������
				flag_int = int_s.erase(i);
				Assert::AreEqual(true, flag_int);
				flag_char = char_s.erase(i);
				Assert::AreEqual(true, flag_char);
				//�������� �������� �������������� �������
				flag_int = int_s.erase(i);
				Assert::AreEqual(false, flag_int);
				flag_char = char_s.erase(i);
				Assert::AreEqual(false, flag_char);
			}
		}
		TEST_METHOD(TestMethodfind)
		{
			Set<int> int_s(100); bool flag_int;
			Set<char> char_s(100); bool flag_char;
			//��������� set�
			for (int i = 32; i < 132; i++)
			{
				int_s.insert(i);
				char_s.insert(i);
			}
			for (int i = 32; i < 132; i++)
			{
				//���� ������������ ��������
				flag_int = int_s.find(i);
				Assert::AreEqual(true, flag_int);
				flag_char = char_s.find(i);
				Assert::AreEqual(true, flag_char);
				//���� �������������� ��������
				flag_int = int_s.find(i+100);
				Assert::AreEqual(false, flag_int);
				flag_char = char_s.find(i+100);
				Assert::AreEqual(false, flag_char);
			}
		}
		TEST_METHOD(TestMethodOperatorEquals)
		{
			Set<int> int_s(100), int_s1(100); bool flag_int;
			Set<char> char_s(100), char_s1(100); bool flag_char;
			size_t a = 32, b = 132;
			//��������� set�
			for (size_t i = a; i < b; i++)
			{
				int_s.insert(i);
				char_s.insert(i);
			}
			int_s1 = int_s;
			char_s1 = char_s;
			//��������� �����. size
			Assert::AreEqual(int_s.set_size(), int_s1.set_size());
			Assert::AreEqual(char_s.set_size(), char_s1.set_size());
			for (size_t i = a; i < b; i++)
			{
				//�������� ��� ��������, �������� �� ��, ��� � ��� ����������, ��� ����� ������ ���� 1
				flag_int = int_s1.erase(i);
				Assert::AreEqual(true, flag_int);
				flag_char = char_s1.erase(i);
				Assert::AreEqual(true, flag_char);
			}
		}
	};
}
