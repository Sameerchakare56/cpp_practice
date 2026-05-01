#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr , int tar){
    int st = 0 , end = arr.size() - 1;

    while(st <= end){
        int mid = st + (end - st) / 2;

        if(tar > arr[mid]){
            st = mid + 1;
        } 
        else if(tar < arr[mid]){
            end = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};

    // Test Case 1: Element present in middle
    cout << "Index of 7: " << binarySearch(arr, 7) << endl;

    // Test Case 2: Element present at beginning
    cout << "Index of 1: " << binarySearch(arr, 1) << endl;

    // Test Case 3: Element present at end
    cout << "Index of 13: " << binarySearch(arr, 13) << endl;

    // Test Case 4: Element not present
    cout << "Index of 6: " << binarySearch(arr, 6) << endl;

    // Test Case 5: Single element array
    vector<int> arr2 = {10};
    cout << "Index of 10: " << binarySearch(arr2, 10) << endl;

    // Test Case 6: Empty array
    vector<int> arr3;
    cout << "Index of 5 in empty array: " << binarySearch(arr3, 5) << endl;

    return 0;
}