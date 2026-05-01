#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int st = 0, end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == tar) {
                return mid;
            }

            if (nums[st] <= nums[mid]) {  
                if (nums[st] <= tar && tar < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if (nums[mid] < tar && tar <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> test_arrays = {
        {4,5,6,7,0,1,2},
        {4,5,6,7,0,1,2},
        {6,7,1,2,3,4,5},
        {6,7,1,2,3,4,5},
        {1,2,3,4,5,6,7},
        {4,5,6,7,0,1,2},
        {1},
        {1},
        {3,1}
    };

    vector<int> targets = {0, 6, 3, 7, 5, 10, 1, 0, 1};

    vector<int> expected = {4, 2, 4, 1, 4, -1, 0, -1, 1};

    for (int i = 0; i < test_arrays.size(); i++) {
        int result = sol.search(test_arrays[i], targets[i]);

        cout << "Test " << i+1 << ":\n";
        cout << "Target: " << targets[i] << "\n";
        cout << "Output: " << result << "\n";
        cout << "Expected: " << expected[i] << "\n";

        if (result == expected[i]) {
            cout << "PASS\n";
        } else {
            cout << "FAIL\n";
        }

        cout << "----------------------\n";
    }

    return 0;
}