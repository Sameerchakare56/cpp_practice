#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binSearch(vector<int>& arr, int tar, int st, int end) {
        if (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] == tar)
                return mid;
            else if (arr[mid] < tar)
                return binSearch(arr, tar, mid + 1, end);
            else
                return binSearch(arr, tar, st, mid - 1);
        }
        return -1;
    }

    int search(vector<int>& arr, int tar) {
        return binSearch(arr, tar, 0, arr.size() - 1);
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {1, 3, 5, 7, 9, 11};
    int target1 = 7;
    cout << "Index of " << target1 << " = "
         << obj.search(arr1, target1) << endl;

    // Test Case 2
    vector<int> arr2 = {2, 4, 6, 8, 10};
    int target2 = 5;
    cout << "Index of " << target2 << " = "
         << obj.search(arr2, target2) << endl;

    // Test Case 3
    vector<int> arr3 = {10};
    int target3 = 10;
    cout << "Index of " << target3 << " = "
         << obj.search(arr3, target3) << endl;

    // Test Case 4
    vector<int> arr4 = {};
    int target4 = 1;
    cout << "Index of " << target4 << " = "
         << obj.search(arr4, target4) << endl;

    return 0;
}