#include <iostream>
#include <iomanip>
#include <type_traits>
#include <typeinfo>

/*
* -----> _v ( just check the value)  --> C++17
* -----> _t (perform transformation) --> C++14
*/


//type_traits
template<typename T>
T divide(T a, T b) {
	//if (std::is_floating_point<T>::value == false) {
	//	std::cout << "Use only floating point numbers" << std::endl;
	//	return 0;
	//}
	//we can use the type traits suffix in this case as well like
	if (std::is_floating_point_v<T> == false) {
		std::cout << "Use only floating point numbers" << std::endl;
		return 0;
	}

	return a / b;
}

template <typename T1>
void check(T1&& ) {
	std::cout << std::boolalpha;
	if (std::is_pointer_v<T1> == true) {
		std::cout << "Is a pointer." << std::endl;
	}
	else if (std::is_reference_v<T1> == true) {
		std::cout << "Is a reference." << std::endl;
	}
	else if (std::is_rvalue_reference_v<T1> == true) {
		std::cout << "Is a r-value reference." << std::endl;
	}
	else if (std::is_integral_v<T1> == true) {
		std::cout << "Is a integral." << std::endl;
	}
	else if (std::is_array_v<T1> == true) {
		std::cout << "Is a Array." << std::endl;
	}
	else {
		std::cout << "is a " << typeid(T1).name() << "." << std::endl;
	}
}
// suppose we want to serialise the objects of a number class into a file or a network

//serialization means we will write the state of number object into the stream
// means we will right some value along with the information aobut the class  into the m_int;

//while deserializing the system has to first create the instances of the Interger using the the default constructor
//since it deosn;t have a default constructor, we will not able to deserialize it.

//SOwe would like to disallow usage of the serialization 
//and deserialization facility of those classes that 
//doesn;t provide default constructor
class Integer {
	int m_int;
public:
	//add due to static assert shows error
	Integer() = default;
	Integer(int val) :m_int(val) {}
};

int main() {
	//So we will use static_assert(statement,"error message");
	static_assert(std::is_default_constructible<Integer>::value,"Only Object with deafult constructor can be deserialized.");
	//if we deson't provide thedefault constructor static assert
	//will show compiletime error as the integerclass doesnot have Default constructor
	/*-------------------------------------------------------------------------------------------*/
	//you can use type alias of type traits
	//so all the type traits which we are using they have a special
	// value member  like below
	// they provide the alias that have _v suffix to check the value 
	//so wedon;t have to use ::value any more
	static_assert(std::is_default_constructible_v<Integer>, "Only Object with deafult constructor can be deserialized.");

	//how to check the type of value passed into the function using type_traits and typeinfo
	check(3);
	check(&Integer());
	std::string name{"rajeev"};
	check(name);
	check(&name);
	char ch[] {"rajev"};
	check(ch);
	return 0;
}