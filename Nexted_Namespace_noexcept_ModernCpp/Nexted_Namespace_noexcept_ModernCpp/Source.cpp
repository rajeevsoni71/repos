#include <iostream>
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
	return 0;
}