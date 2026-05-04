#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1; // Primary stack to store elements in queue order
    stack<int> s2; // Auxiliary stack for reordering

    MyQueue() {
        // Constructor: No specific initialization needed for std::stack
    }
    
    /** 
     * Pushes element x to the back of the queue.
     * Time Complexity: O(n)
     */
    void push(int x) {
        // 1. Move everything from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // 2. Put the new element at the bottom of the "queue"
        s1.push(x);

        // 3. Move everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** 
     * Removes the element from the front of the queue and returns it
     * Time Complexity: O(1)
     */
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    /** 
     * Get the front element.
     * Time Complexity: O(1)
     */
    int peek() {
        return s1.top();
    }
    
    /** 
     * Returns whether the queue is empty.
     */
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue* q = new MyQueue();
    
    q->push(10);
    q->push(20);
    q->push(30);

    cout << "Front element (peek): " << q->peek() << endl; // Should be 10
    cout << "Popped element: " << q->pop() << endl;       // Should be 10
    cout << "New front element: " << q->peek() << endl;   // Should be 20
    
    if (!q->empty()) {
        cout << "Queue is not empty." << endl;
    }

    delete q;
    return 0;
}