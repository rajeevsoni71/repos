/*
* Parallel Algorithm module is added in c++17 
*/

/*
* Parallel STL Algorithm
* 1) May STL algorithm by default execute serially basically on single thread.
* 2) C++17 provides the overloads to existing algorithms that can now execute parallelly
* 3) Operations on each elements will be performed on different threads at the same time
*    so that threads will perform there action parallelly
* 4) Algorithms that can be parallelized accepted a new template parameter called execution policy.
*    -> Used to disambiguate the calls to overloads of the algorithm.
* 5) This canbe used to inform the algorithm if it should execute serially or parallelly
* 6) The internal implementation detials are hidden to the user.
*/

/*
* Syntax
* 1) Parallel versions of sSTL algorithms have a simple interface.
* 2) They are provided as overloaded functions with the first parameter
*    signifying the execution policy
* 3) Execution policy defines how th algorithm should execute
* ---------------------------------------------------------------------
* std::algorithm(execution_policy,begin,end,other args);
*/

/*
* Execution Policies
* 1) All execution policies existing in <execution> header
*    and in std::execution namespace
* 2) Each of the policy is an individual type or has individual class
* 3) All thepolicy types provides global instance and these instances
*    then pass as a first argument in parallel algorithms
* 4) sequenced_policy - seq(this is an execution policy)
*    ->the algorithm's execution will not be parallelized and will
*      perform operations squentailly elements by elements.
*    ->same as invoking the algorithms from C++14.
* 5) parallel_policy - par
*    ->Indicates the algorithmsould execute parallelly.
*    ->Might use threads from thread pool for execution along with
*      the calling thread.
* 6) parallel_unsequenced_policy - par_unseq
*    ->indicates the execution may be parallelized , vectoerized
*      or migrated across threads.
*	vertorized -means multiple intructions can be run parallelly
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <string_view>
#include <vector>
#include <random>
#include <execution>

using namespace std::string_view_literals;
/*
* To see the performance in sequential and parallel algorithm
* we create a helper class for time
*/
class Timer {
	std::chrono::steady_clock::time_point m_start;
public:
	Timer() :m_start{std::chrono::steady_clock::now()} {}
	void showResult(std::string_view message = "") {
		auto end = std::chrono::steady_clock::now();
		auto difference = end - this->m_start;
		std::cout << message
			<< ':'
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(difference).count()
			<< std::endl;
	}
};
//Now we will create a vector of randon numbers to sort
constexpr unsigned VEC_SIZE{10000000}; // NOw incresing the size so that we can see CPU Utilisation
std::vector<long> CreateVector() {
	std::vector<long> vec;
	vec.reserve(VEC_SIZE);
	std::default_random_engine engine{ std::random_device{}() };
	std::uniform_int_distribution<> dist{0,VEC_SIZE};
	for (unsigned i = 0; i < VEC_SIZE; i++)
	{
		vec.push_back(dist(engine));
	}
	return vec;
}
int main() {
	auto dataset1 = CreateVector();
	auto dataset2 = CreateVector();
	Timer t1;
	//std::sort(dataset1.begin(), dataset1.end());
	//t1.showResult("Sequence Sorting Time");
	//Timer t2;
	//std::sort(std::execution::par,dataset2.begin(), dataset2.end());
	//t2.showResult("Parallel Sorting Time");

	//now we will do sum of all numbers in a list
	//auto result = std::accumulate(dataset2.begin(), dataset2.end(),0L); // use left add , 2879700 nanoseconds
	auto result = std::reduce(dataset2.begin(), dataset2.end(), 0L); // use tree to add,  300 nanosecnods

	t1.showResult("Accumulate Time");
	return 0;
}

/*
Sequence Sorting Time:7

Parallel Sorting Time:2
*/

/*
* should we use parallel algorithm always?
* No, lets check why
* suppose we want to sort a list of times which is not large in data.
* 
* if we use sequencial sort then it will take less time in compare of
* parallel algorithm but why?
* 
* Beacuse to start the thread in parallel algorithm there will a little overhead
* added in the time frame so it will take more time to sort just small dataset.
* 
* Please check the required algorithm with its performance to you code and then 
* select the appropritate alogo
* 
* Exception handling 
* In sequenctial algorithm you can handle the exception and continue the excution
* In Parallel algorithm if the exception throw then the program will terminate and mainly it required memory allocation so you can get 
* bad_alloc exception of failure cases
* 
* 
* 
*/