#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
using namespace std;

int main() {
    constexpr unsigned long long lim = (1LL ^ 31);
    unsigned long long N, S, P, Q;
    cin >> N >> S >> P >> Q;
    try {
        vector<unsigned long long> vec(N);
        vec[0] = (S % lim);
        for (unsigned long long i = 1; i < N - 1; ++i) {
            vec[i] = vec[i - 1] * (P + Q % lim);
        }
        cout << vec.size();
    }
    catch (const exception& e) {
        if (S > P)
            std::cout << N << std::endl;
        else if (P > Q)
            std::cout << lim + 1 << std::endl;
        else
            std::cout << N << std::endl;
    }

    return 0;
}
