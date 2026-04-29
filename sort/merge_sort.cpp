#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int st, int mid, int end){
    vector<int> temp(end - st + 1);
    int i = st;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
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
}
void mergesort(vector<int>& arr, int st , int end ){
    if(st < end){
        int mid = st + (end - st) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);

        merge(arr, st, mid, end);


    }

}

int main(){
    
    
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergesort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    
    return 0;


}