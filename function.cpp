#include <iostream>
using namespace std;

void printHello(){
    cout<<"hello\n";
}
int sum(double a, double b){
    double s = a+b;
    return s;
}
int minoftwo(double a , double b){
     if(a<b){
        return a;
     }else{
        return b;
     }
}
int sumofn(int n){
    int sum = 0;
    for(int i =1;i<=n;i++){
        sum +=i;
    }
    return sum;
}

int factorial(int n){
    int sum = 1;
    for(int i =1;i<=n;i++){
        sum *=i;
    }
    return sum;
}

int sumofdigit(int num){
    int digsum = 0;
    while(num>0){
        int lastDig = num%10;  
        num /=10;
        digsum += lastDig;
    }
    return digsum;
}

int nCr(int n , int r){
    int fact_n = factorial(n);
    int fact_r = factorial(r);
    int fact_nmr = factorial(n-r);

    return fact_n/(fact_r*fact_nmr);
}

bool prime(int n){
    bool prime = true;
    for(int i=2;i <n;i++){
     if(n%i==0){
        prime = false;
     }
    }
    return prime ;
}

int print_all_prime(int n ){
    for(int i =2 ; i >=n; i++){
     prime(i);
    } ;
}

// ===============================
// Function to check prime number
// ===============================
bool isPrime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// ==================================
// Function to print primes till n
// ==================================
void printPrimes(int n) {
    cout << "Prime numbers up to " << n << " : ";
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            cout << i << " ";
    }
    cout << endl;
}

// ==================================
// Function to find nth Fibonacci
// ==================================
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main(){
    printHello();
    cout<<sum(10,5)<<"\n min "<<minoftwo(54,68);
    cout<<"\nEnter the value you want to sum ";
    int n ;
    cin >> n;
    cout<<"\nsum of n  : "<<sumofn(n);
    cout<<"\n factorial of n :"<<factorial(n);
    cout<<"\n sum of digit of n :"<<sumofdigit(n);

    int m = 7 , r =3;
    cout <<"\nncr : "<<nCr(m,r)<<endl;

    if(prime(m)!=true){
        cout<<"its not prime";

    }else{cout<<"it's  prime";
    };

    
    printPrimes(n);

    cout << "Nth Fibonacci number: " << fibonacci(n);


    return 0;
}