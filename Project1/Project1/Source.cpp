#include <iostream>
#include <string>
#include <typeinfo>
class Contact {
    std::string m_Name;
    int m_Phone_number;
    std::string m_Address;
    std::string m_Email;
    friend std::ostream& operator<<(std::ostream& out, const Contact& obj) {
        out << obj.m_Name << ","
            << obj.m_Address << ","
            << obj.m_Phone_number << ","
            << obj.m_Email << ",";
        return out;
    }
public:
    Contact(std::string name, int phone_number, std::string add, std::string email) :
        m_Name(name), m_Phone_number(phone_number),m_Address(add),m_Email(email){
    }
};
class Employee {
    std::string m_Name;
    int m_Id;
    int m_salary;
    friend std::ostream& operator<<(std::ostream& out, const Employee& obj) {
        out << obj.m_Name << ","
            << obj.m_Id << ","
            << obj.m_salary << ",";
        return out;
    }
public:
    Employee(std::string name,int id, int sal) :
        m_Name(name), m_Id(id), m_salary(sal) {

    }
};

template<typename T1,typename...params>
T1* CreateObject(params&&... args) {
    return new T1(std::forward<params>(args)...);
}

int main() {
    int* p1 = CreateObject<int>(5);
    std::cout << *p1 << std::endl;
    delete p1;
    
    std::string* s = CreateObject<std::string>("C++");//Default construction
    std::cout << *s << std::endl;
    delete s;

    Employee* emp = CreateObject<Employee>("Bob", 101,1000);
    std::cout << *emp << std::endl;
    delete emp;

    Contact* p = CreateObject<Contact>("Joey", 987654321, "Boulevard Road, Sgr", "joey@poash.com");
    std::cout << *p << std::endl;
    delete p;
	return 0;
}

/*Output
5
C++
Bob,101,1000,
Joey,Boulevard Road, Sgr,987654321,joey@poash.com,
*/