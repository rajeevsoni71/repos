#include <algorithm>
#include <iostream>
#include "User_Define_Function.h"

int substring(char* sub, const char* string)
{
    int i{};
    int j{};
    bool found{ false };
    while ((string[i] != '\0') && (sub[j] != '\0'))
    {
        if (string[i] != sub[j]) {
            j++;
            i = 0;
        }
        else {
            i++;
            j++;
        }
    }
    if (sub[j] == '\0' && i != 0) {
        return 1;
    }
    else {
        return -1;
    }
}

std::vector<std::pair<char, int>> findDuplicateChar(const char* strings){
    int i{ 0 }, j{ 0 };
    std::vector<std::pair<char, int>> duplicate_char;

    while (strings[i] != '\0')
    {
        j = i+1;
        while (strings[j] != '\0') {
            if (strings[i] == strings[j]) {
                auto isEqual = [&](const std::pair<char, int>& element)->bool
                {
                    return element.first == strings[i];
                };
                auto result1 = std::find_if(duplicate_char.begin(), duplicate_char.end(),isEqual);
                if (result1 != duplicate_char.end()) {
                    result1->second++;
                }
                else {
                    duplicate_char.emplace_back(strings[i],1);
                }
            }
            j++;            
        }
        i++;
    }
    return duplicate_char;
}

static int compare(const void* vptra, const void* vptrb) {
    const char *a{reinterpret_cast<const char*>(vptra)};
    const char* b{reinterpret_cast<const char*>(vptrb)};
    if (*a > *b) {
        return 1;
    }
    else if (*a < *b) {
        return -1;
    }
    else
    {
        return 0;
    }
}

int is_anagrams(const char* string1,const char* string2)
 {
    int len1{}, len2{};
    while (string1[len1] != '\0' || string2[len2] != '\0') {
        if (string1[len1] != '\0')
        {
            len1++;
        }
        if (string2[len2] != '\0')
        {
            len2++;
        }
    }
    if (len1 != len2) {
        return -1;
    }
    int flag{ 0 };
    std::qsort(&string1, len1, sizeof(char), compare);
    std::qsort(&string2, len2, sizeof(char), compare);
    len1 = 0;
    len2 = 0;
    while (string1[len1] != '\0' && string2[len2] != '\0') {
        if (string1[len1] != string2[len1]) {
            flag = 1;
        }
        len1++;
        len2++;
    }
    if (flag) {
        return -1;
    }
   return 0;
}
