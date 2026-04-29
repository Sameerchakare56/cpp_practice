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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // 1. Check if there are at least k nodes left
        while(cnt < k){
            if(temp == NULL){
                return head; 
            }
            temp = temp->next;
            cnt++;
        }

        // 2. Recursively call for the rest of the list
        // prevNode will hold the head of the already reversed subsequent groups
        ListNode* prevNode = reverseKGroup(temp, k);

        // 3. Reverse the current k nodes
        temp = head; 
        cnt = 0;
        while(cnt < k){
            ListNode* next = temp->next;
            temp->next = prevNode; // Link current node to the "processed" tail

            prevNode = temp;       // Move prevNode forward
            temp = next;           // Move temp forward
            cnt++;
        }
        
        // prevNode is now the new head of this reversed segment
        return prevNode;
    }
};

// --- Helper Functions for Testing ---

// Function to create a linked list from a vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard case
    // Input: 1->2->3->4->5, k = 2
    // Output: 2->1->4->3->5
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    ListNode* head1 = createList(arr1);
    cout << "Test 1 (k=2): ";
    printList(sol.reverseKGroup(head1, k1));

    // Test Case 2: k is larger than part of the list
    // Input: 1->2->3->4->5, k = 3
    // Output: 3->2->1->4->5
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 3;
    ListNode* head2 = createList(arr2);
    cout << "Test 2 (k=3): ";
    printList(sol.reverseKGroup(head2, k2));

    // Test Case 3: k equals list length
    // Input: 1->2, k = 2
    // Output: 2->1
    vector<int> arr3 = {1, 2};
    int k3 = 2;
    ListNode* head3 = createList(arr3);
    cout << "Test 3 (k=2): ";
    printList(sol.reverseKGroup(head3, k3));

    return 0;
}