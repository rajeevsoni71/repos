#pragma once
#include "Journal.h"
#include <fstream>


class PersistantManager
{
public:
	static void save(const Journal& journal, const std::string& filename);
};

