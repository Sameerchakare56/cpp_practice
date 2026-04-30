#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            else {
                // If we see a closing bracket but the stack is empty, it's invalid
                if (st.empty()) return false;

                char top = st.top();
                // Check if the current closing bracket matches the most recent opening one
                if ((c == ')' && top == '(') || 
                    (c == ']' && top == '[') || 
                    (c == '}' && top == '{')) {
                    st.pop();
                } else {
                    // Mismatch found (e.g., "(]")
                    return false;
                }
            }
        }
        
        // If the stack is empty, all brackets were properly closed
        return st.empty();
    }
};

int main() {
    Solution sol;
    
    // List of test cases
    vector<string> testCases = {
        "()",         // Valid
        "()[]{}",     // Valid
        "(]",         // Invalid: Mismatched types
        "([)]",       // Invalid: Wrong order
        "{[]}",       // Valid: Nested
        "((",         // Invalid: Unclosed
        "]]"          // Invalid: Starts with closing
    };

    cout << "--- Valid Parentheses Test Results ---" << endl;
    for (const string& test : testCases) {
        bool result = sol.isValid(test);
        cout << "Input: \"" << test << "\" -> " 
             << (result ? "VALID" : "INVALID") << endl;
    }

    return 0;
}