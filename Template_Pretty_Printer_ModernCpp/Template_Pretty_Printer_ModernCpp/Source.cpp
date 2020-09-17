#include <iostream>
#include <vector>

template<typename T>
class PrettyPrinter {
	T *m_pdata;
public:
	PrettyPrinter():PrettyPrinter(0){}
	PrettyPrinter(T *data):m_pdata(data) {
	}
	void Print() {
		if (m_pdata!= nullptr)
			std::cout << "{ " << *m_pdata << " }" << std::endl;
		else
			std::cout << "{ NULL }" << std::endl;
	}
	T* getData() const {
		return m_pdata;
	}
};

template<>
class PrettyPrinter <char*> {
	char* m_pdata;
public:
	PrettyPrinter() :PrettyPrinter(0) {}
	PrettyPrinter(char* data) :m_pdata(data) {
	}
	void Print() {
		if (m_pdata != nullptr)
			std::cout << "{ " << m_pdata << " }" << std::endl;
		else
			std::cout << "{ NULL }" << std::endl;
	}
	char* getData() const {
		return m_pdata;
	}
};
/*
But for vector problem is with only Print
so lets create only specialized Print function for vector<int> 
instead of whole new template class
*/
//This is called explicit specialization of member function of a class
template<>
void PrettyPrinter<std::vector<int>>:: Print() {
	if (m_pdata != nullptr) {
		std::cout << "{ ";
			for (const auto& element : *m_pdata) {
				std::cout << element << " ";
			}
			std::cout << " }" << std::endl;
	}
	else {
		std::cout << "{ NULL }" << std::endl;
	}
}
//template<>
//class PrettyPrinter <std::vector<int>> {
//	std::vector<int>* m_pdata;
//public:
//	PrettyPrinter() :PrettyPrinter(0) {}
//	PrettyPrinter(std::vector<int>* data) :m_pdata(data) {
//	}
//	void Print() {
//		if (m_pdata != nullptr) {
//			std::cout << "{ ";
//				for (const auto& element : *m_pdata) {
//					std::cout << element << " ";
//				}
//				std::cout << " }" << std::endl;
//		}
//		else {
//			std::cout << "{ NULL }" << std::endl;
//		}
//	}
//	std::vector<int>* getData() const {
//		return m_pdata;
//	}
//};

//std::vector<std::vector<int>>
template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print() {
	if (m_pdata != nullptr) {
		std::cout << "{ ";
		for (const auto& vec : *m_pdata) {
			std::cout << "\n\t{";
			for (const auto& element : vec) {
				std::cout << element;
				if (&element != &vec.back())
					std::cout << ",";
			}
			std::cout << "}";
			if (&vec != &(m_pdata)->back())
				std::cout << ",";
			std::cout << std::endl;
		}
		std::cout << "}" << std::endl;
	}
	else {
		std::cout << "{ NULL }" << std::endl;
	}
}
int main() {
	int i{ 323 };
	float f{ 3232.2323f };
	std::string s{"Rajeev"};
	PrettyPrinter<int> r1(&i);
	PrettyPrinter<float> r2(&f);
	PrettyPrinter<std::string> r3(&s);
	r1.Print();
	r2.Print();
	r3.Print();
	// Now check for c style string
	const char lname[] {"Soni"};
	char* c{const_cast<char*>(lname)};
	PrettyPrinter<char*> r4(c);
	r4.Print();
	char * pdata = r4.getData(); // get data now return T** so for this case we need to specialise the template

	//Vector
	std::vector<int>vec(3,10);
	PrettyPrinter<std::vector<int>> r5(&vec);
	r5.Print();//Runtime Error as vector doesnt overload the << operator so it will not print the vector data, IN that case we need to again do template specialization for vector>
	
	//vector of vectors
	std::vector<std::vector<int>> dvec{
		{1, 2, 3},    //first element vector<int>
		{4, 5, 6}     //second element vector<int>
	};
	PrettyPrinter<std::vector<std::vector<int>>> r6(&dvec);
	r6.Print();
	return 0;
}