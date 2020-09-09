#include <iostream>
#include <deque> 
using namespace std;
int findmax(int* arr, int& index, int& k) {
    int max = arr[index];
    for (int i = index; i < index + k; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}
void printKMax(int arr[], int n, int k) {
    //Write your code here.
    deque<int> deq;
    for (int i = 0; i < n - k + 1; i++) {
        deq.emplace_back(findmax(arr, i, k));
    }
    for (const auto& ele : deq) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int *arr = new int[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        printKMax(arr, n, k);
        delete []arr;
        t--;
    }
    return 0;
}
