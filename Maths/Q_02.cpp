// Q2. Find the Pivot Integer

// Given a positive integer n, find the pivot integer x such that:

// The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
// Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

 

// Example 1:

// Input: n = 8
// Output: 6
// Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 is the pivot integer since: 1 = 1.
// Example 3:

// Input: n = 4
// Output: -1
// Explanation: It can be proved that no such integer exist.
 

// Constraints:

// 1 <= n <= 1000


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ----------- BRUTE FORCE APPROACH -----------
    int pivotIntegerBrute(int n) {
        int reverse_sum = 0;
        int sum = 0;

        for(int i = 1; i <= n; i++) {
            sum = 0;
            reverse_sum = 0;

            // Sum from 1 to i
            for(int j = 1; j <= i; j++) {
                sum += j;
            }

            // Sum from i to n
            for(int k = n; k >= i; k--) {
                reverse_sum += k;
            }

            if(sum == reverse_sum) {
                return i;
            }
        }
        return -1;
    }

    // ----------- OPTIMIZED APPROACH -----------
    int pivotIntegerOptimized(int n) {
        int total = n * (n + 1) / 2;
        int x = sqrt(total);

        if(x * x == total) {
            return x;
        }
        return -1;
    }
};

int main() {
    Solution obj;

    // ----------- TEST CASES -----------
    int n1 = 8;
    int n2 = 1;
    int n3 = 4;

    cout << "Brute Force Results:\n";
    cout << "n = " << n1 << " -> " << obj.pivotIntegerBrute(n1) << endl;
    cout << "n = " << n2 << " -> " << obj.pivotIntegerBrute(n2) << endl;
    cout << "n = " << n3 << " -> " << obj.pivotIntegerBrute(n3) << endl;

    cout << "\nOptimized Results:\n";
    cout << "n = " << n1 << " -> " << obj.pivotIntegerOptimized(n1) << endl;
    cout << "n = " << n2 << " -> " << obj.pivotIntegerOptimized(n2) << endl;
    cout << "n = " << n3 << " -> " << obj.pivotIntegerOptimized(n3) << endl;

    return 0;
}

/*
==================== SAMPLE OUTPUT ====================
Brute Force Results:
n = 8 -> 6
n = 1 -> 1
n = 4 -> -1

Optimized Results:
n = 8 -> 6
n = 1 -> 1
n = 4 -> -1
======================================================

==================== COMPLEXITY =======================

1. BRUTE FORCE APPROACH:
   Time Complexity  : O(n^2)
   Space Complexity : O(1)

2. OPTIMIZED APPROACH:
   Time Complexity  : O(1)
   Space Complexity : O(1)

======================================================
*/