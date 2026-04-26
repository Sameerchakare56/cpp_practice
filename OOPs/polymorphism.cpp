#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
    string name;

    Student(){
        cout << "No- parameterized\n" << endl;

    }
    Student(string name) {
        this->name = name;
        cout << "Parameterized constructor\n" << endl;
    }

    

    void getInfo() {
        cout << "Name: " << name << endl;
    }
};

class print{
    public:
    void show(int x){
        cout << "Integer: " << x << endl;
    }
    void show(char c){
        cout << "Character: " << c << endl;
    }
};

class Parent{
    public:
    void getInfo() {
        cout << "This is the parent class" << endl;
    }

    virtual void Hello() {
        cout << "Hello from parent class" << endl;
    }

};

class Child : public Parent {
    public:
    void getInfo() {
        cout << "This is the child class" << endl;
    }

    void Hello() {
        cout << "Hello from child class" << endl;
    }
};



int main() {
    Student s1;
    print p1;
    p1.show('c');

    Child c1;
    c1.getInfo();

    Parent c2;
    c2.getInfo();

    c1.Hello();

    return 0;

}