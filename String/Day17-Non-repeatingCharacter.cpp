/*
Find first non-repeating character of given string

Given a string s of lowercase English letters, 
the task is to find the first non-repeating character. 
If there is no such character, return '$'.

Examples: 

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: 'f' is the first character in the string which does not repeat.
*/

/*
[Naive Approach] Using Two Nested Loops
The idea is to use two nested loops, the outer loop for picking 
an element and the inner loop for finding another occurrence of the 
picked character in the string. As soon as we find a character which
 has only one occurrence in the input string, return it. 
If all characters have multiple occurrences, return '$'.
*/

// C++ program to find the index of the first
// non repeating character using nested loop

#include <iostream>
using namespace std;

// Function to find the index of the first 
// non-repeating character
char nonRepeatingChar(string &s) {
    int n = s.length();

    // Iterate over each character in the string
    for (int i = 0; i < n; ++i) {
        bool found = false;

        // Check if the character repeats in the
        // rest of the string
        for (int j = 0; j < n; ++j) {
            if (i != j && s[i] == s[j]) {
                found = true;
                break;
            }
        }

        // If character does not repeat, return it
        if (found == false) 
            return s[i];
    }

    // If no such character is found, return '$'
    return '$';
}

int main() {
    string s = "racecar";
  
    cout << nonRepeatingChar(s);
    return 0;
}

/*
Time Complexity: O(n^2), where n is the length of input string s.
Auxiliary Space: O(1)
*/

/*
[Efficient Approach 1] Using Frequency Array (Two Traversal)
The efficient approach is to either use an array of size 26 to store the frequencies of each character. Traverse the input string twice:

First traversal is to count the frequency of each character.
Second traversal to find the first character in string with a frequency of one.
*/

// C++ program to find the index of the first
// non repeating character using frequency array

#include <iostream>
#include <vector>
using namespace std;

// As the input string can only have lowercase 
// characters, the maximum characters will be 26
const int MAX_CHAR = 26;

char nonRepeatingChar(string &s) {
  
    vector<int> freq(MAX_CHAR, 0);

    // Count the frequency of all characters
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < s.length(); ++i) {
        if (freq[s[i] - 'a'] == 1)
            return s[i];
    }
    
      // If no character with a frequency of 1 is 
      // found, then return '$'
    return '$';
}

int main() {
    string s = "racecar";
  
    cout << nonRepeatingChar(s);
    return 0;
}

/*
[Efficient Approach 2] By Storing Indices (Single Traversal)
The above approach can be optimized using a single traversal of the string. 
The idea is to maintain a visited array of size 26 initialized to -1, 
indicating no characters have been seen yet. Now, we iterate through the string:

If a character is seen for the first time, its index is stored in the array.
If the character is found again then its array value is set to -2 to represent 
this character is now repeating.
After the string traversal, traverse the visited array and check if value in the array is not equal 
to -1 or -2 (means, this character is not repeating). We then find the smallest positive index from
 these values to find the first non-repeating character. 
If no such index is found, return '$'.
*/

// C++ program to find the index of the first non repeating
// character by storing indices

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// As the input string can only have lowercase 
// characters, the maximum characters will be 26
const int MAX_CHAR = 26;

char nonRepeatingChar(string s) {
    vector<int> vis(MAX_CHAR, -1);

    // Iterate through the string
    for (int i = 0; i < s.length(); i++) {

        // If the character is seen for the first time,
        // store its index
        if (vis[s[i] - 'a'] == -1)
            vis[s[i] - 'a'] = i;

        // If the character is seen again, mark it as -2
        else
            vis[s[i] - 'a'] = -2;
    }

    int idx = INT_MAX;
    
    // Find the smallest index among all non-repeating 
    // characters
    for (int i = 0; i < MAX_CHAR; i++) {
        if (vis[i] >= 0)
            idx = min(idx, vis[i]);
    }
  
    // If non-repeating character is found, return it 
    // Else return '$'
    return (idx == INT_MAX ? '$' : s[idx]);
}

int main() {
    string s = "racecar";
    cout << nonRepeatingChar(s) << endl;
    return 0;
}