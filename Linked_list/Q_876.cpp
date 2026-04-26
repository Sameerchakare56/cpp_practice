#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Fast moves twice as fast as slow. 
        // When fast reaches the end, slow is at the middle.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// --- Helper Functions ---

// Creates a linked list from a vector and returns the head
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

// Prints the list starting from a given node
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Odd number of nodes [1, 2, 3, 4, 5] -> Middle is 3
    vector<int> v1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(v1);
    cout << "List 1: "; printList(head1);
    ListNode* mid1 = sol.middleNode(head1);
    cout << "Middle node value: " << mid1->val << "\n\n";

    // Test Case 2: Even number of nodes [1, 2, 3, 4, 5, 6] -> Middle is 4
    // (Per LeetCode rules, if there are two middle nodes, return the second one)
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = createList(v2);
    cout << "List 2: "; printList(head2);
    ListNode* mid2 = sol.middleNode(head2);
    cout << "Middle node value: " << mid2->val << "\n";

    return 0;
}