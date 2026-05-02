#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int limit;
    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

public:
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* resNode = m[key];
        int res = resNode->val;
        
        // Move to most recently used
        delNode(resNode);
        addNode(resNode);
        
        return res;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];
            delNode(existingNode);
            m.erase(key);
            delete existingNode;
        }
        
        if (m.size() == limit) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }

    // Destructor to clean up memory
    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

/**
 * Driver code with Test Cases
 */
int main() {
    cout << "--- Test Case 1: Standard LRU Operations ---" << endl;
    LRUCache lRUCache(2);
    
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    
    cout << "get(1): " << lRUCache.get(1) << " (Expected: 1)" << endl; 
    
    lRUCache.put(3, 3); // LRU was 2, evicts key 2, cache is {1=1, 3=3}
    cout << "get(2): " << lRUCache.get(2) << " (Expected: -1)" << endl; 
    
    lRUCache.put(4, 4); // LRU was 1, evicts key 1, cache is {4=4, 3=3}
    cout << "get(1): " << lRUCache.get(1) << " (Expected: -1)" << endl; 
    cout << "get(3): " << lRUCache.get(3) << " (Expected: 3)" << endl; 
    cout << "get(4): " << lRUCache.get(4) << " (Expected: 4)" << endl;

    cout << "\n--- Test Case 2: Update Existing Key ---" << endl;
    LRUCache lru2(1);
    lru2.put(2, 1);
    cout << "get(2): " << lru2.get(2) << " (Expected: 1)" << endl;
    lru2.put(2, 2);
    cout << "get(2): " << lru2.get(2) << " (Expected: 2)" << endl;

    return 0;
}