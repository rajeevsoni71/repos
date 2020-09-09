#include <vector>
#include <iostream>
#include <string>
#include <memory>

enum class Case { SENSITIVE, INSENSITIVE };
std::string ToUpper(const std::string& str);
std::string ToLower(const std::string& str);
size_t Find(const std::string& source, const std::string& search_string, Case searchCase = Case::INSENSITIVE, size_t offset = 0);

std::vector<int> FindAll(const std::string& target, std::string search_string, Case searchCase = Case::INSENSITIVE, size_t offset = 0);

void Display_find() {
    std::string source{ "Modern C++11/14/17, By Umar!!! and modern c++11/14/17, by umar!!!" };
    std::vector<std::string> sub{
        "modern",
        "c++",
        "by",
        "umar"
    };
    for (const auto& str : sub) {
        std::cout << Find(source, str) << std::endl;
    }
}
int main()
{
    std::vector<int> vec{};
    std::string source{ "modern C++11/14/17, By Umar!!! and modern c++11/14/17, by umar!!!" };
    std::vector<std::string> sub{
        "modern",
        "c++",
        "by",
        "umar"
    };
    for (const auto& str : sub) {
        vec = FindAll(source, str);
    }
    for (const auto& vec_ele : vec)
        std::cout << vec_ele << " ";
    std::cout << std::endl;
}

std::string ToUpper(const std::string& str)
{
    std::string tmp{ str };
    for (size_t i = 0; i < str.length(); i++) {
        if (std::isupper(str[i]))
            tmp[i] = str[i];
        else
           tmp[i] = std::toupper(str[i]);
    }
    return tmp;
}

std::string ToLower(const std::string& str)
{
    std::string tmp{ str };
    for (size_t i = 0; i < str.length(); i++) {
        if (std::islower(str[i]))
            tmp[i] = str[i];
        else
            tmp[i] = std::tolower(str[i]);
    }
    return tmp;
}


size_t Find(
    const std::string& source,         //Source string to be searched
    const std::string& search_string,  //The string to search for
    Case searchCase ,//Choose case sensitive/insensitive search
    size_t offset ) {                //Start the search from this offset
        //Implementations
    std::string common{};
    std::size_t found{};
    switch (searchCase)
    {
    case Case::SENSITIVE:
        common = ToUpper(search_string);
        std::cout << common << std::endl;
        found = source.find(common.c_str(), offset);
        if (found != std::string::npos) {
            std::cout << "found" << std::endl;
            return found;
        }
        break;
    case Case::INSENSITIVE:
        common = ToLower(search_string);
        std::cout << common << std::endl;
        found = source.find(common.c_str(), offset);
        if (found != std::string::npos) {
            std::cout << "found" << std::endl;
            return found;
        }
        break;
    default:
        break;
    }
    /*
    return position of the first character
    of the substring, else std::string::npos
    */
    return std::string::npos;
}


std::vector<int> FindAll(
    const std::string& target,         //Target string to be searched
    std::string search_string,         //The string to search for
    Case searchCase,//Choose case sensitive/insensitive search
    size_t offset) {                //Start the search from this offset
        //Implementation
    std::vector<int> ret;
    std::string common{};
    std::size_t found{};
    switch (searchCase)
    {
    case Case::SENSITIVE:
        common = ToUpper(search_string);
        std::cout << common << std::endl;
        while (offset != target.length()) {
            found = target.find(common, offset++);
            if (found != std::string::npos) {
                //std::cout << "found" << std::endl;
                ret.push_back(found);
            }
            if (offset != 0)
                offset = offset + found;
            else if (offset == found || offset == 0)
                offset++;
        }
        break;
    case Case::INSENSITIVE:
        common = ToLower(search_string);
        std::cout << common << std::endl;
        while (found != target.length()) {
            found = target.find(common, offset);
            if (found != std::string::npos) {
                std::cout << found << std::endl;
                ret.push_back(found);
            }
            if (offset != 0)
                offset = offset + found;
            else if (offset == found)
                offset += found + 1;
            else if (offset == 0)
                offset += 1;
            else
                ++offset;
        }
        break;
    default:
        break;
    }
    /*
    Return indices of found strings,
    else an empty vector
    */
    return ret;
}