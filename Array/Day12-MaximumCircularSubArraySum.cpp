/*
Maximum Circular Subarray Sum

Given a circular array arr[] of size n, find the maximum possible sum of a non-empty subarray.

Examples: 

Input: arr[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22
Explanation: Circular Subarray {12, 8, -8, 9, -9, 10} has the maximum sum, which is 22.

Input: arr[] = {10, -3, -4, 7, 6, 5, -4, -1}
Output: 23 
Explanation: Circular Subarray {7, 6, 5, -4, -1, 10} has the maximum sum, which is 23.
*/

/*
[Naive Approach] Considering all possible subarrays – O(n^2) Time and O(1) Space
A simple approach is to consider every element as the beginning of the subarray, and calculate the maximum possible sum, 
which includes both circular and linear subarrays starting from that element.
*/// C++ program to find maximum Subarray Sum in Circular
// subarray by considering all possbile subarrays

#include <iostream>
#include <vector>
using namespace std;

int circularSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int res = arr[0];
    
    // Subarray that starts with index i
    for(int i = 0; i < n; i++) {
        int currSum = 0;
        
        // Considering all possible endpoints of the 
        // Subarray that begins with index i
        for(int j = 0; j < n; j++) {
            
            // Circular index
            int idx = (i + j) % n;
            currSum = currSum + arr[idx];            
            res = max(res, currSum);
        }
    }
    
    return res;
}

int main() {
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << circularSubarraySum(arr);
}

/*
[Better Approach] Using Prefix and Suffix Sum – O(n) Time and O(n) Space
In a circular array, the maximum subarray sum can be either the maximum normal sum, which is the highest sum of a non-circular array, or the maximum circular sum, which includes elements from both the start and the end of the array. The normal sum can be efficiently calculated using Kadane's algorithm. And, the circular sum is calculated by combining prefix sum and suffix sum.

First, we will compute the maxSuffix array, where maxSuffix[i] stores the maximum suffix sum starting from any index >= i.
Then, as we iterate through the input array, we combine the prefix sum up to index i with the maxSuffix value at index i + 1 (to avoid double-counting the ith element) to calculate circular sum and take the maximum for all values of i.
*/


// C++ program to find maximum Subarray Sum in Circular
// array using prefix and suffix

#include <iostream>
#include <vector>
using namespace std;

int circularSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int suffixSum = arr[n - 1];
    
    // maxSuffix array to store the value of 
    // maximum suffix occured so far.
    vector<int> maxSuffix(n + 1, 0);
    maxSuffix[n - 1] = arr[n - 1];
    
    for(int i = n - 2; i >= 0; i--) {
        suffixSum = suffixSum + arr[i];
        maxSuffix[i] = max(maxSuffix[i + 1], suffixSum);
    }
    
    // circularSum is Maximum sum of circular subarray
    int circularSum = arr[0];
    
    // normalSum is Maxium sum subarray considering 
    // the array is non-circular
    int normalSum = arr[0];
    
    int currSum = 0;
    int prefix = 0;
    
    for(int i = 0; i < n; i++) {
        
        // Kadane's algorithm
        currSum = max(currSum + arr[i], arr[i]);
        normalSum = max(normalSum, currSum);
      
        // Calculating maximum Circular Sum
        prefix = prefix + arr[i];
        circularSum = max(circularSum, prefix + maxSuffix[i+1]);
    }
    
    return max(circularSum, normalSum);
}

int main() {
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << circularSubarraySum(arr);
}

/*
[Expected Approach] Using Kadane's Algorithm – O(n) Time and O(1) Space
This approach is similar to the previous one, 
but the key difference is that we're using Kadane's algorithm to find the 
circular subarray sum as well. The maximum sum of a circular subarray can be defined as the total sum of the array minus the sum of a subarray in the middle. So, to maximize the circular subarray sum, 
we need to minimize the subarray sum.
*/

// C++ program to find maximum Subarray Sum in Circular
// subarray by considering all possbile subarrays

#include <iostream>
#include <vector>
using namespace std;

int circularSubarraySum(vector<int> &arr) {

    int totalSum = 0;
    int currMaxSum = 0, currMinSum = 0;
    int maxSum = arr[0], minSum = arr[0];

    for (int i = 0; i < arr.size(); i++) {

        // Kadane's to find maximum sum subarray
        currMaxSum = max(currMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, currMaxSum);

        // Kadane's to find minimum sum subarray
        currMinSum = min(currMinSum + arr[i], arr[i]);
        minSum = min(minSum, currMinSum);

        // Sum of all the elements of input array
        totalSum = totalSum + arr[i];
    }

    int normalSum = maxSum;
    int circularSum = totalSum - minSum;

    // If the minimum subarray is equal to total Sum
    // then we just need to return normalSum
    if (minSum == totalSum)
        return normalSum;

    return max(normalSum, circularSum);
}

int main() {
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << circularSubarraySum(arr);
}