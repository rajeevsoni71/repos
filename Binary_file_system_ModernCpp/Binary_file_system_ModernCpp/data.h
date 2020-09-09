#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "status.h"

constexpr int BYTES_SIZE_2MB{ 209152 }; // Total image size
constexpr int SINGLE_BYTE{1024}; // Chunk size to be written (this is an arbitrary amount)
constexpr int TOTAL_BLOCKS = BYTES_SIZE_2MB / SINGLE_BYTE; //write per block while creating image

typedef struct DATA_T{
	int Age{};
	char Name[20]{};
	char Course_Enrolled[50]{};
	/*std::string Name{};
	std::string Course_Enrolled{};*/
}DATA;

RETURN_STATUS createImage(const std::string& image);

RETURN_STATUS write_data(const DATA* data, const std::string& image);

RETURN_STATUS read_data(DATA& data, const std::string& image);

void Display(const DATA& data);