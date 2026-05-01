#include <iostream>
using namespace std;

int main(){

    int age = 25 ;
    char grade = 'a';
    float PI = 3.14f;
    bool isused = true;
    double price = 100.99;
    cout <<"Age : "<< age <<"\nGrade :" << grade<< "\nPI :"<< PI <<endl;
    cout << "isused :" << isused << "\nprice : "<< price << endl;

    int value = grade;
    cout <<"value of a when we canvert to char to int : "<< value <<endl;

    double money = 150.95 ;
    int cash = (int)money;
    cout << "cash "<< cash;

    int clas;
    cout << "\nenter your class : ";
    cin >> clas;
    cout <<"class :"<< clas<<endl;
    return 0;
}