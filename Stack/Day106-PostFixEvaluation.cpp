/*
Evaluation of Postfix Expression

Given a postfix expression, the task is to evaluate the postfix expression. A Postfix expression is of the form "a b operator" ("a b +") i.e., a pair of operands is followed by an operator.

Examples:

Input: arr = ["2", "3", "1", "*", "+", "9", "-"]
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) - 9 = 5 - 9 = -4.

Input: arr = ["100", "200", "+", "2", "/", "5", "*", "7", "+"]
Output: 757
Explanation: If the expression is converted into an infix expression, it will be ((100 + 200) / 2) * 5 + 7 = 150 * 5 + 7 = 757.
*/

/*
Approach: Using Stack
To evaluate a postfix expression we can use a stack. Idea is to iterate the expression from left to right and keep on storing the operands into a stack. Once an operator is received, pop the two topmost elements and evaluate them and push the result in the stack again.

Follow the steps mentioned below to evaluate postfix expression using stack:

Create a stack to store operands (values).
Scan the given expression from left to right and do the following for every element in array.
If the element is a number, push it into the stack.
If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack.
When the expression is ended, the number in the stack is the final answer.
Illustration:

Consider the expression: arr = ["2", "3", "1", "*", "+", "9", "-"]
*/

// C++ program to evaluate value of a postfix
// expression Using Stack
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to evaluate a postfix expression given as a vector of strings
int evaluatePostfix(vector<string>& arr) {
    stack<int> st;

    // Loop through each element in the vector
    for (string token : arr) {
        
        // If it's an operand (number), push it onto
        // the stack
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push(stoi(token));
        } 
        
        // Otherwise, it must be an operator
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (token == "+") {
                st.push(val2 + val1);
            } else if (token == "-") {
                st.push(val2 - val1);
            } else if (token == "*") {
                st.push(val2 * val1);
            } else if (token == "/") {
                st.push(val2 / val1);
            }
        }
    }
    return st.top();
}

int main() {
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    cout << evaluatePostfix(arr) << endl; 
    return 0;
}

/*
Time Complexity: O(N), where N is the number of elements in the given array.
Space Complexity: O(N), where N is the number of elements in the given array.
*/
