#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0], fast = arr[0];

        // Step 1: Detect cycle
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);

        // Step 2: Find entry point (duplicate)
        slow = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {1, 3, 4, 2, 2};
    cout << "Duplicate in arr1: " << obj.findDuplicate(arr1) << endl;

    // Test Case 2
    vector<int> arr2 = {3, 1, 3, 4, 2};
    cout << "Duplicate in arr2: " << obj.findDuplicate(arr2) << endl;

    // Test Case 3
    vector<int> arr3 = {1, 1};
    cout << "Duplicate in arr3: " << obj.findDuplicate(arr3) << endl;

    // Test Case 4
    vector<int> arr4 = {1, 4, 6, 3, 2, 5, 6};
    cout << "Duplicate in arr4: " << obj.findDuplicate(arr4) << endl;

    return 0;
}