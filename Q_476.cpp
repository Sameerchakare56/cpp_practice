// 476. Number Complement
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

 

// Example 1:

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

// Constraints:

// 1 <= num < 231


#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;

        int power = 0;
        int result = 0;

        while (num > 0) {
            int remainder = num % 2;

            if (remainder == 0) {
                result += (1 << power);  // 2^power
            }

            power++;
            num = num / 2;
        }

        return result;
    }
};

int main() {
    Solution obj;

    cout << obj.findComplement(5) << endl;   // 2
    cout << obj.findComplement(1) << endl;   // 0
    cout << obj.findComplement(10) << endl;  // 5
    cout << obj.findComplement(0) << endl;   // 1

    return 0;
}