/*
Rotate Square Matrix by 90 Degrees Counterclockwise

Given a n*n square matrix mat[][], rotate it by 90 degrees in counterclockwise direction without using any extra space.

Examples: 

Input: mat[][] = [[1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]]
Output: [[3, 6, 9], 
                [2, 5, 8], 
                [1, 4, 7]]
*/

// C++ program to rotate a matrix in anticlockwise
// direction using exrta space

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));
  
    // Rotate the matrix 90 degrees counterclockwise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[n - j - 1][i] = mat[i][j];
        }
    }

    // Copy the rotated matrix back to the original matrix
    mat = res;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(mat);

    // Print the rotated matrix
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}


// C++ program to rotate a matrix in anticlockwise
// direction by forming cycles

#include <iostream>
#include <vector>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat){
      int n = mat.size();
  
    // Consider all cycles one by one
    for (int i = 0; i < n / 2; i++) {
      
        // Consider elements in group of 4 
        // as P1, P2, P3 & P4 in current square
        for (int j = i; j < n - i - 1; j++) {
              
            int temp = mat[i][j];
            mat[i][j] = mat[j][n - 1 - i];
            mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
            mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
            mat[n - 1 - j][i] = temp;
        }
    }
}
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotateMatrix(mat);
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}



// C++ program to rotate a matrix by 90 degrees anti-
// clockwise by reversing Rows and then Transposing

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat){ 
      int n = mat.size();
      
      // Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());

    // Performing Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotateMatrix(mat);
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}

// Output:

// 4 8 12 16    
// 3 7 11 15
// 2 6 10 14
// 1 5 9 13
