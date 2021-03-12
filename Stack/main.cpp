#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"



int main() {
	Stack<int> A;
	for (int i = 0; i < 20; i++) {
		A.push(i);
	}
	return 0;
}