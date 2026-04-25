#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are not palindrome
        if (x < 0) {
            return false;
        }

        int original = x;
        long long reversed = 0;

        while (x != 0) {
            int reminder = x % 10;
            reversed = reversed * 10 + reminder;
            x = x / 10;
        }

        return original == reversed;
    }
};

int main() {

    Solution obj;

    int testCases[] = {121, -121, 10, 12321, 0};

    for (int x : testCases) {
        cout << "Input: " << x << " -> ";

        if (obj.isPalindrome(x))
            cout << "Palindrome";
        else
            cout << "Not Palindrome";

        cout << endl;
    }

    return 0;
}