#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Optimized Palindrome check using two pointers
    bool isPalin(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void getAllParts(string s, int start, vector<string>& currentPartitions,
                     vector<vector<string>>& ans) {
        // Base Case: If start index reaches the end of string
        if (start >= s.size()) {
            ans.push_back(currentPartitions);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            // Check if the prefix s[start...i] is a palindrome
            if (isPalin(s, start, i)) {
                // Choose: add the substring to current partition
                currentPartitions.push_back(s.substr(start, i - start + 1));
                
                // Explore: move to the next part of the string
                getAllParts(s, i + 1, currentPartitions, ans);
                
                // Un-choose (Backtrack): remove the last added substring
                currentPartitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currentPartitions;
        getAllParts(s, 0, currentPartitions, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    string testInput = "aab";
    
    vector<vector<string>> result = sol.partition(testInput);

    // Print the results
    cout << "Palindrome Partitions for \"" << testInput << "\":" << endl;
    for (const auto& partition : result) {
        cout << "[ ";
        for (const string& s : partition) {
            cout << "\"" << s << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}