#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

//.. Классы исключения и стека;
#include "ExceptionStack.h" 
#include "Stack.h"



int main() {
//..Инцилизируем пустой стэк-массив на 10 элементов;
	Stack<int> A(10);

//.. Запускаем заполнение на 20, должна произойти ошибка;
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

// Запускаем очистку стека, он был заполнен на 10 элементов, после 10 должен сломаться;
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