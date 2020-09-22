#include <iostream>
#include <map>

class Person {
public:
	std::string m_Name;
	int m_age;
	friend std::ostream& operator<<(std::ostream& out, const Person& obj) {
		out << obj.m_Name << ", " << obj.m_age << std::endl;
		return out;
	}
public:
	Person() :Person("",0) {}
	Person(const std::string& name, int age) : m_Name{name}, m_age{age} {}
	~Person() {}
};

struct st {
	int arr[8];
	char name[20];
};

int main() {
	Person p;
	std::cout << p;
	//now we  will use structure binding to modify value of object p
	auto& [l_name, l_age] = p; // only public member can bind to the l_name and l_age(anonymous object)
	// as it is a reference of object p we can change the values as well
	l_name = "Rajeev";
	l_age = 100;
	std::cout << p;
	const auto& [name, age] = p;
	//age = 10; // ERROR

	std::map<int, std::string> errorInfo{ {1, "Not available"}, {2, "Port is in use"} };

	for (auto err : errorInfo) {
		std::cout << err.first << ":" << err.second << std::endl;
	}
	//strcture binding in map
	for (auto [key, value] : errorInfo) {
		std::cout << key << ":" << value << std::endl;
	}

	//struture binding in array
	int arr[] = { 1,2,3 };
	auto [a, b, c] = arr;
	//But arr2 is not array type
	auto arr2 = arr; // arr2 pointer type 

	// now check if the we have strcutre with array inside
	struct st sobj { {0}, "" };
	auto [arr11, arr22] = sobj; // arr11 and arr22 is array type
	return 0;
}
