/*--std::optional
* 1) A new library type that can be used when a function may
*    or may not return a value.
* 2) If it doesn't return a value, a common way is to compare
*    with a predifnedvalue such as 0,nullptr,true/false etc.
* 3) This leads to different kind of checks for different types
* 4) std::optional<T> can be represent a type that may or
*    may not contain a value.
*    4.1) often called nullable type
*/

/*-- properties
* 1) To repersent an empty value you can use std::nullopt type.
* 2) std::optional is a value type - so it can be copied through deep copy
* 3) Doesn't need to allocate any memory on heap
* 4) you cannot store referencees inside std::optional
* 5) Provides sevral overloaded operators and funtions to access the
*    value safely.
* 6) if you try to access a value from std::optional andit doesn't
*    contain any value then it will throw exception std::bad_optional_access
*/

#include <iostream>
#include <optional>
#include <exception>

//create a function which will return a error msg based on errno.

const char* GetErrorString(int errNo) {
	switch (errNo)
	{
	case 0:
		return "Invalid Input";
		break;
	case 1:
		return "Permission not granted";
		break;
	case 2:
		return "Connection lost";
		break;
	default:
		return "";
		break;
	}
}

std::optional<const char*> GetErrorStringOp(int errNo) {
	switch (errNo)
	{
	case 0:
		return "Invalid Input";
		break;
	case 1:
		return "Permission not granted";
		break;
	case 2:
		return "Connection lost";
		break;
	default:
		return std::nullopt;
		break;
	}
}

//example using class
class ContactName {
	std::string firstName;
	std::optional<std::string> middleName;
	std::string lastName;
public:
	ContactName(const std::string & fName, const std::optional<std::string> &mName,const std::string &lName)
		:firstName{fName}, middleName{mName}, lastName{lName} {

	}
	void print() {
		std::cout << this->firstName << ' ';
		std::cout << this->middleName.value_or("") << ' ';
		std::cout << this->lastName << std::endl;
	}
};

int main() {

	/*
	* after return nullptr withour optional statments are not valid
	*/
	//auto message = GetErrorString(23);
	////we don't want to print message wwithout validate
	//if (message != "") {
	//	std::cout << message << std::endl;
	//}
	//else {
	//	std::cout << "Unknown error" << std::endl;
	//}
	////or
	//auto message1 = GetErrorString(2);
	//if (strlen(message1) != 0) {
	//	std::cout << message1 << std::endl;
	//}
	//else {
	//	std::cout << "Unknown error" << std::endl;
	//}

	// But we wnt to use optional so let see how we can use it
	//one way to intialise 
	std::optional<const char*> value; // C++17 only feature
	//second way to intialise
	auto value1 = std::make_optional(90);
	//third way or direct intialise 
	std::optional value2{32};

	value = GetErrorString(90);
	if (value.has_value()) {
		//if the value is null then it throw 
		//bad_optional_access exception
		std::cout << value.value() << std::endl;
		//OR
		//But do not recommend this ways bcoz
		//if the value is null  then program may crash
		//std::cout << *value << std::endl;
	}
	else {
		std::cout << "Unknown Error type" << std::endl;
	}
	try {
		//Second function which return std::optional
		auto errmessage = GetErrorStringOp(23);
		//std::cout << errmessage.value() << std::endl;// just to catch exception
		// there is one more function whcih can use to get value as well as pprint the error msg in case it in empty
		std::cout << errmessage.value_or("Default.") << std::endl;

		if (errmessage.has_value()) {
			std::cout << errmessage.value() << std::endl;
		}
		else {
			std::cout << "unknown error messgae" << std::endl;
		}

		if (errmessage) {
			std::cout << *errmessage << std::endl;
		}
		else {
			std::cout << "Unknown error messgae" << std::endl;
		}

		// you can reset the value of optional using reset function later after use is done.
		value.reset();
	}
	catch (const std::exception& ex) {
		std::cout << "Exception: "<< ex.what() << std::endl;
	}
	/*
	* std::optional is become the statndard way to check the return of the function
	*/

	/*
	* use class as an example
	*/
	ContactName CN1{"Shashi","Kant","Maurya"};
	//so here if we pass nullopt then it will not allocate memory for middle string
	//for this property it is called nullable type
	ContactName CN2{"Rajeev",std::nullopt,"Soni"};

	CN1.print();
	CN2.print();

}