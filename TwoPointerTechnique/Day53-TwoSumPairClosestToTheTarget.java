package TwoPointerTechnique;

/*
 * 
 2 Sum - Pair Sum Closest to Target

Given an array arr[] of n integers and an integer target, the task is to find a pair in arr[] such that it’s sum is closest to target.

Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]
Explanation: Out of all the pairs, [22, 30] has sum = 25 which is closest to 25.
 */


 /*
  */
  /*/ // Java Code to find the pair with sum closest to target by
// exploring all the pairs

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class GfG {

    static List<Integer> sumClosest(int[] arr, int target) {
        int n = arr.length;

        List<Integer> res = new ArrayList<>();
        int minDiff = Integer.MAX_VALUE;

        // Generating all possible pairs
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                int currSum = arr[i] + arr[j];
                int currDiff = Math.abs(currSum - target);

                // if currDiff is less than minDiff, it indicates
                // that this pair is closer to the target
                if (currDiff < minDiff) {
                    minDiff = currDiff;
                    res = Arrays.asList(Math.min(arr[i], arr[j]), 
                                        Math.max(arr[i], arr[j]));
                }

                // if currDiff is equal to minDiff, find the one with
                // largest absolute difference
                else if (currDiff == minDiff && 
                         (res.get(1) - res.get(0)) < Math.abs(arr[i] - arr[j])) {
                    res = Arrays.asList(Math.min(arr[i], arr[j]), 
                                        Math.max(arr[i], arr[j]));
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 7, 1, 4};
        int target = 10;

        List<Integer> res = sumClosest(arr, target);
        if(res.size() > 0)
            System.out.println(res.get(0) + " " + res.get(1));
    }
}
  */

  /*
Expected Approach] Two Pointer Technique - O(nlogn+n) Time and O(1) Space
The idea is to sort the array and use Two Pointer Technique to find the pair with sum closest to target. Initialize a pointer left to the beginning of the array and another pointer right to the end of the array. Now, compare the sum at both the pointers to find the pair sum closest to target:

If arr[left] + arr[right] < target: We need to increase the pair sum, so move left to higher value.
If arr[left] + arr[right] > target: We need to decrease the pair sum, so move right to smaller value.
If arr[left] + arr[right] == target: We have found a pair with sum = target, so we can return the pair.
Note: In this approach, we don't need to separately handle the case when there is a tie between pairs and 
we need to select the one with maximum absolute difference. This is because we are selecting the first element of the pair in increasing order, 
so if we have a tie between two pairs, we can always choose the first pair.
   */

// Java Program to find pair with sum closest to target 
// using Two Pointer Technique

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class GfG {
    
    // function to return the pair with sum closest to target
    static List<Integer> sumClosest(int[] arr, int target) {
        int n = arr.length;
        Arrays.sort(arr);
        List<Integer> res = new ArrayList<>();
        int minDiff = Integer.MAX_VALUE;

        int left = 0, right = n - 1;

        while (left < right) {
            int currSum = arr[left] + arr[right];

            // Check if this pair is closer than the closest
            // pair so far
            if (Math.abs(target - currSum) < minDiff) {
                minDiff = Math.abs(target - currSum);
                res = Arrays.asList(arr[left], arr[right]);
            }

            // If this pair has less sum, move to greater values
            if (currSum < target)
                left++;

            // If this pair has more sum, move to smaller values
            else if (currSum > target)
                right--;

            // If this pair has sum = target, return it
            else
                return res;
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 7, 1, 4};
        int target = 10;

        List<Integer> res = sumClosest(arr, target);
        if(res.size() > 0)
            System.out.println(res.get(0) + " " + res.get(1));
    }
}