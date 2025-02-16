package Hashing;
/*
 Count Subarrays having Sum K

Given an unsorted array of integers, the task is to find the number of subarrays having a sum exactly equal to a given number k.

Examples: 

Input : arr[] = [10, 2, -2, -20, 10], k = -10
Output : 3
Explanation: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum equal to -10.
 */

//[Naive Approach] Using Nested Loop - O(n^2) Time and O(1) Space
//A simple solution is to traverse all the subarrays and calculate their sum. 
//If the sum is equal to the given number k, then increment the count of subarrays.

// Java program to count subarrays having sum K
// using nested loop
// import java.util.*;

// class GfG {
//     static int countSubarrays(int[] arr, int k) {
//         int res = 0;

//         // Pick a starting point of the subarray
//         for (int s = 0; s < arr.length; s++) {
//             int sum = 0;

//             // Pick an ending point
//             for (int e = s; e < arr.length; e++) {
//                 sum += arr[e];
//                 if (sum == k)
//                     res++;
//             }
//         }

//         return res;
//     }

//     public static void main(String[] args) {
//         int[] arr = {10, 2, -2, -20, 10};
//         int k = -10;
//         System.out.println(countSubarrays(arr, k));
//     }
// }

//[Expected Approach] Using Hash Map and Prefix Sum - O(n) Time and O(n) Space
//f you take a closer look at this problem, this is mainly an extension of Subarray with given sum.
//The idea is to use a Hash Map to store the count of every prefix sum of the array. 
//For each index i, with a current prefix sum currSum, we check if (currSum – k) exists in the map. //
//If it does, it indicates the presence of a subarray ending at i with the given sum k. In such cases, 
//we increment the result with the count of (currSum - k) stored in hash map.


// Java program to count subarrays having sum K
// using Hash Map
import java.util.*;

class GfG {
    // Function to find number of subarrays with sum as k
    static int countSubarrays(int[] arr, int k) {

        // HashMap to store prefix sums frequencies
        Map<Integer, Integer> prefixSums = new HashMap<>();
        int res = 0;
        int currSum = 0;

        for (int i = 0; i < arr.length; i++) {
            // Add current element to sum so far.
            currSum += arr[i];

            // If currSum is equal to desired sum, then a new subarray is found.
            if (currSum == k)
                res++;

            // Check if the difference exists in the prefixSums map.
            if (prefixSums.containsKey(currSum - k))
                res += prefixSums.get(currSum - k);

            // Add currSum to the set of prefix sums.
            prefixSums.put(currSum, prefixSums.getOrDefault(currSum, 0) + 1);
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {10, 2, -2, -20, 10};
        int k = -10;
        System.out.println(countSubarrays(arr, k));
    }
}