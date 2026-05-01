class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p,vector<vector<int>>& queries) {
        n = nums.size();
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < queries[i].size(); j++) {
                nums[i] = queries[j];
                if(nums[i] % p == 0) {
            }
            
        }
    }
}