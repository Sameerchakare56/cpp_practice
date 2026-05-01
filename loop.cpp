#include <iostream>
using namespace std;

int main(){

    int n = 10 ;

    for(int i =1 ; i <=n ; i++){
        cout << i <<" ";
    }
    cout << endl;
   

    int x = 50;
    for(int i =1; i<=5;i++){
    for(int j= 1 ; j<=x;j++){
        cout<<"*";
    } x--;
    cout<<endl;
}
    cout <<endl;
    return 0;
    
}