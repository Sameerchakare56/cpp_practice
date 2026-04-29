#include <iostream>
#include <vector>

using namespace std;
int merge(vector<int>& arr, int st, int mid, int end){
    vector<int> temp(end - st + 1);
    int i = st;
    int j = mid + 1;
    int k = 0;
    int invCount = 0;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // Count inversions
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= end){
        temp[k++] = arr[j++];
    }

    for(int i = st; i <= end; i++){
        arr[i] = temp[i - st];
    }

    return invCount;
}
int mergesort(vector<int>& arr, int st , int end ){

    if(st < end){
        int mid = st + (end - st) / 2;
        int left = mergesort(arr, st, mid);
        int right = mergesort(arr, mid + 1, end);
        int invCount =  merge(arr, st, mid, end);
       
        return left + right + invCount;
    }

    return 0;
  

}

int main(){
    vector<int> arr = {6,3,5,2,7};
    
    int ans = mergesort(arr, 0, arr.size() - 1);
    cout << "Number of inversions: " << ans << endl;
    return 0;

}