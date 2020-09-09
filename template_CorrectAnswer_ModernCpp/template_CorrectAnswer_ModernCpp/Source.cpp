// Example program
#include <iostream>
#include <typeinfo>

//pimary template
template<class T0>
T0 MAX(T0 a, T0 b) {
	std::cout << typeid(T0).name() << std::endl;
	return a > b ? a : b;
}

//explicit Instanstiation
template char MAX(char x, char y);

//explecit specialization 
template<> const char* MAX<const char*>(const char*a,const char* b) {
	std::cout << "Explicit Sp" << std::endl;
	return strcmp(a,b) > 0 ? a : b;
}

int main()
{
	auto char1 = MAX('A', 'B');
	std::cout << "MAX " << char1 << std::endl;
	const char* a{ "B" }, *b{ "A" };
	auto charPtr1 = MAX(a, b);
	std::cout << "MAX " << charPtr1 << std::endl;
}
/*
* without template specialization
char
MAX B
char const *
MAX A
* with template specialization
char
MAX B
Explicit Sp
MAX B

*/
