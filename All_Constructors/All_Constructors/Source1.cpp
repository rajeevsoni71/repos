#include <iostream>
#include <cstring>

class mystring {
	char* st;
public:
	mystring() :mystring("NULL") {}
	mystring(const char* s) {
		if (s != "NULL") {
			st = new char[strlen(s) + 1];
			strcpy(st, s);
		}
		else {
			st = new char[5];
			strcpy(st, s);
		}
	}
	mystring(const mystring& obj) {
		st = new char[strlen(obj.st) + 1];
		strcpy(st, obj.st);
	}
	mystring& operator=(const mystring& obj) {
		//mystring tmp;
		st = new char[strlen(obj.st) + 1];
		strcpy(st, obj.st);
		return *this;
	}
	~mystring() {
		delete st;
	}
	mystring operator+(const mystring& obj) {
		mystring tmp;
		if (tmp.st)
			delete tmp.st;
		tmp.st = new char[strlen(st) + strlen(obj.st) + 1];
		strcpy(tmp.st, st);
		strcat(tmp.st, obj.st);
		return tmp;
	}

	friend std::ostream& operator<<(std::ostream& out, const mystring& obj);
};

std::ostream& operator<<(std::ostream& out, const mystring& obj) {
	out << obj.st << " ";
	return out;
}

int main() {
	mystring my1("soni"); // calls parameteried c
	mystring my2 = my1; //  copy construstor
	std::cout << my1;  // overload extraction operator
	mystring my3 = "rajeev"; // copy construstor
	my2 = my3; // copy assignment
	std::cout << my2; // overload extraction operator
	std::cout << my3;
	std::cout << std::endl;
	std::cout << my2 + my3; // operator overloading
}