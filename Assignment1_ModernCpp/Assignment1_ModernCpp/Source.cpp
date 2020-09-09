#include <iostream>
int Add(int* a, int* b);    //Add two numbers and return the sum
void AddVal(int* a, int* b, int* result); //Add two numbers and return the sum through the third pointer argument
void Swap(int* a, int* b);  //Swap the value of two integers
void Factorial(int* a, int* result);       //Generate the factorial of a number and return that through the second pointer argument
int main() {
	int x, y, result;
	std::cout << "Enter two number:" << std::endl;
	std::cin >> x >> y;
	std::cout << "Addition: " << Add(&x,&y) << std::endl;
	AddVal(&x,&y,&result);
	std::cout << "AddVal: " << result << std::endl;
	std::cout << "Before swap: " << x << " " << y << std::endl;
	Swap(&x,&y);
	std::cout << "After swap: " << x << " " << y << std::endl;
	result = 1;
	Factorial(&x,&result);
	std::cout << "Factorial of :" << x << " is " << result << std::endl;
	return 0;
}

int Add(int* a, int* b) {
	return *a + *b;
}
void AddVal(int* a, int* b, int* result) {
	*result = *a + *b;
}
void Swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
void Factorial(int* a, int* result) {
	if (*a == 1) {
		*result = 1;
		return;
	}
	else if (*a == 2) {
		*result = 2;
		return;
	}
	else {
		for (int i = *a; i >= 1; i--) {
			*result*=i;
		}
	}
}