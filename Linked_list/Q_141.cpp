#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        // Fast moves twice as fast as slow
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            // If they meet, there is a cycle
            if (slow == fast) {
                return true;
            }
        }

        return false; // Fast reached the end, so no cycle
    }
};

int main() {
    Solution sol;

    // --- TEST CASE 1: List with a Cycle ---
    // 3 -> 2 -> 0 -> -4 -> (points back to 2)
    ListNode* head1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creating the cycle here!

    cout << "Test Case 1 (Cycle): " << (sol.hasCycle(head1) ? "True" : "False") << endl;

    // --- TEST CASE 2: List without a Cycle ---
    // 1 -> 2 -> NULL
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "Test Case 2 (No Cycle): " << (sol.hasCycle(head2) ? "True" : "False") << endl;

    // --- TEST CASE 3: Empty List ---
    cout << "Test Case 3 (Empty): " << (sol.hasCycle(NULL) ? "True" : "False") << endl;

    return 0;
}