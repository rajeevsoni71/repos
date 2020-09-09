#include <iostream>
#include <string>
int main() {
	//Case 1
	std::string path1{ "D:\Resume.pdf" };// \ special character ir deprecated from the output.
	//So to resolve that we will use Raw string Literals
	std::string path2{R"(D:\Resume.pdf)"};
	std::cout << path1 << std::endl;
	std::cout << path2 << std::endl;

	//Case 2 if you want to print the special characters 
	//std::string string1{"Modern C++11/14/17 "(raw string literal is in c++17)""}; //ERROR it cannot process the special type double quotes
	/* But Here you will face again ERROR*/
	//std::string string1{ R"(Modern C++11/14/17 "(raw string literal is in c++17)")" };
	//So what will bbe the solution for that 
	//hmmmmmmmmmmmmmmmmmmmmm
	// Delimitor in Raw String Literals
	//
	std::string string1{ R"MS(Modern C++11/14/17 "(raw string literal is in c++17)")MS" };
	std::cout << string1 << std::endl;

	return 0;
}
/* Output of case 1
D:Resume.pdf
D:\Resume.pdf

OUtput of case 2
Modern C++11/14/17 "(raw string literal is in c++17)"
*/