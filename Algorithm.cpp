#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

bool comparePairs(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    
    if(p1.first<p2.first) return true;
    else return false;
}


int main() {
    
    int arr[5] = {5, 3, 8, 1, 2};

    sort(arr, arr + 5);
    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> vec = {5, 3, 8, 1, 2};
    reverse(vec.begin(), vec.end());
    for(int val : vec){
        cout << val << " ";
    }

    cout << endl;
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Sorted vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vector<pair<int, int>> vecPair = {{5, 10}, {3, 1}, {8, 16}, {1, 2}, {2, 4}};

    sort(vecPair.begin(), vecPair.end(),comparePairs);
    cout << "Sorted vector of pairs: ";
    for (const auto& p : vecPair) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    string str = "abcd";
    next_permutation(str.begin(), str.end());
    cout << "Next permutation: " << str << endl;
    cout << max(4,5)<<" "<< min(6,10 )<< endl;
    int a = 4 , b = 10;
    swap(a , b);
    cout<< " a = "<<a << endl;

    vector<int > vec8 = {1 , 2,3,4,5};
    cout << *max_element(vec8.begin(),vec8.end()) << endl;
    cout << *min_element(vec8.begin(),vec8.end()) << endl;
    
    cout << binary_search(vec8.begin(),vec8.end(),3) << endl;

    int n= 15;
    long int n1 = 1557855;
    long long int n2 = 15;
    cout<< __builtin_popcount(n) << endl;
    cout<< __builtin_popcountl(n1) << endl;
    cout<< __builtin_popcountll(n2) << endl;

    return 0;
}