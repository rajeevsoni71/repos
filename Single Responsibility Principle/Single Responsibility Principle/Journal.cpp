#include "Journal.h"

Journal::Journal(std::string && title) :m_Title{ std::move(title) } {
	std::cout << __FUNCSIG__ << std::endl;
}

Journal::~Journal()
{
	std::cout << __FUNCSIG__ << std::endl;
}

void Journal::addEntries(const std::string& entry)
{
	static int count{};
	this->m_Entries.push_back(std::to_string(count++)+" : "+ entry);
	std::cout << __FUNCSIG__ << std::endl;
}

std::vector<std::string>::const_iterator Journal::firstEntry() const
{
	return this->m_Entries.cbegin();
}

std::vector<std::string>::const_iterator Journal::lastEntry() const
{
	return this->m_Entries.cend();
}

//void Journal::saveIntoFile(const std::string& filename)
//{
//	std::ofstream output(filename,std::ios::app);
//	std::cout << "Please wait!!! Saving data into file....." << std::endl;
//	auto start{ this->m_Entries.begin() };
//	while (start != this->m_Entries.end()) {
//		output << *start << std::endl;
//		start++;
//	}
//	output.close();
//	std::cout << "Successfully saved the data." << std::endl;
//}
