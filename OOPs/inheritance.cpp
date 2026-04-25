#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }
    Person(){
        cout << "Parent class constructor" << endl;
    }
    ~Person() {
        cout << "Parent class destructor" << endl;
    }
    

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
    public:
    int rollNumber;

    Student() {
        cout << "Child class constructor" << endl;
    }
    Student(string name , int age , int rollNumber) : Person(name, age) {
        this ->rollNumber = rollNumber;
    }
    ~Student(){
        cout << "Child class destructor" << endl;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNumber << endl;
    
    }
} ;
int main() {

    Student s1("John", 20, 101);
   
    s1.getInfo();
    

    return 0;
} 