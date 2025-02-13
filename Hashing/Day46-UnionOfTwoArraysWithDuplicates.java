package Hashing;

import java.util.HashSet;

//Union of Two Arrays

//Given two arrays a[] and b[], the task is to return union of both the arrays in any order.

//Note: Union of two arrays is an array having all distinct elements that are present in either array.

//Examples:

//Input : a[] = {1, 2, 3, 2, 1}, b[] = {3, 2, 2, 3, 3, 2}
//Output : {3, 2, 1}
//Explanation: 3, 2 and 1 are the distinct elements present in either array.

//[Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space
//The idea is to traverse both the arrays a[] and b[] and for each element, 
//check if the element is present in the result or not. If not, then add this element to the result.


// Java program to find union of two arrays

// import java.util.ArrayList;

// class GfG {
//     static ArrayList<Integer> findUnion(int[] a, int[] b) {
//         ArrayList<Integer> res = new ArrayList<>();

//         // Traverse through a[] and search
//         // every element a[i] in result
//         for (int num : a) {

//             // check if the element is already in
//             // the result to avoid duplicates
//             if (!res.contains(num)) {
//                 res.add(num);
//             }
//         }

//         // Traverse through b[] and search
//         // every element b[i] in result
//         for (int num : b) {

//             // check if the element is already in
//             // the result to avoid duplicates
//             if (!res.contains(num)) {
//                 res.add(num);
//             }
//         }
//         return res;
//     }

//     public static void main(String[] args) {
      
//         int[] a = { 1, 2, 3, 2, 1 };
//         int[] b = { 3, 2, 2, 3, 3, 2 };

//         ArrayList<Integer> res = findUnion(a, b);

//         for (int num : res) {
//             System.out.print(num + " ");
//         }
//     }
// }



//[Expected Approach] Using Hash Set - O(n) Time and O(n) Space
//The idea is to use a Hash Set, which helps in keeping only unique elements by removing duplicates. 
//We first create an empty Hash Set and add elements from both arrays. 
//The Hash Set ensures that no duplicates are stored. 
//After adding all the elements, we can create the final union array by iterating through the Hash Set.

class Solution {
    public static int findUnion(int a[], int b[]) {
        HashSet<Integer> res = new HashSet<>();
        
        for(int i=0; i<a.length; i++){
            res.add(a[i]);
        }
        for(int i=0; i<b.length; i++){
            res.add(b[i]);
        }
        
        return res.size();
    }
}

