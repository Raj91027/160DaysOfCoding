package TwoPointerTechnique;

/*
 * 3 Sum - Count Triplets With Given Sum In Sorted Array

Given a sorted array arr[] and a target value, the task is to find the count of triplets present in the given array having sum equal to the given target. 

More specifically, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

Examples:

Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
Output: 4
Explanation: Two triplets that add up to -2 are:
arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2

Input: arr[] = [-2, 0, 1, 1, 5], target = 1
Output: 0
Explanation: There is no triplet whose sum is equal to 1.
 */

 //Using Two Pointers Technique
//The idea is to fix the first element of the triplet at index i and then using two pointers technique to count the other two elements. 
//For each index i, initialize left pointer to i + 1 and right pointer to n - 1.

//For each triplet, calculate the sum as arr[i] + arr[left] + arr[right] and evaluate:

//If sum = target: A valid triplet is found. Additionally, handle duplicates by 
//counting the frequencies of arr[left] and arr[right] and updating the result accordingly. Then move both pointers to the next distinct values.
//If sum < target: Increment the left pointer to explore larger values and increase the sum.
//If sum > target: Decrement the right pointer to explore smaller values and decrease the sum.
//Repeat the above steps until the left pointer is less than the right pointer.

//Finally, return the count of valid triplets.

// Java program to count all triplets having sum equal to
// target by exploring all possible triplets


class GfG {

    // Function to count triplets whose sum equals the target
    static int countTriplets(int[] arr, int target) {
        int n = arr.length;
        int res = 0;

        // Iterate through each element as the first element
        // of the triplet
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            // Use two-pointer approach to find triplets
            while (left < right) {

                // Calculate the sum of the triplet
                int sum = arr[i] + arr[left] + arr[right];

                // If sum is smaller, move to bigger values
                if (sum < target) {
                    left += 1;
                }
                
                // If sum is greater, move to smaller values
                else if (sum > target) {
                    right -= 1;
                }
                
                // If sum is equal, check for frequency of elements
                else if (sum == target) {
                    int ele1 = arr[left], ele2 = arr[right];
                    int cnt1 = 0, cnt2 = 0;

                    // Count frequency of the current value at 'left'
                    while (left <= right && arr[left] == ele1) {
                        left++;
                        cnt1++;
                    }

                    // Count frequency of the current value at 'right'
                    while (left <= right && arr[right] == ele2) {
                        right--;
                        cnt2++;
                    }

                    // If both the elements are the same, then count 
                    // of pairs = the number of ways to choose 2 
                    // elements among cnt1 elements
                    if (ele1 == ele2)
                        res += (cnt1 * (cnt1 - 1)) / 2;

                    // If the elements are different, then count of  
                    // pairs = product of the count of both elements
                    else
                        res += (cnt1 * cnt2);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {-3, -1, -1, 0, 1, 2};
        int target = -2;

        System.out.println(countTriplets(arr, target));
    }
}
