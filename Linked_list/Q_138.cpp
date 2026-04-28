#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        // Map to store (Original Node -> Copied Node)
        unordered_map<Node*, Node*> m;

        // First pass: Create all nodes and store them in the map
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Second pass: Assign random pointers using the map
        oldTemp = head; 
        newTemp = newHead;
        while (oldTemp != NULL) {
            // m[NULL] will naturally return NULL, so this handles null random pointers
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// --- Helper Functions for Testing ---

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        int randomVal = temp->random ? temp->random->val : -1; // -1 represents NULL
        cout << "[" << temp->val << ", Random: " << randomVal << "] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List 1:" << endl;
    printList(n1);

    Node* copiedList1 = sol.copyRandomList(n1);
    cout << "Copied List 1:" << endl;
    printList(copiedList1);
    cout << "-----------------------------------" << endl;

    // Test Case 2: Empty List
    Node* nEmpty = NULL;
    Node* copiedEmpty = sol.copyRandomList(nEmpty);
    cout << "Test Empty List: " << (copiedEmpty == NULL ? "Success (NULL)" : "Fail") << endl;
    
    return 0;
}