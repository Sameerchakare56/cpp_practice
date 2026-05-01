#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                st = mid + 2;  
            } else {
                end = mid;      
            }
        }
        return nums[st];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1,1,2,3,3,4,4,8,8},
        {3,3,7,7,10,11,11},
        {1,1,2},
        {1,2,2,3,3},
        {1},
        {1,1,2,2,3,3,4},
        {0,0,1,1,2,3,3}
    };

    vector<int> expected = {2, 10, 2, 1, 1, 4, 2};

    for (int i = 0; i < tests.size(); i++) {
        int result = sol.singleNonDuplicate(tests[i]);

        cout << "Test " << i+1 << ":\n";
        cout << "Array: ";
        for (int x : tests[i]) cout << x << " ";

        cout << "\nOutput: " << result;
        cout << "\nExpected: " << expected[i];

        if (result == expected[i]) cout << " ✅ PASS\n";
        else cout << " ❌ FAIL\n";

        cout << "----------------------\n";
    }

    return 0;
}