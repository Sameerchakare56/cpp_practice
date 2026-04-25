#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    string dept;

    string subject;

    void changeDept(string newDept) {
        dept = newDept;
    }
};


class Teacher {
private:
    double salary;
public:
    string name;
    string dept ;
    string subject;

    void changeDept(string newDept) {
        dept = newDept;
    }
    void setSalary(double newSalary) {
        salary = newSalary;
    }
    double getSalary() {
        return salary;
    }
};


int main() {

    Teacher t1;
    t1.name = "John Doe";
    t1.dept = "Computer Science";
    t1.subject = "Data Structures";
    cout << "Teacher Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;
    
    t1.setSalary(50000);
    cout << "Salary set successfully." << endl;
    cout << t1.getSalary() << endl; // This will cause an error since getSalary() is not defined
    return 0;   

}