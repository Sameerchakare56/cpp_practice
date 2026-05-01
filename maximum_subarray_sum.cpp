#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int arr[5]= {1,2,3,-4,-5};
    int max_sum = INT8_MIN;

    for(int st = 0 ;st<n;st++){
        int currsum = 0;
        for(int end =st; end<n; end++){
            currsum += arr[end];
            max_sum = max(currsum , max_sum);
            if(currsum<0){currsum =0;}
        }
    }
    cout << "max subarray sum = "<<max_sum <<endl;
}