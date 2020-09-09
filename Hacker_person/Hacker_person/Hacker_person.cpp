#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 6
#define INPUT 3

class Person {
public:
    string name{};
    int age{};
    Person() = default;
    virtual void getdata() {
        cin >> this->name >> this->age;
    }
    virtual void putdata() {
        cout << this->name << " " << this->age << endl;
    }
};

class Professor :public Person{
    int publications{};
    static int cur_id;
public:
    Professor() {
        Professor::cur_id++;
    }
    void getdata() override {
        cin >> this->name >> this->age >> publications;
    }
    void putdata() override {
        cout  << this->name << " " << this->age << " " << publications << " " << Professor::cur_id;
    }
};

class Student : public Person {
    int marks[MAX] = {};
    static int cur_id;
public:
    Student() {
        Student::cur_id++;
    }
    void getdata() {
        cin >> this->name >> this->age;
        for (int i = 0; i < MAX; i++)
            cin >> marks[i];
    }
    void putdata() {
        int sum{};
        cout << this->name << " " << this->age << " ";
        for (int i = 0; i < MAX; i++) {
            sum += marks[i];
        }
        cout << sum << " " << Student::cur_id;
    }
};

int Professor::cur_id{};
int Student::cur_id{};


int main() {

    int n, val;
    //cin >> n; //The number of objects that is going to be created.
    Person* per[INPUT];

    for (int i = 0; i < INPUT; i++) {
        cout << "Enter value:";
        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student
        cout << "Enter data for value:" << val;
        per[i]->getdata(); // Get the data from the user.

    }
    cout << "Displaying.................." << endl;
    for (int i = 0; i < INPUT; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
