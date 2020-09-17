#include <iostream>
#include <iomanip>

constexpr int BITS{ sizeof(int) * 8};

auto LSB = [](int num) {
	return num & 1 ? true : false; 
};

auto MSB = [](int num, int type) {
	if (type == 1) {
		auto msb = 1 << (BITS - 1);
		return (num & msb) ? true : false;
	}
	else {
		auto tmp = num >> (BITS - 1);
		return (num & tmp) ? true : false;
	}
};

auto NBIT = [](int num, int bit,int type) {
	if (type == 1) {
		auto msb = 1 << (bit);
		return (num & msb) ? true : false;
	}
	else {
		auto tmp = (num >> bit);
		return (tmp & 1) ? true : false;
	}
};

auto SETNBIT = [](int num, int bit) {
	auto loc = 1 << (bit);
	//1011
	//0100 | bitwise OR operator
	//----
	//1111
	num |= loc;
	return num;	
};

auto CLEARNBIT = [](int num, int bit) {
	auto loc = ~(1 << (bit));
	//1011-11  -------.  1011
	//1000-(1<<bit)   |     &
	//0111 ~(1<<bit)--.  0111
	//                   0011
	num &= loc;
	return num;
};

auto HIGHERORDER = [](int num) {
	int place{};
	for (size_t i = 0; i < BITS; i++)
	{
		if ((num>>i) & 1)
			place = i;
	}
	return place;
};

auto LOWERORDER = [](int num) {
	int place{};
	for (size_t i = 0; i < BITS; i++)
	{
		if ((num >> i) & 1) {
			place = i;
			break;
		}
	}
	return place;
};

auto TOGGLENBIT = [](int num, int bit) {
	auto loc = (1 << (bit));
	//1011-11 
	//0010-(1<<bit)
	//bitwise XOR operator{01 or 10 will be 1 and 00 or 11 will be 0}
	//1001
	num ^= loc;
	return num;
};

auto TRAILINGZERO = [](int num) {
	int count{};
	for (size_t i = 0; i < BITS; i++)
	{
		if ((num >> i) & 1)
			break;
		count++;
	}
	return count;
};

int main() {
	int num{ 11 }; // 1011
	/*
	* MSB---> 1 0 1 1 <- LSB
	* 
	*/
	//8421
	//1100
	int num2{-1};
	std::cout << std::boolalpha;
	std::cout << " LSB of " << num << " is set : " << LSB(num) << std::endl;
	std::cout << " MSB of " << num2 << " is set : " << MSB(num2,1) << std::endl;
	std::cout << " MSB of " << num2 << " is set : " << MSB(num2,2) << std::endl;
	std::cout << " Nth bit of " << num << " is set : " << NBIT(num, 1, 1) << std::endl;
	std::cout << " Nth bit of " << num << " is set : " << NBIT(num, 1, 2) << std::endl;
	std::cout << " set Nth bit of " << num << ",Now new num is: " << SETNBIT(num, 2) << std::endl;
	std::cout << " clear Nth bit of " << num << ",Now new num is: " << CLEARNBIT(num, 3) << std::endl;
	std::cout << " toggle Nth bit of " << num << ",Now new num is: " << TOGGLENBIT(num, 1) << std::endl;
	std::cout << " Higher order of " << num << " is: " << HIGHERORDER(num) << std::endl;
	std::cout << " Higher order of " << num2 << " is : " << HIGHERORDER(num2) << std::endl;
	std::cout << " Lower order of " << num << " is: " << LOWERORDER(num) << std::endl;
	std::cout << " Lower order of " << num2 << " is : " << LOWERORDER(num2) << std::endl;
	std::cout << " Traling Zero in " << num << " is : " << TRAILINGZERO(num) << std::endl;
	return 0;
}

/*
leading zeros
num = 22 , 00000000000000000000000000010110
         , -------------27------------

*/
