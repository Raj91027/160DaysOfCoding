//Count Subarrays with given XOR
package Hashing;

//Given an array of integers arr[] and a number k, the task is to count the number of subarrays having XOR of their elements as k.

/*Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6].

Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9].
*/

/*
 // Java Program to count all subarrays having
// XOR of elements as given value K
class GfG {
  
    // Function to find count of subarrays of arr 
      // with XOR value equals to K
    static int subarrayXor(int[] arr, int k) {
        int res = 0;

        // Pick starting point i of subarrays
        for (int i = 0; i < arr.length; i++) {
            int prefXOR = 0;

            // Pick ending point j of subarray for each i
            for (int j = i; j < arr.length; j++) {
                // calculate prefXOR for subarray arr[i ... j]
                prefXOR = prefXOR ^ arr[j];

                // If prefXOR is equal to given value, increase res by 1
                if (prefXOR == k)
                    res++;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = { 4, 2, 2, 6, 4 };
        int k = 6;

        System.out.println(subarrayXor(arr, k));
    }
}
 */

 /*
[Efficient Approach] Using Hash Map and Prefix Sum - O(n) Time and O(n) Space
The idea is to use the properties of XOR. Let’s denote the XOR of all elements in the range [0, i] as A, 
the XOR of all elements in the range [i+1, j] as B, and the XOR of all elements in the range [0, j] as C.

From the properties of XOR: C = A ⊕ B
This implies: A = C ⊕ B

Now if we know the value of C (the XOR of the prefix up to index j) and have B (the target XOR value k), 
we can determine A (the XOR of the prefix up to index i) using: A = C ⊕ B

Using this relation, if a prefix sum A has already been seen earlier, 
it means there exists a subarray ending at j whose XOR is equal to k (B).

Step by step Approach:

Use a hash map to store the frequency of prefix XOR values encountered so far.
Traverse through the array and for each element at index i:
Update prefXOR = prefXOR ⊕ arr[i].
Check if A = prefXOR ⊕ k exists in the hash map. If it does, add the value of the hash map entry to result as 
it gives the count of subarrays ending at the current index that have XOR equal to k.
If prefXOR is equal to k, increment the result directly, as this indicates the subarray arr[0, i] has XOR equal to k.
Update the hash map to include the current prefXOR value.
Count-the-number-of-sub-arrays-having-a-given-XOR-1.webp
  */

  // Java Program to count all subarrays having
// XOR of elements as given value K using Hash Map
import java.util.HashMap;

class GfG {
    // Function to find the count of subarrays of arr
    // with XOR value equals to k
    static int subarrayXor(int[] arr, int k) {
        int res = 0;

        // Create map that stores number of prefix arrays
        // corresponding to a XOR value
        HashMap<Integer, Integer> mp = new HashMap<>();

        int prefXOR = 0;

        for (int val : arr) {
          
            // Find XOR of current prefix
            prefXOR ^= val;

            // If prefXOR ^ k exists in mp then there is a subarray
            // ending at i with XOR equal to k
            res += mp.getOrDefault(prefXOR ^ k, 0);

            // If this prefix subarray has XOR equal to k
            if (prefXOR == k)
                res++;

            // Add the XOR of this subarray to the map
            mp.put(prefXOR, mp.getOrDefault(prefXOR, 0) + 1);
        }

        // Return total count of subarrays having XOR of
        // elements as given value k
        return res;
    }

    public static void main(String[] args) {
        int[] arr = { 4, 2, 2, 6, 4 };
        int k = 6;

        System.out.println(subarrayXor(arr, k));
    }
}