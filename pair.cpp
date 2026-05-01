#include <iostream>
#include <deque>
#include <list>
#include <vector>

using namespace std;

int main(){
    pair<string ,int> p1("sameer", 2);
    pair<int , pair<string, int>> p2(1, {"sameer", 2});
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
    
    vector<pair<int, int>> vec ={{1, 2} , {3, 4} , {5, 6}};
    vec.push_back({7, 8});
    vec.emplace_back(9, 10);

    for(auto p:vec){
        cout << p.first << " "<< p.second << endl;
    }
    return 0;

}