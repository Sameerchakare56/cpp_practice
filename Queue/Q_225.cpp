#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    /** Initialize your data structure here. */
    MyStack() {
        // Constructor
    }
    
    /** 
     * Push element x onto stack.
     * Complexity: O(n)
     */
    void push(int x) {
        // 1. Move all elements from q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // 2. Push the new element into the now empty q1
        q1.push(x);

        // 3. Move everything back from q2 to q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    /** 
     * Removes the element on top of the stack and returns that element.
     * Complexity: O(1)
     */
    int pop() {
       int ans = q1.front();
       q1.pop();
       return ans; 
    }
    
    /** 
     * Get the top element.
     * Complexity: O(1)
     */
    int top() {
        return q1.front();
    }
    
    /** 
     * Returns whether the stack is empty.
     */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Example usage:
 */
int main() {
    MyStack* obj = new MyStack();
    obj->push(10);
    obj->push(20);
    
    cout << "Top element: " << obj->top() << endl;    // Returns 20
    cout << "Popped element: " << obj->pop() << endl; // Returns 20
    cout << "Is empty: " << (obj->empty() ? "Yes" : "No") << endl;
    
    return 0;
}