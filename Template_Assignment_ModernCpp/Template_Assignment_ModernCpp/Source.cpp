#include <iostream>
/*
* Convert the following functions into templates
*
int Add(int x, int y); //Return the sum of two elements
int ArraySum(int* pArr, int arrSize); //Returns the sum of array elements
int Max(int* pArr, int arrSize); //Return the largest element in the array
std::pair<int, int> MinMax(int* pArr, int arrSize); //Return the smallest and largest element in a pair
*/
template<class T1, class T2>
T1 Add(T1 x, T2 y) {
	return x + y;
}

template<class T3, class T4>
T3 ArraySum(T3* pArr, T4 arrSize) {
	T3 sum = 0;
	for (T4 i = 0; i < arrSize; i++){
		sum += pArr[i];
	}
	return sum;
}

template<class T0>
T0 MAX(T0 a, T0 b) {
	std::cout << typeid(T0).name() << std::endl;
	return a > b ? a : b;
}

template<class T5, class T6>
T5 Max(T5* pArr, T6 arrSize) {
	T5 max = pArr[0];
	for (T6 i = 1; i < arrSize; i++) {
		if (max < pArr[i])
			max = pArr[i];
	}
	return max;
}
//non-type template argument
template<class r,int size>
r Max(r (&pArr)[size]) {
	std::cout << "non type template argument" << std::endl;
	r max = pArr[0];
	for (auto i = 1; i < size; i++) {
		if (max < pArr[i])
			max = pArr[i];
	}
	return max;
}

template<class T7,class T8>
std::pair<T7, T7> MinMax(T7* pArr, T8 arrSize) {
	std::pair<T7, T7> minmax{};
	minmax.first = pArr[0] > pArr[1] ? pArr[1] : pArr[0];//min
	minmax.second = pArr[0] > pArr[1] ? pArr[0] : pArr[1];//max
	for (T8 i = 2; i < arrSize; i++) {
		if (minmax.first > pArr[i]) {
			minmax.first = pArr[i];
		}
		if (minmax.second < pArr[i]) {
			minmax.second = pArr[i];
		}
	}
	return minmax;
}

int main() {
	/*auto num1 = MAX(1, 2);
	std::cout << "MAX " << num1 << std::endl;
	auto num2 = MAX(10.11f, 29.01f);
	std::cout << "MAX " << num2 << std::endl;

	auto num3 = Add(1,2);
	std::cout << "sum " << num3 << std::endl;
	auto num4 = Add(10.11f, 29.01f);
	std::cout << "sum " << num4 << std::endl;
	*/
	int arri[5]{1,2,3,4,5};
	std::cout << "Array sum " << ArraySum(arri,5) << std::endl;
	std::cout << "Array max " << Max(arri, 5) << std::endl;//Normal template
	std::cout << "Array max " << Max(arri) << std::endl;//Non-type template
	std::pair<int, int> p1 = MinMax(arri, 5);
	std::cout << "Array minmax " << p1.first << ", " << p1.second << std::endl;

	float arrf[5]{ 1.01f,2.01f,3.01f,4.01f,5.01f };
	std::cout << "Array sum " << ArraySum(arrf, 5) << std::endl;
	std::cout << "Array max " << Max(arrf, 5) << std::endl;//Normal template
	std::cout << "Array max " << Max(arrf) << std::endl;//Non-type template
	std::pair<float, float> p2 = MinMax(arrf, 5);
	std::cout << "Array minmax " << p2.first << ", " << p2.second << std::endl;
	// you can create a reference to a array
	float(&reff)[5] = arrf;
	std::cout << "Array max " << Max(reff) << std::endl;//Non-type template
	// using of begin function in arr
	auto it = std::begin(reff);//or you can pass arrf

	//Now check can it will work on char or char*(string type)
	//auto char1 = MAX('A', 'B');
	//std::cout << "MAX " << char1 << std::endl;
	//const char *a{"A"}, *b{"B"};
	//auto charPtr1 = MAX(a,b);
	//std::cout << "MAX " << charPtr1 << std::endl;

	return 0;
}

/*
* output:
sum 3
sum 39.12
Array sum 15
Array max 5
Array minmax 1, 5
Array sum 15.05
Array max 5.01
Array minmax 1.01, 5.01
*/