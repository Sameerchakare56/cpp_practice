#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0; // write pointer

        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            // count same characters
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // store character
            chars[idx++] = ch;

            // store count if > 1
            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--; // adjust index
        }

        chars.resize(idx);
        return idx;
    }
};

void printVector(vector<char>& v) {
    for (char c : v) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    Solution obj;

    vector<vector<char>> testcases = {
        {'a','a','b','b','c','c','c'},   // a2 b2 c3
        {'a'},                          // a
        {'a','b','b','b','b','b','b','b','b','b','b','b','b'}, // ab12
        {'a','a','a','b','b','a','a'},   // a3 b2 a2
        {'x','x','x','x','x','x','x','x','x','x'} // x10
    };

    for (int i = 0; i < testcases.size(); i++) {
        cout << "Test Case " << i + 1 << endl;

        vector<char> chars = testcases[i];

        cout << "Input: ";
        printVector(chars);

        int len = obj.compress(chars);

        cout << "Compressed Output: ";
        printVector(chars);

        cout << "Returned Length: " << len << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}