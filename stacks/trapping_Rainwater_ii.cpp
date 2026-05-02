#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        while (l < r) {
            // Update the maximum heights encountered from both sides
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            // The amount of water is limited by the smaller maximum boundary
            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case: Standard elevation map
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    int result = sol.trap(height);
    
    cout << "Total water trapped: " << result << " units" << endl;

    return 0;
}