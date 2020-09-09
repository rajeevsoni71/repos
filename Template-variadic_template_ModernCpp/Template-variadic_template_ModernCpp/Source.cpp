#include<iostream>
#include <initializer_list>
#include "Integer.h"

/*
* Lets create a print function which can accept any number of argument
* using template
*/
//template<typename T1>
//void Print(std::initializer_list<T1> lst) {
//	for (const auto &elements:lst) {
//		std::cout << elements << " ";
//	}
//}

//base case function to stop recurssion
void Print() noexcept {
	std::cout << std::endl;
}
/*
* Variadic template
*/
//templae parameter pack
template<typename T, typename... params>
//function parameter pack
void Print(T&& a, params&&... args) noexcept { // Now Pass the parameters as reference type
	std::cout << a; //output 1, 2.3, 3, raj, but here it is print comma at last as well so need to remove this,to do that you need to find the size of the argument list first
	/*std::cout << sizeof...(params) << std::endl;
	std::cout << sizeof...(args) << std::endl;*/
	if (sizeof...(args) != NULL)
		std::cout << ", ";
	Print(std::forward<params>(args)...);
}
int main() {
	//Print({1,2,3,4}); // out put 1 2 3 4
	//suppose we want to print double numbers as well
	//Print({1,2.3,3,4});// ERROR,
	// Due to template argument deduction as the Print function have integers and doubles
	//so template will confuse which type to be create at compile time. 

	/*
	* To solve this problem
	* you need to create new template which can accept this type of data
	* Here -We will use variadic template
	*/
	//Print(1,2.3,'3',"raj");

	//**************Lets try using Integer class******************
	Integer i1{ 1 };
	Integer i2{ 2 };
	Print(0,i1,i2,3,4,"rajeev",'f');
	return 0;
}
/*
call stack
1.Print(1,2.3,'3',"raj");
2.Print(2.3,'3',"raj");
3.Print('3',"raj");
4.Print("raj");
5.Print();
*/