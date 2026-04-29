#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;

        Node* curr = head;
        while (curr != nullptr) {
            // If we find a child, we need to inject it between curr and curr->next
            if (curr->child != nullptr) {
                Node* nextNode = curr->next;
                
                // Recursively flatten the child branch
                Node* flattenedChild = flatten(curr->child);
                
                // Connect curr to the flattened child
                curr->next = flattenedChild;
                flattenedChild->prev = curr;
                curr->child = nullptr; // Important: clear the child pointer

                // Traverse to the end of the newly flattened section
                Node* temp = curr;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }

                // Reconnect the rest of the original list
                if (nextNode != nullptr) {
                    temp->next = nextNode;
                    nextNode->prev = temp;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

// --- Helper Functions for Testing ---

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << (temp->next ? " <-> " : "");
        temp = temp->next;
    }
    cout << " (nullptr)" << endl;
}

int main() {
    Solution sol;

    // Creating a dummy multilevel list:
    // 1 - 2 - 3 - 4
    //         |
    //         7 - 8
    
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    // Level 1 connections
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    // Level 2 (child of 3)
    n3->child = n7;
    n7->next = n8; n8->prev = n7;

    cout << "Original List (Head: 1, Child at 3):" << endl;
    
    Node* flattenedHead = sol.flatten(n1);

    cout << "Flattened List:" << endl;
    printList(flattenedHead);

    return 0;
}