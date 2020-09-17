#include <iostream>
#include<iterator>
#include <vector>
#include <utility>
/*
* Lambda Expressions
*/

auto Max = [](const auto& val1, const auto& val2) {
	return val1 > val2 ? val1 : val2;
};

auto Min = [](const auto& val1, const auto& val2) {
	return val1 < val2 ? val1 : val2;
};

auto Greater = [](const auto& val1, const auto& val2) {
	return val1 > val2 ? true : false;
};

auto Less = [](const auto& val1, const auto& val2) {
	return val1 < val2 ? true : false;
};

auto MinMax = [](auto start_it, auto end_it) {
	decltype(start_it)::value_type min = { *start_it };
	decltype(start_it)::value_type max  = { *start_it };
	//1 2 3 4 5
	//min
	//max
	if (start_it != end_it) {
		for (start_it; start_it != end_it; start_it++) {
			auto tmp = *start_it;
			if (min > tmp) {
				min = *start_it;
			}
			else if (max < tmp) {
				max = *start_it;
			}
		}
	}
	return std::make_pair(min,max);
};

int main() {
	std::cout << std::boolalpha;
	std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
	std::vector<int>::iterator it_s = vec.begin();
	std::vector<int>::iterator it_e = vec.end();
	auto ret0 = Max(23, 323);
	auto ret1 = Min(23, 323);
	auto ret2 = Greater(123,456);
	auto ret3 = Greater(321,123);
	auto ret4 = Less(123, 456);
	auto ret5 = Less(321, 123);
	auto ret6 = MinMax(it_s,it_e);
	std::cout << ret0 << std::endl;
	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
	std::cout << ret3 << std::endl;
	std::cout << ret4 << std::endl;
	std::cout << ret5 << std::endl;
	std::cout << ret6.first << ", "<< ret6.second << std::endl;
	return 0;
}