#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            result ^= num;   // XOR operation
        }

        return result;
    }
};

int main() {
    Solution obj;

    // 🔹 Test Case 1
    vector<int> nums1 = {2, 2, 1};
    cout << "Test Case 1 Output: " << obj.singleNumber(nums1) << endl;

    // 🔹 Test Case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Test Case 2 Output: " << obj.singleNumber(nums2) << endl;

    // 🔹 Test Case 3
    vector<int> nums3 = {1};
    cout << "Test Case 3 Output: " << obj.singleNumber(nums3) << endl;

    // 🔹 Test Case 4
    vector<int> nums4 = {7, 3, 5, 4, 5, 3, 4};
    cout << "Test Case 4 Output: " << obj.singleNumber(nums4) << endl;

    // 🔹 Test Case 5
    vector<int> nums5 = {10, 10, 20};
    cout << "Test Case 5 Output: " << obj.singleNumber(nums5) << endl;

    return 0;
}