#include "Integer.h"
#include "CDerived.h"
void Basic_to_Basic() {
	/*
	* -------------------- Part 1 -------------------------
	* Without any const qualifiers
	*/
	int x = 10;
	/*
	* you cannot use static cast to cast between different
	* type as static_cast checks types if it is same then only
	* it allow casting otherise give compile time error.
	*/
	//char* c1_ptr = static_cast<char*>(&x); // ERROR
	/*
	* Apart from using static_cast you can use
	* reinterpret_cast to type cast between different
	* types
	*/
	char* c2_ptr = reinterpret_cast<char*>(&x);
	/*
	* -------------------- Part 2 -------------------------
	* When you have const qualifiers
	*/

	/*
	* static cast doesn't allow user to cast const qualifier
	*/
	const int y = 100;
	int z = 100;
	//int* ci1_ptr = static_cast<int*>(&y); // ERROR
	/*
	* reinterpret cast doesn't allow user to cast const qualifier
	*/
	//int* ci2_ptr = reinterpret_cast<int*>(&y); // ERROR

	int* ci3_ptr = const_cast<int*>(&y); // PASS
	//char* cc1_ptr = const_cast<char*>(&y); // ERROR
	/*
	* const cast can work on without const also
	* but no need because this can be achieve by static_cast.
	*/
	int* ci4_ptr = const_cast<int*>(&z); // PASS

}

void base_to_userdefined() {}
void userdefined_to_base(){}

void userdefined_to_userdefined() {
	/*
	* Dynamic_cast can be used only with pointers and references to objects.
	* Its purpose is to ensure that the result of the type conversion is a
	* valid complete object of the requested class.
	*
	* Therefore, dynamic_cast is always successful
	* when we cast a class to one of its base classes:
	*/
	CBase b; CBase* pb;
	CDerived d; CDerived* pd;

	pb = dynamic_cast<CBase*>(&d);     // ok: derived-to-base
	//pd = dynamic_cast<CDerived*>(&b);  // wrong: base-to-derived 
}
void copy_elicite() {
	Integer a = 10; // Integer a = Integer(10); --> Compiler expends it like this
	// for linux -fno-elide-constructors
	std::cout << a;
}
void Integer_class() {
	Integer a(9);
	auto b = 4 + a;
	auto c = a + b;
	auto d = a + 5 + 3;// OR try a + 5
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;
}

int main() {
	Basic_to_Basic();
	userdefined_to_userdefined();
	copy_elicite();
	Integer_class();
	return 0;
}