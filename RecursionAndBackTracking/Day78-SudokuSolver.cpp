/*
Algorithm to Solve Sudoku | Sudoku Solver

Given an incomplete Sudoku in the form of matrix mat[][] of order 9*9, the task is to complete the Sudoku.
A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-boxes of the grid.
Note: Zeros in the mat[][] indicate blanks, which are to be filled with some number between 1 to 9. You can not replace the element in the cell which is not blank.
*/

/*
[Naive Approach] Using Backtracking
The idea is to use backtracking and recursively generate all possible configurations of numbers from 1 to 9 to fill the empty cells of matrix mat[][]. To do so, for every unassigned cell, 
fill the cell with a number from 1 to 9 one by one. After filling the unassigned cell check if the matrix is safe or not. 
If safe, move to the next cell else backtrack for other cases.

To check if it is safe to place value num in the cell mat[i][j], iterate through all the columns of row i, 
rows of column j and the 3*3 matrix containing cell (i, j) and check if they already has value num, if so return false, else return true.
*/

class Solution {
    private:
      bool isSafe(int row, int col, vector<vector<int>> &board, int val){
          
          for(int i=0; i<board.size(); i++){
              if(board[row][i]==val)
                  return false;
                  
              if(board[i][col]==val)
                  return false;
              
              if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val)
                  return false;
          }
          return true;
      }
      
      bool solve(vector<vector<int>> &board){
          
          int n = board.size();
          
          for(int row=0; row<n; row++){
              
              for(int col=0; col<n; col++){
                  //empty cell
                  if(board[row][col]==0){
                      
                      for(int i=1; i<=9; i++){
                          //if safe
                          if(isSafe(row, col, board, i)){
                              
                              board[row][col] = i;
                          
                              bool isSolutionPossible = solve(board);
                              
                              if(isSolutionPossible){
                                  return true;
                              }
                              else{
                                  //backtrack
                                  board[row][col] = 0;
                              }
                          }
                          
                      }
                      return false;
                  }
              }
          }
          return true;
      }
    public:
      // Function to find a solved Sudoku.
      void solveSudoku(vector<vector<int>> &mat) {
          solve(mat);
      }
  };

// Complexity Analysis
/*
Time Complexity: O(9^(N*N)) where N is the number of cells in the matrix.
In the worst case, we will have to fill all the cells of the matrix.
Space Complexity: O(N*N) where N is the number of cells in the matrix.

The recursion stack will take O(N*N) space in the worst case.
*/
// Note: The above code is a naive approach and can be optimized further using bit manipulation or other techniques.
// The above code is a simple implementation of the backtracking algorithm to solve Sudoku. 
// It is not the most efficient solution, but it is easy to understand and implement.
// The time complexity can be improved by using bit manipulation to keep track of the used numbers in each row, column, and box.
// The space complexity can also be improved by using a single array to keep track of the used numbers instead of using a 2D array.
// The above code is a simple implementation of the backtracking algorithm to solve Sudoku.
