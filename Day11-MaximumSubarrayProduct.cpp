/*
Maximum Product Subarray

Given an integer array, the task is to find the maximum product of any subarray.

Examples:

Input: arr[] = {-2, 6, -3, -10, 0, 2}
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180

Input: arr[] = {-1, -3, -10, 0, 60}
Output: 60
Explanation: The subarray with maximum product is {60}.

*/

/*
[Naive Approach] By using two nested loops – O(n^2) Time and O(1) Space
The idea is to traverse over every contiguous subarray, 
find the product of each of these subarrays and return the maximum product among all the subarrays.
*/
// C++ program to find Maximum Product Subarray 
// using nested loops

#include <bits/stdc++.h>
using namespace std;

// Function to return the product of max product subarray
int maxProduct(vector<int> &arr) {
    int n = arr.size();
  
    // Initializing result
    int result = arr[0];

    for (int i = 0; i < n; i++) {
        int mul = 1;
      
        // traversing in current subarray
        for (int j = i; j < n; j++) {
              mul *= arr[j];
          
            // updating result every time
            // to keep track of the maximum product
            result = max(result, mul);
        }
    }
    return result;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}

/*

[Expected Approach 1] Using minimum and maximum product ending at any index - O(n) Time and O(1) Space
Let's assume that the input array has only positive elements. Then, we can simply iterate from left to right keeping track of 
the maximum running product ending at any index. 
The maximum product would be the product ending at the last index. The problem arises when we encounter zero or a negative element.

If we encounter zero, then all the subarrays containing this zero will have product = 0, so zero simply resets the product of the subarray.
If we encounter a negative number, we need to keep track of the minimum product as well as the maximum product ending at the previous index. 
This is because when we multiply the minimum product with a negative number, it can give us the maximum product. 
So, keeping track of minimum product ending at any index is important as it can lead to the maximum product on encountering a negative number.
Step-by-step algorithm:

Create 3 variables, currMin, currMax and maxProd initialized to the first element of the array.
Iterate the indices 0 to N-1 and update the variables:
currMax = maximum(arr[i], currMax * arr[i], currMin * arr[i])
currMin= minimum(arr[i], currMax * arr[i], currMin * arr[i])
update the maxProd with the maximum value for each index.
Return maxProd as the result.

*/

// C++ program to find Maximum Product Subarray using Minimum
// and Maximum Product ending at every index

#include <bits/stdc++.h>
using namespace std;

// function to find the product of max product subarray
int maxProduct(vector<int> &arr) {
      int n = arr.size();
  
    // max product ending at the current index
    int currMax = arr[0];

    // min product ending at the current index
    int currMin = arr[0];

    // Initialize overall max product
    int maxProd = arr[0];
  
    // Iterate through the array 
    for (int i = 1; i < n; i++) {
          
          // Temporary variable to store the maximum product ending 
          // at the current index
        int temp = max({ arr[i], arr[i] * currMax,
                                            arr[i] * currMin });
        
          // Update the minimum product ending at the current index
          currMin = min({ arr[i], arr[i] * currMax,
                                            arr[i] * currMin });
      
          // Update the maximum product ending at the current index
        currMax = temp;
      
          // Update the overall maximum product
        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}


/*
[Expected Approach 2] By traversing in both directions - O(n) Time and O(1) Space
We will follow a simple approach that is to traverse from the start and keep track of 
the running product and if the running product is greater than the max product, 
then we update the max product. Also, if we encounter '0' then make product of all 
elements till now equal to 1 because from the next element, we will start a new subarray.

But what is the problem with this approach?

Problem will occur when our array will contain odd no. of negative elements. 
In that case, we have to reject one negative element so that we 
can even no. of negative elements and their product can be positive. 
Now, since subarray should be contiguous so we can't simply reject 
any one negative element. We have to either reject the first negative element or the last negative element.

Now, if we traverse from start then only the last negative element can be rejected and 
if we traverse from the last then the first negative element can be rejected. So we will 
traverse from both ends and find the maximum product subarray.
*/

// C++ program to find Maximum Product Subarray using 
// Traversal From Starting and End of an Array

#include <bits/stdc++.h>
using namespace std;

// function to find the product of max product subarray.
int maxProduct(vector<int> &arr) {
      int n = arr.size();
    int maxProd = INT_MIN;
  
    // leftToRight to store product from left to Right
    int leftToRight = 1;
  
    // rightToLeft to store product from right to left
    int rightToLeft = 1;
  
    for (int i = 0; i < n; i++) {
        if (leftToRight == 0)
            leftToRight = 1;
        if (rightToLeft == 0)
            rightToLeft = 1;
      
        // calculate product from index left to right
        leftToRight *= arr[i];
      
        // calculate product from index right to left
        int j = n - i - 1;
        rightToLeft *= arr[j];
        maxProd = max({leftToRight, rightToLeft, maxProd});
    }
    return maxProd;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}