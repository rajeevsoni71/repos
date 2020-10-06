#include <iostream>

class Student {
	int m_RollNo;
	char* m_Name;
public:
	Student() {
		m_RollNo = 0;
		m_Name = new char[1];
		strcpy_s(m_Name,sizeof(char), "\0");
		std::cout << __FUNCSIG__ << std::endl;
	}
	Student(int roll, const char* name) {
		m_RollNo = roll;
		m_Name = new char[strlen(name)+1];
		strcpy_s(this->m_Name, strlen(name) + 1,name);
		std::cout << __FUNCSIG__ << std::endl;
	}
	//copy constructor
	Student(const Student& obj) {
		m_RollNo = obj.m_RollNo;
		m_Name = new char[strlen(obj.m_Name) + 1];
		strcpy_s(this->m_Name, strlen(obj.m_Name) + 1,obj.m_Name);
		std::cout << __FUNCSIG__ << std::endl;
	}
	//copy assignment
	Student& operator=(const Student& rhs) {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &rhs) return *this;
		m_RollNo = rhs.m_RollNo;
		m_Name = new char[strlen(rhs.m_Name) + 1];
		strcpy_s(m_Name, strlen(rhs.m_Name)+1,rhs.m_Name);
		return *this;
	}
	~Student() {
		std::cout << __FUNCSIG__ << std::endl;
		delete m_Name;
	}
};

void class_new() {
	Student stu1(123, "Rajeev Soni"); // paramterised constructor
	Student stu2(stu1); //copy constructor
	Student stu3;// default constructor
	Student stu4;// default constructor
	stu3 = stu2;// copy assignment
}
void OneDimArray() {
	//using pointers
	int* arr1 = new int[10];
	for (size_t i = 0; i < 10; i++)
	{
		*(arr1 + i) = i; // address
		std::cout << *(arr1 + i) << " ";
	}
	std::cout << std::endl;
	delete[] arr1;
	//using indexes
	int* arr2 = new int[10];
	for (size_t i = 0; i < 10; i++)
	{
		arr2[i] = i;//value at 
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
	delete[] arr2;
}

void TwoDimArray() {
	int m = 2;
	int n = 2;
	int** row = new int*[m * n];
	int* col = nullptr;
	for (size_t i = 0; i < m*n; i++)
	{

	}
}

int main() {
	OneDimArray();
	return 0;
}


/*
	[5:11 PM] DONGRE Swapnil (Guest)
	int len = strlen(name);
	​[5:11 PM] DONGRE Swapnil (Guest)
	m_name = new char[len+ 1]
*/
