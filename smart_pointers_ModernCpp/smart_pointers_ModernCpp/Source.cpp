#include <iostream>
#include <cstring>
class Student {
	char* Name{};

	int age{};
public:
	//rule of 3
	//1. copy constructor
	//2. copy asignment operator overloading
	//3. destructor
	Student() :Student(nullptr,1) {};
	Student(const char *arr, int a) {
		if (arr != nullptr) {
			int len = strlen(arr) + 1;
			Name = new char[(len) * sizeof(char)];
			strcpy_s(Name, len, arr);
		}
		else {
			Name = new char[1];
			strcpy_s(Name, 1, "");
		}
		age = a;
	}
	//Solution for abort at runtime
	Student(const Student& obj) {
		age = obj.age;
		int len = strlen(obj.Name)+1;
		Name = new char[len];
		strcpy_s(Name, len, obj.Name);
	}
	Student operator=(const Student& obj) {
		Student tmp(obj.Name, obj.age);
		return tmp;
	}
	~Student() {
		if (Name != nullptr) {
			delete Name;
			Name = nullptr;
		}
		else {
			std::cout << "already free" << std::endl;
		}
	}
	void display() const {
		std::cout << Name << ":" << age << std::endl;
	}
	friend std::ostream& operator<<(std::ostream& out, const Student& obj);
};
int main() {
	Student st("Raj", 32);
	Student dd = st; // this will call copy constructor that's why abort happen at run time
	st.display();
	std::cout << dd;
	return 0;
}

std::ostream& operator<<(std::ostream& out, const Student& obj)
{
	out << obj.Name << ":" << obj.age << std::endl;
	return out;
}
