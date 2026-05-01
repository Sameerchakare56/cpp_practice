// sum of number from 1 to n .

#include <iostream>
using namespace std;

int main() {
    int n ;
    int sum =0 ;
    cout << "enter the number which you want to sum ";
    cin >> n;
    for(int i =1 ; i <=n ; i++ ){
        sum += i;
        }
    cout << "Sum : "<< sum<<endl;
    int sum_odd = 0;
    int i = 1;
    while(i <=n ){
        if(i%2 !=0){
          sum_odd += i;
        }
        i++;
    }
    cout << "Sum of odd : "<< sum_odd<<endl;
    return 0;
}