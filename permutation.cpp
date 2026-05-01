#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        // frequency of s1
        for(int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();

        // sliding window (brute)
        for(int i = 0; i < s2.length(); i++) {
            int windIdx = 0, idx = i;
            int windFreq[26] = {0};

            while(windIdx < windSize && idx < s2.length()) {
                windFreq[s2[idx] - 'a']++;
                windIdx++;
                idx++;
            }

            if(isFreqSame(freq, windFreq)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<pair<string, string>> testcases = {
        {"ab", "eidbaooo"},     // true
        {"ab", "eidboaoo"},     // false
        {"adc", "dcda"},        // true
        {"hello", "ooolleoooleh"}, // false
        {"a", "a"},             // true
        {"abc", "bbbca"},       // true
        {"xyz", "afdgzyxksldfm"}, // true
        {"abc", "defgh"},       // false
        {"aa", "aaa"},          // true
        {"abcd", "dcba"}        // true
    };

    for(int i = 0; i < testcases.size(); i++) {
        string s1 = testcases[i].first;
        string s2 = testcases[i].second;

        cout << "Test Case " << i + 1 << endl;
        cout << "s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;

        bool result = obj.checkInclusion(s1, s2);

        if(result)
            cout << "Output: True\n";
        else
            cout << "output: False\n";

        cout << "--------------------------\n";
    }

    return 0;
}