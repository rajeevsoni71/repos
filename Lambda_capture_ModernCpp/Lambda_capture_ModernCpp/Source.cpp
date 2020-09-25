#include <iostream>
/*
* lamda are implemented as a anonymous class, 
*/
/*
* Static & global variables are automatically available to a lambda expressions.
* They're NOT captured in the way local variables are, because they're global.
*
* Note that lambda  expressions are internally implemented as classes
* with overloaded operator().So, the same rules of access apply to them.
* If a variable is global or static, it will be accessible anywhere.
*/

/*
* Cppreference:

    The identifier in any capture without an initializer 
	(other than the this-capture) is looked up using usual 
	unqualified name lookup in the reaching scope of the lambda. 
	The result of the lookup must be a variable with 
	automatic storage duration declared in the reaching scope.

(emphasis mine)

"To capture" means to put a copy or a reference to a 
variable into a lambda object itself.

Global and static variables have fixed memory location. 
You don't need to store copies or references to them to 
use them since their location is known at compile time 
and doesn't change.

(If you really want to have a copy of a global or static variable, 
you can create it using named capture from C++14, 
which lets you create a custom member variable in a lambda object. 
But such capture is not necessary if you just want to use that 
global / static variable.)

Automatic variables, on the other hand, don't have a fixed location. 
Multiple lambdas created at the exact same place could refer 
to different automatic variables. Because of that, 
a lambda object has to capture such variable - 
which means to contain either a reference to used 
automatic variable or a copy of it.
*/

static int cap{30};
int main() {
	int a = 10;
	auto capture = [&ref=cap](int a) -> int {
		return ref * a;
	};
	std::cout << cap << std::endl;
	std::cout << capture(10) << std::endl;
	std::cout << cap << std::endl;
}