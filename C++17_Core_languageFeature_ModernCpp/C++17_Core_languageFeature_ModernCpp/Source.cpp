#include<iostream>
#include <vector>
//??=define MSG "GeeksforGeeks" // trigraph
//??=define Program "C++"
void check(int a) throw (int) {//warning C5040: dynamic exception specifications are valid only in C++14 and earlier; treating as noexcept(false)
	if (a > 100)
		throw 1;
}
//void feature_add_remove() {
//	register int a = 90; //warning
//	bool chalo = false;
//	chalo++; // Error
//	chalo--; // never allow
//
//	//std::auto_ptr<int> ptr ( new int(20)); // error deleted from c++17
//	//replace it by unique_ptr
//	std::unique_ptr<int> ptr1{ new int(32) };
//	//other pointers
//	std::shared_ptr<int> ptr3{ new int(323) };
//	std::weak_ptr<int> ptr4{ ptr3 };
//	std::weak_ptr<int> ptr45{ new int{34} }; // error no matching constructor argument like that
//	std::cout << ptr4.use_count();
//	auto b = { 1,2,3,5 }; // std::initializer_list;
//	auto a{ 1,2 }; // error
//	auto c{ 3 };
//	std::vector<int> one{ 1,3,4,5,6,7 };
//	std::vector<char> two{ 'A','B' };
//	auto itr1 = one.begin();
//	auto itr2 = two.begin();
//	while (itr1 != two.end()) {
//		itr1++;
//	}
//}

[[deprecated("deprecated, May be new version is came")]]
void createArray(int size) {
	//deprecated
}

class [[deprecated("deprecated  class, May be new version is came")]] demo {

};

namespace [[deprecated("deprecated namespace, May be new version is came")]] android {

};

template<typename T>
[[nodiscard("return value cannot be discarded")]]
T* createArray(int size) {
	return new T[size];
}

void CPP20_Features() {
	//if and switch with intializer
	int* ptr1 = (int*)malloc(sizeof(int));
	if (ptr1 != nullptr) {
		*ptr1 = 1;
		std::cout << "yeppy " << *ptr1 << std::endl;
	}
	else {
		return;
	}
	// here ptr is accessable after the if statement but  we don't want anyone to access it
	if (int* ptr = (int*)malloc(sizeof(int)); ptr != nullptr)
	{
		*ptr = 90;
		std::cout << "yeppy " << *ptr << std::endl;
		free(ptr);
	}
	else {
		*ptr = 50;
	}
	//*ptr = 99; //error 

	switch (int a = 90;*ptr1+a) {
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	free(ptr1);
}

void inline_feature() {

}

int main() {
	int* val = createArray<int>(3); // memory leakage at return is not take care
	//demo d;
	//using namespace android;
}