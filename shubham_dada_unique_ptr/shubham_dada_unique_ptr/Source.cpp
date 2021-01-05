#include <iostream>
#include<memory>
using namespace std;
int main() {
	unique_ptr<int> shubh{ new int{50} };
	return 0;
}