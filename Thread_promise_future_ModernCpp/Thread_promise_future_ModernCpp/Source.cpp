#include <iostream>
#include <thread>
#include <chrono> // time,watch, clock
//#include <Windows.h> //set thread name
#include <future> //tasks
#include <vector> // as a resource

using namespace std::this_thread;
using namespace std::chrono;
using namespace std::chrono_literals;
constexpr int TOP{ 1 };
constexpr int DOWN{ 50 };
constexpr int MIDDLE{ 51 };
constexpr int LENGTH{ 100 };
std::vector<int> g_vector;

void Task1(std::vector<int>& l_vector, int startpoint, int endpoint) {
	std::cout << __FUNCTION__ << ": " << static_cast<std::thread::id>(get_id()) << std::endl;//this_thread
	for (startpoint; startpoint <= endpoint; startpoint++)
	{
		l_vector.push_back(startpoint);
		//sleep_for(200ms); // chrono
	}
}

void Task2(std::vector<int>& l_vector, int startpoint, int endpoint) {
	std::cout << __FUNCTION__ << ": " << static_cast<std::thread::id>(get_id()) << std::endl;//this_thread
	for (startpoint; startpoint <= endpoint; startpoint++)
	{
		l_vector.push_back(startpoint);
		//sleep_for(200ms); // chrono
	}
}


void Display(std::promise<std::vector<int>>& data) {
	std::cout << __FUNCTION__ << ": " << static_cast<std::thread::id>(get_id()) << std::endl;//this_thread
	std::future<std::vector<int>> fur= data.get_future();
	try {
		std::cout << "Waiting for data...\n";
		throw std::runtime_error("unable to get the data"); // FROM THREAD to MAIN
		std::vector<int> l_vector = fur.get();
		std::cout << "data is received.\n";
		for (const auto& vec : l_vector) {
			std::cout << vec << " ";
			sleep_for(50ms); // chrono
		}
		std::cout << std::endl;
	}
	catch (const std::runtime_error& e) {
		//std::cout << "[Display]Exception: " <<e.what() << std::endl;
		throw std::runtime_error("unable to get the data"); // RETHROW the EXCEPTION otherwise it will handle here itself.
	}
}

int main() {
	try {
		std::cout << __FUNCTION__ << ": " << static_cast<std::thread::id>(get_id()) << std::endl;//this_thread
		std::promise<std::vector<int>> data;
		std::future<void> result1 = std::async(Task1, std::ref(g_vector), TOP, DOWN);
		std::future<void> result2 = std::async(Task2, std::ref(g_vector), MIDDLE, LENGTH);
		std::future<void> result3 = std::async(std::launch::async,&Display, std::ref(data));
		std::cout << "main 1" << std::endl;
		if (result1.valid() && result2.valid()) {
			std::cout << "main 2" << std::endl;
			result1.get();
			std::cout << "main 2.1" << std::endl;
			result2.get();
			std::cout << "main 2.2" << std::endl;
		}
		std::cout << "main 3" << std::endl;
		std::this_thread::sleep_for(3s);
		//Suppose promise is failed to set the value then it throws exception
		//but we need to notify the display thread that
		//there is an exception is thrown
		try {
			// throwing the exception is not enough
			//because you display thread doesn't know about it
			//so to know the display thread there is an excepetion
			//thrown then we need to set an exception pointer
			//
			//Exception pointers are shared between the shared state of exception
			//throw std::runtime_error("Data is unable to set."); // From MAIN to THREAD
			data.set_value(std::ref(g_vector));
			if (result3.valid()) {
				result3.get();
			}
		}
		catch (const std::exception& e) {
			//Here set the exception for promise 
			//data.set_exception(std::make_exception_ptr(e));
			std::cout << "[MAIN] Exception1: " << e.what() << std::endl;
		}
	}
	catch (const std::system_error& e) {
		std::cout << "[MAIN] SYSTEM ERROR: " << e.what() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << "[MAIN] Exception: " << ex.what() << std::endl;

	}
	return 0;
}