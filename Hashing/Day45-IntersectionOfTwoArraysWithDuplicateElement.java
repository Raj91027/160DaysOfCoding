package Hashing;

/*
Intersection of two Arrays

Given two arrays a[] and b[], the task is find intersection of the two arrays. 
Intersection of two arrays is said to be elements that are common in both arrays. 
The intersection should not count duplicate elements and the result should contain items in any order.

Input: a[] = {1, 2, 1, 3, 1}, b[] = {3, 1, 3, 4, 1}
Output: {1, 3}
Explanation: 1 and 3 are the only common elements and we need to print only one occurrence of common elements
*/

//[Naive Approach] Using Triple Nested Loops - O(n*n*m) Time and O(1) Space
//Initialize an empty array for result.
//Traverse through a[] and for every element check if it is in b[],
//then check if it is already in result or not. If in b[] and not in result, then add it to the result.
//Return result.

/*
import java.util.ArrayList;
import java.util.List;

class GfG {

    // Function to find intersection of two arrays
    static List<Integer> intersection(int[] a, int[] b) {
        List<Integer> res = new ArrayList<>();

        // Traverse through a[] and search every element a[i] in b[]
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b.length; j++) {

                // If found, check if the element is already in the result
                if (a[i] == b[j]) {
                    if (!res.contains(a[i])) {
                        res.add(a[i]);
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] a = {1, 2, 3, 2, 1};
        int[] b = {3, 2, 2, 3, 3, 2};

        List<Integer> res = intersection(a, b);

        for (int val : res) {
            System.out.print(val + " ");
        }
    }
} 
*/

//[Expected Approach 1] - Using Two Hash Sets - O(n+m) Time and O(n) Space
//Initialize an empty array for result
//Create a hash set as (Set of a[] elements) and put all distinct items of a[] into it. For example, if array is {1, 2, 1, 3, 1}, as is going to store [1, 2, 3]
//Create an empty hash set for result rs (Set of result elements)
//Create an empty array res[] to store result
//Traverse through all items of b[]. If an item is in as and not in rs, then add it to res[] and rs
//Return res[]

// import java.util.*;

// class Day45IntersectionOfTwoArrays {
//     static List<Integer> intersection(List<Integer> a, List<Integer> b) {
      
//         // Put all elements of a[] in as
//         Set<Integer> as = new HashSet<>(a);  
      
//         Set<Integer> rs = new HashSet<>();                    
//         List<Integer> res = new ArrayList<>();                            

//         // Traverse through b[]
//         for (int i = 0; i < b.size(); i++) {
          
//             // If the element is in as and not yet in rs
//             // a) Add it to the result set
//             // b) Add it to the result array
//             if (as.contains(b.get(i)) && 
//                 !rs.contains(b.get(i))) {
//                 rs.add(b.get(i)); 
//                 res.add(b.get(i)); 
//             }
//         }

//         return res;
//     }

//     public static void main(String[] args) {
//         List<Integer> a = Arrays.asList(1, 2, 3, 2, 1);
//         List<Integer> b = Arrays.asList(3, 2, 2, 3, 3, 2);

//         List<Integer> res = intersection(a, b);
      
//         for (int i = 0; i < res.size(); i++) 
//             System.out.print(res.get(i) + " ");
//     }
// }

//[Expected Approach 2] Using One Hash Set - O(n+m) Time and O(n) Space
//We optimize the above approach by avoiding creation of rs hash set. 
//To make sure that duplicates are not added, we simply delete items from as (Set of a[] elements) rather than checking with rs.

import java.util.HashSet;
import java.util.ArrayList;
import java.util.List;

class Day45IntersectionOfTwoArrays {

    // Function to find intersection of two arrays
    static List<Integer> intersection(int[] a, int[] b) {
      
        // Put all elements of a[] in sa
        HashSet<Integer> sa = new HashSet<>();
        for (int num : a) {
            sa.add(num);
        }

        List<Integer> res = new ArrayList<>();

        // Traverse through b[]
        for (int num : b) {
          
            // If the element is in sa
            if (sa.contains(num)) {
                res.add(num);          // Add it to the result array
                sa.remove(num);        // Erase it from sa to avoid duplicates
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] a = {1, 2, 3, 2, 1};
        int[] b = {3, 2, 2, 3, 3, 2};

        List<Integer> res = intersection(a, b);

        for (int val : res) {
            System.out.print(val + " ");
        }
    }
}