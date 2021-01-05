#include <iostream>

class ABC {
	int a{};
	int b{};
public:
	ABC(){
		std::cout << "Default constructor" << std::endl;
	};
	ABC(int a, int b) {
		std::cout << "Param constructor" << std::endl;
		this->a = a;
		this->b = b;
	}
	ABC(const ABC& lol){
		std::cout << "copy constructor" << std::endl;
		this->a = lol.a;
		this->b = lol.b;
	}
	ABC& operator=(const ABC& lol) {
		std::cout << "copy assignemnt" << std::endl;
		this->a = lol.a;
		this->b = lol.b;
		return *this;
	}
};

int main() {
	ABC shubh;
	ABC raj(2,3);
	shubh = raj;// copy assignment call
	ABC shashi = raj;// copy contrucctor call (copy intializsation)
	//Demo d;
}
//out put
/*
d c
p c
c a
c c
*/