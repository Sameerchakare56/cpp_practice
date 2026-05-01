#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool posible(vector<int>& arr, int N , int C, int mid){
    int cowCount = 1, lastPos = arr[0];
    for(int i = 1; i < N; i++){
        if(arr[i] - lastPos >= mid){
            cowCount++;
            lastPos = arr[i];
        }
    }
    return cowCount >= C;
}

int getDistance(vector<int>& arr, int N , int C){

    sort(arr.begin(), arr.end());
    int st = 1, end =  arr[N-1] - arr[0] , ans = -1;
    while (st <= end){
        int mid = st + (end - st) / 2;
        
        if(posible(arr , N,C, mid))
            ans = mid, st = mid + 1;
        else
            end = mid - 1;
    }
    return ans;
}
int main(){
    int N =5, C =3;
    vector<int> arr = {1,2,8,4,9};

    cout << getDistance(arr, N, C) << "\n";
    return 0;
}