#include <iostream>
#include <algorithm>

class Solution {
public:
    int sumOfPrimesInRange(int originalNum) {
        int num = originalNum;
        int reversedNum = 0, remainder;
        
        // 1. Reverse the number
        int temp = num;
        while (temp != 0) {
            remainder = temp % 10;
            reversedNum = reversedNum * 10 + remainder;
            temp /= 10;
        }

        // 2. Identify the range (Start from smaller, end at larger)
        int start = std::min(num, reversedNum);
        int end = std::max(num, reversedNum);

        int totalSum = 0;

        // 3. Loop through the range
        for (int i = start; i <= end; i++) {
            if (i < 2) continue; // 0 and 1 are not prime
            
            bool isPrime = true;
            // Check for primality
            for (int j = 2; j * j <= i; j++) { // j*j <= i is more efficient
                if (i % j == 0) {
                    isPrime = false;
                    break; // Only breaks the 'j' loop
                }
            }

            if (isPrime) {
                totalSum += i;
            }
        }
        return totalSum;
    }
};

int main() {
    Solution sol;

    // Test Case 1: num = 13 (reverse is 31). Primes: 13, 17, 19, 23, 29, 31
    int test1 = 13;
    std::cout << "Sum for " << test1 << ": " << sol.sumOfPrimesInRange(test1) << " (Expected: 132)" << std::endl;

    // Test Case 2: num = 20 (reverse is 02). Primes: 2, 3, 5, 7, 11, 13, 17, 19
    int test2 = 20;
    std::cout << "Sum for " << test2 << ": " << sol.sumOfPrimesInRange(test2) << " (Expected: 77)" << std::endl;

    // Test Case 3: num = 11 (reverse is 11). Primes: 11
    int test3 = 11;
    std::cout << "Sum for " << test3 << ": " << sol.sumOfPrimesInRange(test3) << " (Expected: 11)" << std::endl;

    return 0;
} 