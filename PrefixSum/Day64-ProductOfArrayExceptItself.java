package PrefixSum;

/*
 * 
 Product of Array Except Self

Given an array arr[] of n integers, construct a product array res[] (of the same size) such that res[i] 
is equal to the product of all the elements of arr[] except arr[i]. 

Example: 

Input: arr[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation:

For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.
 */
//[Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space
//The idea is simple, for every element arr[i], we compute product of all elements except itself. 
//To compute the product, we run an inner loop.

/*
 * 
import java.util.Arrays;
class GfG {
    
      // Function to calculate the product of all 
    // elements except the current element
    static int[] productExceptSelf(int[] arr) {
        int n = arr.length;

        // Initialize the result array as 1
        int[] res = new int[n];
        Arrays.fill(res, 1);
        for (int i = 0; i < n; i++) {

            // Compute the product of all except arr[i]
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    res[i] *= arr[j];
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {10, 3, 5, 6, 2};
        int[] res = productExceptSelf(arr);
        for (int val : res) {
            System.out.print(val + " ");
        }
    }
}
 */

 /*
  * 
[Better approach] Using Prefix and Suffix Array - O(n) Time and O(n) Space
The above approach can be optimized by avoiding the repetitive calculation of products of elements. 
The idea is to precompute the prefix and suffix products and store them in two arrays. 
Now we can find the product of array except i-th element, by using these precomputed arrays in constant time.

product of array except i-th element = prefProduct[i] * suffProduct[i]

prefProduct[i] stores product of all elements before i-th index in the array.
suffProduct[i] stores product of all elements after i-th index in the array.



import java.util.Arrays;

class GfG {
  
    // Function to calculate the product of all
    // elements except the current element
    static int[] productExceptSelf(int[] arr) {
        int n = arr.length;
        int[] prefProduct = new int[n];
        int[] suffProduct = new int[n];
        int[] res = new int[n];

        // Construct the prefProduct array
        prefProduct[0] = 1;
        for (int i = 1; i < n; i++)
            prefProduct[i] = arr[i - 1] * prefProduct[i - 1];

        // Construct the suffProduct array
        suffProduct[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--)
            suffProduct[j] = arr[j + 1] * suffProduct[j + 1];

        // Construct the result array using
        // prefProduct[] and suffProduct[]
        for (int i = 0; i < n; i++)
            res[i] = prefProduct[i] * suffProduct[i];

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {10, 3, 5, 6, 2};
        int[] res = productExceptSelf(arr);

        System.out.println(Arrays.toString(res));
    }
}
  */

  /*
   * 
[Efficient Approach] Using Product Array - O(n) Time and O(1) Space
The idea is to handle two special cases of the input array: when it contains zero(s) and when it doesn't.

If the array has no zeros, product of array at any index (excluding itself) can be calculated by 
dividing the total product of all elements by the current element.

However, division by zero is undefined, so if there are zeros in the array, the logic changes. 
If there is exactly one zero, the product for that index will be the product of all other non-zero elements,
 while the elements in rest of the indices will be zero.
If there are more than one zero, the product for all indices will be zero, since multiplying by zero results in zero.
   */

   import java.util.Arrays;

   class GfG {
     
       // Function to calculate the product of all elements 
       // except the current element
       static int[] productExceptSelf(int[] arr) {
           int zeros = 0, idx = -1, prod = 1;
           int n = arr.length;
   
           // Count zeros and track the index of the zero
           for (int i = 0; i < n; i++) {
               if (arr[i] == 0) {
                   zeros++;
                   idx = i;
               } else {
                   prod *= arr[i];
               }
           }
   
           int[] res = new int[n];
           Arrays.fill(res, 0);
   
           // If no zeros, calculate the product for all elements
           if (zeros == 0) {
               for (int i = 0; i < n; i++) 
                   res[i] = prod / arr[i];
           }
           // If one zero, set product only at the zero's index
           else if (zeros == 1)
               res[idx] = prod;
   
           return res;
       }
   
       public static void main(String[] args) {
           int[] arr = {10, 3, 5, 6, 2};
           int[] res = productExceptSelf(arr);
   
           for (int val : res)
               System.out.print(val + " ");
       }
   }