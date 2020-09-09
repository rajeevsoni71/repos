#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minimumswap(string status) {
    vector<char> vec(status.begin(),status.end());
    return 0;
}

int main()
{
    vector<string> vec{
    "RSRSRS", //0
    "SSRRSSRR", //2
    "SRSRRS", // 1
    "SRSRRR", //1
    "SRRRS" //1
    };

    auto it = vec.begin();
    while (it != vec.end()) {
        cout << minimumswap(*it) << endl;
    }
}

