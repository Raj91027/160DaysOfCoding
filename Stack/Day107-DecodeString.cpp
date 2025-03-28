/*
Decode a string recursively encoded as count followed by substring

An encoded string s is given, the task is to decode it. See examples to understand the pattern in which string is encoded .

Examples:  

Input: s = "3[b2[ca]]"
Output: "bcacabcacabcaca"
Explanation: 1. inner substring "2[ca]" breakdown into "caca".
2. now , new string becomes "3[bcaca]"
3. similarly "3[bcaca]" becomes "bcacabcacabcaca " which is final result.

Input: s = "2[ab]"
Output: "abab"

Input: s = "2[ab]a"
Output: "ababa"
*/

/*
[Approach 1] Using Two Stacks - O(n) Time and O(n) Space
The idea is to use two stacks, one for integers and another for characters. 

Now, traverse the string,

Whenever we encounter any number, push it into the integer stack and in case of any alphabet (a to z) or open bracket ('['), push it on the character stack.
Whenever any close bracket (']') is encountered, pop the characters from the character stack until open bracket ('[') is found in the stack. 
Also, pop the top element from the integer stack, say n. Now make a string repeating the popped character n number of time. Now, push all character of the string in the stack.
After traversing whole string, integer stack will be empty and last string which will be formed will be the given result.
*/

// C++ program to decode a string recursively
// encoded as count followed substring
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to decode the pattern string 's'
string decodedString(string &s) {
    stack<int> numStack;
    stack<char> charStack;
    string temp = "";
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        int cnt = 0;
      
        // If Digit, convert it into number and 
      	// push it into integerstack.
        if (s[i] >= '0' && s[i] <= '9') {
            while (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + s[i] - '0';
                i++;
            }
            i--;
            numStack.push(cnt);
        }

        // If closing bracket ']' is encountered
        else if (s[i] == ']') {
            temp = "";

            cnt = numStack.top();
            numStack.pop();
			
          	// pop element till opening bracket '[' is not found in the
        	// character stack.
            while (charStack.top() != '[') {
                temp = charStack.top() + temp;
                charStack.pop();
            }
            charStack.pop();

            // Repeating the popped string 'temp' count number of times.
            for (int j = 0; j < cnt; j++)
                res = res.append(temp);

            // Push it in the character stack.
            for (int j = 0; j < res.length(); j++)
                charStack.push(res[j]);

            res = "";
        }
        else
            charStack.push(s[i]);
    }

    // Pop all the element, make a string and return.
    while (!charStack.empty()) {
        res = charStack.top() + res;
        charStack.pop();
    }

    return res;
}

int main() {
    string s = "3[b2[ca]]";
    cout << decodedString(s) << endl;
    return 0;
}

/*
[Approach 2] Using Single Stack - O(n) Time and O(n) Space
In this approach, we use a single stack to store both characters and digits. Instead of maintaining a separate integer stack for storing repetition counts, we store the digits directly in the main stack. The key observation is that the number always appears before the opening bracket '['. This allows us to retrieve it later without needing an extra stack.

Below are the detailed steps of implementation.

Initialize an empty stack.
Traverse the string:
Push characters onto the stack until ']' is encountered.
When ']' is found:
Pop characters to form the substring until '[' is found, then remove '['.
Extract the preceding number from the stack and convert it to an integer.
Repeat the substring and push the expanded result back onto the stack.
After traversal, pop all characters from the stack, reverse them, and return the final decoded string.
*/

// C++ program to decode a string recursively encoded
// as count followed substring Using Single Stack

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string decodeString(string &s) {
    stack<char> st;
    
    // Traverse the input string
    for (int i = 0; i < s.length(); i++) {
        // Push characters into the stack until ']' is encountered
        if (s[i] != ']') {
            st.push(s[i]);
        } 
        // Decode when ']' is found
        else {
            string temp;
            
            // Pop characters until '[' is found
            while (!st.empty() && st.top() != '[') {
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(), temp.end()); // Reverse extracted string
            // Remove '[' from the stack
            st.pop(); 

            string num;
            // Extract the number (repetition count) from the stack
            while (!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            
            // Convert extracted number to integer
            int number = stoi(num); 
            string repeat;
            
            // Repeat the extracted string 'number' times
            for (int j = 0; j < number; j++)
                repeat.append(temp);
            
            // Push the expanded string back onto the stack
            for (char c : repeat)
                st.push(c);
        }
    }

    string res;
    // Pop all characters from stack to form the final result
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    
    // Reverse to get the correct order
    reverse(res.begin(), res.end()); 
    return res;
}

int main() {
    string str = "3[b2[ca]]";
    cout << decodeString(str);
    return 0;
}

/*
[Alternate Approach] Without Using Stack - O(n) Time and O(n) Space
The given problem can be solved by traversing the encoded string character 
by character and maintaining a result string. Whenever a closing bracket is encountered, 
we can extract the substring enclosed within the corresponding opening bracket, 
and the number of times it needs to be repeated, and append the resulting string to the current result. 
We can continue this process until we reach the end of the input string.
*/

// C++ implementation to decode the string 
// without using stack

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Function to decode the given encoded string
string decodedString(string &s) {

    // Declare a string variable to store the decoded
    // string
    string res = "";

    // Traverse the encoded string character by character.
    for (int i = 0; i < s.length(); i++) {

        // If the current character is not a clostring
        // bracket, append it to the result string.
        if (s[i] != ']') {
            res.push_back(s[i]);
        }

        // If the current character is a closing bracket
        else {
          
            // Create a temporary string to store the
            // substring within the corresponding opening
            // bracket.
            string temp = "";
            while (!res.empty() && res.back() != '[') {
                temp.push_back(res.back());
                res.pop_back();
            }

            // Reverse the temporary string to obtain the
            // correct substring.
            reverse(temp.begin(), temp.end());

            // Remove the opening bracket from the result
            // string.
            res.pop_back();

            // Extract the preceding number and convert it
            // to an integer.
            string num = "";
            while (!res.empty() && res.back() >= '0' && res.back() <= '9') {
                num.push_back(res.back());
                res.pop_back();
            }
            reverse(num.begin(), num.end());
            int p = stoi(num);

            // Append the substring to the result string,
            // repeat it to the required number of times.
            while (p--) {
                res.append(temp);
            }
        }
    }

    // Return the decoded string.
    return res;
}

int main() {
    string s = "3[b2[ca]]";
    cout << decodedString(s);
    return 0;
}