#include<iostream>
void Add(int a, int b, int& result);    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int& result);    //Find factorial of a number and return that through a reference parameter
void Swap(int& a, int& b);
/*
Name Mangling:
In compiler construction, name mangling (also called name decoration)
is a technique used to solve various problems caused by the need to 
resolve unique names for programming entities in many 
modern programming languages.

Without Extern C
 0002:00001350       ?Add@@YAXHHAAH@Z           00412350 f   Source.obj
 0002:000013b0       ?Factorial@@YAXHAAH@Z      004123b0 f   Source.obj
 0002:00001480       ?Swap@@YAXAAH0@Z           00412480 f   Source.obj
 
Avoid Namemangling so that function can be called fromc and any other programming language
With Extern C
 0002:00001350       ?Add@@YAXHHAAH@Z           00412350 f   Source.obj
 0002:000013b0       ?Factorial@@YAXHAAH@Z      004123b0 f   Source.obj
 0002:00001700       _Swap
*/
int main() {
	int x{}, y{}, result{};
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> x >> y;
	Add(x, y, result);
	std::cout << "Addition: " << result << std::endl;
	Factorial(x, result);
	std::cout << "Factorial of " << x << " is " << result << std::endl;
	std::cout << "before swap: " << x << " " << y << std::endl;
	Swap(x,y);
	std::cout << "after swap: " << x << " " << y << std::endl;
	return 0;
}

void Add(int a, int b, int& result) {
	result = a + b;
}
void Factorial(int a, int& result) {
	if (a == 1) {
		result = 1;
		return;
	}
	else if (a == 2) {
		result = 2;
		return;
	}
	else {
		if (result != 1)
			result = 1;
		for (int i = 1; i <= a; i++) {
			result *= i;
		}
	}
}
void Swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}