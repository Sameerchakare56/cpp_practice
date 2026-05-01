#include <iostream>
using namespace std;

int GCD(int a , int b){
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int LCM(int a , int b){
    int gcd = GCD(a , b);
    return (a * b) / gcd;

}
int main(){
    int a = 28 , b = 20;

    a = GCD(a , b);

    cout << "GCD: " << a << endl;

    cout << "LCM: " << LCM(28 , 20) << endl;

    return 0;
}