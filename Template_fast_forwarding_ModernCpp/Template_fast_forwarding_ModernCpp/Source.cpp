#include<string>

#include "Integer.h"

//Has a relationship or composition
class Employee {
	std::string m_Name;
	Integer m_Id;
public:
	Employee()=delete; // Now no one can create empty employee object
	//Employee(const std::string& name, const Integer& id): // this will call parameterised constructor
	//	m_Name{ name },  //--> this will call copy constuctor
	//	m_Id{ id }{      //--> this will call copy constuctor
	//	    std::cout << __FUNCSIG__ << std::endl;
	//}

	//Employee(std::string&& name, Integer&& id) : // this will call parameterised constructor
	//	m_Name{name},//--> this will still call copy constuctor
	//	m_Id{std::move(id)}{    //--> this will still call copy constuctor, because it has a name and due to that it explicitly call CC
	//	//and due to name it will become l-value that's why it call's CC
	//	//To solve this add std::move()call inside.
	//	std::cout << __FUNCSIG__ << std::endl;
	//}
	template<typename T1, typename T2>
	Employee(T1 &&name, T2 &&id) : // this will call parameterised constructor
		m_Name{std::forward<T1>(name)},//--> this will still call copy constuctor
		m_Id{std::forward<T2>(id)}{
		std::cout << __FUNCSIG__ << std::endl;
	}
};

int main() {
	/*Employee e1{"Rajeev",27};*/
	/*output of above code
		__thiscall Integer::Integer(int)
		__thiscall Integer::Integer(const class Integer &)
		Destructor is called for 27
		Destructor is called for 27
	*-----------------------------------------------------
	* So why two constuctors are called as we are passing temprary values.
	* Because even we pass the temparrary values to constuctor
	* but it received as l-value references
		Employee(const std::string& name, const Integer& id): // this will call parameterised constructor
			m_Name{ name }, //--> this will call copy constuctor
			m_Id{ id }{     //--> this will call copy constuctor
		}
	* so because of above reason two times Integer constructor called
	*/

	//So let make the Emplyee constructor to accept r-value reference (&&)
	/* Output of calling r-valuereference constructor
		__thiscall Integer::Integer(int)
		__thiscall Integer::Integer(const class Integer &)
		__thiscall Employee::Employee(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &&,class Integer &&)
		Destructor is called for 27
		Destructor is called for 27
	*/

	//so after adding std::move it calls move cosntructor of Integer class
	/* output after adding std::move()
		__thiscall Integer::Integer(int)
		__thiscall Integer::Integer(class Integer &&) noexcept
		__thiscall Employee::Employee(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &&,class Integer &&)
		Desturctor is called for nullptr
		Destructor is called for 27
	*/

	//But after adding all this problem is still not solved
	//As User wouldn;t create the object everytime like that  "Employee e1{"Rajeev",27};"

	// Lets check
	//std::string name{"Rajeev"};
	//Employee e2{ name, 27 };
	/*Output of type e2
	__thiscall Integer::Integer(int)
	__thiscall Integer::Integer(const class Integer &)
	__thiscall Employee::Employee(const class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &,const class Integer &)
	Destructor is called for 27
	Destructor is called for 27
	*/
	//what why it is calling the Employee's class overloaded constructor
	//becasue even though the 2nd argument is temprary the first argument is type of l-value
	//that's why Integer class copy constructor is called 
	//Integer id{ 100 };
	//Employee e2{ "Raj", id };
	/*
	* For this as well the ooutput will be same and explanation as well.
	*/
	/*std::string name1{ "Rajeev" };
	Integer id1{ 100 };
	Employee e2{ name1, id1 };*/
	/*
	* For this as well, output and explanation will be same.
	*/
	/************************So how to give solution for all types*********************
	* 1. Create all overloaded constructors with all possible inputs
	*	1.1. But it will be tidious because if a class has more input then,
	*        it is not possible to create each and every constructor inside a class.
	* 2. Create a constuctor using template
	*
	* so comment all constructors and create a template member constructor.
	*/

	//After template
	Employee e1{ "Rajeev",27 };
	/*
	__thiscall Integer::Integer(int)
	__thiscall Employee::Employee<const char(&)[7],int>(const char (&)[7],int &&)
	Destructor is called for 27
	*/
	//But here as well it calls the Integer copy constructor instead of move constructor

	//Solution for that
	// use std::forward() which tells the compiler that please preserve the type of the data during the initlization of another type
	/*
	__thiscall Integer::Integer(int)
	__thiscall Employee::Employee<const char(&)[7],int>(const char (&)[7],int &&)
	Destructor is called for 27
	*/
	return 0;
}