#include "pch.h"
#include "CppUnitTest.h"
#include "../Project5/Header.h"
#include <set> 
//tests version 2.1
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
			Set<int> a1; Set<char> b1; Set<point> c1;
			std::set<int> a2; std::set<char> b2; std::set<point> c2;
			bool fa, fb, fc;
			point r1;

			for (int i = 0; i < 128; i++)
			{
				a1.insert(i);
				a2.insert(i);

				b1.insert(i);
				b2.insert(i);

				r1 = { i,i,i };
				c1.insert(r1);
				c2.insert(r1);
			}

			for (int i = 0; i < 128; i++)
			{
				fa = *a1.find_it(i) == *a2.find(i);
				Assert::AreEqual(true, fa);

				fb = *b1.find_it(i) == *b2.find(i);
				Assert::AreEqual(true, fb);

				r1 = { i,i,i };
				fc = *c1.find_it(r1) == *c2.find(r1);
				Assert::AreEqual(true, fc);
			}
		}
		TEST_METHOD(TestMethodFind)
		{
			Set<int> a1; Set<char> b1; Set<point> c1;
			bool fa, fb, fc;
			point r1;
			for (int i = 0; i < 128; i++)
			{
				a1.insert(i);

				b1.insert(i);
	
				r1 = { i,i,i };
				c1.insert(r1);
			}
			for (int i = 0; i < 128; i++)
			{
				fa = a1.find(i);
				Assert::AreEqual(true, fa);

				fb = b1.find(i);
				Assert::AreEqual(true, fb);

				r1 = { i,i,i };
				fc = c1.find(r1);
				Assert::AreEqual(true, fc);
			}
		}
		TEST_METHOD(TestMethodErase)
		{
			Set<int> a1; Set<char> b1; Set<point> c1;
			std::set<int> a2; std::set<char> b2; std::set<point> c2;
			bool fa, fb, fc;
			point r1;

			for (int i = 0; i < 128; i++)
			{
				a1.insert(i);
				a2.insert(i);

				b1.insert(i);
				b2.insert(i);

				r1 = { i,i,i };
				c1.insert(r1);
				c2.insert(r1);
			}

			for (int i = 0; i < 127; i++)
			{
				fa = *a1.erase(a1.set_begin()) == *a2.erase(a2.begin());
				Assert::AreEqual(true, fa);

				fb= *b1.erase(b1.set_begin()) == *b2.erase(b2.begin());
				Assert::AreEqual(true, fb);

				fc = *c1.erase(c1.set_begin()) == *c2.erase(c2.begin());
				Assert::AreEqual(true, fc);
			}
		}
		TEST_METHOD(TestMethodAssignmentOperator)
		{
			Set<int> a1; Set<char> b1; Set<point> c1;
			Set<int> a2; Set<char> b2; Set<point> c2;
			bool fa, fb, fc;
			point r1;

			for (int i = 0; i < 128; i++)
			{
				a1.insert(i);
				
				b1.insert(i);
				
				r1 = { i,i,i };
				c1.insert(r1);
			}

			a2 = a1;
			b2 = b1;
			c2 = c1;

			for (int i = 0; i < 128; i++)
			{
				fa = *a2.find_it(i) == *a1.find_it(i);
				Assert::AreEqual(true, fa);

				fb = *b2.find_it(i) == *b1.find_it(i);
				Assert::AreEqual(true, fb);
				
				r1 = { i,i,i };
				fc = *c2.find_it(r1) == *c1.find_it(r1);
				Assert::AreEqual(true, fc);
			}
		}
	};
}
