#include <iostream>
#include <vector>

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
    ListNode* swapPairs(ListNode* head) {
        // Edge case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = nullptr;

        while (first != nullptr && sec != nullptr) {
            ListNode* third = sec->next;

            // Swapping logic
            sec->next = first;
            first->next = third;

            // Connecting with the previous part of the list
            if (prev != nullptr) {
                prev->next = sec;
            } else {
                head = sec; // Update head for the first pair
            }

            // Move pointers forward for the next iteration
            prev = first;
            first = third;
            if (third != nullptr) {
                sec = third->next;
            } else {
                sec = nullptr;
            }
        }
        return head;
    }
};

// --- Helper Functions for Testing ---

// Utility to create a linked list from a vector
ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Utility to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;

    // Test Case 1: Even number of nodes [1, 2, 3, 4]
    ListNode* list1 = createList({1, 2, 3, 4});
    std::cout << "Original: 1 -> 2 -> 3 -> 4" << std::endl;
    list1 = sol.swapPairs(list1);
    std::cout << "Swapped:  ";
    printList(list1); 

    // Test Case 2: Odd number of nodes [1, 2, 3, 4, 5]
    ListNode* list2 = createList({1, 2, 3, 4, 5});
    std::cout << "\nOriginal: 1 -> 2 -> 3 -> 4 -> 5" << std::endl;
    list2 = sol.swapPairs(list2);
    std::cout << "Swapped:  ";
    printList(list2);

    // Test Case 3: Empty list []
    ListNode* list3 = createList({});
    std::cout << "\nOriginal: []" << std::endl;
    list3 = sol.swapPairs(list3);
    std::cout << "Swapped:  ";
    printList(list3);

    // Test Case 4: Single node [1]
    ListNode* list4 = createList({1});
    std::cout << "\nOriginal: 1" << std::endl;
    list4 = sol.swapPairs(list4);
    std::cout << "Swapped:  ";
    printList(list4);

    return 0;
}