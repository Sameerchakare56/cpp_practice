#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution obj;

    vector<pair<string, string>> testcases = {
        {"daabcbaabcbc", "abc"},     // expected: dab
        {"axxxxyyyyb", "xy"},       // expected: ab
        {"aaaaa", "aa"},            // expected: a
        {"hello world", "lo"},      // expected: hel world
        {"abababa", "aba"},         // expected: ba
        {"mississippi", "issi"},    // expected: mssippi
        {"abc", "d"},               // expected: abc (no change)
        {"", "a"},                  // expected: ""
        {"aaa", "aaaa"},            // expected: aaa
        {"aabbaabb", "ab"}          // expected: ba
    };

    for (int i = 0; i < testcases.size(); i++) {
        string s = testcases[i].first;
        string part = testcases[i].second;

        cout << "Test Case " << i + 1 << endl;
        cout << "Input: s = \"" << s << "\", part = \"" << part << "\"" << endl;

        string result = obj.removeOccurrences(s, part);
        cout << "Output: " << result << endl;

        cout << "--------------------------\n";
    }

    return 0;
}