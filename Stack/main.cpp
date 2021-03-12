#include <iostream>

using namespace std;

#include "Stack.h"



int main() {
	Stack<int> A;
	A.pop();
	try {
		A.pop();	
	}
	catch (const exc::EStackEmpty& e)
	{
	};
	return 0;
}