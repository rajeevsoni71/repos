#include <iostream>
#include <string>
#include <any>
class Integer {
	int a;
	friend std::ostream& operator<<(std::ostream& out, const Integer& obj) {
		out << obj.a << std::endl;
		return out;
	}
public:
	Integer(int a) :a{ a } {
		std::cout << __FUNCSIG__ << std::endl;
	}
	Integer(const Integer& r) {
		this->a = r.a;
		std::cout << __FUNCSIG__ << std::endl;
	}
	Integer(Integer&& rj) noexcept {
		this->a = rj.a;
		rj.a = NULL;
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Integer() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	Integer& operator=(Integer&& rj) noexcept {
		this->a = rj.a;
		rj.a = NULL;
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};
void Basic() {
	std::any number{ 10 };
	// any may allocate memory in heap so 
	//you may need to deallocate it as soon as 
	//you are done with it.
	// by using reset()

	//number.reset(); 
	//Important any can throw the exception
	try {
		std::cout << std::any_cast<int>(number) << std::endl; // if we call reset before using then it will throw exception so reset it after use
		/*std::cout << std::any_cast<std::string>(number) << std::endl;*/// this throw exception
		number.reset();
		//But if you want ot reuse it after reset then
		using namespace std::string_literals;
		number = "Rajeev"s;
		std::cout << std::any_cast<std::string>(number) << std::endl;

		// if you want to check the value before use then you can use 
		if (number.has_value()) {
			//and if you want to check the type explicitly before any_cast to prevent from exception
			if (number.type() == typeid(std::string)) {
				std::cout << std::any_cast<std::string>(number) << std::endl;
			}
		}
	}
	catch (const std::exception& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}
}
int main() {
	/*
	* std::any_cast<Integer> - this return rvlaue by default
	* std::any_cast<Integer&> - this will return the reference of that object
	*/
	//you can use class type as well
	//std::any lol{Integer(3)};
	auto lol = std::make_any<Integer>(4);
	try {
		if (lol.has_value()) {
			/*std::cout << std::any_cast<Integer>(lol);*/ // this calls a copy constructor
			//so we will cast by reference
			//lol.reset();//this will throw exception
			auto n1 = std::any_cast<Integer&>(lol);
			std::cout << n1; // Now the problem is solved:)
			//lets chanage the value
			//std::cout << std::any_cast<Integer&>(lol); // but it throw exception here we need to capture by referecne
			auto &n2 = std::any_cast<Integer&>(lol);
			n2 = 400;
			std::cout << std::any_cast<Integer>(lol);

		}
	}
	catch (const std::exception &ex) {
		std::cout << "Exception: " <<ex.what() << std::endl;
	}
	return 0;
}