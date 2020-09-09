#pragma once
#include <iostream>
class Integer
{
	int* m_ptr;
public:
	//constructor Overloading
	Integer();
	Integer(int val);
	Integer(const Integer&);
	Integer(Integer &&) noexcept;
	~Integer();

	//setter/getter
	void setValue(int);
	int getValue() const;

	//Operator Overloading
	Integer& operator=(const Integer&);
	Integer& operator=(Integer&&) noexcept;
	Integer& operator++(); //Pre-Increment
	Integer operator++(int); //Post-Increment
	bool operator==(const Integer &) const;
	Integer operator+(const Integer &); // Allow a=a+b and c=a+b;
};
Integer operator +(int x, const Integer& obj); // Allow a/b = 4+a;
std::ostream& operator <<(std::ostream& out, const Integer& obj);
std::istream& operator >> (std::istream& input, Integer& obj);
