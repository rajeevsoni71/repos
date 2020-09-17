#include <iostream>
#include <typeinfo>
#include <string>
#include "Source.h"

class lambda_c {
public:
	int operator()(int a , int b) const { // by default it is constant
		return a + b;
	}
};
//OR
struct lambda_s {
	int operator()(int a, int b) const { // by default it is constant
		return a + b;
	}
};

//Parameter pass to lambda expression
struct __Unnamed {
	int sum{};
	void operator()(int a, int b) {
		sum = a + b;
	}
};

template<typename T,int SIZE, typename callback>
void forEach(T (&arr)[SIZE],callback call) {
	for (size_t i = 0; i < SIZE-1; i++)
	{
		call(arr[i]);
	}
}
//pass the class variables to the lambda expression
class Product {
	std::string name;
	int price;
public:
	Product(const std::string &name, int price) :name(name),price(price){}

	void Assignfinalprice() {
		float taxes[]{ 12, 5, 5 };
		auto base_price{this->price};
		forEach(taxes, [base_price, this](float tax) {
			auto finalprice{ base_price * tax / 100 };
			price += finalprice;
		});
	}

	auto get_finalprice() const {
		return this->price;
	}
};

int main() {
	int a{ 10 }, b{ 20 };
	auto lambda = [](int a , int b){
		return a + b;
	};
	std::cout << lambda(a, b) << std::endl;
	/*
	* How the lambda expression is inplemented
	* lets check
	*/
	std::cout << typeid(lambda).name() << std::endl;
	/*
	* Hey wait a second,
	* it implemented as a class
	* --->class <lambda_2102de17be248dd3aaa2e93d1090c0d2>
	*/
	/*
	* Wow now we implement our own lamba expression class
	*/
	lambda_c cls;
	lambda_s stt;
	std::cout << cls(5, 4) << std::endl;
	std::cout << typeid(lambda_c).name() << std::endl;
	std::cout << stt(5, 4) << std::endl;
	std::cout << typeid(lambda_s).name() << std::endl;

	/*Pass varaibles to the lambda expression
	* 1. By value
	* 2. By Reference
	* 3. Both at same time like [1, 2](){}; or [2, 1](){}; repectively as above.
	*/
	int x{ 10 }, y{ 20 };
	int sum{};
	auto lambda1 = [&sum](int a, int b) /*mutable*/ { 
		// Here mutable is written only in case of pass by value and that value need to be change
		//otherwise mutable is not required for pass by reference
		sum = a + b;
		/*
		* Hey wait a second error but why?
		* Hey again Error but why this time?
		*/
	};
	// OR you can use above LE like below only in case of pass by reference
	//auto lambda1 = [&](int a, int b) {
	//	sum = a + b;
	//};
	/*
	* why?
	* Because sum is not accessible in lambda
	* so we need to explicitly capture sum into the lambda
	* solution:
	* pass the sum as a capture list in lambda expression
	* [sum] by value
	*/
	/*
	* why this time?
	* Because we are modifying the sum variable inside the lambda expression,
	* As you know by default LE is declare as const modifier
	* solution :
	* add mutable key word in the LE.
	*/

	//Now print the sum of two variables
	lambda1(x,y);
	//std::cout << "sum: " << sum << std::endl; // Hey, it print <sum: 0> But why?
	/*
	* But why?
	* Because you pass the sum as a value so sum is
	* accessible within the LE as its scope is limited inside LE only.
	* solution:
	* Pass sum varaible as a refernce
	* [&sum] by reference
	*/
	std::cout << "sum: " << sum << std::endl; // perfecto :)
	/*
	* More example of passing the argument in LEs are
	* 1.All variable pass by value
	*	auto lambda1 = [=](...) {};
	* 2.All variable pass by reference
	*	auto lambda2 = [&](...) {};
	* 3.Some vaiable pass by value except one
	*	auto lambda3 = [=, &somevariable](...) {};
	* 4.Some vaiable pass by reference except one
	*	auto lambda3 = [&, somevariable](...) {};
	*/

	//lambda expresssion in class
	Product prd("soni",12345);
	prd.Assignfinalprice();
	std::cout << prd.get_finalprice() << std::endl;
	return 0;
}