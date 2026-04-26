#include <iostream>
#include <vector>

using namespace std;

// 1. Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse the link
            prev = curr;        // Move prev forward
            curr = next;        // Move curr forward
        }
        return prev; // New head of the list
    }
};

// --- Helper Functions for Testing ---

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << (temp->next ? " -> " : "");
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

// Function to create a linked list from a vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Main function to run the test
int main() {
    Solution sol;

    // Test Case: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> data = {1, 2, 3, 4, 5};
    ListNode* head = createList(data);

    cout << "Original List: ";
    printList(head);

    // Reverse the list
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    // Clean up memory (optional for simple tests, good practice)
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}