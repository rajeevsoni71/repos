#include <iostream>
#include <thread>
#include <future>
#include <exception>
#include <Windows.h>

std::string concatstring1(const std::string& a,const std::string &b) {
	std::cout << __FUNCTION__ << "+" << std::endl;
	std::string c = a + b;
	std::cout << __FUNCTION__ << "-" << std::endl;
	return c;
}

void concatstring2(const std::string& a, const std::string& b) {
	std::cout << __FUNCTION__ << "+" << std::endl;
	std::string c = a + b;
	std::cout << __FUNCTION__ << "-" << std::endl;
	std::cout << c;
}

int calculatesquare(int a) {
	std::cout << __FUNCTION__<< "+" << std::endl;
	a = a * a;
	std::cout << __FUNCTION__<< "-" << std::endl;
	return a;
}

class String {
public:
	String() {
		std::cout << __FUNCTION__ << std::endl;
	}
	~String() {
		std::cout << __FUNCTION__ << std::endl;
	}
	String(const String& obj) {
		std::cout << __FUNCTION__ << "(const String&)" << std::endl;
	}
	String& operator=(const String& obj) {
		std::cout << __FUNCTION__ << std::endl;
		return *this;
	}
};

void stringclass(const String& a) {
	std::cout << __FUNCTION__ << "+" << std::endl;
	Sleep(2000);
	std::cout << __FUNCTION__ << "-" << std::endl;
}

int main() {
	try {
		std::future<int> fp = std::async(std::launch::deferred,calculatesquare, 5);
		if (fp.valid()) {
			std::cout << fp.get() << std::endl;
		}
		std::future<std::string> fps = std::async(std::launch::async,concatstring1,"Hello","world");
		if (fps.valid()) {
			std::cout << fps.get() << std::endl;
		}
		std::string a{"rajeev"};
		std::string b{"soni"};
		std::cout << "Main thread 1 \n\n";
		std::thread thread1(concatstring2,std::cref(a),std::cref(b));
		String s;
		//std::thread thread2(stringclass,s);//this will call a copy constructor
		std::thread thread2(stringclass, std::cref(s));
		/*
		* Once you reading the return value from the thread then
		* it is not available again so make sure you shouldn't read
		* return value again otherwise it will through no state Exception.
		*/
		//std::cout << fp.get(); // Runtime error, throws exception
		thread1.join();
		thread2.join();
		std::cout << "Main thread 2 \n\n";
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " <<e.what() << std::endl;
	}
	return 0;
}