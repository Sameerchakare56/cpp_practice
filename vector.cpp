#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums){
    int ans = 0; 
    for(int val :nums){
        ans = ans ^val;
    }
    return ans;
}
int main(){
    vector<int>vec= {1,2,3,4};
    cout <<"size = "<<vec.size()<<endl;

    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);

    cout <<"after push back size = "<<vec.size()<<endl;
    
    vec.pop_back();

    for(int i : vec){
        cout <<i <<endl;
    }

    cout << vec.front() <<endl;

    cout << vec.back() <<endl;

    cout << vec.at(2) <<endl;
    
    vector<int> vec2;
    vec2.push_back(0);
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(2);

    vec2.push_back(2);

    
    cout << vec2.size()<< endl;
    cout << vec2.capacity()<< endl;
   
    vector<int>nums= {3,1,2,1,2};
    cout <<"single number "<< singleNumber(nums);
     
    return 0;
}