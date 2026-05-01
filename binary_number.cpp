#include <iostream>
using namespace std;

int dectoBinary(int decNum){
    int ans =0, pow = 1;
    while(decNum >0){
        int rem = decNum %2;
        decNum /=2;

        ans += (rem*pow);
        pow *=10;

    }
    return ans;
}


int dectoOctal(int decNum){
    int ans =0, pow = 1;
    while(decNum >0){
        int rem = decNum %8;
        decNum /=8;

        ans += (rem*pow);   
        pow *=10;

    }
    return ans;
}

string dectoHexa(int decNum){
    string ans ="";
    char hexDigits[]="0123456789ABCDEF";
    while(decNum >0){
        int rem = decNum %16;
        ans = hexDigits[rem] + ans;

        decNum /= 16;
    }
    return ans;
}

int binToDecimal(int binNum){
    int ans = 0 , pow =1 ;
    while (binNum >0){
        int rem = binNum %10;
        ans += rem *pow;

        binNum /= 10;
        pow *= 2;
    }
    return ans;
}
int main(){
    int decNum ;
    cout <<"enter a number you want to binary : ";
    cin >>decNum;

    cout << dectoBinary(decNum)<<"\n";
    cout << dectoOctal(decNum)<<"\n";
    cout << dectoHexa(decNum)<<"\n";
    cout << binToDecimal(decNum)<<"\n";


    return 0;

          
}