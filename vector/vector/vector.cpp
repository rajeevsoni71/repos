#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, ele, x, a, b;
    vector<int> vec;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ele;
        vec.push_back(ele);
    }
    cin >> x;
    if (x >= 1 || x <= N) {
        vec.erase(vec.begin() + x - 1);
    }
    else {
        return 1;
    }
    cin >> a >> b;
    if (b > a) {
        vec.erase(vec.begin() + a-1, vec.begin() + b-1);
    }
    else {
        return 1;
    }
    cout << vec.size() << endl;
    auto it = vec.begin();
    while (it != vec.end()) {
        cout << *it << " ";
        it++;
    }
    return 0;
}
