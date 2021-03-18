#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

//.. ������ ���������� � �����;
#include "ExceptionStack.h" 
#include "Stack.h"



int main() {
//..������������ ������ ����-������ �� 10 ���������;
	Stack<int> A(10);

//.. ��������� ���������� �� 20, ������ ��������� ������;
	try
	{
		for (int i = 0; i < 20; i++) { 

			A.push(i); 
			std::cout << i << '\t';
		}
	}
	catch (const exc::Exception& ex)
	{

		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

// ��������� ������� �����, �� ��� �������� �� 10 ���������, ����� 10 ������ ���������;
	try
	{ 
		for (int i = 0; i < 20; i++) {	
				A.pop();
				std::cout << i << '\t';
			}
		}
	catch (const exc::Exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}


	return 0;
}