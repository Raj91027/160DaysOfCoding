package Hashing;

/*
 2 Sum - Count pairs with given sum

Given an array arr[] of n integers and a target value, 
the task is to find the number of pairs of integers in the array whose sum is equal to target.

Examples:  

Input: arr[] = {1, 5, 7, -1, 5}, target = 6
Output:  3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) & (1, 5).         
 */

 //[Naive Approach] By Generating all Possible Pairs - O(n^2) time and O(1) space
//The very basic approach is to generate all the possible pairs and check if any pair exists whose sum is equals to given target value, 
//then increment the count variable.
// Java Program to count pairs with given sum by
// generating all possible pairs



// class Day43TwoSumCountPairWithGivenSum {
    
//     // Function to count all pairs whose sum is equal
//     // to the given target value
//     static int countPairs(int[] arr, int target) {
//         int n = arr.length;
//         int cnt = 0;

//         // Iterate through each element in the array
//         for (int i = 0; i < n; i++) {
          
//             // For each element arr[i], check every
//             // other element arr[j] that comes after it
//             for (int j = i + 1; j < n; j++) {
              
//                 // Check if the sum of the current pair
//                 // equals the target
//                 if (arr[i] + arr[j] == target) {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }

//     public static void main(String[] args) {
//         int[] arr = { 1, 5, 7, -1, 5 };
//         int target = 6;
//         System.out.println(countPairs(arr, target));
//     }
// }


/*
 [Better Approach] Using Two Pointers Technique - O(nlogn) Time and O(1) Space
The idea is to sort the input array and use two-pointer technique. Maintain two pointers, 
say left and right and initialize them to the first and last element of the array respectively. According to the sum of left and right pointers, we can have three cases:

arr[left] + arr[right] < target: Increase the pair sum by moving the left pointer towards right.
arr[left] + arr[right] > target: Decrease the pair sum by moving the right pointer towards left.
arr[left] + arr[right] = target: We have found a pair whose sum is equal to target. 
We can find the product of the count of both the elements and add them to the result.
 */

// Java Program to count pairs with given sum by
// using two-pointer technique  

// class GfG {

//     // Function to count all pairs whose sum is equal    
//     // to the given target value
//     static int countPairs(int[] arr, int target) {
//         int n = arr.length;
//         int cnt = 0;

//         // Sort the input array
//         Arrays.sort(arr);

//         // Initialize two pointers
//         int left = 0, right = n - 1;

//         // Loop until left pointer is less than right pointer
//         while (left < right) {

//             // If the sum of the current pair is less than the target
//             if (arr[left] + arr[right] < target) {
//                 left++;
//             }

//             // If the sum of the current pair is greater than the target
//             else if (arr[left] + arr[right] > target) {
//                 right--;
//             }

//             // If the sum of the current pair is equal to the target
//             else {
//                 // Find the count of the left element
//                 int leftCount = 1;
//                 while (left + 1 < right && arr[left] == arr[left + 1]) {
//                     leftCount++;
//                     left++;
//                 }

//                 // Find the count of the right element
//                 int rightCount = 1;
//                 while (right - 1 > left && arr[right] == arr[right - 1]) {
//                     rightCount++;
//                     right--;
//                 }

//                 // Update the count of pairs
//                 cnt += leftCount * rightCount;

//                 // Move the pointers
//                 left++;
//                 right--;
//             }
//         }
//         return cnt;
//     }


/*
 [Expected Approach] Using Hash Map or Dictionary - O(n) Time and O(n) Space
HashMap or Dictionary provides a more efficient solution to the 2Sum problem. 
Instead of checking every pair of numbers, we keep each number in a map as we go through the array. 
For each number, we calculate its complement (i.e., target - current number) and check if it’s in the map. 
If it is, increment the count variable by the occurrences of complement in map.
  
 */

 // Java Program to count pairs with given sum
// using Hash Map

import java.util.Map;
import java.util.HashMap;

class Day43TwoSumCountPairWithGivenSum {
    
    // Returns number of pairs in arr[0...n-1] with
    // sum equal to 'target'
    static int countPairs(int[] arr, int target) {
        Map<Integer, Integer> freq = new HashMap<>();
        int cnt = 0;

        for (int i = 0; i < arr.length; i++) {
          
            // Check if the complement (target - arr[i])
            // exists in the map. If yes, increment count
            if (freq.containsKey(target - arr[i])) {
                cnt += freq.get(target - arr[i]); 
            }
          
            // Increment the frequency of arr[i]
            freq.put(arr[i], 
                     freq.getOrDefault(arr[i], 0) + 1); 
        }
        return cnt;
    }

    public static void main(String[] args) {
        int[] arr = {1, 5, 7, -1, 5}; 
        int target = 6; 
        System.out.println(countPairs(arr, target));    
    }
}