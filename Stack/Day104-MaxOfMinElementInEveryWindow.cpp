/*
Maximum of minimums of every window size in a given array

Given an integer array arr[] of size n, the task is to find the maximum of the minimums for every window size in the given array, where the window size ranges from 1 to n.

Example:

Input: arr[] = [10, 20, 30]
Output: [30, 20, 10]
Explanation:
First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10], [20], [30]. Maximum of these minimums are 30 and similarly other outputs can be computed

Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10]
Explanation: The first element in the output indicates the maximum of minimums of all windows of size 1. 
Minimums of windows of size 1 are [10], [20], [30], [50], [10], [70] and [30]. 
Maximum of these minimums is 70
The second element in the output indicates the maximum of minimums of all windows of size 2. 
Minimums of windows of size 2 are [10], [20], [30], [10], [10], and [30]. 
Maximum of these minimums is 30
The third element in the output indicates the maximum of minimums of all windows of size 3. 
Minimums of windows of size 3 are [10], [20], [10], [10] and [10]. 
Maximum of these minimums is 20
Similarly, other elements of output are computed. 
*/

//[Naive Approach] - O(n^3) Time and O(1) Space
//The idea is to calculate the minimum of every window separately and print the maximum of each window size.

// C++ program to find the maximum of the minimums 
// for every window size in the array

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, 0);

    // Consider all windows of different 
    // sizes starting from size 1
    for (int k = 1; k <= n; k++) {
      
        // Initialize max of min for current window size k
        int maxOfMin = INT_MIN;

        // Traverse through all windows of current size k
        for (int i = 0; i <= n - k; i++) {
          
            // Find minimum of current window
            int minVal = arr[i];
            for (int j = 1; j < k; j++) {
                if (arr[i + j] < minVal)
                    minVal = arr[i + j];
            }

            // Update maxOfMin if required
            if (minVal > maxOfMin)
                maxOfMin = minVal;
        }

        // Store max of min for current window size
        res[k - 1] = maxOfMin;
    }

    return res;
}

int main() {
    vector<int> arr = { 10, 20, 30, 50, 10, 70, 30 };
    vector<int> res = maxOfMins(arr);
    for (int x : res)
        cout << x << " ";
    return 0;
}

// Output: 70 30 20 10 10 10 10

/*
[Expected Approach] Using Stack - O(n) Time and O(n) Space
The idea is to find the next smaller and previous smaller of each element and update the maximum of window with size as the difference in their indices. This problem is mainly a variation of Largest Area in a Histogram.

Below is the implementation of the above approach:

Initialize res[] to store maximum minimums and len[] to store window sizes. Use a stack s for efficient processing.
Traverse the array to determine window sizes. For each element, pop larger or equal elements from the stack, calculate their window sizes, and update len[]. Push the current index onto the stack.
Process remaining stack elements to determine their window sizes using the right boundary.
Populate res[] using len[] and arr[], storing the maximum minimum for each window size.
Update res[] to ensure values correctly reflect the maximum of the minimums.
Return res[], containing the maximum of minimums for every window size.
*/

// C++ program to find the maximum of the minimums 
// for every window size in the array

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, 0); 
    stack<int> s;

    // Array to store the length of the window 
    // where each element is the minimum
    vector<int> len(n, 0);

    // Traverse through array to determine 
    // window sizes using a stack
    for (int i = 0; i < n; i++) {
      
        // Process elements to find next smaller 
        // element on the left
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            int top = s.top();
            s.pop();
            int windowSize = s.empty() ? i : i - s.top() - 1;
            len[top] = windowSize;
        }
        s.push(i);
    }

    // Process remaining elements in the stack
    // for right boundaries
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int windowSize = s.empty() ? n : n - s.top() - 1;
        len[top] = windowSize;
    }

    // Fill res[] based on len[] and arr[]
    for (int i = 0; i < n; i++) {
        int windowSize = len[i] - 1;  // 0-based indexing
        res[windowSize] = max(res[windowSize], arr[i]);
    }

    // Fill remaining entries in res[] to ensure 
    // all are max of min
    for (int i = n - 2; i >= 0; i--)
        res[i] = max(res[i], res[i + 1]);

    return res;
}

int main() {
    vector<int> arr = { 10, 20, 30, 50, 10, 70, 30 };
    vector<int> res = maxOfMins(arr);
    for (int x : res)
        cout << x << " ";
    return 0;
}

// Output: 70 30 20 10 10 10 10
// Explanation:
// The first element in the output indicates the maximum of minimums of all windows of size 1.
// Minimums of windows of size 1 are [10], [20], [30], [50], [10], [70] and [30].
// Maximum of these minimums is 70
// The second element in the output indicates the maximum of minimums of all windows of size 2.
// Minimums of windows of size 2 are [10], [20], [30], [10], [10], and [30].
// Maximum of these minimums is 30
// The third element in the output indicates the maximum of minimums of all windows of size 3.
// Minimums of windows of size 3 are [10], [20], [10], [10] and [10].
// Maximum of these minimums is 20
// Similarly, other elements of output are computed.
// The output is the maximum of minimums for every window size in the given array.
// The time complexity of this approach is O(n) and the space complexity is O(n).
// This is an efficient solution to the problem, and it uses a stack to keep track of the indices of the elements in the array.
// The stack is used to find the next smaller and previous smaller elements for each element in the array.
// This allows us to calculate the window sizes efficiently.
// The final result is stored in the res[] array, which contains the maximum of minimums for every window size.
// The output is printed in the main function, showing the maximum of minimums for each window size.
