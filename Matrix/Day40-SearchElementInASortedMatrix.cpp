/*
Search element in a sorted matrix

Given a sorted matrix mat[][] of size nxm and an element x, the task is to find if x is present in the matrix or not.
Matrix is sorted in a way such that all elements in a row are sorted in increasing order and for row i, where 1 <= i <= n-1, 
the first element of row i is greater than or equal to the last element of row i-1.

Examples:

Input: x = 14, mat[][] = [[ 1, 5, 9],
[14, 20, 21],
[30, 34, 43]]
Output: true

Input: x = 42, mat[][] = [[ 1, 5, 9, 11],
[14, 20, 21, 26],
[30, 34, 43, 50]]
Output: false
*/
/*
[Naive Approach] Comparing with all elements – O(n*m) Time and O(1) Space
In this approach, we will iterate through the entire matrix mat[][] and compare each element with x. 
If an element matches the x, we will return true. Otherwise, at the end of the traversal, we will return false. 
Please refer to Searching Algorithms for 2D Arrays (Matrix) to know more about the implementation.
*/

// C++ program to search an element in row-wise
// and column-wise sorted matrix

#include <iostream>

using namespace std;

bool searchElement(int mat[4][4], int n, int m, int x) {
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
    int mat[4][4] = {{1, 5, 9, 11},
                     {14, 20, 21, 26},
                     {30, 34, 43, 50}};
    int x = 14;
    if(searchElement(mat, 3, 4, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}

// Time Complexity: O(n*m)
// Space Complexity: O(1)

/*
[Better Approach] Using Binary Search Twice - O(logn + logm) Time and O(1) Space
First, we locate the row where the target x might be by using binary search, and then we apply binary search again within that row.

To find the correct row, we perform binary search on the first elements of the middle row.
Start with low = 0 and high = n - 1.

If x is smaller than the first element of the middle row (a[mid][0]), then x will be smaller than all elements in rows >= mid, so update high = mid - 1.
If x is greater than the first element of the middle row (a[mid][0]), then x will be greater than all elements in rows < mid, 
so store the current mid row and update low = mid + 1.
Once we have found the correct row, we can apply binary search within that row to search for the target element x.
*/

// C++ program to search in the sorted matrix using
// Binary Search two times

#include <iostream>
#include <vector>
using namespace std;

// Function to binary search for x in arr[]
bool search(vector<int> &arr, int x) {
    int lo = 0, hi = arr.size() - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (x == arr[mid])
            return true;
        if (x < arr[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int lo = 0, hi = n - 1;
    int row = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        // If the first element of mid row is equal to x,
        // return true
        if (x == mat[mid][0])
            return true;
      
        // If x is greater than first element of mid row,
        // store the mid row and search in lower half
        if (x > mat[mid][0]) {
            row = mid;
            lo = mid + 1;
        }
      
        // If x is smaller than first element of mid row,
        // search in upper half
        else
            hi = mid - 1;
    }
   
    // If x is smaller than all elements of mat[][]
    if (row == -1)
        return false;

    return search(mat[row], x);
}

int main() {
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Time Complexity: O(logn + logm)
// Space Complexity: O(1)

/*
[Expected Approach] Using Binary Search Once - O(log(n*m)) and O(1) Space
The idea is to consider the given matrix as 1D array and apply only one binary search. 
For example, for a matrix of size n x m and we can consider it as a 1D array of size n*m, 
then the first index would be 0 and last index would n*m-1. 
So, we need to do binary search from low = 0 to high = (n*m-1).

How to find the element in 2D matrix corresponding to index = mid?

Since each row of mat[][] will have m elements, so we can find the row of the element as (mid / m) 
and the column of the element as (mid % m). Then, we can compare x with arr[mid/m][mid%m] for each mid and 
complete our binary search.
*/

// C++ program to search in the sorted matrix using
// binary search

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size(), m = mat[0].size();

    int lo = 0, hi = n * m - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
      
        // Find row and column of element at mid index
        int row = mid / m;
        int col = mid % m;
      
        // If x is found, return true
        if (mat[row][col] == x) 
            return true;
      
        // If x is greater than mat[row][col], search in
        // right half
        if (mat[row][col] < x) 
            lo = mid + 1;
        
        // If x is less than mat[row][col], search in 
        // left half
        else 
            hi = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Time Complexity: O(log(n*m))
// Space Complexity: O(1)
