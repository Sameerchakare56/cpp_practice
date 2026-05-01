#include <iostream>
#include <vector>

using namespace std;

void changeValue(int* ptr) {
    *ptr = 20; // Change the value at the address pointed to by ptr
}

int main(){

    int a = 10;
    int* ptr = &a;

    int* ptrnull = NULL;

    int** parptr =&ptr;
    cout <<"ptr "<<ptr<<endl;
    cout <<"a "<<*(&a)<<endl;
    cout <<"ptr "<<&ptr<<endl;
    cout <<"parptr "<<**(parptr)<<endl;
    cout <<"ptrnull "<<ptrnull<<endl;

    int arr[] = {1,2,3,4,5};

    cout << *arr <<endl;
    cout << *(arr+1) <<endl;
    cout << *(arr+2)  <<endl;
    cout << *(arr+3)  <<endl;
    cout << *(arr+4)  <<endl;

    changeValue(ptr);
    cout <<"a "<<a<<endl;

}