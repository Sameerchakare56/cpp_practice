#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(int matrix[4][4] , int n ) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
        if(i != n-i-1){
            sum += matrix[i][n-1-i];
        }
    }   
    
    return sum;
}

int main() {

    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = 4; 
    cout << "The sum of the diagonal elements is: " << diagonalSum(matrix , n) << endl;
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for(int i = 0; i < matrix2.size(); i++) {
        for(int j = 0; j < matrix2[i].size(); j++)
            cout << matrix2[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}