#include <iostream>
#include <sstream>
namespace A {
	namespace B {
		namespace C {
			void foo() {
				std::cout << __FUNCSIG__ <<std::endl;
			}
		}
	}
}
namespace X::Y::Z {
	void func() {
		std::cout << __FUNCSIG__ << std::endl;
	}
}

void function_1() {
	std::cout << __FUNCSIG__ << std::endl;
}

void function_2() noexcept {
	std::cout << __FUNCSIG__ << std::endl;
}

using functionPtr = void(*)() noexcept;

class Demo {
	int *value;
public:
	Demo() :Demo(0) {};
	Demo(int val){
		value = new int(val);
	}
	Demo(const Demo& rhs) {
		this->value = new int(*rhs.value);
	}
	~Demo() {
		delete value;
	}
	auto display() {
		return [*this](const std::string &header) {
			std::ostringstream out;
			out << header << std::endl;
			out << "value: " << *value << std::endl;
			return out.str();
		};
	}
};

int main() {
	using namespace A::B::C;
	foo();
	A::B::C::foo();
	X::Y::Z::func();

	// no except feature enhancement in c++17
	functionPtr fp;
	//fp = function_1; // error
	fp = function_2;
	fp();

	//constexpr lambda expression
	auto sum = [](int a, int b)  { 
		return a + b;
	};

	int arr[sum(3,4)]{}; // so here lmbda expression can be used ans constants

	Demo d;
	d.display();

	Demo* obj = new Demo{12};
	auto desc = obj->display();
	std::cout << desc("############");
	delete obj;
	// the object is already deleted so we need some machanisum
	//to know the function that the value shouldn't dependent on intialized object
	std::cout << desc("############");
	return 0;
}