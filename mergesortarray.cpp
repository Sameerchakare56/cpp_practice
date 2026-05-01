#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        int i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx--] = nums1[i--];
            } else {
                nums1[idx--] = nums2[j--];
            }
        }

        // If elements left in nums2
        while (j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }
};

// Helper function to print vector
void printVector(vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);
    cout << "Test Case 1 Output: ";
    printVector(nums1);

    // Test Case 2
    vector<int> nums3 = {4, 5, 6, 0, 0, 0};
    vector<int> nums4 = {1, 2, 3};
    m = 3; n = 3;

    sol.merge(nums3, m, nums4, n);
    cout << "Test Case 2 Output: ";
    printVector(nums3);

    // Test Case 3 (nums2 empty)
    vector<int> nums5 = {1};
    vector<int> nums6 = {};
    m = 1; n = 0;

    sol.merge(nums5, m, nums6, n);
    cout << "Test Case 3 Output: ";
    printVector(nums5);

    // Test Case 4 (nums1 empty initially)
    vector<int> nums7 = {0};
    vector<int> nums8 = {1};
    m = 0; n = 1;

    sol.merge(nums7, m, nums8, n);
    cout << "Test Case 4 Output: ";
    printVector(nums7);

    return 0;
}