#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        int count = 0;

        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                count++;
                for(int j = i * 2; j < n; j = j + i) {
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    int n1 = 10;
    cout << "Number of primes less than " << n1 << " = "
         << obj.countPrimes(n1) << endl;

    // Test Case 2
    int n2 = 0;
    cout << "Number of primes less than " << n2 << " = "
         << obj.countPrimes(n2) << endl;

    // Test Case 3
    int n3 = 1;
    cout << "Number of primes less than " << n3 << " = "
         << obj.countPrimes(n3) << endl;

    // Test Case 4
    int n4 = 2;
    cout << "Number of primes less than " << n4 << " = "
         << obj.countPrimes(n4) << endl;

    // Test Case 5
    int n5 = 20;
    cout << "Number of primes less than " << n5 << " = "
         << obj.countPrimes(n5) << endl;

    // Custom Input (optional)
    int n;
    cout << "\nEnter a number: ";
    cin >> n;
    cout << "Number of primes less than " << n << " = "
         << obj.countPrimes(n) << endl;

    return 0;
}