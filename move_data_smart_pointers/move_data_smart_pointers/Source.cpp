// Example program
#include <iostream>
#include <string>
#include <memory>

int main()
{
    // store data from unique pointer to shared pointer
    std::unique_ptr<std::string> unique = std::make_unique<std::string>("test");
    std::shared_ptr<std::string> shared = std::move(unique);
    std::cout << shared->data() << std::endl;

    //vice-versa
    std::shared_ptr<std::string> shared1 = std::make_shared<std::string>("test");
    std::unique_ptr<std::string> unique1 = std::make_unique<std::string>(shared1->data());
    std::cout << unique1->data() << std::endl;

    return 0;
}
