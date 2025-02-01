/**
 Kth Missing Positive Number in a Sorted Array

Given a sorted array of distinct positive integers arr[] and integer k, 
the task is to find the kth positive number that is missing from arr[].

Examples : 

Input: arr[] = [2, 3, 4, 7, 11], k = 5
Output: 9
Explanation: Missing are 1, 5, 6, 8, 9, 10, ... and 5th missing number is 9.

Input: arr[] = [1, 2, 3], k = 2
Output: 5
Explanation: Missing are 4, 5, 6.... and 2nd missing number is 5.
 */

// C++ Program to find Kth missing positive number
// using Hash Set

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int kthMissing(vector<int>& arr, int k) {
  
    // Insert all array elements into a set
    unordered_set<int> s(arr.begin(), arr.end());
  
    int count = 0, curr = 0;
    while (count < k) {
        curr++;
      
        // Increment missing count if current
        // element is missing
        if (s.find(curr) == s.end()) {
            count++;
        }      
    }
    return curr;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k);
    return 0;
}



// C++ Program to find Kth missing positive number
// using index comparison

#include <iostream>
#include <vector>
using namespace std;

int kthMissing(vector<int> &arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] > (k + i))
            return (k + i);
    }

    // If all numbers from 1 to n are present 
    // in arr[], return k + n
    return k + n;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k);
    return 0;
}


/*
[Expected Approach] Using Binary Search - O(log n) Time and O(1) Space
In the previous approach, we used linear search to find the first index where arr[i] > (k + i). 
Since the input array is sorted, once we have found the index i such that arr[i] > (k + i), 
then for all indices j (j > i), arr[j] will also be greater than (k + j). So, we can optimize the previous 
approach using binary search to find the index i so that the k-th missing element is k + i.
*/
// C++ Program to find Kth missing positive number
// using Binary Search

#include <iostream>
#include <vector>
using namespace std;

// Function to find the k-th missing positive number
int kthMissing(vector<int> &arr, int k) {
    int lo = 0, hi = arr.size() - 1;
    int res = arr.size() + k;

    // Binary Search for index where arr[i] > (i + k)
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] > mid + k) {
            res = mid + k;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k);
    return 0;
}