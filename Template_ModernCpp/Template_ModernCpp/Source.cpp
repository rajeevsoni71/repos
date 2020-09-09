#include <iostream>

//int MAX(int x , int y) {
//	return x > y ? x : y;
//}
//
//float MAX(float x, float y) {
//	return x > y ? x : y;
//}

/*
* if you don't call template method then the code
* will not generate 
*/
template<class T>// or you can use typename as well instead of class
T MAX(T x, T y) {
	return x > y ? x : y;
}

int main() {
	auto num1 = MAX(1,2);
	std::cout << num1 << std::endl;
	auto num2 = MAX(1.0f, 2.99f);
	std::cout << num2 << std::endl;
	return 0;
}