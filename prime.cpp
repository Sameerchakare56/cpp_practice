#include <iostream>
using namespace std;
int main(){

    bool isprime = true ;
    int n ;
    cout << "enter the number ";
    cin >> n;
    for(int i = 2; i*i<=n-1;i++ ){
        if(n%i==0){
            isprime = false;
            break;
        }
    }
    if(isprime==true){
        cout<< "this prime number "<<n ;
    }
    else{ cout<< "this not prime : "<<n;
    }
}