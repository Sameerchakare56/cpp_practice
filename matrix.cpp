#include <iostream>
using namespace std;

bool linearSearch(int matrix[4][3], int rows, int cols, int target) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

int getMaxSumRow(int matrix[4][3], int rows, int cols) {
    int maxSum = INT8_MIN;

    for(int i = 0; i < rows; i++){
        int sum = 0;
        for(int j = 0; j < cols; j++){
            sum += matrix[i][j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    int rows = 4;
    int cols = 3;
    matrix[2][1] = 100;
    cout << matrix[2][1] << endl; 

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }

    cout << linearSearch(matrix, rows, cols, 100) << endl;
    cout << getMaxSumRow(matrix, rows, cols) << endl;
    // int matrix2[2][2];
    // for(int i = 0; i < 2; i++) {
    //     for(int j = 0; j < 2; j++){
    //         cin >> matrix2[i][j];
    //     }
    // }

    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++){
    //         cout << matrix2[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
    
    

    return 0;
}