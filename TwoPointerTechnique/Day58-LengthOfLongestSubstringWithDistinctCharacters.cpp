/*
Longest Substring Without Repeating Characters

Given a string s having lowercase characters, find the length of the longest substring without repeating characters. 

Examples:

Input: s = "geeksforgeeks"
Output: 7
Explanation: The longest substrings without repeating characters are "eksforg” and "ksforge", with lengths of 7.
*/

/*
[Naive Approach] Consider Substrings Starting From Every Index
The idea is to find length of longest substring with distinct characters starting from every index and maximum of all such lengths will be our answer.

To find the length of the longest substring with distinct characters starting from an index, we create a new visited array of size = MAX_CHAR = 26 to keep track of included characters in the substring. vis[0] checks for 'a', vis[1] checks for 'b', vis[2] checks for 'c' and so on.

Note the MAX_CHAR is alphabet size of input characters which is typically a constant. If we have only lower case characters, then MAX_CHAR is 26 only. If we consider all ASCII characters, then MAX_CHAR is 256.
*/

// C++ program to find the length of the longest 
// substring without repeating characters

#include <iostream>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

int longestUniqueSubstr(string& s) {
    int n = s.size();
    int res = 0;

    for (int i = 0; i < n; i++) {

        // Initializing all characters as not visited
        vector<bool> vis(MAX_CHAR, false);

        for (int j = i; j < n; j++) {

            // If current character is visited
            // Break the loop
            if (vis[s[j] - 'a'] == true)
                break;

            // Else update the result if this window is larger,
            // and mark current character as visited.
            else {
                res = max(res, j - i + 1);
                vis[s[j] - 'a'] = true;
            }
        }
    }
    return res;
}

int main() {
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}


/*
[Expected Approach 1] Using Sliding Window of Distinct Characters
The idea is to maintain a window of distinct characters. The window is initialized as single character. We keep extending the window on the right side till we see distinct characters. When we see a repeating character, we remove characters from the left side of the window. We keep track of the maximum length window.

Below are the detailed steps:

Initialize two pointers left and right with 0, which define the current window being considered.
The right pointer moves from left to right, extending the current window.
If the character at right pointer is not visited, it's marked as visited.
If the character at right pointer is visited, it means there is a repeating character. The left pointer moves to the right while marking visited characters as false until the repeating character is no longer part of the current window.
The length of the current window (right - left + 1) is calculated and answer is updated accordingly.

*/

// C++ code to find the largest substring with non-repeating
// characters using Sliding Window

#include <iostream>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

int longestUniqueSubstr(string& s) {
    if (s.length() == 0 || s.length() == 1)
        return s.length();

    int res = 0;
    vector<bool>vis(MAX_CHAR, false);

    // left and right pointer of sliding window
    int left = 0, right = 0;
    while (right < s.length()) {

        // If character is repeated, move left pointer marking
          // visited characters as false until the repeating 
          // character is no longer part of the current window
        while (vis[s[right] - 'a'] == true) {

                vis[s[left] - 'a'] = false;
                left++;
           }

        vis[s[right] - 'a'] = true;

        // The length of the current window (right - left + 1)
        // is calculated and answer is updated accordingly.
        res = max(res, (right - left + 1));
        right++;
    }
    return res;
}

int main() {
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}


/*
[Expected Approach 2] Using Last Index of Each Character
The approach stores the last indexes of already visited characters. The idea is to maintain a window of distinct characters. Start from the first character, and keep extending the window on the right side till we see distinct characters. When we see a repeating character, we check for the last index of the repeated character:

If last index of repeated character >= starting index of the current window, then we update the starting index of the current window to last index of repeated character + 1 to remove the repeated character.
If last index of repeated character < starting index of the current window, then it means that the repeated character is already outside the current window so the window size remains unchanged.
After iterating over all the characters, the largest window size will be our answer.
*/

// C++ code to find the largest substring with non-repeating
// characters using last index of repeated character

#include <iostream>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

int longestUniqueSubstr(string& s) {
    int n = s.size();
    int res = 0;

    // last index of all characters is initialized as -1
    vector<int> lastIndex(MAX_CHAR, -1);

    // Initialize start of current window
    int start = 0;

    // Move end of current window
    for (int end = 0; end < n; end++) {

        // Find the last index of s[end]
        // Update starting index of current window as
        // maximum of current value of end and last index + 1
        start = max(start, lastIndex[s[end] - 'a'] + 1);

        // Update result if we get a larger window
        res = max(res, end - start + 1);

        // Update last index of s[end]
        lastIndex[s[end] - 'a'] = end;
    }
    return res;
}

int main() {
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}