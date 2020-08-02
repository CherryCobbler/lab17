#include "pch.h"
#include "CppUnitTest.h"
#include "../Project5/Header.h"
//tests version 1.2
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethodConstructorANDConstructorCopy)
		{
			/*To be honest, I don't really understand how to test the constructor yet, 
			so far I only thought of creating possible options and, accordingly, 
			if it doesn't break, it works.*/
			Set<int> a1; Set<char> b1;
			Set<int> a2(0); Set<char> b2(0);
			Set<int> a3(1000); Set<char> b3(1000);
			/*Set<int> a4(-1); Set<char> b4(-1);-It should give an error when you try to create it, 
			but so far I haven't found documentation on how to make it count this result as positive.*/

			//In this version of tests, I don't see the point in separating the constructor and the copy constructor.
			Set<int> aa1(a1); Set<char> bb1(b1);
			Set<int> aa2(a2); Set<char> bb2(b2);
			Set<int> aa3(a3); Set<char> bb3(b3);
		}
		TEST_METHOD(TestMethodInsert)
		{
			Set<int> a1; Set<char> b1;
			const int* iflag; const char* cflag;
			for(int i = 0; i < 128; i++)//
			{

				iflag = a1.insert(i);
				Assert::AreEqual(i, *iflag);//here I can compare by value
				iflag = a1.insert(i);
				Assert::AreNotEqual(a1.set_begin()+i, iflag);//but here it will be someone else's memory

				cflag = b1.insert(i);
				Assert::AreEqual(b1.set_begin() + i, cflag);//after 127, insert with char does not quite adequately perceive incoming data 
				//(the function works correctly, but the value returned to it is a curve), 
				//which is logical since 128 is already Russian letters. 
				//Is it an error writing insert or is it supposed to be?
				cflag = b1.insert(i);
				Assert::AreNotEqual(b1.set_begin() + i, cflag);
			}
		}
		TEST_METHOD(TestMethodSet_Begin)
		{
			//This is my only idea how to test a single-line method: return array
			Set<int> a; Set<char> b;
			const int* iiflag; const char* ciflag;
			const int* isflag; const char* csflag;

			iiflag = a.insert(1);
			isflag=a.set_begin();
			Assert::AreEqual(iiflag, isflag);

			ciflag = b.insert(1);
			csflag = b.set_begin();
			Assert::AreEqual(ciflag, csflag);
		}
		TEST_METHOD(TestMethodFind_It)
		{
			Set<int> a1; Set<char> b1;
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
			}
		}
		TEST_METHOD(TestMethodErase)
		{
			//version 1.0
			Set<int> a; Set<char> b;
			bool iflag, cflag;
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
			}
		}
		TEST_METHOD(TestMethodSet_Capasity)
		{
			Set<int> a; Set<char> b;
			Set<int> a1(0); Set<char> b1(0);
			Set<int> a2(1000); Set<char> b2(1000);
			size_t i1=1, i2=0, i3=1000;

			Assert::AreEqual(i1, a.set_capasity());
			Assert::AreEqual(i1, b.set_capasity());
			Assert::AreEqual(i2, a1.set_capasity());
			Assert::AreEqual(i2, b1.set_capasity());
			Assert::AreEqual(i3, a2.set_capasity());
			Assert::AreEqual(i3, b2.set_capasity());
		}
		TEST_METHOD(TestMethodSet_Size)
		{
			Set<int> a(1000); Set<char> b(1000);
			size_t i1 = 0,i2=128;

			Assert::AreEqual(i1, a.set_size());
			Assert::AreEqual(i1, b.set_size());

			for (int i = 0; i < 128; i++)
			{
				a.insert(i);
				b.insert(i);
			}

			Assert::AreEqual(i2, a.set_size());
			Assert::AreEqual(i2, b.set_size());

		}
		TEST_METHOD(TestMethodClear)
		{
			Set<int> a1; Set<char> b1;
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
			Assert::AreNotEqual(cflag, b1.set_begin());
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
			Set<int> a1; Set<char> b1;
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
				
			}
		}
	};
}
