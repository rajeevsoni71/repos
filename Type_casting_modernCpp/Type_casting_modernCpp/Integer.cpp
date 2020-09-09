#include "Integer.h"

Integer::Integer(): Integer(0)
{
	std::cout << "Integer()" << std::endl;
}

Integer::Integer(int val) : m_ptr(new int{val})
{
	std::cout << "Integer(int)" << std::endl;
}

Integer::Integer(const Integer& lhs) : Integer(*lhs.m_ptr)
{
	std::cout << "Integer(const Integer&)" << std::endl;
}

Integer::Integer(Integer&& lhs) noexcept
{
	std::cout << "Integer(const Integer&&)" << std::endl;
	this->m_ptr = lhs.m_ptr;
	lhs.m_ptr = nullptr;
}

int Integer::getValue() const
{
	return *m_ptr;
}

Integer& Integer::operator=(const Integer& lhs)
{
	std::cout << "operator=(const Integer& lhs)" << std::endl;
	if (this != &lhs) {
		delete m_ptr;
		m_ptr = new int{*lhs.m_ptr};
	}
	return *this;
}

Integer& Integer::operator=(Integer&& lhs) noexcept
{
	std::cout << "operator=(Integer&& lhs)" << std::endl;
	if (this != &lhs) {
		delete m_ptr;
		m_ptr = lhs.m_ptr;
		lhs.m_ptr = nullptr;
	}
	return *this;
}

Integer& Integer::operator++()
{
	++(*this->m_ptr);
	return *this;
}

Integer Integer::operator++(int)
{
	Integer tmp{*this};
	++(*m_ptr);
	return tmp;
}

bool Integer::operator==(const Integer& lhs) const
{
	return (*this->m_ptr == *lhs.m_ptr);
}

Integer Integer::operator+(const Integer& lhs)
{
	Integer tmp;
	*tmp.m_ptr = *(this->m_ptr) + *(lhs.m_ptr);
	return tmp;
}

void Integer::setValue(int val)
{
	*this->m_ptr = val;
}

Integer::~Integer()
{
	std::cout << "~Integer()" << std::endl;
	delete m_ptr;
}

Integer operator+(int x, const Integer& obj)
{
	Integer tmp;
	tmp.setValue(x+obj.getValue());
	return tmp;
}

std::ostream& operator<<(std::ostream& out, const Integer& obj)
{
	// TODO: insert return statement here
	out << obj.getValue() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& input, Integer& obj)
{
	int x;
	std::cout << "Enter integer value:" << std::endl;
	input >> x;
	obj.setValue(x);
	return input;
}
