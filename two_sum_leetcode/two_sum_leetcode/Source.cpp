#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp;
        for (vector<int>::iterator it1 = nums.begin(); it1 != nums.end(); it1++) {
            for (vector<int>::iterator it2 = it1 + 1; it2 != nums.end(); it2++) {
                if ((*it1) + (*it2) == target) {
                    tmp.push_back(it1 - nums.begin());
                    tmp.push_back(it2 - nums.begin());
                    break;
                }
            }
        }
        return tmp;
    }
};

int main() {
    vector<int> vec{2,5,5,11};
    int tar = 10;
    Solution s;
    vector<int> result = s.twoSum(vec,tar);
    vector<int>::iterator it = result.begin();
    while (it != result.end()) {
        cout << *it << " ";
        it++;
    }
    return 0;
}