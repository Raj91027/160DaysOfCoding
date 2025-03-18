/*
Printing all solutions in N-Queen Problem

Given an integer n, the task is to find all distinct solutions to the n-queens problem, where n queens are placed 
on an n * n chessboard such that no two queens can attack each other.

Note: Each solution is a unique configuration of n queens, represented as a permutation of [1,2,3,....,n]. 
The number at the ith position indicates the row of the queen in the ith column. 
For example, [3,1,4,2] shows one such layout.
*/


class Solution {
    private:
      void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
          vector<int> res;
          
          for(int i=0; i<n; i++){
              for(int j=0;j<n; j++){
                  if(board[i][j]==1){
                      res.push_back(j+1);
                  }
              }
          }
          ans.push_back(res);
      }
      
      bool isSafe(int row, int col, vector<vector<int>> &board, int n){
          
          int x = row;
          int y = col;
          
          while(y>=0){
              if(board[x][y]==1)
                  return false;
              y--;
          }
          
          x = row;
          y = col;
          
          while(x>=0 && y>=0){
              if(board[x][y]==1){
                  return false;
              }
              x--;
              y--;
          }
          
          x = row;
          y = col;
          
          while(x<n && y>=0){
              if(board[x][y]==1){
                  return false;
              }
              x++;
              y--;
          }
          
          return true;
      }
      
      
      void solve(int col,vector<vector<int>> &board, vector<vector<int>> &ans, int n){
          
          //base case
          if(col == n){
              addSolution(board, ans, n);
              return;
          }
          
          //solve one case
          for(int row=0; row<n; row++){
              if(isSafe(row, col, board, n)){
                  board[row][col]=1;
                  
                  solve(col+1, board, ans, n);
                  //backtrack
                  board[row][col] = 0;
              }
          }
      }
      
      
    public:
      vector<vector<int>> nQueen(int n) {
          vector<vector<int>> ans;
          
          vector<vector<int>> board(n, vector<int>(n,0));
          
          solve(0, board, ans, n);
          
          return ans;
          
      }
  };

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> result = sol.nQueen(n);
    
    for (const auto& solution : result) {
        for (int i : solution) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;

}
// Output:
// 1 3 0 2
// 2 0 3 1
// 2 1 3 0
// 0 2 3 1
// 1 2 0 3
// 3 0 2 1
// 0 1 3 2

// 3 1 0 2
// 1 2 0 3

