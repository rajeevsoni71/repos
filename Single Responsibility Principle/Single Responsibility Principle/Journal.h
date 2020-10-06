#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

class Journal
{
	std::string m_Title;
	std::vector<std::string> m_Entries;
public:
	Journal() = delete;
	Journal(std::string&& title);
	~Journal();
	void addEntries(const std::string &entry);
	std::vector<std::string>::const_iterator firstEntry() const;
	std::vector<std::string>::const_iterator lastEntry() const;
	//void saveIntoFile(const std::string& filename);
};

