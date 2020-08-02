#include "pch.h"
#include "CppUnitTest.h"
#include "../Project5/Header.h"
#include <set> 
//tests version 2.0.0
//new insert
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethodConstructorANDConstructorCopy)
		{
			Set<int> a1; Set<char> b1;
			Set<int> a2(0); Set<char> b2(0);
			Set<int> a3(1000); Set<char> b3(1000);
			Set<point> a4(1000);
			/*Set<int> a4(-1); Set<char> b4(-1);-It should give an error when you try to create it, 
			but so far I haven't found documentation on how to make it count this result as positive.*/

			//In this version of tests, I don't see the point in separating the constructor and the copy constructor.
			Set<int> aa1(a1); Set<char> bb1(b1);
			Set<int> aa2(a2); Set<char> bb2(b2);
			Set<int> aa3(a3); Set<char> bb3(b3);
			Set<point> aa4(a4);
		}
		TEST_METHOD(TestMethodInsert)
		{
			Set<int> a1; Set<char> b1; Set<point> c1;
			std::set<int> a2; std::set<char> b2; std::set<point> c2;
			bool fa1, fb1, fc1;
			bool fa2, fb2, fc2;

			std::pair<const int*, bool> pair_int;
			std::pair<std::set<int>::iterator, bool> fpit1;
			
			std::pair<const char*, bool> pair_char;
			std::pair<std::set<char>::iterator, bool> fpit2;

			std::pair<const point*, bool> pair_point;
			std::pair<std::set<point>::iterator, bool> fpit3;
			point r1;

			for (int i = 0; i < 128; i++)
			{
				pair_int = a1.insert(i);
				fpit1 = a2.insert(i);
				fa1 = *pair_int.first == *fpit1.first;
				fa2= pair_int.second == fpit1.second;
				Assert::AreEqual(true, fa1);
				Assert::AreEqual(true, fa2);

				pair_char = b1.insert(i);
				fpit2 = b2.insert(i);
				fb1 = *pair_char.first == *fpit2.first;
				fb2 = pair_char.second == fpit2.second;
				Assert::AreEqual(true, fb1);
				Assert::AreEqual(true, fb2);

				r1 = { i,i,i };
				pair_point = c1.insert(r1);
				fpit3 = c2.insert(r1);
				fc1 = *pair_point.first == *fpit3.first;
				fc2 = pair_point.second == fpit3.second;
				Assert::AreEqual(true, fc1);
				Assert::AreEqual(true, fc2);
			}
		}
		TEST_METHOD(TestMethodFind_It)
		{
			/*Set<int> a1; Set<char> b1;
			const int* iiflag; const char* ciflag;
			const int* ifflag; const char* cfflag;
			for (int i = 0; i < 127; i++)//
			{
				iiflag = a1.insert(i);
				ifflag = a1.find_it(i);
				Assert::AreEqual(iiflag, ifflag);
				ifflag = a1.find_it(i+1);
				Assert::AreNotEqual(iiflag, ifflag);

				ciflag = b1.insert(i);
				cfflag = b1.find_it(i);
				Assert::AreEqual(ciflag, cfflag);
				cfflag = b1.find_it(i+1);
				Assert::AreNotEqual(ciflag, cfflag);
			}*/
		}
		TEST_METHOD(TestMethodErase)
		{
			//version 1.0
			/*Set<int> a; Set<char> b;
			for (int i = 0; i < 128; i++)
			{
				a.insert(i);
				b.insert(i);
			}
			const int* istart; const char* cstart;
			for (int i = 0; i < 128; i++)
			{
				istart = a.set_begin();
				a.erase(istart);
				Assert::AreEqual(false, a.find(i));
				
				cstart = b.set_begin();
				b.erase(cstart);
				Assert::AreEqual(false, b.find(i));
			}*/
		}
		TEST_METHOD(TestMethodClear)
		{
			/*Set<int> a1; Set<char> b1;
			const int* iflag; const char* cflag;
			iflag = a1.insert(0);
			cflag = b1.insert(0);
			for (int i = 1; i < 128; i++)
			{
				a1.insert(i);
				b1.insert(i);
			}

			a1.clear();
			b1.clear();

			size_t i = 0;
			Assert::AreEqual(i, a1.set_capasity());
			Assert::AreEqual(i, b1.set_capasity());

			Assert::AreEqual(i, a1.set_size());
			Assert::AreEqual(i, b1.set_size());

			Assert::AreNotEqual(iflag, a1.set_begin());
			Assert::AreNotEqual(cflag, b1.set_begin());*/
		}
		TEST_METHOD(TestMethodAssignmentOperator)
		{
			Set<int> a(100); Set<char> b(100);
			Set<int> a1(100); Set<char> b1(100);
			for (int i = 1; i < 128; i++)
			{
				a.insert(i);
				b.insert(i);
			}

			a1 = a;
			b1 = b;

			Assert::AreEqual(a.set_capasity(), a1.set_capasity());
			Assert::AreEqual(b.set_capasity(), b1.set_capasity());

			Assert::AreEqual(a.set_size(), a1.set_size());
			Assert::AreEqual(b.set_size(), b1.set_size());

			const int* iflag1; const char* cflag1;
			const int* iflag2; const char* cflag2;
			iflag1 = a.set_begin();
			iflag2 = a1.set_begin();
			cflag1 = b.set_begin();
			cflag2 = b1.set_begin();
			for (int i = 0; i < 128; i++)
			{
				Assert::AreEqual(*(iflag1 + i), *(iflag2 + i));
				Assert::AreEqual(*(cflag1 + i), *(cflag2 + i));
			}
		}
		TEST_METHOD(TestMethodFind)
		{
			/*Set<int> a1; Set<char> b1;
			bool ifflag; bool cfflag;
			for (int i = 0; i < 127; i++)//
			{
				a1.insert(i);
				ifflag = a1.find(i);
				Assert::AreEqual(true, ifflag);
				ifflag = a1.find(i + 1);
				Assert::AreEqual(false, ifflag);

				b1.insert(i);
				cfflag = a1.find(i);
				Assert::AreEqual(true, cfflag);
				cfflag = a1.find(i + 1);
				Assert::AreEqual(false, cfflag);
				
			}*/
		}
	};
}
