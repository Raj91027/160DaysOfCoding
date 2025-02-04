/*
Search in row wise sorted matrix

Given a row-wise sorted matrix mat[][] and an integer x, the task is to check if x is present in mat[][] or not. 
Note that there is no ordering among column elements.

Examples:

Input: x = 9, mat[][] = [[3, 4, 9],
[2, 5, 6],
[9, 25, 27]]
Output: true
Explanation: mat[0][2] is equal to 9.

Input: x = 56, mat[][] = [[19, 22, 27, 38, 55, 67]]
Output: false
Explanation: 56 is not present in mat[][].
*/


/*
[Naive Approach] Comparing with all elements – O(n*m) Time and O(1) Space
The simple idea is to traverse the complete matrix and search for the target element. 
If the target element is found, return true. Otherwise, return false. 
Please refer to Searching Algorithms for 2D Arrays (Matrix) to know more about the implementation.
/*

// C++ program to search an element in row-wise 
// sorted matrix

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
    vector<vector<int>> mat = {{3, 4, 9},
                               {2, 5, 6},
                               {9, 25, 27}};
    int x = 9;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}

//Time Complexity: O(N*M)
//Auxiliary Space: O(1)

/*
[Expected Approach] Using Binary Search - O(n * log(m)) Time and O(1) Space
The idea is simple, we traverse through the matrix and apply binary search on each row to find the element.
*/

// C++ program to search an element in row-wise
// sorted matrix 

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &arr, int x) {
    int lo = 0, hi = arr.size();
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
      
        // If x = mid, return true
        if(x == arr[mid]) 
            return true;
      
        // If x < arr[mid], search in left half
        if(x < arr[mid])
            hi = mid - 1;
       
        // If x > arr[mid], search in right half
        else
            lo = mid + 1;
    }
    return false;
}

bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
  
    // Iterate over all the rows to find x
    for(int i = 0; i < n; i++) {
      
        // binary search on ith row
        if(search(mat[i], x))
            return true;
    }
  
    // If x was not found, return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 4, 9},
                               {2, 5, 6},
                               {9, 25, 27}};
    int x = 9;
    if(searchRowMatrix(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}