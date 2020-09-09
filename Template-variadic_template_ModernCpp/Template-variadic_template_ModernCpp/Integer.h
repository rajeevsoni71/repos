#pragma once
#include<iostream>

class Integer
{
	int* m_val;
	friend std::ostream& operator << (std::ostream& out, const Integer& c);
public:
	Integer();//default constructor
	Integer(int val); // overloaded constructor/deligating constructor
	Integer(const Integer& val);//copy constructor
	Integer(Integer&& val) noexcept; //move constructor
	~Integer(); // destructor
	Integer& operator=(const Integer& rhs);//copy assignment
	Integer& operator=(Integer&& rhs) noexcept;//move assignment
	//setter/getter
	void set_Integer(int val);
	int get_Integer() const;
};
