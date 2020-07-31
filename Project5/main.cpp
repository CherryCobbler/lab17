#include "Header.h"
int main()
{
	
	Set<int> a1; Set<char> b1;
	const int* iflag; const char* cflag;
	for (int i = 0; i < 1000; i++)
	{

		/*cflag = b1.insert(i);
		if (b1.set_begin() + i != cflag)
		{
			std::cout << i << "		" << cflag << "		" << b1.set_begin() + i;
			break;
		}*/
	
		//	cflag = b1.insert(i);
			//Assert::AreNotEqual(b1.set_begin() + i, cflag);
	}
	char a = 128;
	cflag = b1.insert(128);
	
	std::cout << b1;
	return 0;
}