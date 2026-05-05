#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Finds the index of the first non-repeating character.
     * Time Complexity: O(N) - Each character is pushed and popped from the queue at most once.
     * Space Complexity: O(1) - The map and queue store at most 26-256 characters/indices.
     */
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> Q;

        for (int i = 0; i < s.size(); i++) {
            // If it's the first time seeing the character, it's a candidate for being unique
            if (m.find(s[i]) == m.end()) {
                Q.push(i);
            }
            
            // Increment the frequency count
            m[s[i]]++;

            // Clean up the front of the queue: 
            // If the character at the front is no longer unique, discard it.
            while (!Q.empty() && m[s[Q.front()]] > 1) {
                Q.pop();
            }
        }

        // If queue is empty, no unique character exists
        return Q.empty() ? -1 : Q.front();
    }
};

// --- Test Harness ---
int main() {
    Solution sol;

    // Define test cases: {input_string, expected_output}
    vector<pair<string, int>> testCases = {
        {"leetcode", 0},       // 'l' is unique at index 0
        {"loveleetcode", 2},   // 'v' is unique at index 2
        {"aabb", -1},          // No unique characters
        {"alphabet", 1},       // 'l' is unique at index 1 ('a' repeats)
        {"", -1},              // Empty string case
        {"z", 0}               // Single character case
    };

    cout << "Running Test Cases..." << endl;
    cout << "---------------------------------------" << endl;
    cout << "Input\t\t| Expected\t| Result" << endl;
    cout << "---------------------------------------" << endl;

    for (const auto& test : testCases) {
        int result = sol.firstUniqChar(test.first);
        cout << (test.first.empty() ? "(empty)" : test.first) << "\t\t| " 
             << test.second << "\t\t| " << result;
        
        if (result == test.second) {
            cout << " [PASS]" << endl;
        } else {
            cout << " [FAIL]" << endl;
        }
    }

    return 0;
}