/*
Valid Parentheses in an Expression

Given a string s representing an expression containing various types of brackets: {}, (), and [],
the task is to determine whether the brackets in the expression are balanced or not. 
A balanced expression is one where every opening bracket has a corresponding closing bracket in the correct order.

Example: 

Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.

Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.
*/

/*
[Expected Approach 1] Using Stack - O(n) Time and O(n) Space
The idea is to put all the opening brackets in the stack. Whenever you hit a closing bracket, 
search if the top of the stack is the opening bracket of the same nature. 
If this holds then pop the stack and continue the iteration. In the end if the stack is empty, 
it means all brackets are balanced or well-formed. Otherwise, they are not balanced.

Step-by-step approach:

Declare a character stack (say temp).
Now traverse the string s. 
If the current character is an opening bracket ( '(' or '{'  or '[' ) then push it to stack.
If the current character is a closing bracket ( ')' or '}' or ']' ) and the closing bracket matches 
with the opening bracket at the top of stack, then pop the opening bracket. Else s is not balanced.
After complete traversal, if some starting brackets are left in the stack then the expression is not balanced, else balanced.
*/

// C++ program to check if parentheses are balanced

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string& s) {
  
    // Declare a stack to store the opening brackets
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        
        // Check if the character is an opening bracket
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]); 
        } 
      
        else {

            // If it's a closing bracket, check if the stack is non-empty
            // and if the top of the stack is a matching opening bracket
            if (!st.empty() && 
                ((st.top() == '(' && s[i] == ')') ||
                 (st.top() == '{' && s[i] == '}') ||
                 (st.top() == '[' && s[i] == ']'))) {

                // Pop the matching opening bracket
                st.pop(); 
            }
            else {
                
                // Unmatched closing bracket
                return false; 
            }
        }
    }
    
    // If stack is empty, return true (balanced), otherwise false
    return st.empty();
}

int main() {  
    string s = "{([])}";
    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}


/*
[Expected Approach 2] Without using Stack - O(n) Time and O(1) Space
Instead of using actual Stack, we can uses the input string s itself to simulate stack behavior. 
We can use a top variable to keep track of the "top" of this virtual stack. 
This approach makes use of the existing string to avoid the need for additional memory to store stack elements.

Note: Strings are immutable in Java, Python, C#, and JavaScript. 
Therefore, we cannot modify them in place, making this approach unsuitable for these languages.

Step-by-Step approach:

Initialize top = -1 to represent an empty stack.
Traverse over the given string and for each character:
If top is -1 or the current character doesn’t match the top, increment top and store the character at s[top].
If the current character matches s[top], decrement top to remove the last unmatched opening parenthesis.
After processing, if top is -1, the string is balanced. Otherwise, it is unbalanced.
*/

// C++ program to check if parentheses are balanced
#include <bits/stdc++.h>
using namespace std;

// Check if characters match
bool checkMatch(char c1, char c2){
    if (c1 == '(' && c2 == ')') return true;
    if (c1 == '[' && c2 == ']') return true;
    if (c1 == '{' && c2 == '}') return true;
    return false;
}

// Check if parentheses are balanced
bool isBalanced(string& s){
  
    // Initialize top to -1
    int top = -1;
    for (int i = 0; i < s.length(); ++i){
      
        // Push char if stack is empty or no match
        if (top < 0 || !checkMatch(s[top], s[i])){
            ++top;
            s[top] = s[i];
        }
        else{
          
            // Pop from stack if match found
            --top;
        }
    }
  
    // Return true if stack is empty (balanced)
    return top == -1;
}

int main(){
    string s = "{([])}";
    cout << (isBalanced(s) ? "true" : "false") << endl;
    return 0;
}

