#include <iostream>
#include <numeric>
#include <cassert>

/*
*  ---------> ... 3 dots are called Elipsis
*/

//base case of variadic template
auto sum() {
	return 0;
}

//variadic template
template<typename first,typename ...args>
auto sum(first val, args...nval) {
	return val + sum(nval...);
}
/*sum(1,2,3,4,5);
* return 1 + sum(2,3,4,5);
* return 2 + sum(3,4,5);
* return 3 + sum(4,5);
* return 4 + sum(5);
* return 5 + sum();
* return 5 + 0;
* Becasue we are using recurssion here of the expression can be treated as
* 1+(2+(3+(4+(5+(0)))))
* 1+(2+(3+(4+5)))
* 1+(2+(3+9))
* 1+(2+12)
* 1+14
* 15
* this process is called folding, reduce or accumulate
* 
* we already have a algorithm which can apply unary operation on a list of elements
*/

//helping function for accumulate 
int myfun(int x, int y) { return x + y; }

//functor
class MYFUNC {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

/*
* using fold expresions in c++17
* (pack op ...) unary right fold
* (... op pack) unary left fold
* (pack op ... op init) binary right fold 
* (int op ... op pack) binary left fold
* 
* &&	true
* ||	false
* ,		void()
* other ill-formed
*/

//(pack op ...) unary right fold
/* Expention
* 1+(2+(3+(4+(5+(0)))))
* 
*/
template <class...T2>
auto sum2(T2...args) {
	return (args +...);
}

//(... op pack) unary left fold
/*Expention
* ((((1+2)+3)+4)+5)
*/
template <class...T3>
auto sum3(T3...args) {
	return (... + args);
}

//binary right fold
template <class...T4>
auto sum4(T4...args) {
	return (args + ... + 0);
}

//binary left fold
template <class...T5>
auto sum5(T5...args) {
	return (0 + ... + args);
}

//binary || fold
template <class...T6>
auto anyof(T6...args) {
	return (... || (args % 2 == 0) );
}

//binary && fold
template <class...T7>
auto allof(T7...args) {
	return (... && (args % 2 == 0));
}

void printf(const char* format)
{
    while (*format != '\0') {
        if (*format == '%') {
            if (*(format + 1) == '%') {
                ++format;
            }
        }
        else {
            //invalid string format
            assert(false);
        }

        std::cout << *format++;
    }
}

template<typename T, typename...Args>
void printf(const char* format, T& value, Args...args)
{
    //std::cout << "args size:" << sizeof...(args) << std::endl;
    while (*format != '\0') {
        if (*format == '%') {
            if (*(format + 1) == '%') {
                ++format;
            }
            else { //this is an argument
                std::cout << value;
                //from here on do recurse and pass next format and args
                printf(format + 1, args...);
                return;
            }
        }

        std::cout << *format;
        ++format;
    }
}

//fold expressions
//unary right fold
template <class...T8>
void CustomPrint(T8...args) {
	((std::cout << args << ' '), ...); // extra pair of paranthesis is required to make that entity as a one entity.
}

int main() {
	std::cout << "using variadic template accumulate:" << sum<int>(1,2,3,4,5) << std::endl;

	//another algorithm to accumulate unary operation with different forms
	int v{}; // intial value or called as indentity element
	auto list = {1,2,3,4,5};
	std::cout << "using default accumulate:" << std::accumulate(list.begin(), list.end(), v) << std::endl;
	std::cout << "using functional plus accumulate:" << std::accumulate(list.begin(), list.end(), v , std::plus<int>()) << std::endl;
	std::cout << "using function accumulate:" << std::accumulate(list.begin(), list.end(), v,myfun) << std::endl;
	std::cout << "using functor accumulate:" << std::accumulate(list.begin(), list.end(), v, MYFUNC()) << std::endl;

	//To perform folding till c++14 we use variadic template
	// but in c++17 it introduce folding expressions
	std::cout << "unary right fold:" << sum2(1,2,3) << std::endl;
	std::cout << "unary left fold:" << sum3(1,2,3) << std::endl;
	//you can not call the unary right or left with empty argument list
	// becase when the expention (... + args) take place then
	// args will be 0 and there is no other argements in ...
	//But you canuse binary fold in that case
	std::cout << "binary right fold:" << sum4() << std::endl;
	std::cout << "binary left fold:" << sum5() << std::endl;
	CustomPrint(1,2,34,5,3,6,"rajeev");
	return 0;
}