#include <iostream>
#include <vector>
#include <list>

/***************** typedef *********************/
typedef unsigned int UINT;
UINT var{ 30 };

typedef long long int LLINT;
LLINT var1{ 3454323399999999999 };

typedef std::vector<int> VecInt;

typedef const char* (*ERRORFN)(int);

const char* errMessage(int err) {

	if (err == 0) {
		return "success";
	}
	else {
		"ERROR";
	}
}

ERRORFN errmsg = errMessage;

/***************** type aliases **********************/
using UINT1 = unsigned int;
using ULLONG = unsigned long long;
using Fptr = const char* (*)(int);
Fptr fptr = errMessage;

/************* templatization of typedef and type alias ************/
typedef std::vector<std::list<std::string>> Names;

template<typename T>
using NAMES = std::vector<std::list<T>>;

class Employee {
	std::string name;
	int id;
public:
	Employee() = default;
};

int main() {
	std::cout << var << std::endl;
	std::cout << var1 << std::endl;
	VecInt vec (10,1);
	VecInt::const_iterator cit = vec.begin();

	while (cit != vec.end()) {
		std::cout << *cit << " ";
		cit++;
	}

	Names name;
	//Names<Employee> lis; //ERROR, As typedef doesn't support template parmaeter
	NAMES<Employee> neams;
	return 0;
}