package PrefixSum;

/*
 Longest Subarray With Equal Number of 0s and 1s

Given an array arr[] containing only 0s and 1s, find the longest subarray which contains equal no of 0s and 1s.

Examples: 

Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1 ... 6] is the longest subarray with three 0s and three 1s.
 * 
 */

 /*
  * 
// Java program to find the longest subarray with
// equal number of 0s and 1s using nested loop

import java.util.*;
class LargestSubArrayOf0sAnd1s {
    static int maxLen(int[] arr) {
        int res = 0;

        // Pick a starting point as 's'
        for (int s = 0; s < arr.length; s++) {
            int sum = 0;

            // Consider all subarrays arr[s...e]
            for (int e = s; e < arr.length; e++) {
                sum += (arr[e] == 0) ? -1 : 1;

                // Check if it's a 0-sum subarray
                if (sum == 0)
                    // Update max size
                    res = Math.max(res, e - s + 1);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {1, 0, 0, 1, 0, 1, 1};
        System.out.println(maxLen(arr));
    }
}
  */

  /*


[Expected Approach] Using Hash Map and Prefix Sum Technique - O(n) Time and O(n) Space
If we consider every 0 as -1, then this problem become same as the longest subarray with 0 sum problem.

We traverse the array and compute the prefix sum

If current prefix sum == 0, it means that subarray from index (0) till present index has equal number of 0's and 1's.
If we encounter a prefix sum value which we have already encountered before, 
which means that subarray from the previous index+1 till the present index has equal number of 0's and 1's as 
they give a cumulative sum of 0.
In a nutshell this problem is equivalent to finding two indexes i & j in arr[], 
such that prefix sums till i and j are same, and (j - i) is maximum. 
To store the first occurrence of each unique cumulative sum value we use a hash map where 
if we get that value again we can find the subarray size and compare it with the maximum size found till now.

   */

   // Java program to find longest subarray with equal
// number of 0's and 1's Using HashMap and Prefix Sum
import java.util.HashMap;

class LargestSubArrayOf0sAnd1s {
    static int maxLen(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        int preSum = 0;
        int res = 0;

        // Traverse through the given array
        for (int i = 0; i < arr.length; i++) {

            // Add current element to sum
            // if current element is zero, add -1
            preSum += (arr[i] == 0) ? -1 : 1;

            // To handle sum = 0 at last index
            if (preSum == 0)
                res = i + 1;

            // If this sum is seen before, then update 
              // result with maximum
            if (mp.containsKey(preSum))
                res = Math.max(res, i - mp.get(preSum));

            // Else put this sum in hash table
            else
                mp.put(preSum, i);
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {1, 0, 0, 1, 0, 1, 1};

        System.out.println(maxLen(arr));
    }
}

// Output
// 6
// Time Complexity: O(n), where n is the size of the given array.
// Space Complexity: O(n), where n is the size of the given array.
//
//  */
