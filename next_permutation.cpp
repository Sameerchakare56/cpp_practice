#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();

        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot → reverse whole array
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find next greater element
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse suffix
        int i = pivot + 1, j = n - 1;
        while (i <= j) {
            swap(nums[i++], nums[j--]);
        }
    }
};

// Helper function to print vector
void print(vector<int>& nums) {
    for (int x : nums) cout << x << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> t1 = {1, 2, 3};
    sol.nextPermutation(t1);
    cout << "Test 1: ";
    print(t1);   // 1 3 2

    // Test Case 2
    vector<int> t2 = {3, 2, 1};
    sol.nextPermutation(t2);
    cout << "Test 2: ";
    print(t2);   // 1 2 3

    // Test Case 3
    vector<int> t3 = {1, 1, 5};
    sol.nextPermutation(t3);
    cout << "Test 3: ";
    print(t3);   // 1 5 1

    // Test Case 4
    vector<int> t4 = {1, 3, 2};
    sol.nextPermutation(t4);
    cout << "Test 4: ";
    print(t4);   // 2 1 3

    // Test Case 5
    vector<int> t5 = {2, 3, 1};
    sol.nextPermutation(t5);
    cout << "Test 5: ";
    print(t5);   // 3 1 2

    // Test Case 6 (single element)
    vector<int> t6 = {1};
    sol.nextPermutation(t6);
    cout << "Test 6: ";
    print(t6);   // 1

    return 0;
}