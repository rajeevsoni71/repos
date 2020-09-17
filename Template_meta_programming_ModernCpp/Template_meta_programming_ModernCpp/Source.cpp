#include <iostream>
#include <type_traits>

template <typename T>
T add(T a, T b) {
	if (!std::is_floating_point<T>::value) {
		return a + b;
	}
	else {
		return 0;
	}
}

int main() {
	std::cout << "It is an void " << std::is_pointer<int*>::value << std::endl;
	std::cout << add(1, 2) << std::endl;
	std::cout << add(1.f, 2.f) << std::endl;
}