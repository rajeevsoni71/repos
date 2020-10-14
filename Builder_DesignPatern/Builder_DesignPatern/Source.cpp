#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
//suppose if you want to print html
//tags like backend programming

void withoutBuilderDesignPattern() {
	//Example
	string input = "Hello";
	string name;
	name += "<p>";
	name += input;
	name += "</p>";
	std::cout << name << std::endl;
	//or you can use stringstream to capture array of string into one
	//like
	string names[] = { "Hello","World","123" };
	ostringstream os;
	os << "</ul>\n";
	for (auto& name : names) {
		os << "\t" << "<li>" << name << "</li>\n";
	}
	os << "</ul>" << std::endl;
	std::cout << os.str();
}

//builder design pattern basically used 
// when we want build some kind of output 
//which is built using different inputs streams
//and at last that should be combind into one

//Other usageis  if you want to parse some kind of
//file like xml,csv, etc.
struct HTMLElement {
	string tags, text;
	vector<HTMLElement> elements;
	const int indent_size = 2;
	HTMLElement() {}
	HTMLElement(const std::string& tag, const std::string& text)
		:tags{ tag }, text{ text }{}
	~HTMLElement() {}

	//Now main problem is that how to print it
	std::string str(int indent = 0) const {
		ostringstream oss;
		std::string idt(indent_size*indent,' ');
		oss << idt << "<" << tags << ">" << std::endl;
		if (text.size() > 0)
			oss << std::string((indent_size * indent) + 1, ' ') << text << std::endl;
		for (auto& eachElement:elements) {
			oss << eachElement.str(indent+1);
		}
		oss << idt << "</" << tags << ">" << std::endl;
		return oss.str();
	}
};

struct HTMLBUILDER {
	HTMLElement root;
	HTMLBUILDER(std::string root_tag) {
		root.tags = root_tag;
	}

	//void add_child(const std::string& tag,const std::string& tag_text) {
	//	HTMLElement element(tag,tag_text);
	//	root.elements.emplace_back(element);
	//}

	HTMLBUILDER& add_child(const std::string& tag, const std::string& tag_text) {
		HTMLElement element(tag, tag_text);
		root.elements.emplace_back(element);
		return *this;
	}

	std::string str() const {
		return root.str();
	}
};
int main() {
	//withoutBuilderDesignPattern();

	HTMLBUILDER builder{"ul"};
	builder.add_child("li","Rajeev");
	builder.add_child("li", "Soni");
	//std::cout << builder.str() << std::endl;

	//but to add another child in a child we
	//need fluent builder
	builder.add_child("li", "Vanya").add_child("li", "Bhandula").add_child("li","UP");

	std::cout << builder.str() << std::endl;
	return 0;
}