#include<iostream>
#include <string>
#include <cstring>

std::string ToUpper(const std::string &str) ;
std::string ToLower(const std::string &str) ;
void Display(const std::string& str);

int main() {
	std::string s1{"hello"}; // convert to upper
	std::string s2{"WORLD"}; // conver to lower

	Display(ToUpper(s1));
	Display(ToLower(s2));

	return 0;
}

std::string ToUpper(const std::string& str)
{
	std::string tmp{str};
	for (size_t i = 0; i < str.length(); i++) {
		tmp[i] = std::toupper(str[i]);
	}
	return tmp;
}

std::string ToLower(const std::string& str)
{
	std::string tmp{str};
	for (size_t i = 0; i < str.length(); i++) {
		tmp[i] = std::tolower(tmp[i]);
	}
	return tmp;
}

void Display(const std::string& str)
{
	std::cout << str << std::endl;
}