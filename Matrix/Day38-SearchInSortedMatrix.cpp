/*
Search in a row wise and column wise sorted matrix

Given a matrix mat[][] and an integer x, the task is to check if x is present in mat[][] or not. 
Every row and column of the matrix is sorted in increasing order.

Examples: 

Input: x = 62, mat[][] = [[3, 30, 38],
[20, 52, 54],
[35, 60, 69]]
Output: false
Explanation: 62 is not present in the matrix.
*/

//Naive Approach
// C++ program to search an element in row-wise
// and column-wise sorted matrix 

#include <iostream>
#include <vector>

using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
  
    // Iterate over all the elements to find x
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == x)
                return true;
        }
    }
  
    // If x was not found, return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}

//Time Complexity: O(N*M)   
//Auxiliary Space: O(1)

/*
[Expected Approach] Eliminating rows or columns - O(n + m) Time and O(1) Space:
The idea is to remove a row or column in each comparison until an element is found. 
Start searching from the top-right corner of the matrix. There are 3 possible cases:

x is greater than the current element: This ensures that all the elements in the current 
row are smaller than the given number as the pointer is already at the right-most element and the row is sorted. 
Thus, the entire row gets eliminated and continues the search from the next row.
x is smaller than the current element: This ensures that all the elements in the current column are greater than the given number. 
Thus, the entire column gets eliminated and continues the search from the previous column, i.e. the column on the immediate left.
The given number is equal to the current number: This will end the search.
*/

// C++ program to search an element in row-wise 
// and column-wise sorted matrix

// C++ program to search an element in row-wise
// and column-wise sorted matrix 

#include <iostream>
#include <vector>

using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m - 1;
  
    while(i < n && j >= 0) {
      
        // If x > mat[i][j], then x will be greater
        // than all elements to the left of 
        // mat[i][j] in row i, so increment i
        if(x > mat[i][j]) {
            i++;
        }
      
        // If x < mat[i][j], then x will be smaller
        // than all elements to the bottom of
        // mat[i][j] in column j, so decrement j
        else if(x < mat[i][j]) {
            j--;
        }
      
        // If x = mat[i][j], return true
        else {
            return true;
        }
    }
  
    // If x was not found, return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}

//Time Complexity: O(N + M)
//Auxiliary Space: O(1)

