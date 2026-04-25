#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int last = height.size() - 1;
        int maxwater = 0;

        while (start < last) {
            int h = min(height[start], height[last]);
            int width = last - start;
            int water = h * width;

            maxwater = max(maxwater, water);

            if (height[start] < height[last])
                start++;
            else
                last--;
        }

        return maxwater;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> tests = {
        {1,8,6,2,5,4,8,3,7},
        {1,1},
        {4,3,2,1,4},
        {1,2,1}
    };

    for(auto t : tests) {
        cout << "Max Water: " << obj.maxArea(t) << endl;
    }

    return 0;
}