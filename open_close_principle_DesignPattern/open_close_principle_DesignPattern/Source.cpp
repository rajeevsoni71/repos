#include <iostream>
#include <string>
#include <vector>

enum class COLOR {red, green, blue};
enum class SIZE {small,medium, large};
typedef struct Product {
	std::string m_Name;
	COLOR color;
	SIZE size;
};

typedef struct ProductFilter {
	std::vector<Product*> by_color(const std::vector<Product*> vec, COLOR Color) {
		std::vector<Product*> result;
		for (auto &pro:vec) {
			if (pro->color == Color) {
				result.push_back(pro);
			}
		}
		return result;
	}

	std::vector<Product*> by_size(const std::vector<Product*> vec, SIZE size) {
		std::vector<Product*> result;
		for (auto& pro : vec) {
			if (pro->size == size) {
				result.push_back(pro);
			}
		}
		return result;
	}

	std::vector<Product*> by_size_color(const std::vector<Product*> vec, SIZE size, COLOR color) {
		std::vector<Product*> result;
		for (auto& pro : vec) {
			if (pro->size == size && pro->color == color) {
				result.push_back(pro);
			}
		}
		return result;
	}
};

//open close principle says that
//the module is open for extension
//but close of modification

template<typename T> struct Specification {
	virtual bool is_specialised(T* items) = 0;
};

typedef struct ColorSpecification : Specification<Product> {
	COLOR m_Color;
	ColorSpecification(COLOR Color) :m_Color{ Color } {};

	// Inherited via Specification
	virtual bool is_specialised(Product* items) override
	{
		bool ret = (items->color == m_Color) ? true : false;
		return ret;
	}
};

typedef struct SizeSpecification : Specification<Product> {
	SIZE m_Size;
	SizeSpecification(SIZE Size) :m_Size{ Size } {};

	// Inherited via Specification
	virtual bool is_specialised(Product* items) override
	{
		bool ret = (items->size == m_Size) ? true : false;
		return ret;
	}
};

typedef struct ColorAndSizeSpecification : Specification<Product> {
	COLOR m_Color;
	SIZE m_Size;
	ColorAndSizeSpecification(COLOR Color, SIZE Size) :m_Color{ Color }, m_Size{Size} {};

	// Inherited via Specification
	virtual bool is_specialised(Product* items) override
	{
		bool ret = ((items->color == m_Color) && (items->size == m_Size)) ? true : false;
		return ret;
	}
};

template <typename T> struct Filter {
	virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};


typedef struct BetterFilter : Filter<Product>{
	// Inherited via Filter
	virtual std::vector<Product*> filter(std::vector<Product*> items, 
		Specification<Product>& spec) override
	{
		std::vector<Product*> result;
		for (auto& item : items)
			if (spec.is_specialised(item))
				result.push_back(item);
		return result;
	}
};

int main()
{
	Product Apple{"Apple",COLOR::green,SIZE::medium};
	Product Banana{"Banana",COLOR::red,SIZE::large};
	Product Carrot{"Carrot",COLOR::red,SIZE::medium};
	Product Tree{"Tree",COLOR::green,SIZE::large };

	std::vector<Product*> items{&Apple,&Banana,&Carrot,&Tree};
	ProductFilter pf;
	auto red_things = pf.by_color(items,COLOR::red);
	for (const auto & red_items: red_things) {
		std::cout << red_items->m_Name << " is red." << std::endl;
	}
	//using the inheritance and open/close principle
	BetterFilter bf;
	ColorSpecification greenCol(COLOR::green);
	ColorAndSizeSpecification greenandsize(COLOR::green,SIZE::large);
	for (auto& item : bf.filter(items, greenandsize)) {
		std::cout << item->m_Name << " is green." << std::endl;
	}
	return 0;
}