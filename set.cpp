#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
    set<int > s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout <<"lower bound of 2 : " << *s.lower_bound(2) << endl;
    cout <<"upper bound of 4 : " << *s.upper_bound(4) << endl;
    s.erase(3  );
    for(auto item : s){
        cout << item << endl;
    }
    
    auto it = s.lower_bound(2);
    if(it != s.end()) {
        cout << "First element >= 2 is: " << *it << endl;
    }
    auto it2 = s.upper_bound(4);
    if(it2 != s.end()) {
        cout << "First element > 4 is: " << *it2 << endl;
    }

    multiset<int > ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    cout <<" Multiset : " << endl;
    for(auto item : ms) {
        cout << item << endl;
    }

    unordered_set<int > us;
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(4);
    us.insert(5);
    cout <<" Unordered set : " << endl;
    for(auto item : us) {
        cout << item << endl;
    }

    return 0;
}