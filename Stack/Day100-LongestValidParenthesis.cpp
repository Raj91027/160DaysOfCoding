/*
Longest Valid Parentheses Substring

Given a string str consisting of opening and closing parenthesis '(' and ')', the task is to find the length of the longest valid parenthesis substring.

Examples: 

Input: str = "((()"
Output: 2
Explanation: Longest Valid Parentheses Substring is "()".

Input: str = ")()())"
Output: 4
Explanation: Longest Valid Parentheses Substring is "()()".
*/

/*
[Expected Approach - 1] Using Stack - O(n) Time and O(n) Space
The idea is to use a stack-based approach to track the indices of unmatched open parentheses. 
It determines the length of valid (well-formed) parentheses substrings by keeping track of the 
position of the last unmatched closing parenthesis or the starting position of a valid substring.

Follow the steps below to solve the problem:

For every opening parenthesis, we push its index onto the stack.
For every closing parenthesis, we pop the stack.
If the stack becomes empty after popping, it means we've encountered an unmatched closing parenthesis, 
so we push the current index to serve as a base for the next potential valid substring.
If the stack is not empty, we calculate the length of the valid substring by subtracting the index 
at the top of the stack from the current index.
A variable maxLength keeps track of the maximum length of valid parentheses encountered during the 
traversal.



*/

// C++ program to find length of the 
// longest valid substring

#include <iostream>
#include <stack>
using namespace std;

int maxLength(string s) {
    stack<int> st;

    // Push -1 as the initial index to 
      // handle the edge case
    st.push(-1);
    int maxLen = 0;

    // Traverse the string
    for (int i = 0; i < s.length(); i++) {
        
        // If we encounter an opening parenthesis,
          // push its index
        if (s[i] == '(') {
            st.push(i);
        } else {
            
            // If we encounter a closing parenthesis,
              // pop the stack
            st.pop();

            // If stack is empty, push the current index 
            // as a base for the next valid substring
            if (st.empty()) {
                st.push(i);
            } else {
                
                // Update maxLength with the current length 
                // of the valid parentheses substring
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}

int main() {
    string s = ")()())"; 
    cout << maxLength(s) << endl;

    return 0;
}


/*
[Expected Approach - 2] Using DP - O(n) Time and O(n) Space
The idea is to solve this problem using dynamic programming (DP) where dp[i] represents the length of the longest valid parentheses substring ending at index i. 
If a valid substring ends at i, we calculate and store the length of that substring in dp[i].

Follow the steps below to solve the problem:

If we encounter an opening parenthesis, we can't form a valid substring yet, so we move to the next character.
If we encounter a closing parenthesis, we check the previous character to determine if it forms a valid substring.
If the previous character is '(', we have a valid pair, so dp[i] = dp[i-2] + 2 (if i-2 is valid).
If the previous character is ')', check if the substring before it forms a valid substring. We use dp[i-1] to determine where the valid substring might start.
Also, store the maximum length of valid parentheses during the traversal.
*/

// C++ program to find length of the
// longest valid substring using DP
#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the
// longest valid parentheses substring
int maxLength(string s) {

    int n = s.length();
    vector<int> dp(n, 0);
    int maxLen = 0;

    // Traverse the string
    for (int i = 1; i < n; i++) {

        // If we encounter a closing parenthesis
        if (s[i] == ')') {

            // Check if the previous character is an
            // opening parenthesis '('
            if (s[i - 1] == '(') {
                if (i >= 2) {
                    dp[i] = dp[i - 2] + 2;
                }
                else {
                    dp[i] = 2;
                }
            }

            // Check if the previous character is a
            // closing parenthesis ')' and the matching opening
            // parenthesis exists before the valid substring
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                if (i - dp[i - 1] >= 2) {
                    dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                }
                else {
                    dp[i] = dp[i - 1] + 2;
                }
            }

            // Update the maximum length
            maxLen = max(maxLen, dp[i]);
        }
    }

    return maxLen;
}

int main() {
  
    string s = ")()())";
    cout << maxLength(s) << endl;

    return 0;
}



/*
[Expected Approach - 3] Using Two Traversals - O(n) Time and O(1) Space
The idea is to solve the problem using two traversals of the string, one from left to right and one from right to left, while keeping track of the number of open and close parentheses using two counters: open and close.

Why there is a Two Traversals?

Left to right traversal ensures that every valid substring that ends at the rightmost closing parenthesis is counted.
Right to left traversal ensures that every valid substring that starts from the leftmost opening parenthesis is counted.
Follow the steps below to solve the problem:

Left to Right Traversal:
Use two counters, say open to count the number of opening parentheses '(', and close to count the number of closing parentheses ')'.
For each character, if it's '(', increment open else increment close.
Whenever open == close, we have found a valid substring, and we calculate the length: 2 * close. Keep track of the maximum valid length.
If at any point close exceeds open, it means we have too many closing parentheses, and we reset both open and close to 0.
Right to Left Traversal:
Similarly, use open and close counters again.
For each character, if it's '(', increment open else increment close.
Again, whenever open == close, update the maximum valid length.
If open exceeds close, reset both counters to 0.
*/

// C++ program to find length of the
// longest valid substring

#include <iostream>
using namespace std;

int maxLength(string s) {
    int maxLen = 0;

    // Left to Right Traversal
    int open = 0, close = 0;
    for (char ch : s) {
        if (ch == '(') {
            open++;
        }
        else if (ch == ')') {
            close++;
        }

        if (open == close) {
            maxLen = max(maxLen, 2 * close);
        }
        else if (close > open) {
            open = close = 0;
        }
    }

    // Right to Left Traversal
    open = close = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            open++;
        }
        else if (s[i] == ')') {
            close++;
        }

        if (open == close) {
            maxLen = max(maxLen, 2 * open);
        }
        else if (open > close) {
            open = close = 0;
        }
    }

    return maxLen;
}

int main() {
    string s = ")()())";
    cout << maxLength(s) << endl;
    return 0;
}