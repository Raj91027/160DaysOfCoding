package TwoPointerTechnique;

/*
Container with Most Water

Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, 
find the maximum amount of water that can be contained between any two lines, together with the x-axis.

Examples :  

Input: arr[] = [1, 5, 4, 3]
Output: 6
Explanation: 5 and 3 are 2 distance apart. So the size of the base = 2. Height of container = min(5, 3) = 3. So total area = 3 * 2 = 6.
 */

 /*
  * 
[Naive Approach] Finding all possible boundaries - O(n^2) Time and O(1) Space
The idea is to iterate over all pair of lines in the array. For each line arr[i], 
consider it as the left boundary and then iterate over all subsequent lines arr[j] (j > i) 
to consider them as them as the right boundary. For each pair of boundaries, 
calculate the water that can be contained between them by the formula min(arr[i], arr[j]) * (j - i). 
The result will be the maximum amount of water found across all pairs.
  */

  // Java Program to find the maximum amount of water
// by iterating over all possible boundaries

// import java.util.*;
// class GfG {
//     static int maxWater(int[] arr) {
//         int n = arr.length;
//         int res = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
              
//                 // Calculate the amount of water
//                 int amount = Math.min(arr[i], arr[j]) * (j - i);
              
//                 // Keep track of maximum amount of water
//                 res = Math.max(amount, res);
//             }
//         }
//         return res;
//     }

//     public static void main(String[] args) {
//         int[] arr = {2, 1, 8, 6, 4, 6, 5, 5};
//         System.out.println(maxWater(arr));
//     }
// }

/*
 * 
[Expected Approach] Using Two Pointers - O(n) Time and O(1) Space
The idea is to maintain two pointers: left pointer at the beginning of the array and right pointer at the end of the array. 
These pointers act as the container's sides so we can calculate the amount of water stored between them using the formula: 
min(arr[left], arr[right]) * (right - left).

After calculating the amount of water for the given sides, we can have three cases:

arr[left] < arr[right]: This means that we have calculated the water stored for the container of height arr[left], so increment left by 1.
arr[left] >= arr[right]: This means that we have calculated the water stored for the container of height arr[right], so decrement right by 1.
Repeat the above process till left is less than right keeping track of the maximum water stored as the result.
 */

 // Java Program to find the maximum amount of water in the 
// container using Two Pointer Technique

import java.util.*;

class ContainerWithMostWater {
    static int maxWater(int[] arr) {
        int left = 0, right = arr.length - 1;
        int res = 0;
        while (left < right) {
            
            // Find the water stored in the container between 
            // arr[left] and arr[right]
            int water = Math.min(arr[left], arr[right]) * (right - left);
            res = Math.max(res, water);
            
            if (arr[left] < arr[right])
                left += 1;
            else
                right -= 1;
        }
        
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {2, 1, 8, 6, 4, 6, 5, 5};
        System.out.println(maxWater(arr));
    }
}