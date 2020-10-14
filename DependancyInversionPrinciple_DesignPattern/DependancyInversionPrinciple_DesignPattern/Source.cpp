#include <iostream>
#include <vector>
#include <tuple>
/*
* This principle says that
* 1. HIgh level module shouldn't dependant on low level module.
*	Both should depand on abstraction.
* 2.Abstractions shouldn't depandant details
*	Details should depand on abstractions
*/

//example
enum class Relationship {
	parents,
	child,
	siblings
};

struct Person {
	std::string name;
	Person(const std::string&& name) :name{name} {}
};

struct IResearchBrowser {
	virtual std::vector<Person> find_all_Children(const std::string& name) = 0;
};

struct Relationships // Low-Level , As this contains the data structure to store the data
	: IResearchBrowser
{
	//adding rules
	//suppose low-level is make the all member variables as private 
	// so in this case High level will breaks down
	//Now how to solve that problem
	//you can introduce a new interface or an abstraction
	std::vector<std::tuple<Person, Relationship, Person>> relations;

	void add_parent_and_child(const Person& parent,const Person& child) {
		relations.push_back({ parent, Relationship::parents, child });
		relations.push_back({ child, Relationship::child, parent });
	}

	// Inherited via IResearchBrowser
	virtual std::vector<Person> find_all_Children(const std::string& name) override
	{
		std::vector<Person> result;
		for (auto&& [first,rel,second]: relations) {
			if (first.name == name && rel == Relationship::parents) {
				result.push_back(second);
			}
		}
		return result;
	}

};

struct Research // High-Level, Problem : high level is dependant on low level
{
	Research(IResearchBrowser& researchbrowser) {
		for (auto children : researchbrowser.find_all_Children("rajeev")) {
			std::cout << "Rajeev has child called " << children.name << std::endl;
		}

	}
	//Research(Relationships& relationships) { //dependancy on low level
	//	auto& relations = relationships.relations;
	//	for (auto&& [first,rel,second]:relations) {
	//		if ( first.name == "rajeev" && rel == Relationship::parents) {
	//			std::cout << "Rajeev has a child called " << second.name << std::endl;
	//		}
	//	}
	//}
};

int main() {
	Person parent("rajeev");
	Person child1("boy");
	Person child2("girl");

	Relationships relation;
	relation.add_parent_and_child(parent,child1);
	relation.add_parent_and_child(parent, child2);

	Research _(relation);
	//In above code implementaion shows how to break all the rules.

	// Now lets find out how to implement the above code with rules.
	//for that 
	//


	return 0;
}