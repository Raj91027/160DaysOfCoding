
/*
Minimum Characters to Add at Front for Palindrome

Given a string s, the task is to find the minimum number of characters to be added to the 
front of s to make it palindrome. 
A palindrome string is a sequence of characters that reads the same forward and backward.

Examples: 

Input: s = "abc"
Output: 2
Explanation: We can make above string palindrome as "cbabc", by adding 'b' and 'c' at front.
*/



/*
The idea is based on the observation that we need to find the longest prefix from given string which is also a palindrome. 
Then minimum front characters to be added to make given string palindrome will be the remaining characters.
Start by checking if the entire string is a palindrome. If it is, then we don’t need to add any letters. 
If the entire string isn’t a palindrome, we then check the next longest prefix, which is the string without its last letter. 
We keep checking shorter prefixes until we find the longest one that is a palindrome. 
As soon as we find a prefix which is also a palindrome, we return the
*/
// C++ program for counting minimum character to be
// added at front to make string palindrome
#include <iostream>
using namespace std;

// Function to check if the substring s[i...j] is a palindrome
bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
      
        // If characters at the ends are not equal, it's not a palindrome
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minChar(string &s) {
    int cnt = 0;
    int i = s.size() - 1;
    
    // Iterate from the end of the string, checking for the longest 
    // palindrome starting from the beginning
    while (i >= 0 && !isPalindrome(s, 0, i)) {
        
        i--;
        cnt++;
    }
    
    return cnt;
}

int main() {
    string s = "AACECAAAA";
  
    cout << minChar(s);
    return 0;
}

/*
[Expected Approach] Using lps array of KMP Algorithm - O(n) Time and O(n) Space
The observation is that the longest palindromic prefix becomes longest palindromic suffix of its reverse.

For string = aacecaaaa
Reverse string = aaaacecaa
longest palindromic prefix = aacecaa

Now to find this prefix the idea is to use lps array of KMP algorithm, as each index of lps array represents the 
longest proper prefix which is also a suffix. 
First we concatenate the given string s with a special character '$' and with the reverse of given string s', 
then we will get lps array for this concatenated string( s + '$' + s').

We only need the last value of this lps[] array because it gives us the longest suffix of 
the reversed string that matches the prefix of the original string i.e., these many characters
already satisfy the palindrome property. Finally minimum number of characters needed to make the string a 
*/




int constructLps(string &s){
        vector<int>lps(s.length());
        int len = 0;
        
        lps[0] = 0;
        int i=1;
        
        while(i<s.length()){
            if(s[len] == s[i]){
                len++;
                lps[i]= len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] =0;
                    i++;
                }
            }
        }
        return lps.back();
}
int minChar(string& s) {
        int n = s.length();
        string temp = s;
        
        reverse(s.begin(), s.end());
        
        s = temp+'$'+s;
        
        int lps = constructLps(s);
        
        return n - lps;
}
int main() {
    string s = "AACECAAAA";
    cout << minChar(s);
    return 0;
}