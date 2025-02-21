package TwoPointerTechnique;

/*
 * 
 * 2 Sum - Count Pairs with given Sum in Sorted Array

Given a sorted array arr[] and an integer target, the task is to find the number of pairs in the array whose sum is equal to target.

Examples: 

Input: arr[] = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: Pairs with sum 6 are (1, 5), (1, 5) and (-1, 7).      
 */

 /*
  * 
  [Expected Approach] Using Two Pointer Technique - O(n) and O(1) Space
The idea is to use the two-pointer technique by maintaining two pointers, say left and right and initialize 
them to the first and last element of the array respectively. According to the sum of left and right pointers, we can have three cases:

arr[left] + arr[right] < target: We need to increase the sum of pair, move the left pointer towards right.
arr[left] + arr[right] > target: We need to decrease the sum of pair, move the right pointer towards left.
arr[left] + arr[right] = target: We have found a pair whose sum is equal to target. We can find the product of the count of both the 
elements and add them to the result.
  */

  // Java program for counting pairs with given sum 
// using Two Pointer Technique


class GfG {

    // Function to return the count of pairs
    static int countPairs(int[] arr, int target) {
        int res = 0;
        int n = arr.length;
        int left = 0, right = n - 1;

        while (left < right) {
          
            // If sum is greater 
            if (arr[left] + arr[right] < target)
                left++;

            // If sum is lesser
            else if (arr[left] + arr[right] > target)
                right--;

            // If sum is equal
            else {
                int cnt1 = 0, cnt2 = 0;
                int ele1 = arr[left], ele2 = arr[right];
              
                // Count frequency of first element of the pair
                while (left <= right && arr[left] == ele1) {
                    left++;
                    cnt1++;
                }
              
                // Count frequency of second element of the pair
                while (left <= right && arr[right] == ele2) {
                    right--;
                    cnt2++;
                }
               
                // If both the elements are same, then count of
                // pairs = the number of ways to choose 2 
                // elements among cnt1 elements
                if (ele1 == ele2) 
                    res += (cnt1 * (cnt1 - 1)) / 2;
              
                // If the elements are different, then count of
                // pairs = product of the count of both elements
                else 
                    res += (cnt1 * cnt2);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {-1, 1, 5, 5, 7};
        int target = 6;

        System.out.println(countPairs(arr, target));
    }
}