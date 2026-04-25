// Q3. Palindrome Number
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer x, return true if x is a palindrome, and false otherwise.

 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:

// -231 <= x <= 231 - 1


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindrome
        // Numbers ending with 0 (except 0 itself) are also not palindrome
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse only half of the number
        while(x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even digits: x == reversedHalf
        // For odd digits: x == reversedHalf/10
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};

int main() {
    Solution obj;

    // ----------- TEST CASES -----------
    int x1 = 121;
    int x2 = -121;
    int x3 = 10;
    int x4 = 1221;

    cout << "x = " << x1 << " -> " << obj.isPalindrome(x1) << endl;
    cout << "x = " << x2 << " -> " << obj.isPalindrome(x2) << endl;
    cout << "x = " << x3 << " -> " << obj.isPalindrome(x3) << endl;
    cout << "x = " << x4 << " -> " << obj.isPalindrome(x4) << endl;

    return 0;
}

/*
==================== SAMPLE OUTPUT ====================
x = 121  -> 1 (true)
x = -121 -> 0 (false)
x = 10   -> 0 (false)
x = 1221 -> 1 (true)
======================================================

==================== COMPLEXITY =======================

Time Complexity  : O(log10(n))
                  (We process half of the digits)

Space Complexity : O(1)
                  (No extra space used)

======================================================
*/