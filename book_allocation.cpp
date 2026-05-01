#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& books, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for(int i = 0; i < n; i++){
        if(pageSum + books[i] > mid){
            studentCount++;
            pageSum = books[i];
        } else {
            pageSum += books[i];
        }
    }
    return studentCount <= m;
}

int allocateBooks(vector<int>& books, int n, int m) {
    if(m > n) return -1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += books[i];
    }
    int st = 0, end = sum;
    int ans = -1;
    while (st < end){
        int mid = st + (end - st) / 2;
        if(isValid(books, n, m, mid)){
            ans = mid;
            end = mid-1;
        } else {
            st = mid + 1;
        }
    }
    return ans;

}

int main() {
    vector<int> books = {40,30,10,20};

    int n = 4 , m = 2;
    cout << allocateBooks(books, n, m) << "\n";
    return 0;
}