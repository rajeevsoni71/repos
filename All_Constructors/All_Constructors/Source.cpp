#include <iostream>
#include <string>
using namespace std;
class person {
    string  Name{};
    int age{};
public:
    person() :person("", 0) {}//deligating constructor
    person(string n, int a) {
        std::cout << "param constructor" << std::endl;
        Name = n;
        age = a;
    }
    person(const person& obj) {
        std::cout << "copy constructor" << std::endl;
        Name = obj.Name;
        age = obj.age;
    }
    person operator=(const person& rhs) {
        std::cout << "copy assignment" << std::endl;
        return person(rhs.Name, rhs.age);
    }
    person(person&& mv) {
        std::cout << "Move constructor" << std::endl;
        Name = mv.Name;
        age = mv.age;
        mv.Name = "";
        mv.age = 0;
    }
    person operator=(person&& rhs) {
        std::cout << "Move assignment" << std::endl;
        Name = rhs.Name;
        age = rhs.age;
        rhs.Name = "";
        rhs.age = 0;
    }
    void show() {
        std::cout << Name << ", " << age << std::endl;
    }
    void show(int n) {
        std::cout << Name << ", " << age + n << std::endl;
    }
};

person getperson(string n, int a) {
    return person(n, a);
}

int main() {
    /*    person p1; // deliaget to param constructor
        person p2("raj",22);//param constructor
        person p3=p1; // copy constructor
        person p4; // deligate to param
        p4 = p3; // copy assignment*/

    person p5 = { "raj",21 };
    return 0;
}

