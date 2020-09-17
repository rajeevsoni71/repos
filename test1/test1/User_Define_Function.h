#pragma once
#include <utility> //pair
#include <vector>

int substring(char* sub, const char* string);
std::vector<std::pair<char, int>> findDuplicateChar(const char* strings);
int is_anagrams(const char* string1, const char* string2);