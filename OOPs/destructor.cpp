#include <iostream>
#include <string>

using namespace std;

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

    ~Student() {
        delete cgpaPtr; // Free the allocated memory
        cout << "Destructor called for " << name << endl;
    }

    void getInfo() {
        cout << "Student Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }

} ;

int main() {
    double cgpa1 = 3.8;
    Student s1("Alice", &cgpa1);

    s1.getInfo();

    return 0;
}