/*
* Generalizing lambda capture is in C++14
*/
#include <iostream>
#include <fstream>

int main() {
	int x{ 5 };
	auto lambda = [xx=x](int val) {
		return val * xx;
	};
	std::cout << lambda(4) << std::endl;

	/*
	* But where will this feature is use full
	*/

	std::ofstream out{"file.txt"};
	//why move because ofstream class cannot copied 
	auto lamfile = [out=std::move(out)](int val) mutable { // mutable becasue we the editing the out inside the lambda
		out << val;
	};
	//but don;t want out to be use anywhere in the code except the lambda function
	// then use generalization lambda
	lamfile(300);
	return 0;
}