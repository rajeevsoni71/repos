#include <iostream>
#include <thread>
#include <vector>
#include<Windows.h>

constexpr int VECSIZE{ 1000000 };
void download2(const std::string &str) {
	std::cout << "Download start for " << str << std::endl;
	std::cout << "Downloading.";
	for (size_t i = 0; i < 10; i++)
	{
			Sleep(100);
	}
	std::cout << "100%\nDownload Completed" << std::endl;
}
void download0() {
	std::vector<int>vec{};
	std::cout << "Download start" << std::endl;
	std::cout << "Downloading.";
	for (size_t i = 0; i < VECSIZE; i++)
	{
		vec.push_back(i);
		if (i % 10000 == 0) {
			std::cout << ".";
			Sleep(100);
		}
	}
	std::cout << "100%\nDownload Completed" << std::endl;
}

void download1(size_t SIZE) {
	std::vector<int>vec{};
	std::cout << "Download start" << std::endl;
	std::cout << "Downloading.";
	for (size_t i = 0; i < SIZE; i++)
	{
		vec.push_back(i);
		if (i % 10000 == 0) {
			std::cout << ".";
			Sleep(100);
		}
	}
	std::cout << "100%\nDownload Completed" << std::endl;
}

int main() {
	std::cout << "Main Thread-started" << std::endl;
	std::string file{"chain smoker"};
	std::thread thread0(download0);
	std::thread thread1(download1,1000000);
	std::thread thread2(download2,std::cref(file));
	//if the thread is detach thread then it cannot join or join again.
	/*thread1.detach();
	if (thread1.joinable()) {
		thread1.join();
	}*/
	thread0.join();
	thread1.join();
	thread2.join();

	//system("pause");
	std::cout << "Main Thread-end " << std::endl;
	return 0;
}