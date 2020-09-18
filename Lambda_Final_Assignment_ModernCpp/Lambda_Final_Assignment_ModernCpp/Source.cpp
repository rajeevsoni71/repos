#include <iostream>
#include<iterator>
#include <vector>
#include <utility>
/*
* --------------Lambda Expressions----------------
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
	typename decltype(start_it)::value_type min = { *start_it };
	typename decltype(start_it)::value_type max  = { *start_it };
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

/*
* -----------Function Object ----------------
*/

template <class T>
struct MAX {
	T operator()(const T&& val1, const T&& val2) const {
		return val1 > val2 ? val1 : val2;
	};
};

template<class T1>
struct MIN {
	T1 operator()(const T1&& val1, const T1&& val2) const {
		return val1 < val2 ? val1 : val2;
	};
};

template<class T2>
struct GREATER {
	bool operator()(const T2&& val1, const T2&& val2) const {
		return val1 > val2 ? true : false;
	};
};

template<class T3>
struct LESS {
	bool operator()(const T3&& val1, const T3&& val2) const {
		return val1 > val2 ? true : false;
	};
};

template<class T4>
struct MINMAX {
	auto operator()(T4 start_it, T4 end_it) const {
		typename decltype(start_it)::value_type min{ *start_it };
		typename decltype(start_it)::value_type max{ *start_it };
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
		return std::make_pair(min, max);
	};
};

void lambda_function() {
	std::cout << std::boolalpha;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int>::iterator it_s = vec.begin();
	std::vector<int>::iterator it_e = vec.end();
	auto ret0 = Max(23, 323);
	auto ret1 = Min(23, 323);
	auto ret2 = Greater(123, 456);
	auto ret3 = Greater(321, 123);
	auto ret4 = Less(123, 456);
	auto ret5 = Less(321, 123);
	auto ret6 = MinMax(it_s, it_e);
	std::cout << ret0 << std::endl;
	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
	std::cout << ret3 << std::endl;
	std::cout << ret4 << std::endl;
	std::cout << ret5 << std::endl;
	std::cout << ret6.first << ", " << ret6.second << std::endl;
}

void fucntion_object() {
	std::cout << std::boolalpha;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int>::iterator it_s = vec.begin();
	std::vector<int>::iterator it_e = vec.end();
	struct MAX<int> max;
	struct MIN<int> min;
	struct GREATER<int> greater;
	struct LESS<int> less;
	struct MINMAX<std::vector<int>::iterator> minmax;
	auto ret0 = max(23, 323);
	auto ret1 = min(23, 323);
	auto ret2 = greater(123, 456);
	auto ret3 = greater(321, 123);
	auto ret4 = less(123, 456);
	auto ret5 = less(321, 123);
	auto ret6 = minmax(it_s, it_e);
	std::cout << ret0 << std::endl;
	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
	std::cout << ret3 << std::endl;
	std::cout << ret4 << std::endl;
	std::cout << ret5 << std::endl;
	std::cout << ret6.first << ", " << ret6.second << std::endl;
}

int main() {
	lambda_function();
	fucntion_object();
	return 0;
}