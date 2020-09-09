#include "Integer.h"

Integer::Integer()
{
    std::cout << __FUNCSIG__ << std::endl;
    this->m_val = new int(0);
}

Integer::Integer(int val)
{
    std::cout << __FUNCSIG__ << std::endl;
    this->m_val = new int(val);

}

Integer::Integer(const Integer& val)
{
    std::cout << __FUNCSIG__ << std::endl;
    this->m_val = new int(*val.m_val);
}

Integer::Integer(Integer&& val) noexcept
{
    std::cout << __FUNCSIG__ << std::endl;
    this->m_val = val.m_val;
    val.m_val = nullptr;
}

Integer::~Integer()
{
    if (m_val != nullptr)

        // If the pointer is not 
        // pointing to NULL 
        std::cout << "Destructor is called for "
        << *this->m_val << std::endl;
    else

        // If the pointer is 
        // pointing to nullptr 
        std::cout << "Desturctor is called"
        << " for nullptr"
        << std::endl;
    delete m_val;
}

Integer& Integer::operator=(const Integer& rhs)
{
    // TODO: insert return statement here
    std::cout << __FUNCSIG__ << std::endl;
    if (this != &rhs) {
        this->m_val = new int(*rhs.m_val);
    }
    return *this;
}

Integer& Integer::operator=(Integer&& rhs) noexcept
{
    // TODO: insert return statement here
    std::cout << __FUNCSIG__ << std::endl;
    if (this != &rhs) {
        this->m_val = rhs.m_val;
        rhs.m_val = nullptr;
    }
    return *this;
}

std::ostream& operator << (std::ostream& out, const Integer& c)
{
    out << *c.m_val;
    return out;
}

void Integer::set_Integer(int val)
{
    *this->m_val = val;
}

int Integer::get_Integer() const
{
    return *m_val;
}
