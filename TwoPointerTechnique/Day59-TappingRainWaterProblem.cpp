/*
Trapping Rain Water Problem - Tutorial with Illustrations

Trapping Rainwater Problem states that given an array of n 
non-negative integers arr[] representing an elevation map 
where the width of each bar is 1, compute how much water it can trap after rain.
Examples:  

Input: arr[] = [3, 0, 1, 0, 4, 0, 2]
Output: 10

Observations
The basic intuition of the problem is as follows:

An element of the array can store water if there are higher bars on the left and the right. 
The amount of water to be stored in every position can be found by finding the heights of the higher bars on the left and right sides. 
The total amount of water stored is the summation of the water stored in each index.
No water can be filled if there is no boundary on both sides.


[Naive Approach] Find left and right max for each index - O(n^2) Time and O(1) Space
Traverse every array element and find the highest bars on the left and right sides. 
Take the smaller of two heights. The difference between the smaller height and the height of the 
current element is the amount of water that can be stored in this array element.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to return the maximum water that can be stored
int maxWater(vector<int>& arr) {
    int res = 0;

    // For every element of the array
    for (int i = 1; i < arr.size() - 1; i++) {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res += (min(left, right) - arr[i]);
    }

    return res;
}

int main() {
    vector<int> arr = { 2, 1, 5, 3, 1, 0, 4 };
    cout << maxWater(arr);
    return 0;
}

/*
[Better Approach] Prefix and suffix max for each index - O(n) Time and O(n) Space
In the previous approach, for every element we needed to calculate the highest element on the left and on the right. 

So, to reduce the time complexity: 

For every element we first calculate and store the highest bar on the left and on the right (say stored in arrays left[] and right[]). 
Then iterate the array and use the calculated values to find the amount of water stored in this index, 
which is the same as ( min(left[i], right[i]) - arr[i] )
*/

#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int>& arr) {
    int n = arr.size();

    // Left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    vector<int> left(n);

    // Right[i] contains height of tallest bar to
    // the right of i'th bar including itself
    vector<int> right(n);

    int res = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element
    for (int i = 1; i < n - 1; i++) {
        int minOf2 = min(left[i - 1], right[i + 1]);
        if (minOf2 > arr[i]) {
            res += minOf2 - arr[i];
        }
    }

    return res;
}

int main() {
    vector<int> arr = { 2, 1, 5, 3, 1, 0, 4 };
    cout << maxWater(arr);
    return 0;
}

/*
[Expected Approach] Using Two Pointers - O(n) Time and O(1) Space
The approach is mainly based on the following facts:

If we consider a subarray arr[left...right], we can decide the amount of water either for arr[left] or arr[right] if we know the left max (max element in arr[0...left-1]) and right max (max element in arr[right+1...n-1].
If left max is less than the right max, then we can decide for arr[left]. Else we can decide for arr[right]
If we decide for arr[left], then the amount of water would be left max - arr[left] and if we decide for arr[right], then the amount of water would be right max - arr[right].
How does this work? Let us consider the case when left max is less than the right max. For arr[left], we know left max for it and we also know that the right max for it would not be less than left max because we already have a greater value in arr[right...n-1]. So for the current bar, we can find the amount of water by finding the difference between the current bar and the left max bar.


*/
#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int> &arr) { 
    int left = 1;
    int right = arr.size() - 2;

    // lMax : Maximum in subarray arr[0..left-1]
    // rMax : Maximum in subarray arr[right+1..n-1]
    int lMax = arr[left - 1];
    int rMax = arr[right + 1];

    int res = 0;
    while (left <= right) {
      
        // If rMax is smaller, then we can decide the amount of water for arr[right]
        if (rMax <= lMax) {
          
            // Add the water for arr[right]
            res += max(0, rMax - arr[right]);

            // Update right max
            rMax = max(rMax, arr[right]);

            // Update right pointer as we have decided the amount of water for this
            right -= 1;
        } else { 
            // Add the water for arr[left]
            res += max(0, lMax - arr[left]);

            // Update left max
            lMax = max(lMax, arr[left]);

            // Update left pointer as we have decided water for this
            left += 1;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr) << endl;
    return 0;
}

/*
One important observation here is the item below every item in stack is the previous greater element. So for every element, we can compute both previous greater and next greater in one traversal and a stack. Now you must be wondering that for the trapping rain water problem, we need greatest on right and left (not closest greater). Please pause reading for a moment and think how we can use next greater and previous greater for finding the amount of water.

As discussed above, the idea is to find next greater and previous greater for every element using a stack and single traversal.
When we have valid next greater and previous greater, we know for sure that we need to fill water between next greater and previous greater. We know a minimum amount also, so we fill the known amount. And when we consider previous greater and next greater we find their next and previous greater, and fill some more amount. We do this until we find next greatest and previous greatest.
We do not fill the exact amount in a go and we also do not necessarily fill one by one, we fill all between next greater and previous greater.



*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to return the maximum water that can be stored
int maxWater(vector<int>& arr) {
    stack<int> st;  
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
       
        // Pop all items smaller than arr[i]
        while (!st.empty() && arr[st.top()] < arr[i]) {          
            
            int pop_height = arr[st.top()];
            st.pop();
          
            if (st.empty())
                break;

            // arr[i] is the next greater for the removed item
            // and new stack top is the previous greater 
            int distance = i - st.top() - 1;
          
            // Take the minimum of two heights (next and prev greater)
            // and find the amount of water that we can fill in all
            // bars between the two
            int water = min(arr[st.top()], arr[i]) - pop_height;

            res += distance * water;
        }
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr);
    return 0;
}