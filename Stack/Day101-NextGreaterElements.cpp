/*Next Greater Element (NGE) for every element in given Array

Given an array arr[] of integers, the task is to find the Next Greater Element for each element of the array in order of their appearance in the array.
Note: The Next Greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 

Examples: 

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
*/


/*
[Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space
The idea is to look at all the elements to its right and check if there's a larger element for each element in the array. 
If we find one, we store it as the next greater element. If no greater element is found, we store -1. 
This is done using two nested loops: the outer loop goes through each element, 
and the inner loop searches the rest of the array for a greater element.
*/

// C++ implementation to find the next
// greater element using two loops
#include <iostream>
#include <vector>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {

        // Check for the next greater element
        // in the rest of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }

    return res;
}


int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    
    vector<int> res = nextLargerElement(arr);
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}

//  

/*
[Expected Approach] Using Stack - O(n) Time and O(n) Space
The idea is to use stack to find the next greater element by using the Last-In-First-Out (LIFO) property. 
We traverse the array from right to left. For each element, we remove elements from the stack that are smaller than or equal to it, 
as they cannot be the next greater element. If the stack is not empty after this, the top element of 
the stack is the next greater element for the current element. We then push the current element onto the stack.


*/

// C++ implementation to find the next
// greater element using a stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop elements from the stack that are less
        // than or equal to the current element
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }

        // If the stack is not empty, the top element
        // is the next greater element
        if (!stk.empty()) {
            res[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return res;
}

int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextLargerElement(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}