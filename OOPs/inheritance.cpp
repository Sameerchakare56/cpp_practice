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

class GradStudent : public Student {
    public:
    string thesisTopic;

    GradStudent(string name, int age, int rollNumber, string thesisTopic) : Student(name, age, rollNumber) {
        this->thesisTopic = thesisTopic;
    }

    void getInfo() {
        Student::getInfo();
        cout << "Thesis Topic: " << thesisTopic << endl;
    }
};

class Teacher  {
    public:
    string subject;
    double salary;
};

class TA : public Student , public Teacher {
    public:
    string ResearchArea;

};
int main() {

    GradStudent s1("John", 20, 101 , "AI");
   
    s1.getInfo();

    TA t1;
    t1.name = "Alice";
    t1.subject = "Mathematics";

    cout << "TA Name: " << t1.name << endl;
    cout << "TA Subject: " << t1.subject << endl;
    

    return 0;
} 