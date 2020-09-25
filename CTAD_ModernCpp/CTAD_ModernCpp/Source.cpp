/*
* CTAD-class template argument deduction
*/
#include <iostream>
#include <utility>
#include <string>

template<typename T>
class Demo {
	T value;
public:
	Demo(const T& v) :value(v){}
};

Demo(const char*)->Demo<std::string>;
Demo(int)->Demo<long>;

int main() {
	std::pair<int, int> p(1,3);
	std::cout << p.first << ", " << p.second << std::endl;
	std::pair p1(3,4);

	Demo<int> d(10);
	/*
	* it wouldn't consider as a string class 
	* instead it will considered as const char[] 
	* so need to specialised the type deduction
	* for this type
	*/
	Demo ds("string");
	Demo dl(30);// here type will be deducted as integer
	/*but we want to be long everytime when the class is instantiated by a integer value
	*so need to specialised the type deduction
	* for this type
	*/
}