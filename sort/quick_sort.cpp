#include <iostream>
#include <vector>

using namespace std;
int partition(vector<int>& arr, int st, int end){
    int idx = st -1 , pivot = arr[end];

    for(int i = st; i < end; i++){
        if(arr[i] < pivot){
            idx++;
            swap(arr[idx], arr[i]);
        }
    }

    idx ++;
    swap(arr[idx], arr[end]);
    return idx;



}
void quicksort(vector<int>& arr, int st, int end){
    if(st < end){
        int pivIdx = partition(arr, st, end);
        quicksort(arr, st, pivIdx - 1);
        quicksort(arr, pivIdx + 1, end);
    }

}
int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
    quicksort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}