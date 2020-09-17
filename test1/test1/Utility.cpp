#include<iostream>
#include "utility.h"

void Question1() {
    const char* Names[]{ "blackcat", "blackdog", "blackrat", "whitetiger", "blueelephant" };
    char substr[]{ "black" };
    int found{ -1 };
    for (const auto &strings : Names)
    {
        found = substring(substr, /*const_cast<char*>*/(strings));
        if (found != -1) {
            std::cout << strings << " ";
        }
    }
    std::cout << std::endl;
}

void Question2()
{
    const char* Names[]{ "mam", "anaa", "java", "wow" };
    std::vector<std::vector<std::pair<char, int>>> s;
    for (const auto &strings : Names)
    {
        std::vector<std::pair<char, int>> vec;
        vec = findDuplicateChar(strings);
        s.push_back(vec);
    }

    //display
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j < s[i].size(); j++)
        {
            std::cout << "{"<< s[i].at(j).first <<", "<< s[i].at(j).second << "}" << std::endl;
        }
    }
    std::cout << std::endl;
}

void Question3()
{
    const char* Names[]{"Army","Mary"};
    if (is_anagrams(Names[0], Names[1]) == 0)
    {
        std::cout << Names[0] << " and " << Names[1] << " is anagrams." << std::endl;
    }
    else {
        std::cout << Names[0] << " and " << Names[1] << " is not anagrams." << std::endl;
    }
}

