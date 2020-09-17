#include<iostream>
//using Comparator = bool (*)(int, int);
template<typename T, int SIZE, typename Comparator>
void sort(T (&arr)[SIZE],Comparator comp) {
	for (size_t i = 0; i < SIZE -1; i++)
	{
		for (size_t j = 0; j < SIZE -1 ; j++)
		{
			if (comp(arr[j], arr[j + 1])) {
				T tmp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(tmp);
			}
		}
	}
}

bool comp(int a, int b) {
	return a > b;
}

bool comp1(int a, int b) {
	return a < b;
}

struct Comp2 {
	bool operator()(int x, int y) {
		return x > y;
	}
};

struct Comp3 {
	template <typename T>
	bool operator()(const T &x, const T &y) {
		return x > y;
	}
};

template<typename T, int SIZE>
void display(const T(&arr)[SIZE]) {
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[]{98,7,65,3,5,0 };
	display(arr);

	sort(arr,comp);
	display(arr);

	sort(arr, comp1);
	display(arr);

	//function objects or functor
	/*
	* As function pointer cannotbe optimised by the compiler
	* sowe will use function object so that compiler can optimized it
	* and it may be faster then function pointer
	*/
	/*
	* And one more thing is that 
	* 1. function object have a state while
	*    function pointer doesn't have it.
	* 2. we can track the no. of call of function object while
	*    we cannot track the global function because it will be
	*    share among all objects not just one object.
	*/
	Comp2 comp2;
	// now call sort
	sort(arr,comp2);
	display(arr);

	//strings
	Comp3 comp3;
	std::string str_arr[]{
		"amar",
		"chawal",
		"babita"
	};
	display(str_arr);

	sort(str_arr, comp3);
	display(str_arr);

	[]() {
		std::cout << "HEllo! I am anonymos function object or call me lambda expresssion" << std::endl;
	}();
	//??OR you can call lambda expression like 
	auto lm = []() {
		std::cout << "HEllo! I am anonymos function object or call me lambda expresssion" << std::endl;
	};
	lm();

	//Now use lambda expression as a comparator
	std::string str[]{
	"amar",
	"cakbar",
	"bnthoni"
	};
	display(str);
	auto lambda = [](std::string& a, const std::string& b) noexcept(false) ->bool {
		return a > b;
	};
	sort(str, lambda);
	display(str);

	//or you can make egeneric lambda but it introduced in C++14
	auto generic_lambda = [](auto a, const auto b) noexcept ->bool {
		return a > b;
	};

	//noexcept means cannot throw exception
	//noexcept(false) means can throwe exception
}