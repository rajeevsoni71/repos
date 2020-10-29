#include <iostream>
#include <string>

//Pass by reference 
void displayRef(std::string& str) {
	std::cout << __FUNCSIG__ << ": " << str << std::endl;
}

//pass by value
void displayVal(std::string str) {
	std::cout << __FUNCSIG__ << ": " << str << std::endl;
}

//pass by r-value reference
void displayRVR(std::string&& str) {
	std::cout << __FUNCSIG__ << ": " <<str << std::endl;
}

int main() {
	std::string stdstr{"Rajeev"};
	displayRef(stdstr);
	displayRVR(std::move(stdstr));
	displayRVR("raj");
	//stdstr = "soni";
	//std::cout << __FUNCSIG__ << ": " << stdstr << std::endl;
	displayVal(stdstr); // how the value is still there even after move
	return 0;
}