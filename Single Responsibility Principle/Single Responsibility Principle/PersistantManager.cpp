#include "PersistantManager.h"

void PersistantManager::save(const Journal& journal, const std::string& filename)
{
	std::ofstream output(filename, std::ios::app);
	std::cout << "Please wait!!! Saving data into file....." << std::endl;
	auto start{ journal.firstEntry() };
	while (start != journal.lastEntry()) {
		output << *start << std::endl;
		start++;
	}
	output.close();
	std::cout << "Successfully saved the data." << std::endl;
}
