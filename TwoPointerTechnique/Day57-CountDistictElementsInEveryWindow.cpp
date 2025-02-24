/*
Count Distinct Elements In Every Window of Size K

Given an array arr[] of size n and an integer k, return the count of distinct numbers in all windows of size k. 

Examples: 

Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
Output: [3, 4, 4, 3]
Explanation: First window is [1, 2, 1, 3], count of distinct numbers is 3.
                      Second window is [2, 1, 3, 4] count of distinct numbers is 4.
                      Third window is [1, 3, 4, 2] count of distinct numbers is 4.
                      Fourth window is [3, 4, 2, 3] count of distinct numbers is 3.
*/




/*
[Naive Approach] Traversing all windows of size k - O(n * k) Time and O(1) Space
Traverse the given array considering every window of size k in it and keeping a count on the distinct elements of the window.
*/
// C++ program to count distinct elements in every window
// of size k by traversing all windows of size k

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();  
    vector<int> res;
  
    // Iterate over every window
    for (int i = 0; i <= n - k; i++) {
      
        // Hash Set to count unique elements
        unordered_set<int> st;
        for(int j = i; j < i + k; j++)
            st.insert(arr[j]);
      
        // Size of set denotes the number of unique elements
        // in the window
        res.push_back(st.size());
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> res = countDistinct(arr, k);
    for(int ele: res)
        cout << ele << " ";
    return 0;
}


/*
[Expected Approach] Sliding Window Technique - O(n) Time and O(k) Space
The idea is to use Sliding Window Technique and count the number of distinct element in the current window using the count of previous window. Maintain a hash map or dictionary to store the frequency of elements of the current window and the count of distinct elements in the window will be equal to the size of the hash map.

Store the frequency of first k elements in the hash map. Now start iterating from index = k,

increase the frequency of arr[k] in the hash map.
decrease the frequency of arr[i - k] in the hash map. If frequency of arr[i - k] becomes 0, remove arr[i] from the hash map.
insert size of hash map into the resultant array.
*/
// C++ program to count distinct elements in every window
// of size k by traversing all windows of size k

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();  
    vector<int> res;
    unordered_map<int, int> freq;
  
    // Store the frequency of elements of first window
    for(int i = 0; i < k; i++)
        freq[arr[i]] += 1;
  
    // Store the count of distinct element of first window
    res.push_back(freq.size());
  
    for(int i = k; i < n; i++) {
        freq[arr[i]] += 1;
        freq[arr[i - k]] -= 1;
      
        // If the frequency of arr[i - k] becomes 0, remove 
        // it from hash map
        if(freq[arr[i - k]] == 0)
            freq.erase(arr[i - k]);
      
        res.push_back(freq.size());
    }
      
    return res;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> res = countDistinct(arr, k);
    for(int ele: res)
        cout << ele << " ";
    return 0;
}

//Using Single Loop
// C++ program to count distinct elements in every window   
// of size k by traversing all windows of size k


class Solution {
    public:
      vector<int> countDistinct(vector<int> &arr, int k) {
          int n = arr.size();
          
          vector<int> ans;
          
          unordered_map<int,int> freq;
          
          // for(int i=0; i<k; i++){
          //     freq[arr[i]] +=1;
          // }
          
          // ans.push_back(freq.size());
          
          for(int i=0; i<n; i++){
              
              if(i<k){
                  freq[arr[i]] +=1;
                  if(i+1==k)
                      ans.push_back(freq.size());
              }
              else{
                  freq[arr[i]]+=1;
                  
                  freq[arr[i-k]]-=1;
                  
                  if(freq[arr[i-k]]==0){
                      freq.erase(arr[i-k]);
                  }
                  
                  ans.push_back(freq.size());
              }
          }
          
          return ans;
      }
  };