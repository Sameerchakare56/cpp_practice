#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Handle empty input edge case

        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];

        // Fill left-max array
        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], height[i]);
        }

        // Fill right-max array
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], height[i]);
        }

        int ans = 0;
        // Calculate trapped water at each index
        for (int i = 0; i < n; i++) {
            ans += min(lmax[i], rmax[i]) - height[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1: Standard case
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Water (Example 1): " << sol.trap(height1) << " units" << endl;

    // Example 2: Stepped case
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Trapped Water (Example 2): " << sol.trap(height2) << " units" << endl;

    return 0;
}