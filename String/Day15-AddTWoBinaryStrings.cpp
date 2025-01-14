/*
Add two binary strings

Given two binary strings s1 and s2, the task is to return their sum.
The input strings may contain leading zeros but the output string should not have any leading zeros.

Example: 

Input: s1 = "1101", s2 = "111"
Output: "10100"
Explanation:


Bit-by-bit addition with carry - O(n + m) Time and O(1) Space
The idea is to first trim the leading zeros in the input strings. 
Now, start from the last characters of the strings and compute the digit sum one by one. 
If the sum becomes more than 1, then store carry for the next digits. 
Also consider this carry while calculating the digit sum. After calculating the sum, 
if an additional carry is generated, prepend a '1' of the result.
*/

// C++ program to add two binary strings
// using Bit-by-Bit addition
#include <iostream>
using namespace std;

// Function to trim leading zeros from a binary string
string trimLeadingZeros(const string &s) {
    
    // Find the position of the first '1'
    size_t firstOne = s.find('1');
    return (firstOne == string::npos) ? "0" : s.substr(firstOne);
}

// This function adds two binary strings and return
// result as a third string
string addBinary(string &s1, string &s2) {
  
    // Trim leading zeros
    s1 = trimLeadingZeros(s1);
    s2 = trimLeadingZeros(s2);
  
    int n = s1.size();  
    int m = s2.size(); 
    
    // swap the strings if s1 is of smaller length
    if (n < m) {
        return addBinary(s2, s1);
    }
    
    int j = m - 1;  
    int carry = 0; 
    
    // Traverse both strings from the end
    for (int i = n - 1; i >= 0; i--) {
      
          // Current bit of s1
        int bit1 = s1[i] - '0';  
        int sum = bit1 + carry;
        
        // If there are remaining bits in s2, add them to the sum
        if (j >= 0) {
              
              // Current bit of s2
            int bit2 = s2[j] - '0';  
            sum += bit2;
            j--;
        }
        
        // Calculate the result bit and update carry
        int bit = sum % 2;
        carry = sum / 2;
        
        // Update the current bit in s1
        s1[i] = (char)(bit + '0');
    }
    
    // If there's any carry left, update s1
    if (carry > 0) {
        s1 = '1' + s1;
    }
    
    return s1;
}

int main() {
  
    string s1 = "1101", s2 = "111";
    cout << addBinary(s1, s2) << endl;
    return 0;
}