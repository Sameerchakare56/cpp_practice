#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        // Step 1: reverse whole string
        reverse(s.begin(), s.end());

        // Step 2: extract words
        for(int i = 0; i < n; i++) {
            string word = "";

            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Step 3: reverse individual word
            reverse(word.begin(), word.end());

            // Step 4: add to answer
            if(word.length() > 0) {
                ans += " " + word;
            }
        }

        // Step 5: remove leading space
        return ans.substr(1);
    }
};

// helper function to print string with quotes
void printString(string s) {
    cout << "\"" << s << "\"" << endl;
}

int main() {
    Solution obj;

    vector<string> testcases = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        "  Bob    Loves  Alice   ",
        "single",
        "   multiple     spaces   here   "
    };

    for(int i = 0; i < testcases.size(); i++) {
        cout << "Test Case " << i + 1 << endl;

        string input = testcases[i];

        cout << "Input: ";
        printString(input);

        string result = obj.reverseWords(input);

        cout << "Output: ";
        printString(result);

        cout << "--------------------------" << endl;
    }

    return 0;
}