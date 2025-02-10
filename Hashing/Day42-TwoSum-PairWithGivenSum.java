package Hashing;

/*
 Two Sum - Pair with given Sum

Given an array arr[] of n integers and a target value, the task is to 
find whether there is a pair of elements in the array whose sum is equal to target. 
This problem is a variation of 2Sum problem.

Examples: 

Input: arr[] = [0, -1, 2, -3, 1], target = -2
Output: true
Explanation: There is a pair (1, -3) with the sum equal to given target, 1 + (-3) = -2.
 */


// Brute Force Approach
// Time Complexity: O(N^2)
// Space Complexity: O(1)


// class Day42TwoSumPairWithGivenSum {
//     // Function to check whether any pair exists
//     // whose sum is equal to the given target value
//     static boolean twoSum(int[] arr, int target){
//         int n = arr.length;

//         // Iterate through each element in the array
//         for (int i = 0; i < n; i++) {
          
//             // For each element arr[i], check every
//             // other element arr[j] that comes after it
//             for (int j = i + 1; j < n; j++) {
              
//                 // Check if the sum of the current pair
//                 // equals the target
//                 if (arr[i] + arr[j] == target) {
//                     return true;
//                 }
//             }
//         }
      
//         // If no pair is found after checking
//         // all possibilities
//         return false;
//     }

//     public static void main(String[] args){

//         int[] arr = { 0, -1, 2, -3, 1 };
//         int target = -2;
      
//         if (twoSum(arr, target))
//             System.out.println("true");
//         else
//             System.out.println("false");
//     }
// }




// import java.util.Arrays;

// class GfG {

//     // Function to perform binary search
//     static boolean binarySearch(int[] arr, int left,
//                                 int right, int target){
//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             if (arr[mid] == target)
//                 return true;
//             if (arr[mid] < target)
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
//         return false;
//     }

//     // Function to check whether any pair exists
//     // whose sum is equal to the given target value
//     static boolean twoSum(int[] arr, int target){
        
//         // Sort the array
//         Arrays.sort(arr);

//         // Iterate through each element in the array
//         for (int i = 0; i < arr.length; i++) {
//             int complement = target - arr[i];

//             // Use binary search to find the complement
//             if (binarySearch(arr, i + 1, arr.length - 1,
//                              complement))
//                 return true;
//         }
//         // If no pair is found
//         return false;
//     }

//     public static void main(String[] args){
//         int[] arr = { 0, -1, 2, -3, 1 };
//         int target = -2;

//         if (twoSum(arr, target)) {
//             System.out.println("true");
//         }
//         else {
//             System.out.println("false");
//         }
//     }
// }




// import java.util.Arrays;

// class GfG {

//     // Function to check whether any pair exists
//     // whose sum is equal to the given target value
//     static boolean twoSum(int[] arr, int target){
//         // Sort the array
//         Arrays.sort(arr);

//         int left = 0, right = arr.length - 1;

//         // Iterate while left pointer is less than right
//         while (left < right) {
//             int sum = arr[left] + arr[right];

//             // Check if the sum matches the target
//             if (sum == target)
//                 return true;
//             else if (sum < target)
//                 left++; // Move left pointer to the right
//             else
//                 right--; // Move right pointer to the left
//         }
//         // If no pair is found
//         return false;
//     }

//     public static void main(String[] args){
//         int[] arr = { 0, -1, 2, -3, 1 };
//         int target = -2;

//         // Call the twoSum function and print the result
//         if (twoSum(arr, target)) {
//             System.out.println("true");
//         }
//         else {
//             System.out.println("false");
//         }
//     }
// }



//Step-by-step approach:

//Create an empty Hash Set or Unordered Set
//Iterate through the array and for each number in the array:
//Calculate the complement (target - current number).
//Check if the complement exists in the set:
//If it is, then pair found.
//If it isn’t, add the current number to the set.
//If the loop completes without finding a pair, return that no pair exists.

import java.util.HashSet;

class Day42TwoSumPairWithGivenSum {

    // Function to check whether any pair exists
    // whose sum is equal to the given target value
    static boolean twoSum(int[] arr, int target){

        // Create a HashSet to store the elements
        HashSet<Integer> set = new HashSet<>();

        // Iterate through each element in the array
        for (int i = 0; i < arr.length; i++) {

            // Calculate the complement that added to
            // arr[i], equals the target
            int complement = target - arr[i];

            // Check if the complement exists in the set
            if (set.contains(complement)) {
                return true;
            }

            // Add the current element to the set
            set.add(arr[i]);
        }
        // If no pair is found
        return false;
    }

    public static void main(String[] args){

        int[] arr = { 0, -1, 2, -3, 1 };
        int target = -2;

        // Call the twoSum function and print the result
        if (twoSum(arr, target))
            System.out.println("true");
        else
            System.out.println("false");
    }
}