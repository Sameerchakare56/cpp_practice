#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> m;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int first = nums[i];
            int sec = target - first;

            if(m.find(sec) != m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first] = i;
        }
        return ans;
    }
};

int main() {
    Solution obj;

    // 🔹 Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = obj.twoSum(nums1, target1);

    cout << "Test Case 1: ";
    for(int i : res1) cout << i << " ";
    cout << endl;

    // 🔹 Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> res2 = obj.twoSum(nums2, target2);

    cout << "Test Case 2: ";
    for(int i : res2) cout << i << " ";
    cout << endl;

    // 🔹 Test Case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> res3 = obj.twoSum(nums3, target3);

    cout << "Test Case 3: ";
    for(int i : res3) cout << i << " ";
    cout << endl;

    return 0;
}