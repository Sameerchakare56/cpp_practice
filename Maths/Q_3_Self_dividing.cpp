// A self-dividing number is a number that is divisible by every digit it contains.

// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
// A self-dividing number is not allowed to contain the digit zero.

// Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).

 

// Example 1:

// Input: left = 1, right = 22
// Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
// Example 2:

// Input: left = 47, right = 85
// Output: [48,55,66,77]
 

// Constraints:

// 1 <= left <= right <= 104

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for (int num = left; num <= right; num++) {
            int temp = num;
            bool isValid = true;

            while (temp > 0) {
                int digit = temp % 10;

                // Check if digit is 0 or not divisible
                if (digit == 0 || num % digit != 0) {
                    isValid = false;
                    break;
                }

                temp /= 10;
            }

            if (isValid) {
                result.push_back(num);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int left1 = 1, right1 = 22;
    vector<int> res1 = sol.selfDividingNumbers(left1, right1);
    cout << "Input: " << left1 << " " << right1 << endl;
    cout << "Output: ";
    for (int x : res1) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 3 4 5 6 7 8 9 11 12 15 22\n\n";

    // Test Case 2
    int left2 = 47, right2 = 85;
    vector<int> res2 = sol.selfDividingNumbers(left2, right2);
    cout << "Input: " << left2 << " " << right2 << endl;
    cout << "Output: ";
    for (int x : res2) cout << x << " ";
    cout << endl;
    cout << "Expected: 48 55 66 77\n\n";

    // Test Case 3 (Edge Case)
    int left3 = 10, right3 = 15;
    vector<int> res3 = sol.selfDividingNumbers(left3, right3);
    cout << "Input: " << left3 << " " << right3 << endl;
    cout << "Output: ";
    for (int x : res3) cout << x << " ";
    cout << endl;
    cout << "Expected: 11 12 15\n";

    return 0;
}