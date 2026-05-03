#include <iostream>
#include <vector>
#include <deque>

using namespace std; 

int main(){
    deque<int> q ;

    q.push_back(1) ;
    q.push_front(2) ;
    q.push_back(23);
    q.push_front(20) ;

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop_front();
    }

    return 0;
}