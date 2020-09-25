#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <exception>
#include <Windows.h>

const int length{10000};
std::list<int> lst;
std::mutex list_mutex;


void download1() {
	std::cout << std::this_thread::get_id() << std::endl;
	for (size_t i = 0; i < length; i++)
	{
		/* Solution for problem statement 1
		So to get rid of unlocking the mutex or anydeadlcok condition
		c++11 introduced a new class lock_guard which works on RAII standards
		to eliminate the headache of unlocking the mutex
		*/
		std::lock_guard<std::mutex> l{list_mutex};
		//list_mutex.lock(); // removed for solution P S 1
		lst.push_back(i);
		/* Problem statement 1 
		 suppose the thread is get terminate somehow
		 then the lock is not get release so
		 it cause deadlock condition
		 So be sure in every case if the thread is got terminated
		 release the mutex.
		*/
		/*if (i == 500)
			return;*/
		//list_mutex.unlock(); // removed for solution P S 1
	}
}

void download2() {
	std::cout << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for (size_t i = 0; i < length; i++)
	{
		/* Problem statement 2
		But even after solution for PS 1, here is another problem 2
		suppose 2 threads ae pushing the data into the list one by one
		even when CPU is in IDLE state then in that case you program is
		not good at utilising the CPU.
		Because at a time one thread will write into the list and still
		the CPU utilisation is not 100%
		---->Solution for above problem is:
		both threads will create there own list and in the main thread after the join
		programmer will merge both list into one.
		*/
		std::lock_guard<std::mutex> l{list_mutex};
		//list_mutex.lock(); // removed for solution P S 1
		lst.push_back(i);
		//list_mutex.unlock(); // removed for solution P S 1
	}
}

//lambda expression
auto f = []() {
	std::lock_guard<std::mutex> l{ list_mutex };
	for (size_t i =0; i < length;i++)
		lst.push_back(i);
};

//functor
class functor {
public:
	void operator()(size_t i) {
		std::lock_guard<std::mutex> l{ list_mutex };
		for (i; i < length; i++)
			lst.push_back(i);
	}
};

int main() {
	try {
		std::thread thread1(download1);
		std::thread thread2(download2);
		std::thread thread3(f);
		std::thread thread4(functor(),0);

		//set thread name using handle
		HANDLE handle = thread1.native_handle();
		SetThreadDescription(handle,L"Thread1");
		SetThreadDescription(thread2.native_handle(), L"Thread2");
		SetThreadDescription(thread3.native_handle(), L"Thread3");
		SetThreadDescription(thread4.native_handle(), L"Thread4");
		//Get thread id
		auto t1 = thread1.get_id();
		std::thread::id t2 = thread2.get_id();
		std::cout << "thread1_id: " << t1 << std::endl;
		std::cout << "thread2_id: " << t2 << std::endl;
		std::cout << "thread3_id: " << thread3.get_id() << std::endl;
		std::cout << "thread4_id: " << thread4.get_id() << std::endl;

		int cores = std::thread::hardware_concurrency();
		std::cout << "No of cores :" << cores << std::endl;

		thread1.join();
		thread2.join();
		thread3.join();
		thread4.join();
		std::cout << lst.size() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Excpetion: " << e.what() << std::endl;
	}
	return 0;
}

/*********************************************************************************************************************
Native handler 
--It return the type of threadin the corresponding platform

Get the thread handler

LINUX--Type of handle(pthread_t)
thread1.native_handle();
WINDOWS--Type of handle(handle)
thread1.native_handle();

***************************************************************************************************************/







/****************************************************************************************************************
How to give a name to the thread

------------------------------- LINUX ---------------------------------------------
pthread_setname_np

Note that the actual thread names will be in /proc/$PID/tasks/$TID/stat
-----------------------------------------------------------------------

As of glibc v2.12, you can use pthread_setname_np and pthread_getname_np to set/get the thread name.

These interfaces are available on a few other POSIX systems (BSD, QNX, Mac) in various slightly different forms.

Setting the name will be something like this:

#include <pthread.h>  // or maybe <pthread_np.h> for some OSes

// Linux
int pthread_setname_np(pthread_t thread, const char *name);

// NetBSD: name + arg work like printf(name, arg)
int pthread_setname_np(pthread_t thread, const char *name, void *arg);

// FreeBSD & OpenBSD: function name is slightly different, and has no return value
void pthread_set_name_np(pthread_t tid, const char *name);

// Mac OS X: must be set from within the thread (can't specify thread ID)
int pthread_setname_np(const char*);

And you can get the name back:

#include <pthread.h>  // or <pthread_np.h> ?

// Linux, NetBSD:
int pthread_getname_np(pthread_t th, char *buf, size_t len);
// some implementations don't have a safe buffer (see MKS/IBM below)
int pthread_setname_np(pthread_t thread, const char **name);
int pthread_getname_np(pthread_t thread, char *name);

// FreeBSD & OpenBSD: dont' seem to have getname/get_name equivalent?
// but I'd imagine there's some other mechanism to read it directly for say gdb

// Mac OS X:
int pthread_getname_np(pthread_t, char*, size_t);
-------------------------------WINDOWS---------------------------------------------
set thread name using handle
include <Windows.h> //Handle

HANDLE handle = thread1.native_handle();
SetThreadDescription(handle,L"Thread1"); // L is for wide string 
SetThreadDescription(thread2.native_handle(), L"Thread2");
*********************************************************************************************************************/






/********************************************************************************************************************
* get the thread id 
* sleep for the thread
std::cout << std::this_thread::get_id() << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(1));
********************************************************************************************************************/