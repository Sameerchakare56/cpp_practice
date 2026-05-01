#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.front() << endl; // Output: 1
    cout << "Back element: " << q.back() << endl; // Output: 3
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 2

    q.push(4);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}