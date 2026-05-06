#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    /**
     * Logic: 
     * 1. If total gas < total cost, the circuit is impossible.
     * 2. If we start at station 'start' and run out of gas at station 'i', 
     *    then no station between 'start' and 'i' can be a valid starting point.
     *    We reset our start to 'i + 1'.
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0, totCost = 0;

        // Calculate total balance to see if a solution even exists
        for (int val : gas) totGas += val;
        for (int val : cost) totCost += val;

        if (totGas < totCost) {
            return -1;
        }

        int start = 0;
        int currGas = 0;

        for (int i = 0; i < gas.size(); i++) {
            currGas += (gas[i] - cost[i]);

            // If currGas drops below zero, the current 'start' is invalid
            if (currGas < 0) {
                // Pick the next station as the new starting candidate
                start = i + 1;
                // Reset current tank
                currGas = 0;
            }
        }

        return start;
    }
};

// --- Test Harness ---
int main() {
    Solution sol;

    struct TestCase {
        vector<int> gas;
        vector<int> cost;
        int expected;
    };

    vector<TestCase> testCases = {
        {{1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3}, // Start at index 3
        {{2, 3, 4}, {3, 4, 3}, -1},             // Total cost > total gas
        {{5, 1, 2, 3, 4}, {4, 4, 1, 5, 1}, 4}, // Start at index 4
        {{3, 1, 1}, {1, 2, 2}, 0}              // Start at index 0
    };

    cout << "Running Gas Station Tests..." << endl;
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < testCases.size(); i++) {
        int result = sol.canCompleteCircuit(testCases[i].gas, testCases[i].cost);
        
        cout << "Test " << i + 1 << ": ";
        if (result == testCases[i].expected) {
            cout << "[PASS]";
        } else {
            cout << "[FAIL]";
        }
        cout << " (Result: " << result << ", Expected: " << testCases[i].expected << ")" << endl;
    }

    return 0;
}