#include "People.h"

People::People() :People("", 0)
{
	//std::cout << __FUNCSIG__ << " obj: " << this << std::endl;
}

People::People(const std::string& name, int age)
	: m_Name{name}, m_Age{ new int(age)}
{
	std::cout << __FUNCSIG__ << " obj: " << this << std::endl;
}

People::People(const People& obj) 
	: m_Name{ obj.m_Name }, m_Age{ new int{*obj.m_Age} }
{
	std::cout << __FUNCSIG__ << " obj: " << this << std::endl;
}

People& People::operator=(const People&)
{
	// TODO: insert return statement here
}

People::People(People&& obj)  noexcept
{

}

void People::showa(const People& obj)
{
	std::cout << "Name: " << obj.getName() <<
		", Age: " << obj.getAge() << std::endl;
}

std::string People::getName() const
{
	return m_Name;
}

int People::getAge() const
{
	return *m_Age;
}

void People::showDetails()
{
	std::cout << "Name: " << m_Name <<
		", Age: " << m_Age << std::endl;
}

People::~People()
{
	delete m_Age;
	std::cout << __FUNCSIG__ << " obj: " << this << std::endl;
}
