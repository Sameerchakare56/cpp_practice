#include <iostream>
#include <string>

using namespace std;

class Teacher {
    public:
    Teacher() {
        cout << "Constructor called!" << endl;
    }


    string name;
    string dept ;
    string subject;
    Teacher(string name, string d, string s) {
        this ->name = name;
        dept = d;
        subject = s;
    }

    // Copy constructor
    Teacher(const Teacher &obj) {
        this ->name = obj.name;
        dept = obj.dept;
        // subject = obj.subject;
    }

    void changeDept(string newDept) {
        dept = newDept;
    }
    void getInfo() {
        cout << "Teacher Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
    }
};

class Student {
    public:
    string name ; 
    double* cgpaPtr;
    Student(string n, double* c) {
        name = n;
        cgpaPtr = c;
    }
    // Copy constructor
    Student(const Student &obj) {
        name = obj.name;
        cgpaPtr = new double; // Allocate new memory for the CGPA
        *cgpaPtr = *(obj.cgpaPtr); // Copy the value of CGPA
    }

    void getInfo() {
        cout << "Student Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }

} ;
int main() {
    Teacher t1("John Doe", "Computer Science", "Data Structures");
    cout << "Teacher Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;
    Teacher t2;
    Teacher t3;
    t1.getInfo();
    t2.getInfo();
    t3.getInfo();
    Teacher t4(t1);
    t4.getInfo();
    
    Student s1("Alice", new double(3.8));
    s1.getInfo();
    Student s2(s1); 
    s2.getInfo();
    *(s2.cgpaPtr) = 9.0; 
    s1.getInfo();
    s2.name = "Bob";
    s2.getInfo();

    return 0;   
}