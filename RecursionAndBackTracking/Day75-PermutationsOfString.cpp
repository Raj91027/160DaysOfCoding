/*
Print all Unique permutations of a given string.

Given a string that may contain duplicates, the task is find all unique permutations of given string in any order.

Examples: 

Input: "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations as "ABC", "ACB", "BAC", "BCA", "CAB" and "CBA".

Input: "AAA"
Output: ["AAA"]
Explanation: No other unique permutations can be formed as all the characters are same.
*/

class Solution {
    private:
      void solve(string &s, vector<string> &ans, unordered_set<string> &uniqueSet, int index ){
          //base case
          if(index >= s.size()){
              //handle duplicate string
              if(uniqueSet.find(s)==uniqueSet.end()){
                  ans.push_back(s);
                  uniqueSet.insert(s);
              }
              return;
          }
          
          for(int j=index; j<s.size();j++){
              swap(s[index], s[j]);
              solve(s,ans,uniqueSet,index+1);
              
              //backtrack
              swap(s[index], s[j]);
          }
      }      
    public:
      vector<string> findPermutation(string &s) {
          //stores ans
          vector<string> ans;
          //stores uniqueStrings
          unordered_set<string>uniqueSet;
          
          int index = 0;
          
          solve(s, ans,uniqueSet, index);
          
          return ans;
      }
  };

//main function, driver code
int main(){
    Solution obj;
    string s = "ABC";
    vector<string> ans = obj.findPermutation(s);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}

// Time Complexity: O(n*n!)
// Space Complexity: O(n*n!) where n is the length of the string.

// Input: "ABC"
// Output: ABC ACB BAC BCA CBA CAB
// Explanation: Given string ABC has 6 unique permutations as "ABC", "ACB", "BAC", "BCA", "CAB" and "CBA.
