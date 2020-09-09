#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int>mp;
    string x;
    int Q, type;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            int y;
            cin >> x >> y;
            auto it = mp.find(x);
            if (it != mp.end()) {
                (it->second) += y;
            }
            else {
                mp.emplace(x, y);
            }
        }
        else if (type == 2) {
            cin >> x;
            auto it = mp.find(x);
            if (it != mp.end()) {
                (it->second) = 0;
            }
        }
        else if (type == 3) {
            cin >> x;
            auto it = mp.find(x);
            if (it != mp.end()) {
                cout << it->second << endl;
            }
            else {
                cout << "0" << endl;
            }
        }
        else {
            return 1;
        }
    }
    return 0;
}