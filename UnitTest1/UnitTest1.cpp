#include "pch.h"
#include "CppUnitTest.h"
#include "../Project5/Header.h"
//tests version 1.0
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod—onstructorAND—onstructorCopy)
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

		}
		TEST_METHOD(TestMethodFind_It)
		{

		}
		TEST_METHOD(TestMethodFind)
		{

		}
		TEST_METHOD(TestMethodErase)
		{

		}
		TEST_METHOD(TestMethodSet_Size)
		{

		}
		TEST_METHOD(TestMethodClear)
		{

		}
		TEST_METHOD(TestMethodAssignmentOperator)
		{

		}
	};
}
