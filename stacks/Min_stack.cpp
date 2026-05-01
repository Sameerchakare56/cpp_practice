// class MinStack {
// public:
//     stack<long long int> s;
//     long long int minVal;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(s.empty()){
//             s.push(val);
//             minVal = val;
//         }else{
//             if(val < minVal){
//                 s.push((long long)2* val - minVal );
//                 minVal = val ;
//             }else{
//                 s.push(val);
//             }
//         }
        
//     }
    
//     void pop() {
//         if(s.top() <minVal){
//             minVal = 2*minVal - s.top();
//         }
//         s.pop();
//     }
    
//     int top() {
//         if(s.top() < minVal){
//             return minVal;
//         }return s.top();
//     }
    
//     int getMin() {
//         return minVal;
//     }
// };


#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class MinStack {
public:
    // pair.first stores the actual value, pair.second stores the minimum in the stack so far
    stack<pair<int, int>> s;

    MinStack() {
        // Constructor: Nothing specific needed for the internal stack
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            // Compare current value with the minimum of the element below it
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }
    
    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Test Execution
 */
int main() {
    MinStack* minStack = new MinStack();
    
    cout << "--- Starting MinStack Tests ---" << endl;

    // Test Case 1: Standard Push & Min check
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    
    cout << "Current Min (expected -3): " << minStack->getMin() << endl; // Returns -3
    
    // Test Case 2: Pop and check Min change
    minStack->pop();
    cout << "Top value (expected 0): " << minStack->top() << endl;      // Returns 0
    cout << "Current Min (expected -2): " << minStack->getMin() << endl; // Returns -2

    // Test Case 3: Duplicate Minimums
    minStack->push(-5);
    minStack->push(-5);
    cout << "Current Min (expected -5): " << minStack->getMin() << endl;
    
    minStack->pop();
    cout << "Min after popping one -5 (expected -5): " << minStack->getMin() << endl;

    // Clean up
    delete minStack;
    
    cout << "--- Tests Completed ---" << endl;
    return 0;
}