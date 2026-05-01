#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> vec ;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.pop_back();
    vec.emplace_back(6);
    vector<int> vec2(vec);
    for(int val : vec2) {
        cout << val << " ";
    }
    cout << endl;
    cout << "val at idx 2 is " << vec[2]<<endl;
    cout << " val at idx 3 is " << vec.at(3) << endl;
    cout << " Front element is " << vec.front() << endl;
    cout << " Back element is " << vec.back() << endl;


    vector<int> vec3(5, 10); 
    vec3.insert(vec3.begin(), 5);
    vec3.insert(vec3.begin()+2, 15);

    vec3.erase(vec3.begin()+3, vec3.end()-1);
    for(int val : vec3) {
        cout << val << " ";
    }
    cout << "\n is empty : "<< vec3.empty() << endl;
    cout << endl;


    vector<int> vec4 = {1, 2, 3, 4, 5};
    vector<int>::iterator it;
    for(it = vec4.begin(); it != vec4.end(); ++it) {
        cout << *it << " ";
    }
    vector<int>::reverse_iterator rit;
    cout << "\nReverse order: ";
    for(rit = vec4.rbegin(); rit != vec4.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << "\n using auto keyword: ";
    for(auto it = vec4.begin(); it != vec4.end(); ++it) {
        cout << *it << " ";
    }
    return 0;

}
