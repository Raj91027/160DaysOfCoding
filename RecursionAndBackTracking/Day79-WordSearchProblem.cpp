
/*
Word Search - Check if a word exists in a grid or not

Given a 2-D grid of characters mat[][] and a string word, the task is to check if that word exist in the grid mat[][] or not. 
A word can be matched in 4 directions at any point. The 4 directions are horizontally left and right, vertically up and down. 

Examples: 

Input: mat[][] = [['T', 'E', 'E'],
['S', 'G', 'K'],
['T', 'E', 'L']]
word = "GEEK"
Output: true
Explanation: Word "GEEK" can be found in the given grid as follows
*/

/*
Using Backtracking
The idea is to use backtracking to find a word in a grid by exploring different paths.

We traverse through the entire grid, and whenever we find the first letter of the word, we start a recursive search from that cell.
From the current matching cell, we check all four possible directions (down, right, up, left) to continue matching the remaining letters of the word.
As we explore each direction, we temporarily replace the value with another value the current cell to mark it as visited to avoid using this cell twice within the same path. 
After exploring a path, we backtrack by placing the original value at the cell, allowing it to be reused in other paths.
When all characters of the word were successfully matched, return true.
Note: When we go out of bounds or hit an unmatched character, we backtrack to previous matched cell and try another direction.


*/

// C++ program to check if the word exists in the grid or not

#include <iostream>
#include <vector>
using namespace std;

// Function to check if a word exists in a grid
// starting from the first match in the grid
// wIdx: index till which pattern is matched
// x, y: current position in 2D array
bool findMatch(vector<vector<char>> &mat, string word, int x, int y, int wIdx) {
    int wLen = word.length();
	int n = mat.size();
  	int m = mat[0].size();
  
    // Pattern matched
    if (wIdx == wLen)
        return true;

    // Out of Boundary
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;

    // If grid matches with a letter while
    // recursion
    if (mat[x][y] == word[wIdx]) {

        // Marking this cell as visited
        char temp = mat[x][y];
        mat[x][y] = '#';

        // finding subpattern in 4 directions
        bool res = findMatch(mat, word, x - 1, y, wIdx + 1) ||
                   findMatch(mat, word, x + 1, y, wIdx + 1) ||
                   findMatch(mat, word, x, y - 1, wIdx + 1) ||
                   findMatch(mat, word, x, y + 1, wIdx + 1);

        // marking this cell as unvisited again
        mat[x][y] = temp;
        return res;
    }
  	
  	// Not matching then return false
    return false;
}

// Function to check if the word exists in the matrix or not
bool isWordExist(vector<vector<char>> &mat, string word) {
    int wLen = word.length();
	int n = mat.size();
  	int m = mat[0].size();
  
    // if total characters in matrix is
    // less than word length
    if (wLen > n * m)
        return false;

    // Traverse in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // If first letter matches, then recur and check
            if (mat[i][j] == word[0]){
                if (findMatch(mat, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> mat = { {'a', 'x', 'm', 'y'}, 
                                  {'b', 'g', 'd', 'f'}, 
                                  {'x', 'e', 'e', 't'}, 
                                  {'r', 'a', 'k', 's'} };
  	string word = "geeks";	
    cout << (isWordExist(mat, word) ? "true" : "false");

    return 0;
}


//Time Complexity: O(N * M * 4^L) where N is the number of rows, M is the number of columns and L is the length of the word.
//Space Complexity: O(L) where L is the length of the word. The recursion stack will take O(L) space in the worst case.
// The space complexity of the algorithm is O(1) if we do not consider the recursion stack.