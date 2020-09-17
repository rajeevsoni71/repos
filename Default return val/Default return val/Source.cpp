#include <iostream>
class Example
{
    int* buf;
public:
    Example(size_t n = 1024) {
        buf = new int(1024);
        std::cout << "constructor" << std::endl;
    }
    ~Example() {
        std::cout << "Destructor " << std::endl;
        delete[] buf;
    }
};

int main(void) {
    void* ptr = new Example();
    delete ptr; // Destructor wouldn't call
    return 0;
}
