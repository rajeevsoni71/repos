#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<class T>
void display(const T &s) {
    std::cout << "[ ";
    for (const auto le : s)
        std::cout << le << " ";
    std::cout << "]\n";
}
std::vector<int> stringAnagram(const std::vector<std::string> &dictionary,const std::vector<std::string> &query) {
    std::vector<int> total (query.size());
	std::vector<std::string>tmp;
	std::vector<std::string>::iterator sit;
	auto it = query.begin();
	int next_string{ 0 };
	while (it!=query.end()) {
		tmp.push_back(*it);
		int count{ 0 };
		/* Number of subsequences is (2^n -1)*/
		size_t n = (*it).length();
		size_t opsize = static_cast<size_t> (pow(2, n));
		//std::cout << *it << ","<< opsize << std::endl;
		/* All subsequences of a given string using counter 000..1 to 111..1*/
		for (size_t counter = 1; counter < opsize; counter++)
		{
			std::string subs = "";
			for (size_t j = 0; j < n; j++)
			{
				/* Check if jth bit in the counter is set
					If set then print jth element from arr[] */
				if (counter & (1 << j))
					subs.push_back((*it)[j]);
			}

			/* find the each permutation in dictionary */
			do
			{
				if (n == subs.length()) {
					//std::cout << subs << " ";
					auto sit = std::find(dictionary.begin(), dictionary.end(), subs);
					if (sit != dictionary.end()) {
						total.at(next_string)=++count;
						//std::cout << subs << "," << next_string << "," <<count << " ";
					}
				}
				else {
					continue;
				}
			} while (std::next_permutation(subs.begin(), subs.end()));
		}
		it++;
		++next_string;
	}
    return total;
}

int main()
{
    std::vector<std::string> dic {"heater","cold","reheat","locd","docl"};
    std::vector<std::string> qry {"cold","heater","abcd"};
    std::vector<int> got = stringAnagram(dic, qry);
	display(got);
    return 0;
}