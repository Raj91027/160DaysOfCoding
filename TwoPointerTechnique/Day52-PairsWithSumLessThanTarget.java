package TwoPointerTechnique;

/*
 *Count Pairs With Sum Less Than Target

Given an array arr[] and an integer target, 
the task is to find the count of pairs whose sum is strictly less than given target.

Examples:

Input: arr[] = [7, 2, 5, 3], target = 8
Output: 2
Explanation: There are 2 pairs with sum less than 8: (2, 5) and (2, 3).
 */

 /*
  * 
  [Naive Approach] - By Generating all the pairs- O(n^2) Time and O(1) Space
A simple approach is to generate all possible pairs using two nested for loops and count 
those pairs whose sum is less than given target.

// Java program to count pairs whose sum is less than
// given target by generating all the pairs

class GfG {
    static int countPairs(int[] arr, int target) {
        int cnt = 0;

        // Generating all possible pairs
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {

                // If sum of this pair is less than
                // target, then increment the cnt
                if (arr[i] + arr[j] < target)
                    cnt++;
            }
        }

        return cnt;
    }

    public static void main(String[] args) {
        int[] arr = {2, 1, 8, 3, 4, 7, 6, 5};
        int target = 7;
        System.out.println(countPairs(arr, target));
    }
}

[Better Approach] - Using Binary Search - O(2*nlogn) Time and O(1) Space
The idea is to first sort the array. For each element we will calculate the complement (target - arr[i]) required to make pair sum equal to the target. 
Then, find the first element in the array which is greater than or equal (lower bound) to the complement using binary search. 
All the elements which appear before that element will make a valid pair with current element having sum less than given target. 
We also need to handle the case where an element pairs with itself. Since, 
each pair is counted twice, total count divide by two will be our answer.
// Java program to count pairs whose sum is less than 
// given target using binary search

import java.util.Arrays;

class GfG {
  
    // Binary search to find lower bound
    static int binarySearch(int[] arr, int complement) {
        int lo = 0, hi = arr.length - 1;
        int res = arr.length;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (arr[mid] >= complement) {
                res = mid;
                hi = mid - 1;
            } 
              else {
                lo = mid + 1;
            }
        }
        return res;
    }

    static int countPairs(int[] arr, int target) {
        int cnt = 0;

        // Sort the array to use binary search
        Arrays.sort(arr);

        for (int i = 0; i < arr.length; i++) {
            int complement = target - arr[i];

            // Index of the element which is greater 
            // or equal to the complement
            int ind = binarySearch(arr, complement);

            // arr[i] will make valid pairs with  
            // each element before the index 'ind'
            cnt += ind;

            // If element has made a pair with itself
            if (ind > i)
                cnt--;
        }

        // Each pair is counted twice
        return cnt / 2;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 1, 8, 3, 4, 7, 6, 5 };
        int target = 7;
        System.out.println(countPairs(arr, target));
    }
}
  */

//[Expected Approach] - Using Two Pointers Technique - O(n*logn+n) Time and O(1) Space
//First sort the array, then use Two Pointers Technique to find the number of pairs with a sum less than the given target. 
//Initialize two pointers, one at the beginning (left) and the other at the end (right) of the array. 
//Now, compare the sum of elements at these pointers with the target:

//If sum < target:
//Pairs formed by the element at the left pointer with every element between left and right (inclusive) will have a sum less than the target. 
//Therefore, we add (right - left) to the count and move the left pointer one step to the right to explore more pairs.
//If sum >= target:
//We move the right pointer one step to the left to reduce the sum.
//count-pairs-with-sum-less-than-target-using-two-pointers-technique-2.webp

// Java program to count pairs with sum less 
// than target using two pointers technique

import java.util.Arrays;

class GfG {
    static int countPairs(int[] arr, int target) {
      
        // Sort the array to use two pointer technique
        Arrays.sort(arr);
        int left = 0, right = arr.length - 1;
        int cnt = 0;

        // Two pointer technique
        while (left < right) {
            int sum = arr[left] + arr[right];

            // If the sum is less than target, then arr[left] 
            // will form a valid pair with every element 
            // from index left + 1 to right.
            if (sum < target) {
                cnt += right - left;
                left++;
            } 
              else {
                right--;
            }
        }

        return cnt;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 1, 8, 3, 4, 7, 6, 5 };
        int target = 7;
        System.out.println(countPairs(arr, target));
    }
}