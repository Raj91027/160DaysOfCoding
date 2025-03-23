/*
Largest Rectangular Area in a Histogram

Given a histogram represented by an array arr[], where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

Task is to find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars whose heights are given in an array.

Example: 

Input: arr[] = [60, 20, 50, 40, 10, 50, 60]
Output: 100
*/

/*
[Naive Approach] By Finding Max Area of Rectangles all Heights - O(n^2) Time and O(1) Space
The idea is to consider each bar as the minimum height and find the maximum area. 
We traverse toward left of it and add its height until we see a smaller element. We do the same thing for right side of it.

So the area with current bar as minimum is going to be height of current bar multiplied by total width 
traversed on both left and right including the current bar. The area is the bar’s height multiplied by the total traversed width. 
Finally, we return the maximum of all such areas.
*/

// C++ program to find the largest rectangular area possible 
// in a given histogram 
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum rectangular
// area in the Histogram
int getMaxArea(vector<int> &arr){
    int res = 0, n = arr.size();
  
    // Consider every bar one by one
    for(int i = 0; i < n; i++){
        int curr = arr[i];
      
        // Traverse left while we have a greater height bar
        for(int j = i-1; j>=0 && arr[j] >= arr[i]; j--)
             curr += arr[i];
      
        // Traverse right while we have a greater height bar      
        for(int j = i+1; j<n && arr[j] >= arr[i]; j++)
            curr += arr[i];
      
        res = max(res, curr);
    }
    return res;
}

int main() { 
    vector<int> arr =  {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr);
    return 0; 
}

/*
[Expected Approach] Precomputing (Using Two Stack) - O(n) Time and O(n) Space
The idea is based on the naive approach. Instead of linearly finding previous smaller and next smaller for every element, we find previous smaller and next smaller for the whole array in linear time.

Build an array prevS[] in O(n) time using stack that holds index of previous smaller element for every item.
Build another array nextS[] in O(n) time using stack that holds index of next smaller element for every item.
Now do following for every element arr[i]. Consider arr[i] find width of the largest histogram with arr[i] being the smallest height. width = nextS[i] - prevS[i] - 1. Now find the area as arr[i] * width.
Return the maximum of all values found in step 3.
*/

// C++ program to find the largest rectangular area possible 
// in a given histogram 

#include <bits/stdc++.h>
using namespace std;

// Function to find next smaller for every element
vector<int> nextSmaller(vector<int>& arr) {
    int n = arr.size();
  
    // Initialize with n for the cases when next smaller
    // does not exist
    vector<int> nextS(n, n);
  
    stack<int> st;
 
    // Traverse all array elements from left to right
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {

            // Setting the index of the next smaller element
            // for the top of the stack
            nextS[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nextS;
}

// Function to find previous smaller for every element
vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
  
    // Initialize with -1 for the cases when prev smaller
    // does not exist
    vector<int> prevS(n, -1);
  
    stack<int> st;
 
    // Traverse all array elements from left to right
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {

            // Setting the index of the previous smaller element
            //  for the top of the stack
            st.pop();
        }
        if (!st.empty()) {
            prevS[i] = st.top();
        }
        st.push(i);
    }
    return prevS;
}

// Function to calculate the maximum rectangular
// area in the Histogram
int getMaxArea(vector<int>& arr) {
    vector<int> prevS = prevSmaller(arr);
    vector<int> nextS = nextSmaller(arr);
    
    int maxArea = 0;

    // Calculate the area for each Histogram bar
    for (int i = 0; i < arr.size(); ++i) {
        int width = nextS[i] - prevS[i] - 1; 
        int area = arr[i] * width;          
        maxArea = max(maxArea, area);        
    }
    
    return maxArea;
}

int main() {
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr) << endl;
    return 0;
}

/*
[Further Optimized] Using Single Stack - O(n) Time and O(n) Space
This approach is mainly an optimization over the previous approach.

When we compute next smaller element, we pop an item from the stack and mark current item as next smaller of it. One important observation here is the item below every item in stack is the previous smaller element. So we do not need to explicitly compute previous smaller.

Below are the detailed steps of implementation.

Create an empty stack.
Start from the first bar, and do the following for every bar arr[i] where 'i' varies from 0 to n-1
If the stack is empty or arr[i] is higher than the bar at top of the stack, then push 'i' to stack. 
If this bar is smaller than the top of the stack, then keep removing the top of the stack while the top of the stack is greater. 
Let the removed bar be arr[tp]. Calculate the area of the rectangle with arr[tp] as the smallest bar. 
For arr[tp], the 'left index' is previous (previous to tp) item in stack and 'right index' is 'i' (current index).
If the stack is not empty, then one by one remove all bars from the stack and do step (2.2 and 2.3) for every removed bar
*/

// C++ program to find the largest rectangular area possible 
// in a given histogram 

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum rectangular area
int getMaxArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    int res = 0;
    int tp, curr;
    for (int i = 0; i < n; i++) {      
         
        while (!s.empty() && arr[s.top()] >= arr[i]) {
          
            // The popped item is to be considered as the 
            // smallest element of the Histogram
            tp = s.top(); 
            s.pop();
          
            // For the popped item previous smaller element is 
            // just below it in the stack (or current stack top)
            // and next smaller element is i
            int width = s.empty() ? i : i - s.top() - 1;
          
            res = max(res,  arr[tp] * width);
        }
        s.push(i);
    }

    // For the remaining items in the stack, next smaller does
    // not exist. Previous smaller is the item just below in
    // stack.
    while (!s.empty()) {
        tp = s.top(); s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }

    return res;
}

int main() {
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr);
    return 0;
}

