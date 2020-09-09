// queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <list>
#include <string>

template<typename T>
void display(T qq) {
	std::cout << "[ ";
	while (!qq.empty()) {
		std::cout << qq.front() << " ";
		qq.pop();
	}
	std::cout << "]\n";
}

void Test1() {
	std::cout << "**********Test1 int queue**********" << std::endl;
	std::queue<int> q;
	q.push(2);
	q.push(3);
	std::cout << "front: " << q.front() << std::endl;
	std::cout << "back: " << q.back() << std::endl;
	std::cout << "size: " << q.size() << std::endl;
	display(q);

}

void Test2() {
	std::cout << "**********Test2 string queue**********" << std::endl;
	std::queue<std::string> q;
	q.push("rajeev");
	q.push("soni");
	std::cout << "front: " << q.front() << std::endl;
	std::cout << "back: " << q.back() << std::endl;
	std::cout << "size: " << q.size() << std::endl;
	display(q);
}

class Person {
	std::string name;
	int age;
	friend std::ostream& operator<<(std::ostream& os, const Person& obj) {
		os << obj.name << ":" << obj.age;
		return os;
	}
public:
	Person() { this->name = ""; this->age = 0; }
	Person(std::string name, int age)
		: name{name}, age{age} {}
};

void Test3() {
	std::cout << "**********Test3 class queue**********" << std::endl;
	std::queue<Person> q;
	q.push(Person("rajeev",27));
	q.push(Person("soni",27));
	std::cout << "front: " << q.front() << std::endl;
	std::cout << "back: " << q.back() << std::endl;
	std::cout << "size: " << q.size() << std::endl;
	display(q);
}

void Test4() {
	std::cout << "**********Test4 list,vector and deque queue**********" << std::endl;
	std::queue<int, std::list<int>> lst_qq;
	lst_qq.emplace(1);
	lst_qq.emplace(34);
	lst_qq.emplace(11);
	std::cout << "front: " << lst_qq.front() << std::endl;
	std::cout << "back: " << lst_qq.back() << std::endl;
	std::cout << "size: " << lst_qq.size() << std::endl;
	display(lst_qq);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
