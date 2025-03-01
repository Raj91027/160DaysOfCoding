package PrefixSum;

/*
 Longest Subarray With Sum K

Given an array arr[] of size n containing integers, the task is to find the length of the longest subarray having sum equal to the given value k.

Note: If there is no subarray with sum equal to k, return 0.

Examples: 

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
 */


 //[Naive Approach] Using Nested Loop - O(n^2) Time and O(1) Space
 /*
// Java program to find the length of the longest
// subarray having sum k using nested loop
class GfG {
  
      // Function to find longest sub-array having sum k
    static int longestSubarray(int[] arr, int k) {
        int res = 0;

        for (int i = 0; i < arr.length; i++) {
            
            // Sum of subarray from i to j
            int sum = 0;
            for (int j = i; j < arr.length; j++) {
                sum += arr[j];
              
                // If subarray sum is equal to k
                if (sum == k) {
                  
                    // find subarray length and update result
                    int subLen = j - i + 1;
                    res = Math.max(res, subLen);
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {10, 5, 2, 7, 1, -10};
        int k = 15;
        System.out.println(longestSubarray(arr, k));
    }
}
  */

  /*
[Expected Approach] Using Hash Map and Prefix Sum - O(n) Time and O(n) Space
If you take a closer look at this problem, this is mainly an extension of Longest Subarray with 0 sum.

The idea is based on the fact that if Sj - Si = k (where Si and Sj are prefix sums till index i and j respectively, and i < j), then the subarray between i+1 to j has sum equal to k.
For example, arr[] = [5, 2, -3, 4, 7] and k = 3. The value of S3 - S0= 3, it means the subarray from index 1 to 3 has sum equals to 3.

So we mainly compute prefix sums in the array and store these prefix sums in a hash table. And check if current prefix sum - k is already present. If current prefix sum - k is present in the hash table and is mapped to index j, then subarray from j to current index has sum equal to k.

Below are the main points to consider in your implementation.

If we have the whole prefix having sum equal to k, we should prefer it as it would be the longest possible till that point.
If there are multiple occurrences of a prefixSum, we must store index of the earliest occurrence of prefixSum because we need to find the longest subarray.
   */

// Java program to find longest sub-array having sum k
// using Hash Map and Prefix Sum

import java.util.HashMap;
import java.util.Map;

class GfG {
  
      // Function to find longest sub-array having sum k
    static int longestSubarray(int[] arr, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int res = 0;
        int prefSum = 0;

        for (int i = 0; i < arr.length; ++i) {
            prefSum += arr[i];

            // Check if the entire prefix sums to k
            if (prefSum == k) 
                res = i + 1;

            // If prefixSum - k exists in the map then there exist such 
              // subarray from (index of previous prefix + 1) to i.
            else if (mp.containsKey(prefSum - k)) 
                res = Math.max(res, i - mp.get(prefSum - k));

            // Store only first occurrence index of prefSum
            if (!mp.containsKey(prefSum))
                mp.put(prefSum, i);
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {10, 5, 2, 7, 1, -10};
        int k = 15;
        System.out.println(longestSubarray(arr, k));
    }
}