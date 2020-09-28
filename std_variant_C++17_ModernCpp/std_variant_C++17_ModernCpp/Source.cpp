/*--std::variant
* 1) It is a type-safe replacement of union typess
* 2) Just like union it will use the storage of largest member
* 3) The first member is always default intialised if the variant is default constructed
* 4) Alternatively, you can initialise any one member during the construction of the variant
* 5) Members of the variant destroy properly unlike in union we have to destroy them explicitly
* 6) if the variant is empty it will throw std::bad_variant_access exception
*/

/*
* internals of variant
* get return the reference of active member otherwise throw exception
* get_if returns the pointer to  the active member otherwise return nullptr
* 
* Note:
* In any case if use pass wrong index or type which is not part of variant then
* it is a compiler error.
*/

#include <iostream>
#include <variant>

int main() {
	try {
		/*
		* As we didn't intialise the variant so the currently active member is std::string
		*/
		std::variant<std::string, int> vari1;
		//How to access the value from the variant
		auto value1 = std::get<0>(vari1); // using index
		//OR
		auto value2 = std::get<std::string>(vari1);
		std::cout << value1 << std::endl;
		std::cout << value2 << std::endl;
		//How to get the active member index of variant
		auto activeIndex = vari1.index();
		std::cout << "Active Index: " << activeIndex << std::endl;

		/*
		* Create another variant with initialisation
		* As we intialise the variant so the currently active member will be int
		*/
		std::variant<std::string, int> vari2{ 23 };
		auto value3 = std::get<int>(vari2);
		std::cout << value3 << std::endl;
		auto activeIndex1 = vari2.index();
		std::cout << "Active Index1: " << activeIndex1 << std::endl;

		/*
		* if you will try to access a type which is not in the variant list
		* then you will get compilation error
		* 1) using get<type>(variant);
		* 2) using get<index>(variant);
		*/
		//auto value4 = std::get<float>(vari2); //ERROR
		// OR
		//auto value5 = std::get<3>(vari2); //ERROR


		/*
		* if you trying to access non active member of variant
		* then it will throw runtime exception "bad_variant_access"
		* 1) using get<type>(variant);
		* 2) using get<index>(variant);
		*/
		//auto value4 = std::get < std::string > (vari2); //throws Exception
		// OR
		//auto value5 = std::get<0>(vari2); //throws Exception

		/*
		* you can use get_if to access the variant members
		*/
		auto value4 = std::get_if<std::string>(&vari2);
		if (value4 != nullptr) {
			std::cout << *value4 << std::endl;
		}
		else {
			std::cout << "NULL PTR" << std::endl;
		}

		auto value5 = std::get_if<int>(&vari2);
		if (value5 != nullptr) {
			std::cout << *value5 << std::endl;
		}
		else {
			std::cout << "NULL PTR" << std::endl;
		}
		
		/*
		* How to initialise and construct members of variant class
		* But initialisation/modification happen only for active member otherwise throw exception
		*/
		std::variant < std::string, int > vari3{67};
		vari3 = int{ 32 };
		//or
		std::get<int>(vari3) = 44; 
		//or
		vari3.emplace<int>(99);
		//Another ways to intialise the member is throught visitation

	}
	catch (const std::exception &ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}
