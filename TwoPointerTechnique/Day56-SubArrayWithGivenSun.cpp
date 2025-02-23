/*

Subarray with Given Sum

Given a 1-based indexing array arr[] of non-negative integers and an integer sum. You mainly need to return the left and right indexes(1-based indexing) of that subarray. In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.

Examples: 

Input: arr[] = [15, 2, 4, 8, 9, 5, 10, 23], target = 23
Output: [2, 5]
Explanation: Sum of subarray arr[2...5] is 2 + 4 + 8 + 9 = 23.*/

/*
[Naive Approach] Using Nested loop - O(n^2) Time and O(1) Space
The very basic idea is to use a nested loop where the outer loop picks a starting element, and the inner loop calculates the cumulative sum of elements starting from this element.

For each starting element, the inner loop iterates through subsequent elements and adding each element to the cumulative sum until the given sum is found or the end of the array is reached. 
If at any point the cumulative sum equals the given sum, then return starting and ending indices (1-based). 
If no such sub-array is found after all iterations, then return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find a continuous sub-array which adds up to
// a given number.
vector<int> subarraySum(vector<int> arr, int target) {
    vector<int> res;
    int n = arr.size();

    // Pick a starting point for a subarray
    for (int s = 0; s < n; s++) {
        int curr = 0;
          
        // Consider all ending points
        // for the picked starting point 
        for (int e = s; e < n; e++) {
            curr += arr[e];
            if (curr == target) {
                res.push_back(s + 1);
                res.push_back(e + 1);
                return res;
            }
        }
    }
      // If no subarray is found
    return {-1}; 
}

int main() {
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    vector<int> res = subarraySum(arr, target);
  
    for (int ele : res)
        cout << ele << " ";
    return 0;
}



/*
[Expected Approach] Sliding Window - O(n) Time and O(1) Space
The idea is simple, as we know that all the elements in subarray are positive so, 
If a subarray has sum greater than the given sum then there is no possibility that adding 
elements to the current subarray will be equal to the given sum. So the Idea is to use a similar approach to a sliding window. 

Start with an empty window 
add elements to the window while the current sum is less than sum 
If the sum is greater than sum, remove elements from the start of the current window.
If current sum becomes same as sum, return the result
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find a continuous sub-array which adds up to
// a given number.
vector<int> subarraySum(vector<int>& arr, int target) {
      // Initialize window
    int s = 0, e = 0;  
    vector<int> res;

    int curr = 0;
    for (int i = 0; i < arr.size(); i++) {
        curr += arr[i];

        // If current sum becomes more or equal,
        // set end and try adjusting start
        if (curr >= target) {
            e = i;

            // While current sum is greater, 
              // remove starting elements of current window
            while (curr > target && s < e) {
                curr -= arr[s];
                ++s;
            }

            // If we found a subraay
            if (curr == target) {
                res.push_back(s + 1);
                res.push_back(e + 1);
                return res;
            }
        }
    }
    // If no subarray is found
    return {-1};
}

int main() {
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    vector<int> res = subarraySum(arr, target);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}