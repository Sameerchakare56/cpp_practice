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

    return 0;   
}