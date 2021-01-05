#include <iostream>

using namespace std;

template<typename T, int SIZE>
void createArray(T** arrPtr) {
    *arrPtr = new T[SIZE];
    for (int i = 0; i < SIZE; i++)
        (*arrPtr[i]) = i + 1;
}

int main()
{
    constexpr int size = 3;
    int* ptr = nullptr;
    createArray<int, size>(&ptr);
    if (ptr == nullptr)
        return -1;
    for (int i = 0; i < size; i++)
        std::cout << *(ptr++) << " ";
    delete ptr;
    ptr = nullptr;
    return 0;
}