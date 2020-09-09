// Lower Bound-STL.cpp : This file contains the 'main' function. Program execution begins and ends there.

/// <summary>
//You are given integers in sorted order. Also, you are given queries.In each query, 
//you will be given an integerand you have to tell whether that integer is present in the array.
//If so, you have to tell at which index it is presentand if it is not present, 
//you have to tell the index at which the smallest integer that is just greater than the given number is present.
//
//Lower bound is a function that can be used with a sorted vector.
//Learn how to use lower bound to solve this problem by Clicking Here.
/// </summary>
/// <returns></returns>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void search(const vector<int>& vec, int y) {
    auto low = lower_bound(vec.begin(), vec.end(), y);
    if (vec[low - vec.begin()] == y) {
        cout << "Yes " << (low - vec.begin() + 1) << endl;
    }
    else {
        cout << *(vec.begin()) << endl;
        cout << low - vec.begin() << endl;
        cout << "No " << (low - vec.begin() + 1) << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> vec;
    int N, Q, x, y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    cin >> Q;
    for (int j = 0; j < Q; j++) {
        cin >> y;
        search(vec, y);
    }
    return 0;
}


/*
Input Format

The first line of the input contains the number of integers N
The next line contains N integers in sorted order. 
The next line contains Q, the number of queries. 
Then Q lines follow each containing a single integer Y

Note that if the same number is present multiple times, 
you have to print the first index at which it occurs. Also, 
the input is such that you always have an answer for each query.
 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15
*/
/*
Output Format

For each query you have to print "Yes" (without the quotes) 
if the number is present and at which index(1-based) it is present separated by a space.

If the number is not present you have to print "No" (without the quotes) 
followed by the index of the next smallest number just greater than that number.

You have to output each query in a new line.
 Yes 1
 No 5
 Yes 6
 Yes 8
*/