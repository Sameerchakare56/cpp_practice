#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        // Phase 1: Determine if a cycle exists
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next; 
            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        // Phase 2: Find the entry point of the cycle
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// Helper function to create a linked list with a cycle for testing
ListNode* createListWithCycle(vector<int> values, int pos) {
    if (values.empty()) return NULL;

    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    ListNode* cycleEntry = NULL;

    if (pos == 0) cycleEntry = head;

    for (int i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
        if (i == pos) {
            cycleEntry = curr;
        }
    }

    // Link the end of the list to the node at index 'pos'
    if (pos != -1) {
        curr->next = cycleEntry;
    }

    return head;
}

int main() {
    Solution sol;
    // Time Complexity O(n)
    // Space Complexity O(1)
    // --- Test Case 1 ---
    // List: 3 -> 2 -> 0 -> -4, Cycle back to index 1 (value 2)
    vector<int> vals1 = {3, 2, 0, -4};
    int pos1 = 1;
    ListNode* head1 = createListWithCycle(vals1, pos1);

    ListNode* result1 = sol.detectCycle(head1);
    if (result1) {
        cout << "Test Case 1: Cycle detected at node with value " << result1->val << endl;
    } else {
        cout << "Test Case 1: No cycle detected." << endl;
    }

    // --- Test Case 2 ---
    // List: 1 -> 2, Cycle back to index 0 (value 1)
    vector<int> vals2 = {1, 2};
    int pos2 = 0;
    ListNode* head2 = createListWithCycle(vals2, pos2);

    ListNode* result2 = sol.detectCycle(head2);
    if (result2) {
        cout << "Test Case 2: Cycle detected at node with value " << result2->val << endl;
    } else {
        cout << "Test Case 2: No cycle detected." << endl;
    }

    // --- Test Case 3 ---
    // List: 1, No cycle
    vector<int> vals3 = {1};
    int pos3 = -1;
    ListNode* head3 = createListWithCycle(vals3, pos3);

    ListNode* result3 = sol.detectCycle(head3);
    if (result3) {
        cout << "Test Case 3: Cycle detected at node with value " << result3->val << endl;
    } else {
        cout << "Test Case 3: No cycle detected." << endl;
    }

    return 0;
}