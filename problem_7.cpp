#include <iostream>
#include <climits>
using namespace std;

int reverseInteger(int x) {
    long long y = 0;

    while (x != 0) {
        int reminder = x % 10;
        y = y * 10 + reminder;
        x = x / 10;
    }

    // Check overflow
    if (y > INT_MAX || y < INT_MIN) {
        return 0;
    }

    return (int)y;
}

int main() {

    int testCases[] = {123, -123, 120, 1534236469, -2147483412};

    for (int x : testCases) {
        cout << "Input: " << x 
             << "  -> Reversed: " << reverseInteger(x) 
             << endl;
    }

    return 0;
}