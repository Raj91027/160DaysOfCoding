package Hashing;

/*
Longest Consecutive Subsequence

Given an array of integers, the task is to find the length of the longest subsequence such that elements in the 
subsequence are consecutive integers, the consecutive numbers can be in any order. 

Examples:  

Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation: The consecutive numbers here are from 1 to 6. 
These 6 numbers form the longest consecutive subsequence [2, 6, 1, 4, 5, 3].
*/


// [Optimized Approach] Using HashSet - O(n) Time and O(n) Space    
// The idea is to use a HashSet to store all the elements of the array.
// Then, traverse through the array and for each element, check if the element-1 is present in the HashSet or not.
// If not, then this element is the starting element of a subsequence.
// Then, keep incrementing the element by 1 and check if the incremented element is present in the HashSet or not.
// If yes, then increment the length of the subsequence.
// Finally, update the maximum length of the subsequence found so far.
// Return the maximum length of the subsequence.

import java.util.HashSet;

public class Day47LongestConsecutiveSubsequence {
    static int longestConsecutiveSubsequence(int[] arr) {
        HashSet<Integer> set = new HashSet<>();
        int n = arr.length;
        int maxLen = 0;

        // Insert all the elements of the array into the HashSet
        for (int i = 0; i < n; i++) {
            set.add(arr[i]);
        }

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // Check if the element-1 is present in the HashSet or not
            if (!set.contains(arr[i] - 1)) {
                int currNum = arr[i];
                int currLen = 1;

                // Increment the element by 1 and check if the incremented element is present in the HashSet or not
                while (set.contains(currNum + 1)) {
                    currNum++;
                    currLen++;
                }

                // Update the maximum length of the subsequence found so far
                maxLen = Math.max(maxLen, currLen);
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 6, 1, 9, 4, 5, 3 };

        System.out.println("The length of the longest consecutive subsequence is: " + longestConsecutiveSubsequence(arr));
    }
}


// Output   
// The length of the longest consecutive subsequence is: 6

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), where n is the number of elements in the array.

// Note: The above approach can also be solved using sorting in O(nlogn) time and O(1) space.
// The idea is to sort the array and then traverse through the array to find the longest consecutive subsequence.
// The time complexity of this approach is O(nlogn) due to sorting.
// The space complexity of this approach is O(1) as we are not using any extra space.
// The above approach is more efficient than the sorting approach as it has a time complexity of O(n) and a space complexity of O(n).
// Hence, the above approach is the optimized approach to find the longest consecutive subsequence.

// The above approach can also be solved using a HashMap in O(n) time and O(n) space.
// The idea is to use a HashMap to store the elements of the array and their corresponding lengths of the subsequence.
// Then, traverse through the array and for each element, check if the element-1 is present in the HashMap or not.
// If not, then this element is the starting element of a subsequence.
// Then, keep incrementing the element by 1 and check if the incremented element is present in the HashMap or not.
// If yes, then increment the length of the subsequence.
// Finally, update the maximum length of the subsequence found so far.
// Return the maximum length of the subsequence.
// The time complexity of this approach is O(n) and the space complexity is O(n).
// The above approach using a HashSet is more efficient than the HashMap approach as it has a space complexity of O(1) compared to O(n) in the HashMap approach.
// Hence, the above approach using a HashSet is the optimized approach to find the longest consecutive subsequence.

//Approach2:Using TreeSet to sort array and then find the longest consecutive subsequence

// class Solution {

//     // Function to return length of longest subsequence of consecutive integers.
//     public int longestConsecutive(int[] arr) {
//         TreeSet<Integer> s = new TreeSet<>();
        
//         for(int i=0; i<arr.length; i++){
//             s.add(arr[i]);
//         }
        
//         int i=0; 
//         Iterator<Integer> it = s.iterator();
//         while(it.hasNext()){
//             arr[i++] = it.next();
//         }
        
//         int res=1, cnt=1;
//         for(i=1; i<arr.length; i++){
//             if(arr[i]-arr[i-1]==1){
//                 cnt++;
//             }
//             else{
//                 cnt=1;
//             }
            
//             res = Math.max(res,cnt);
//         }
//         return res;
//     }
// }