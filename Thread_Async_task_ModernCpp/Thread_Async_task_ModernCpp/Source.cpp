#include <iostream>
#include <thread>
#include <chrono> // time,watch, clock
#include <Windows.h> //set thread name
#include <future> //tasks
#include <vector> // as a resource

using namespace std::this_thread;
using namespace std::chrono;
using namespace std::chrono_literals;
constexpr int TOP{ 1 };
constexpr int DOWN{50};
constexpr int MIDDLE{51};
constexpr int LENGTH{100};
std::vector<int> g_vector;

void Task1(std::vector<int>& l_vector,int startpoint,int endpoint) {
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


void Display(const std::vector<int>& l_vector) {
	std::cout << __FUNCTION__ << ": " << static_cast<std::thread::id>(get_id()) << std::endl;//this_thread
	for (const auto& vec : l_vector) {
		std::cout << vec << " ";
		sleep_for(50ms); // chrono
	}
	std::cout << std::endl;
}

int main() {
	try {
		std::cout << __FUNCTION__ << ": " << static_cast<std::thread::id>(get_id()) << std::endl;//this_thread
		std::future<void> result1 = std::async(std::launch::async,Task1, std::ref(g_vector), TOP, DOWN);
		std::this_thread::sleep_for(1s);
		std::future<void> result2 = std::async(std::launch::async,Task2, std::ref(g_vector), MIDDLE, LENGTH);
		std::this_thread::sleep_for(1s);
		if (result1.valid()) {
			result1.get();
		}
		if (result2.valid()) {
			result2.get();// same as pthread_join();
		}
		//now when the below function called 
		//basically when we call get function ,it like function call
		std::cout << "Calculation is done." << std::endl;
		std::future<void> result3 = std::async(std::launch::deferred,Display, std::cref(g_vector));
		if (result3.valid()) {
			auto status = result3.wait_for(1s);
			switch (status)
			{
			case std::future_status::ready:
				std::cout << "Ready \n";
				break;
			case std::future_status::timeout:
				std::cout << "time out \n";
				break;
			case std::future_status::deferred:
				std::cout << "synchronous \n";
				break;
			default:
				break;
			}
			//it is simmilar to calling display();
			//display(g_vector);
			result3.get();// same as pthread_join();
		}
		std::cout << "main continue running" << std::endl;// main thread is blocked

	}
	catch (const std::system_error &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << __FUNCTION__ << " END\n"<< std::endl;//this_thread
	return 0;
}
