package Hashing;

/*
 3 Sum - Find All Triplets with Zero Sum

Given an array arr[], the task is to find all possible indices {i, j, k} of triplet {arr[i], arr[j], arr[k]} 
such that their sum is equal to zero and all indices in a triplet should be distinct (i != j, j != k, k != i). 
We need to return indices of a triplet in sorted order, i.e., i < j < k.

Examples :

Input: arr[] = {0, -1, 2, -3, 1}
Output: {{0, 1, 4}, {2, 3, 4}}
Explanation:  Two triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
 */

 /*
  
 // Java program to find triplet having sum zero using 
// three nested loops

import java.util.ArrayList;
import java.util.List;

class GfG {
    static ArrayList<ArrayList<Integer>> findTriplets(int[] arr) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        int n = arr.length;

        // Generating all triplets
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                  
                    // If the sum of triplet equals to zero
                    // then add it's indexes to the result
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        ArrayList<Integer> triplet = new ArrayList<>();
                        triplet.add(i);
                        triplet.add(j);
                        triplet.add(k);
                        res.add(triplet);
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {0, -1, 2, -3, 1};
        ArrayList<ArrayList<Integer>> res = findTriplets(arr);
        for (List<Integer> triplet : res) 
            System.out.println(triplet.get(0) + " " + triplet.get(1)
                                                 + " " + triplet.get(2));
    }
}
  */


/*
[Expected Approach] Using Hashing - O(n^3) Time and O(n^2) Space
The idea is to store sum of all the pairs with their indices the hash map. 
Then, for each element in the array, we check if the pair which makes triplet's sum zero, 
exists in the hash map or not. Since there can be multiple valid pairs, 
we add each one to the hash set (to manage duplicates) while ensuring that all indices in the triplet are distinct.

In the worst case, this approach also takes O(n^3) time but in the average case, 
it is much faster than Naive approach as we are iterating over only those triplets whose sum is equal to target.
 */

 // Java program to find all triplets with zero sum using hashing

import java.util.*;

class GfG {
    static ArrayList<ArrayList<Integer>> findTriplets(int[] arr) {
        
        // Set to handle duplicates
        Set<ArrayList<Integer>> resSet = new HashSet<>();
        int n = arr.length;
        Map<Integer, List<int[]>> mp = new HashMap<>();

        // Store sum of all the pairs with their indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp.computeIfAbsent(arr[i] + arr[j], 
                              k -> new ArrayList<>()).add(new int[]{i, j});
            }
        }

        for (int i = 0; i < n; i++) {
            
            // Find remaining value to get zero sum
            int rem = -arr[i];
            if (mp.containsKey(rem)) {
                List<int[]> pairs = mp.get(rem);
                for (int[] p : pairs) {
                    
                    // Ensure no two indices are same in triplet
                    if (p[0] != i && p[1] != i) {
                        ArrayList<Integer> curr = 
                          new ArrayList<>(Arrays.asList(i, p[0], p[1]));
                        Collections.sort(curr);
                        resSet.add(curr);
                    }
                }
            }
        }
        return new ArrayList<>(resSet);  
    }

    public static void main(String[] args) {
        int[] arr = {0, -1, 2, -3, 1};
        ArrayList<ArrayList<Integer>> res = findTriplets(arr);
        for (ArrayList<Integer> triplet : res) {
            System.out.println(triplet.get(0) + " " + 
                               triplet.get(1) + " " + triplet.get(2));
        }
    }
}