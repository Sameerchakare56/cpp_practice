#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List {
    
    Node* head;
    Node* tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    //O(1)
    void push_front(int val){
        Node* newNode = new Node(val);
        // Node newNode(val); Static allocation
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    //O(1)
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    //O(1)
    void pop_front(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    //O(n)
    void pop_back(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        if(head->next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    //O(n)
    void insert(int val , int pos){
        if(pos < 0){
            cout << " invalid pos\n" ;
            return ;
        }

        if(pos ==0 ){
            push_front(val);
            return ;
        }

        Node* temp = head ;
        for(int i =0 ; i < pos -1;i++){
            temp = temp -> next ;
        }

        Node* newNode = new Node(val);
        newNode-> next = temp -> next ;
        temp-> next = newNode ;

    } 
    //O(n)
    int search(int key ){
        Node* temp = head ;
        int idx = 0 ;

        while(temp != NULL){
            if(temp -> data == key ){
                return idx ;
            }

            temp = temp-> next ;
            idx++;
        }

        return -1;
    }
    //O(n)
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }        

};
int main() {

    List l1;
    l1.push_front(10);
    l1.push_front(20);
    l1.insert(4 ,0);
    l1.insert(7 ,1);
    l1.push_front(30);
    l1.push_back(40);
    l1.pop_front();
    l1.pop_back();

    
    l1.printLL();
    cout <<" \n" ;
    cout <<l1.search(10);

    


    return 0;
    

}