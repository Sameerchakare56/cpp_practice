#include <iostream>
using namespace std;

void swapArray(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void  uniqueValues(int arr[], int n){
    int i = 0;
    for(int j=1; j<n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }

    }
    for(int k = 0; k<=i; k++){
        cout << arr[k] << " ";
    }
}
    

int main(){
    int arr[] = {1,2,3,4,5 , 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    swapArray(arr,n);
    uniqueValues(arr,n);
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;

}