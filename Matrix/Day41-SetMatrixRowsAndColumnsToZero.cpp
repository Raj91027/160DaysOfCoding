/*
Set Matrix Rows and Columns to Zeroes

Given a matrix mat[][] of size nxm, the task is to update the matrix such that if an element is zero, 
set its entire row and column to zeroes.

Examples:

Input: mat[][] = [[1, -1, 1],
[-1, 0, 1],
[1, -1, 1]]
Output: [[1, 0, 1],
[0, 0, 0],
[1, 0, 1]]
Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.
*/

/*
[Naive Approach] Using Two Auxiliary Arrays - O(n*m) Time and O(n+m) Space
The idea is to maintain two additional arrays, say rows[] and cols[] to store 
the rows and columns which contains at least one element equal to 0. 
So, first traverse the entire matrix and for each mat[i][j] = 0, mark rows[i] = true and cols[j] = true. 
Now in the second traversal, for each cell (i, j), if either rows[i] or cols[j] is marked as true, 
update mat[i][j] = 0 else continue to the next cell.
*/

// C++ code to implement Set Matrix Zeroes using
// two auxiliary arrays 

#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    // To store which rows and columns are
    // supposed to mark with zeroes
    vector<bool> rows(n, false), cols(m, false);

    // Traverse the matrix to fill rows[] and cols[]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // If the cell contains zero then mark
            // its row and column as zero
            if (mat[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // Mark cell (i, j) with zero if either
            // of rows[i] or cols[j] is true
            if (rows[i] || cols[j])
                mat[i][j] = 0;
        }
    }
}

int main() {
    vector<vector<int> > mat = { { 0, 1, 2, 0 },
                                 { 3, 4, 0, 2 },
                                 { 1, 3, 1, 5 } };

    setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
[Expected Approach] Using First Row and Column - O(n*m) Time and O(1) Space
In the previous approach we took two arrays to store the row's and column's status. 
Now instead of two auxiliary arrays, we can use the first row and first column of mat[][] to 
store which row elements and column elements are to be marked as zeroes.

So if the first cell of a row is set to 0, then all cells of that row should be updated with 0. 
Similarly, if the first cell of a column is set to 0, then all cells of that column should be updated to 0. 

Since cell (0, 0) is first cell of the first row as well as the first column, so maintain another variable, 
say c0 to store the status of the first column and cell(0, 0) will store the status of the first row.
*/

// C++ code to implement Set Matrix Zeroes using
// first row and column

#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    int c0 = 1;

    // Traverse the arr and mark first cell of
    // each row and column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {

                // mark i-th row
                mat[i][0] = 0;

                // mark j-th column
                if (j == 0)
                    c0 = 0;
                else
                    mat[0][j] = 0;
            }
        }
    }

    // Traverse and mark the matrix from (1, 1)
    // to (n - 1, m - 1)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            // Check for col & row
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // Mark the first row
    if (mat[0][0] == 0) {
        for (int j = 0; j < m; j++)
            mat[0][j] = 0;
    }
  
    // Mark the first column
    if (c0 == 0) {
        for (int i = 0; i < n; i++)
            mat[i][0] = 0;
    }
}

int main() {
    vector<vector<int> > mat = { { 0, 1, 2, 0 },
                                 { 3, 4, 0, 2 },
                                 { 1, 3, 1, 5 } };

    setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(n*m)
// Space Complexity: O(1)
