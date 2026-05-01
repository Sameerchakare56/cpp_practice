#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(){
    char str[] = {'a', 'b', 'c', 'd', '\0'};

    cout << str << endl;
    cout << strlen(str) << endl;

    char str2[] = "sameer";
    cout << str2[2]<< endl;

 

    char str4[100];
    cout << "Enter a string with spaces: ";
    cin.getline(str4, 100);
    cout << "You entered: " << str4 << endl;
    
    string str5= "sameer";
    str5 = "hello"; 
    cout << str5<< endl;

    string str6 = "sameer";
    cout << str6 << endl;

    cout << (str5 == str6 ) << endl;
    cout << (str5 != str6 ) << endl;
    cout << (str5 <= str6 ) << endl;
    cout << (str5 >= str6 ) << endl;
    cout << (str5 < str6 )  << endl;

    string str7;
    getline(cin, str7);
    cout << str7 << endl;
    char str8[]  = "hello world";
    int st = 0 , end = strlen(str8)- 1;
    while(st < end){
        swap(str8[st], str8[end]);
        st ++;
        end--;
    }
    cout << str8 << endl;

    string str9 = "hello world";
    reverse(str9.begin() , str9.end());
    cout << str9 << endl;
    return 0;


}