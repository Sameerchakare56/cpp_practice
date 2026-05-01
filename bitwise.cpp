#include <iostream>
using namespace std;



int reverse(int a){
    int rem, num;
    int ans =1;
    int pow = 1;

    while(a>0){
    rem = a%10;
    num = pow *rem;
    ans = num +ans;
    a/=10;
    pow *=10;

   }
   return ans;
}
int main(){

    int a , b ;
    cout << "enter a number ";
    cin >>a ;
    cout << "enter b number ";
    cin >>b ;
    cout <<"bitwise & : "<< (a&b);
    cout <<"\nbitwise | : "<<  (a|b);
    cout <<"\nbitwise ^ : "<< (a^b);
    int  i= 1 ;
    cout <<"\nbitwise << : "<< (a<<b);
    cout <<"\nbitwise >> : "<< (a>>b)<<endl;
    cout <<sizeof(int)<<endl;
    cout <<sizeof(long int)<<endl;
    cout <<sizeof(short int)<<endl;
    cout <<sizeof(long long int)<<endl;
    cout <<sizeof(unsigned int)<<endl;
    cout <<sizeof(signed int)<<endl;
    cout <<reverse(a)<<endl;

    return 0;

}