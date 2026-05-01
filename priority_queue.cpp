#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);
    pq.push(3);
    pq.push(7);

    cout << "Top element: " << pq.top() << endl; // Output: 8
    pq.pop();
    cout << "Top element after pop: " << pq.top() << endl; // Output: 5
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(5);
    min_pq.push(2);
    min_pq.push(8);
    min_pq.push(1);
    cout << endl;
    while(!min_pq.empty()){
        cout << min_pq.top() << " ";
        min_pq.pop();
    }


    return 0;
}