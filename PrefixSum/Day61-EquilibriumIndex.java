package PrefixSum;

/*
Equilibrium Index

Given an array arr[] of size n, the task is to return an equilibrium index (if any) or -1 if no equilibrium index exists. The equilibrium index of an array is an index such that the sum of all elements at lower indexes equals the sum of all elements at higher indexes.

Note: When the index is at the start of the array, the left sum is 0, and when it's at the end, the right sum is 0.

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.
 */

 //[Naive Approach] Using Nested Loop - O(n^2) Time and O(1) Space
//The most basic idea is to use nested loops.

//The outer loop iterates through all the indices one by one. Consider it as equilibrium index.
//The inner loop finds out whether index i is equilibrium index or not, by checking if left side sum = right side sum.

// Java program to find equilibrium index of an array
// using nested loop
/*
class EquilibriumIndex {
    static int findEquilibrium(int[] arr) {
      
        // Check for indexes one by one until
        // an equilibrium index is found 
        for (int i = 0; i < arr.length; ++i) {
            // Get left sum
            int leftSum = 0;
            for (int j = 0; j < i; j++)
                leftSum += arr[j];

            // Get right sum
            int rightSum = 0;
            for (int j = i + 1; j < arr.length; j++)
                rightSum += arr[j];

            // If leftsum and rightsum are same, then 
            // index i is an equilibrium index
            if (leftSum == rightSum)
                return i;
        }

        // If equilibrium index doesn't exist
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {-7, 1, 5, 2, -4, 3, 0};
        System.out.println(findEquilibrium(arr));
    }
}

/*
 * 
[Better Approach] Prefix Sum and Suffix Sum Array - O(n) Time and O(n) Space
The idea is to remove the need of inner loop. Instead of calculating the left side sum and right side sum each time, 
precompute the prefix sum array and suffix sum array, and simply access this in O(1) time.

So for each index i, we can check if prefixSum[i - 1] = suffixSum[i + 1] but to avoid unnecessary 
boundary checks we can also check if prefixSum[i] = suffixSum[i].
 */
// Java program to find equilibrium index of an array
// using prefix sum and suffix sum arrays
/*
import java.util.*;
class EquilibriumIndex {
    static int findEquilibrium(int[] arr) {
        int n = arr.length;

        int[] pref = new int[n];
        int[] suff = new int[n];

        // Initialize the ends of prefix and suffix array
        pref[0] = arr[0];
        suff[n - 1] = arr[n - 1];

        // Calculate prefix sum for all indices
        for (int i = 1; i < n; i++) 
            pref[i] = pref[i - 1] + arr[i];

        // Calculating suffix sum for all indices
        for (int i = n - 2; i >= 0; i--) 
            suff[i] = suff[i + 1] + arr[i];

        // Checking if prefix sum is equal to suffix sum
        for (int i = 0; i < n; i++) {
            if (pref[i] == suff[i]) 
                return i;
        }

        // if equilibrium index doesn't exist
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {-7, 1, 5, 2, -4, 3, 0};

        System.out.println(findEquilibrium(arr));
    }
}

/*
 * 
[Expected Approach] Running Prefix Sum and Suffix Sum - O(n) Time and O(1) Space
Now the above prefix sum array and suffix sum array approach can be further optimized in terms of space, 
by using prefix sum and suffix sum variables. 
The idea is that instead of storing the prefix sum and suffix sum for each element in an array, we can simply use the fact that

PrefixSum(arr[0 : pivot - 1]) + arr[pivot] + SuffixSum[pivot + 1: n - 1] = ArraySum

so, SuffixSum[pivot + 1: n - 1] = ArraySum - PrefixSum(arr[0 : pivot - 1])

Here, pivot refers to the index that we are currently checking for the equilibrium index.
 */

 // Java program to find equilibrium index of an array
// using prefix sum and suffix sum variables

class EquilibriumIndex {
    static int equilibriumPoint(int[] arr) {
        int prefSum = 0, total = 0;

        // Calculate the array sum
        for (int ele : arr) {
            total += ele;
        }

        // Iterate pivot over all the elements of the array
        for (int pivot = 0; pivot < arr.length; pivot++) {
            int suffSum = total - prefSum - arr[pivot];
            if (prefSum == suffSum) {
                return pivot;
            }
            prefSum += arr[pivot];
        }

        // There is no equilibrium point
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {1, 7, 3, 6, 5, 6};

        System.out.println(equilibriumPoint(arr));
    }
}