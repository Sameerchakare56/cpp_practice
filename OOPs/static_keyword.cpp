#include <iostream>
#include <string>

using namespace std;

void fun() {
    static int  x = 10;
    cout << "Value of x: " << x << endl;
    x ++;
}

class A {
    public:
    int x;

    void incX() {
        x  = x+1;
    }
};

class ABC{
    public:
    ABC() {
        cout << "Constructor called" << endl;
    }
    ~ABC() {
        cout << "Destructor called" << endl;
    }
};
int main(){
    fun();
    fun();
    fun();

    A obj ; 
    A obj2 ; 
    obj.x = 0 ;
    obj2.x = 100; 
    cout << "Value of x: " << obj.x << endl;
    cout << "Value of x: " << obj2.x << endl;
    obj.incX();

    cout << "Value of x: " << obj.x << endl;
    cout << "Value of x: " << obj2.x << endl;

    if(true){
        ABC obj1;
    }
    cout << "End of main function" << endl;

    if(true){
        static ABC obj1;
    }

    cout << "End of main function" << endl;

    return 0;
}