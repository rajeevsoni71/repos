/*
Multithreading support was introduced in C+11. Prior to C++11, 
we had to use POSIX threads or p threads library in C. 
While this library did the job the lack of any standard 
language provided feature-set caused serious portability issues. 

C++ 11 did away with all that and gave us std::thread. 
The thread classes and related functions are defined in the thread header file.

std::thread is the thread class that represents a single thread in C++. 
To start a thread we simply need to create a new thread object 
and pass the executing code to be called (i.e, a callable object) 
into the constructor of the object. Once the object is created a new thread
is launched which will execute the code specified in callable.

A callable can be either of the three

    A function pointer
    A function object
    A lambda expression

    After defining callable, pass it to the constructor.
    
    import<thread>
    std::thread thread_object(callable)

*/
#include <iostream>
#include <thread>
#include <string>
#include <chrono>

void foo(std::string str)
{
    std::cout << str << std::this_thread::get_id() << std::endl;
    //std::this_thread::sleep_for(2s);
}

// Define the class of function object 
class fn_object_class {
    // Overload () operator 
public:
    void operator()(std::string st)
    {
        std::cout << st << std::this_thread::get_id() << std::endl;
        //std::this_thread::sleep_for(2s);
    }
};

int main() {
    std::cout << "******Launching thread using function pointer" << std::endl;
    std::thread thread_object1(foo, "Hi! Guys i am child thread.");
    
    thread_object1.join();

    std::cout << "******Launching thread using lambda expression" << std::endl;
    // Define a lamda expression 
    auto lambda_exp = [](std::string st) {
            std::cout << st << std::this_thread::get_id()<< std::endl;
            //std::this_thread::sleep_for(2s);
    };

    std::thread thread_object2(lambda_exp, "Hey Guys!, I am child of lambda thread.");
    //OR you can pass lambda expression directly into the creation time
    //std::thread thread_object([](std::string st) { 
	// std::cout << st << std::endl;
    //}; , "lambda Expression thread.");
    thread_object2.join();
    std::cout << "******Launching threads using function objects " << std::endl;
    // Create thread object 
    std::thread thread_object3(fn_object_class(), "Hi i ma class of function object thread.");

    thread_object3.join();
    std::cout << "main thread executed now." << std::this_thread::get_id() << std::endl;
	return 0;
}
