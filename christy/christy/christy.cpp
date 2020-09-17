// Example program
#include <iostream>
#include <string>
int in_parameter(const char* input) {
    if (input == nullptr) return -1;
    std::cout << input << std::endl;
    /*    int len{};
        while(input[len] !='\0'){
            input[len]='r';
            ++len;
        }*/
    return 0;
}

void out_parameter(char* output) {
    std::cout << output << std::endl;
    int len = strlen(output);
    std::cout << len << std::endl;
    char lastname[]{" lalu"};
    size_t total_len = len + (sizeof(lastname));
    for (size_t i = len ; i < total_len; i++) // 5+5+1, chris+lalu+\0
    {
        output[i] = lastname[i-len]; // i=5,len=5= 0,i=6,len5 = 1 , .....i=10,len=5,=5
    }
}

int main()
{
    const char* string{ "christy" }; // you cannot modify
    const char* str1 = nullptr;
    if (in_parameter(str1) == 0) {
        std::cout << "good" << std::endl;
    }
    else {
        std::cout << "bad" << std::endl;
    }
    char arr[30]{ "chris" }; // you can modify this
    out_parameter(arr);
    std::cout << arr << std::endl;
    std::cout << arr << std::endl;
}

