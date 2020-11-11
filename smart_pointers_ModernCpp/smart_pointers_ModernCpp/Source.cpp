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
	Student() = delete;
	Student(const char* arr, int a) {
		if (arr != nullptr) {
			int len = strlen(arr) + 1;
			Name = (char*)malloc((len + 1) * sizeof(char));
			strcpy_s(Name, len + 1, arr);
		}
		age = a;
	}
	Student operator=(const Student& obj) {
		Student tmp(obj.Name, obj.age);
		return tmp;
	}
	~Student() {
		free(Name);
	}
	void display() const {
		std::cout << Name << ":" << age << std::endl;
	}
};
int main() {
	Student st("Raj", 32);
	Student dd = st;
	st.display();
	return 0;
}