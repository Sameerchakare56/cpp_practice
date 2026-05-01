#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;  // copy original prices
        stack<int> st;             // store indices

        for(int i = 0; i < n; i++) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};

void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Solution obj;

    // Test Case 1
    vector<int> prices1 = {8,4,6,2,3};
    printVector(obj.finalPrices(prices1));  // Expected: 4 2 4 2 3

    // Test Case 2
    vector<int> prices2 = {1,2,3,4,5};
    printVector(obj.finalPrices(prices2));  // Expected: 1 2 3 4 5

    // Test Case 3
    vector<int> prices3 = {10,1,1,6};
    printVector(obj.finalPrices(prices3));  // Expected: 9 0 1 6

    // Test Case 4 (single element)
    vector<int> prices4 = {5};
    printVector(obj.finalPrices(prices4));  // Expected: 5

    // Test Case 5 (all equal)
    vector<int> prices5 = {7,7,7,7};
    printVector(obj.finalPrices(prices5));  // Expected: 0 0 0 7

    // Test Case 6 (descending)
    vector<int> prices6 = {9,8,7,6,5};
    printVector(obj.finalPrices(prices6));  // Expected: 1 1 1 1 5

    // Test Case 7 (mixed)
    vector<int> prices7 = {2,3,1,2,4,2};
    printVector(obj.finalPrices(prices7));

    // Test Case 8 (large values)
    vector<int> prices8 = {1000,1,1000,1};
    printVector(obj.finalPrices(prices8));

    // Test Case 9
    vector<int> prices9 = {3,3,2,1,4};
    printVector(obj.finalPrices(prices9));

    // Test Case 10
    vector<int> prices10 = {1,1,1,1,1};
    printVector(obj.finalPrices(prices10));

    return 0;
}