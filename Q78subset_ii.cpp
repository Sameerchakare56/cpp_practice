#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllsubsets(vector<int>& nums , vector<int> & ans, int i , vector<vector<int>> &allsubsets){
        if(i== nums.size()){
            allsubsets.push_back(ans);
            return ;
        }

        // include
        ans.push_back(nums[i]);
        getAllsubsets(nums , ans, i+1 , allsubsets);

        // backtrack
        ans.pop_back();

        // skip duplicates
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx -1]) idx++;

        // exclude
        getAllsubsets(nums , ans , idx , allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int> nums) { // ✅ FIXED
        sort(nums.begin() , nums.end());

        vector<vector<int>> allsubsets;
        vector<int> ans;

        getAllsubsets(nums ,ans , 0 ,allsubsets);
        return allsubsets;
    }
};

void print(vector<vector<int>> res){
    for(auto &v : res){
        cout << "[ ";
        for(int x : v) cout << x << " ";
        cout << "]\n";
    }
    cout << "------\n";
}

int main(){
    Solution obj;

    print(obj.subsetsWithDup(vector<int>{1,2,2}));
    print(obj.subsetsWithDup(vector<int>{0}));
    print(obj.subsetsWithDup(vector<int>{1,1}));
    print(obj.subsetsWithDup(vector<int>{1,2,2,2}));
    print(obj.subsetsWithDup(vector<int>{}));

    return 0;
}