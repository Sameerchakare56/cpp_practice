#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isAlphaNum(char ch){
        if((ch >= '0' && ch <= '9') ||
           (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while(st < end){
            if(!isAlphaNum(s[st])){
                st++;
                continue;
            }
            if(!isAlphaNum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};

int main() {
    Solution obj;

    vector<string> testcases = {
        "madam",
        "A man, a plan, a canal: Panama",
        "hello",
        "12321",
        "race a car",
        "!!!@@@",
        "Noon",
        "",
        "Was it a car or a cat I saw",
        "1@2#2@1"
    };

    for(int i = 0; i < testcases.size(); i++){
        cout << "Test Case " << i+1 << ": " << testcases[i] << endl;

        if(obj.isPalindrome(testcases[i])){
            cout << "Result: Palindrome\n";
        } else {
            cout << "Result: Not Palindrome\n";
        }

        cout << "----------------------\n";
    }

    return 0;
}