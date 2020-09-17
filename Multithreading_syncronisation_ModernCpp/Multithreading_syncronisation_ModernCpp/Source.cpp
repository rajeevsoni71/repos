#include <iostream>
#include<fstream>
#include <string>
#include<Windows.h>
#include <cerrno>

#define HAVE_STRUCT_TIMESPEC
#include<pthread.h>

char buff[128]{};
const std::string file_path{ "text.txt" };
constexpr int tid[]{0,1,2,3,4};

/*
* if we have only one read thread,
* or you have to read one by one
*/
pthread_mutex_t mutex{PTHREAD_MUTEX_INITIALIZER};

/*
* If you want to use multiple thread to read simultaniously
*/
pthread_rwlock_t read_write_lock{PTHREAD_RWLOCK_INITIALIZER};

void* read_file(void* ptr) {
	//pthread_mutex_lock(&mutex);
	pthread_rwlock_rdlock(&read_write_lock);
	std::cout << __FUNCTION__ << "+" << std::endl;
	int tid = *static_cast<int*>(ptr);
	std::ifstream input;
	input.open(file_path,std::ios::in);
	if (input.is_open()) {
		std::string buffer{};
		while (!std::getline(input,buffer).eof()) {
			std::cout << "Reading from thread: "<< tid << " :"<<buffer << std::endl;
			Sleep(1000);
		}
	}
	else {
		std::cout << "Unable to read file..." << strerror_s(buff, errno) << std::endl;
		//pthread_mutex_unlock(&mutex);
		pthread_rwlock_unlock(&read_write_lock);

		pthread_exit(0);
		return (int*)-1;
	}
	input.close();
	std::cout << __FUNCTION__ << "-" << std::endl;
	//pthread_mutex_unlock(&mutex);
	pthread_rwlock_unlock(&read_write_lock);

	pthread_exit(0);
	return 0;
}

void* write_file(void* ptr) {
	//pthread_mutex_lock(&mutex);
	pthread_rwlock_wrlock(&read_write_lock);
	std::cout << __FUNCTION__ << "+" << std::endl;
	std::ofstream output;
	output.open(file_path, std::ios::out| std::ios::app);
	if (output.is_open()) {
		std::string buffer = *reinterpret_cast<std::string*>(ptr);
		output << buffer << std::endl;
		Sleep(1000);
	}
	else {
		std::cout << "Unable to write file..." << strerror_s(buff, errno) << std::endl;
		//pthread_mutex_unlock(&mutex);
		pthread_rwlock_unlock(&read_write_lock);
		pthread_exit(0);
		return (int*)-1;
	}
	output.close();
	std::cout << __FUNCTION__ << "-" << std::endl;
	//pthread_mutex_unlock(&mutex);
	pthread_rwlock_unlock(&read_write_lock);

	pthread_exit(0);
	return 0;
}

void* create_file(void* ptr) { 
	//pthread_mutex_lock(&mutex);
	pthread_rwlock_wrlock(&read_write_lock);
	std::cout << __FUNCTION__ << "+" << std::endl;
	std::fstream file;
	file.open(file_path);
	if (!file) {
		std::cout << file_path << " not found so creating new." << std::endl;
		file.open(file_path, std::fstream::trunc);
	}
	else {
		std::cout << file_path << " found." << std::endl;
	}
	Sleep(2000);
	file.close();
	std::cout << __FUNCTION__ << "-" << std::endl;
	//pthread_mutex_unlock(&mutex);
	pthread_rwlock_unlock(&read_write_lock);
	pthread_exit(0);
	return 0;
}

int main(void) {
	pthread_t threads[5];
	/*
	* if we have only one read thread,
	* or you have to read one by one
	*/
	//pthread_mutex_init(&mutex,nullptr);

	/*
	* If you want to use multiple thread to read simultaniously
	*/
	pthread_rwlock_init(&read_write_lock,NULL);
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int* detachstate = new int();
	memset(detachstate, 0x00, sizeof(int));
	pthread_attr_getdetachstate(&attr, detachstate);
	std::cout << *detachstate <<std::endl;

	std::string message{ "Hello Rajeev!!!!!!" };
	std::cout << "Main thread started" << std::endl;
	pthread_create(&threads[0], &attr, create_file, (void*)&tid[0]);
	pthread_create(&threads[1], &attr, read_file, (void*)&tid[1]);
	pthread_create(&threads[2], &attr, write_file, (void*)&message);
	pthread_create(&threads[3], &attr, read_file, (void*)&tid[3]);
	pthread_create(&threads[4], &attr, read_file, (void*)&tid[4]);

	for (int i = 0; i < 5; i++) {
		pthread_join(threads[i], 0);
	}

	/*
	* if we have only one read thread,
	* or you have to read one by one
	*/
	//pthread_mutex_destroy(&mutex);
	/*
	* If you want to use multiple thread to read simultaniously
	*/
	pthread_attr_destroy(&attr);
	pthread_rwlock_destroy(&read_write_lock);
	delete detachstate;
	std::cout << "Main thread End" << std::endl;

	return 0;
}
