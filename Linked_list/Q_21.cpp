#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        // Base Case: If one list is empty, return the other
        if (head1 == nullptr || head2 == nullptr) {
            return head1 == nullptr ? head2 : head1;
        }

        // Recursive Step: Compare values
        if (head1->val <= head2->val) {
            // head1 is smaller, so find what comes after head1
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            // head2 is smaller, so find what comes after head2
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

// --- Helper Functions for Testing ---

// Creates a linked list from a vector of integers
ListNode* createList(vector<int> nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Prints the linked list
void printList(ListNode* head) {
    if (!head) {
        cout << "[]";
    }
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // --- Test Case 1: Both lists have values ---
    cout << "Test Case 1:" << endl;
    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});
    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);
    
    ListNode* result1 = sol.mergeTwoLists(l1, l2);
    cout << "Merged: "; printList(result1);
    cout << "--------------------------" << endl;

    // --- Test Case 2: One list is empty ---
    cout << "Test Case 2:" << endl;
    ListNode* l3 = nullptr; // Empty list
    ListNode* l4 = createList({0});
    cout << "List 3: "; printList(l3);
    cout << "List 4: "; printList(l4);
    
    ListNode* result2 = sol.mergeTwoLists(l3, l4);
    cout << "Merged: "; printList(result2);
    cout << "--------------------------" << endl;

    // --- Test Case 3: Both lists are empty ---
    cout << "Test Case 3:" << endl;
    ListNode* l5 = nullptr;
    ListNode* l6 = nullptr;
    
    ListNode* result3 = sol.mergeTwoLists(l5, l6);
    cout << "Merged: "; printList(result3);
    
    return 0;
}