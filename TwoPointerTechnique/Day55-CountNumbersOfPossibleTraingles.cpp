
//Count Possible Triangles

//Given an unsorted array of positive integers, the task is to find the number of triangles that 
//can be formed with three different array elements as three sides of triangles.

//For a triangle to be possible from 3 values as sides, the sum of the two values (or sides) must always be greater than the third value (or third side). 

//Examples: 

//Input: arr[] = [4, 6, 3, 7]
//Output: 3
//Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. 
//Note that [3, 4, 7] is not a possible triangle.  


//naive Approach

// C++ code to count the number of possible triangles 
// using Nested Loop
#include <iostream>
#include <vector>
using namespace std;

// Function to count all possible triangles with arr[]
// values as sides
int countTriangles(vector<int>& arr) {
    int res = 0;

    // The three loops select three different values from
    // array
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            for (int k = j + 1; k < arr.size(); k++)

                // Sum of two sides is greater than the third
                if (arr[i] + arr[j] > arr[k] && 
                    arr[i] + arr[k] > arr[j] && 
                    arr[k] + arr[j] > arr[i])
                    res++;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {4, 6, 3, 7};
    cout << countTriangles(arr);
    return 0;
}

//[Better Approach] Using Binary Search - O((n^2)*log n) Time and O(1) Space

// C++ code to count the number of possible triangles
// using Binary Search
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of valid triangles.
int countTriangles(vector<int> &arr) {
    int res = 0;

    // Sort the array to apply the triangle inequality efficiently
    sort(arr.begin(), arr.end());

    // Iterate through pairs of sides (arr[i], arr[j])
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
          
            // Find the first index where the sum of two sides is not valid
            int k = lower_bound(arr.begin() + j + 1, arr.end(), arr[i] + arr[j])
                - arr.begin();
            
            // Count the number of valid third sides
            int cnt = k - j - 1;
            res += cnt;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {4, 6, 3, 7};
    cout << countTriangles(arr);
    return 0;
}

//[Expected Approach] Using Two Pointers Technique - O(n^2) Time and O(1) Space
//The idea is to sort the array to simplify checking the triangle inequality. 
//Then, for each element (treated as the largest side), use two pointers technique to 
//find count of pairs of smaller sides that can form a triangle with it.
//For this, the two pointers are initialized as: one pointer (left) starts at index 0, 
//and the other pointer (right) is positioned just before the current largest side (arr[i]).

//Now, compare the sum of arr[left] + arr[right] with the current largest side (arr[i]):

//If the sum is greater than or equal to arr[i], a valid triangle can be formed. 
//Count all valid pairs between left and right, then move the right pointer to the left to explore smaller side values.
//If the sum is less than arr[i], increment the left pointer to increase the sum and check larger values.

class Solution {
    public:
      // Function to count the number of possible triangles.
      int countTriangles(vector<int>& arr) {
          int n = arr.size();
          sort(arr.begin(), arr.end());
          int res=0;
          for(int i=n-1; i>0; i--){
              int left=0, right=i-1;
              
              while(left < right){
                  int sum = arr[left] + arr[right];
                  
                  if(sum > arr[i])
                  {
                      res+=right-left;
                      right--;
                  }
                  else
                      left++;
              }
          }
          return res;
      }
  };