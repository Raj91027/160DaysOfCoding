
/*
KMP Algorithm for Pattern Searching

Given two strings txt and pat, the task is to return all indices of occurrences of pat within txt.

Examples:

Input: txt = "abcab", pat = "ab"
Output: [0, 3]
Explanation: The string "ab" occurs twice in txt, first occurrence starts from index 0 and second from index 3.

Input: txt=  "aabaacaadaabaaba", pat =  "aaba"
Output: [0, 9, 12]
Explanation:
*/

/*
KMP Pattern Searching Algorithm
The Knuth-Morris-Pratt (KMP) algorithm is a string-searching algorithm which is used to 
find a pattern within large texts efficiently. Unlike naive pattern searching algorithm which 
starts from the beginning of the pattern after each mismatch, KMP uses the structure of 
the pattern to avoid redundant comparisons. It preprocesses the pattern string and 
creates an array called the Longest Prefix Suffix (lps) array which indicates how much of the pattern can be reused after a mismatch.

LPS Array
LPS is the Longest Proper Prefix which is also a Suffix. A proper prefix is a prefix that doesn't include whole string. 
For example, prefixes of "abc" are "", "a", "ab" and "abc" but proper prefixes are "", "a" and "ab" only. 
Suffixes of the string are "", "c", "bc", and "abc".
Each value, lps[i] is the length of longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].
Construction of LPS Array
lps[0] is always 0 since a string of length one has no non-empty proper prefix.
We store the value of the previous LPS in a variable len, initialized to 0. 
As we traverse the pattern, we compare the current character at index i, with the character at index len.

Case 1 - pat[i] = pat[len]: this means that we can simply extend the LPS at the previous index, 
so increment len by 1 and store its value at lps[i].

Case 2 - pat[i] != pat[len] and len = 0: it means that there were no matching characters earlier 
and the current characters are also not matching, so lps[i] = 0.

Case 3 - pat[i] != pat[len] and len > 0: it means that we can't extend the LPS at index i-1. 
However, there may be a smaller prefix that matches the suffix ending at i. To find this, 
we look for a smaller suffix of pat[i-len...i-1] that is also a proper prefix of pat. 
We then attempt to match pat[i] with the next character of this prefix. 
If there is a match, pat[i] = length of that matching prefix. Since lps[i-1] equals len, we know that pat[0...len-1] is the same as pat[i-len...i-1]. 
Thus, rather than searching through pat[i-len...i-1], 
we can use lps[len - 1] to update len, since that part of the pattern has already been matched.

*/

/*
Implementation of KMP Algorithm
We initialize two pointers, one for the text string and another for the pattern. 
When the characters at both pointers match, we increment both pointers and continue the comparison. 
If they do not match, we reset the pattern pointer to the last value from the LPS array, because that
 portion of the pattern has already been matched with the text string. Similarly, if we have traversed 
 the entire pattern string, we add the starting index of occurrence of pattern in text, to the result 
 and continue the search from the lps value of last element of the pattern.

Let’s say we are at position i in the text string and position j in the pattern string when a mismatch occurs:

At this point, we know that pat[0..j-1] has already matched with txt[i-j..i-1].
The value of lps[j-1] represents the length of the longest proper prefix of the substring pat[0..j-1] that is also a suffix of the same substring.
From these two observations, we can conclude that there's no need to recheck the characters in pat[0..lps[j-1]]. 
Instead, we can directly resume our search from lps[j-1].
*/


// C++ program to search the pattern in given text using
// KMP Algorithm

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void constructLps(string &pat, vector<int> &lps) {

    // len stores the length of longest prefix which
    // is also a suffix for the previous index
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {

        // If characters match, increment the size of lps
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else {
            if (len != 0) {

                // Update len to the previous lps value
                // to avoid reduntant comparisons
                len = lps[len - 1];
            }
            else {

                // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &txt) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    vector<int> res;

    constructLps(pat, lps);

    // Pointers i and j, for traversing
    // the text and pattern
    int i = 0;
    int j = 0;

    while (i < n) {

        // If characters match, move both pointers forward
        if (txt[i] == pat[j]) {
            i++;
            j++;

            // If the entire pattern is matched
            // store the start index in result
            if (j == m) {
                res.push_back(i - j);

                // Use LPS of previous index to
                // skip unnecessary comparisons
                j = lps[j - 1];
            }
        }

        // If there is a mismatch
        else {

            // Use lps value of previous index
            // to avoid redundant comparisons
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int main() {
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}