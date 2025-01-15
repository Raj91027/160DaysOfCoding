/*
Check if two Strings are Anagrams of each other

Given two strings s1 and s2 consisting of lowercase characters, the task is to check whether the two given strings are anagrams of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different.

Examples:

Input: s1 = “geeks”  s2 = “kseeg”
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.

Input: s1 = “allergy”  s2 = “allergic”
Output: false
Explanation: Characters in both the strings are not same. s1 has extra character 'y' and s2 has extra characters 'i' and 'c', so they are not anagrams.

Input: s1 = "g", s2 = "g"
Output: true
Explanation: Characters in both the strings are same, so they are anagrams.

*/

/*
[Naive Approach] Using Sorting
The idea is that if the strings are anagrams, then their characters will be the same, 
just rearranged. Therefore, if we sort the characters in both strings, 
the sorted strings will be identical if the original strings were anagrams. 
We can simply sort the two given strings and compare them – 
if they are equal, then the original strings are anagrams of each other.
*/

// C++ Code to check if two Strings are anagrams of 
// each other using sorting

#include <algorithm>
#include <iostream>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagrams(string &s1, string &s2) {
    
    // Sort both strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // Compare sorted strings
    return s1 == s2;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}

/*
[Expected Approach 1] Using Hash Map or Dictionary
The idea is to use a hash map or dictionary count the frequency of each character in both the input strings. 
If the frequency of every character matches in both strings, then the strings are anagrams.

First, count the occurrences of each character in first string.
Then, decrement the count for each character in the second string.
If the strings are anagrams, all positions in the frequency array should 
be zero as any non-zero position means that the frequency of that character is not same in both strings.
*/

// C++ Code to check if two Strings are anagram of 
// each other using Hash map

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areAnagrams(string &s1, string &s2) {
    
    // Create a hashmap to store character frequencies
    unordered_map<char, int> charCount;
    
    // Count frequency of each character in string s1
    for(char ch: s1) 
        charCount[ch] += 1;
  
    // Count frequency of each character in string s2
    for(char ch: s2) 
        charCount[ch] -= 1;
  
    // Check if all frequencies are zero
    for (auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    // If all conditions satisfied, they are anagrams
    return true;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}

/*
[Expected Approach 2] Using Frequency Array
Instead of using a hash map to store the frequency of each character, 
we can create a frequency array of size 26 by using characters as index in this array. 
The frequency of ‘a’ is going to be stored at index 0, ‘b’ at 1, and so on. 
To find the index of a character, 
we subtract character a’s ASCII value from the ASCII value of the character.

Count character frequency in the first string, then for each character in the second string, 
decrement its count from the frequency array. If the strings are anagrams, 
all positions in the frequency array will be zero. Any non-zero position means the frequency of that character is not equal in both the strings.
*/

// C++ Code to check if two Strings are anagram of 
// each other using Frequency Array

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// As the input strings can only have lowercase 
// characters, the maximum characters will be 26
const int MAX_CHAR = 26;

bool areAnagrams(string &s1, string &s2) {
    vector<int> freq(MAX_CHAR, 0);
    
    // Count frequency of each character in string s1
    for(char ch: s1) 
        freq[ch - 'a']++;
  
    // Count frequency of each character in string s2
    for(char ch: s2) 
        freq[ch - 'a']--;
  
    // Check if all frequencies are zero
    for (int count : freq) {
        if (count != 0) 
            return false;
    }
    
    return true;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}