/*
The Stock Span Problem

The stock span problem is a financial problem where we have a series of daily price quotes for a stock 
denoted by an array arr[] and the task is to calculate the span of the stock's price for all days. 

The span of the stock's price on ith day represents the maximum number of consecutive days leading up to 
ith day (including the current day) where the stock's price was less than or equal to its price on day i.

Examples:

Input: arr[] = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more elements 
behind it so the span is 1, 80 is greater than equal to 80 and smaller than 100 so the span is 1, 
60 is greater than equal to 60 and smaller than 80 so the span is 1, 70 is greater than equal to 60,70 and smaller 
than 80 so the span is 2 and so on. 
Hence the output will be 1 1 1 2 1 4 6.
*/
/*
[Naive Approach] Using Nested Loop - O(n^2) Time and O(1) Space
The idea is to use nested loops, where the outer loop iterates through the array to process each stock 
price. For each day, the inner loop moves leftward in the array, comparing previous prices and 
increasing the span count until a higher price is found or the beginning of the array is reached.
*/

// C++ program to calculate stock 
// span values
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate stock span values
vector<int> calculateSpan(vector<int>& arr) {

    int n = arr.size(); 
    vector<int> span(n, 1);
    
    // Calculate span for each day
    for (int i = 1; i < n; i++) {
        
        // Traverse left while the next element
        // on the left is smaller than arr[i]
        for (int j = i - 1; (j >= 0)
                      && (arr[i] >= arr[j]); j--) {
            span[i]++;
        }
    }

    return span;
}


int main() {
  
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span = calculateSpan(arr);
    for (int x : span) {
        cout << x << " ";
    }
    return 0;
}


/*
[Expected Approach] Using Stack - O(n) Time and O(n) Space
If we take a closer look at the problem, we can notice that we need to mainly find index of the previous 
greater element for every element. Let us understand in details.

We see that span[i] on the day i can be easily computed if we know the closest day preceding i, 
such that the price is greater than on that day than the price on the day i. 
If such a day exists, let’s call it greater(i), otherwise, we define greater(i) = -1
The span is now computed as span[i] = i - greater(i). See the following diagram

To implement this logic, we use a stack as an abstract data type to store the days i, greater(i), greater(greater(i)), and so on. 
The idea is to use a stack to find the span of stock prices. For each day, we remove indices from 
the stack while the current price is greater than or equal to the price at the top of the stack, as those day's prices cannot influence the span.

If the stack becomes empty, it means all previous prices are smaller, and the span is the current day index plus one.
Otherwise, the span is the difference between the current index and the top of the stack, which represents the last higher price's index.
*/

// C++ program to calculate stock span 
// values using a stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate stock span values
vector<int> calculateSpan(vector<int>& arr) {

    int n = arr.size(); 
    vector<int> span(n);  
    stack<int> stk;  

    // Process each day's price
    for (int i = 0; i < n; i++) {
        
        // Remove elements from the stack while the current
        // price is greater than or equal to stack's top price
        while (!stk.empty() && arr[stk.top()] <= arr[i]) {
            stk.pop();
        }

        // If stack is empty, all elements to the left are smaller
        // Else, top of the stack is the last greater element's index
        if (stk.empty()) {
            span[i] = (i + 1);
        }
        else {
            span[i] = (i - stk.top());
        }

        // Push the current index to the stack
        stk.push(i);
    }

    return span;
}

int main() {
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span = calculateSpan(arr);
     for (int x : span) {
        cout << x << " ";
    }
    return 0;
}