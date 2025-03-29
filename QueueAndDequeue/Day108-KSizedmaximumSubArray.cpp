/*
Sliding Window Maximum (Maximum of all subarrays of size K)

Given an array arr[] of integers and an integer k, your task is to find the maximum value for each contiguous subarray of size k. The output should be an array of maximum values corresponding to each contiguous subarray.

Examples : 

Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
Output: [3, 3, 4, 5, 5, 5, 6]
Explanation:
1st contiguous subarray = [1 2 3] max = 3
2nd contiguous subarray = [2 3 1] max = 3
3rd contiguous subarray = [3 1 4] max = 4
4th contiguous subarray = [1 4 5] max = 5
5th contiguous subarray = [4 5 2] max = 5
6th contiguous subarray = [5 2 3] max = 5
7th contiguous subarray = [2 3 6] max = 6

Input: arr[] = [5, 1, 3, 4, 2, 6], k = 1
Output: [5, 1, 3, 4, 2, 6]
Explanation: When k = 1, each element in the array is its own subarray, so the output is simply the same array.

Input: arr[] = [1, 3, 2, 1, 7, 3], k = 3
Output: [3, 3, 7, 7]
*/

#include <iostream>
#include <vector>
using namespace std;

// Method to find the maximum for each
// and every contiguous subarray of size k.
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();

    // to store the results
    vector<int> res;
  
    for (int i = 0; i <= n - k; i++) {
      
        // Find maximum of subarray beginning
        // with arr[i]
        int max = arr[i];
        for (int j = 1; j < k; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        res.push_back(max);
    }
  
    return res;
}

int main() {
    vector<int> arr = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    return 0;
}

/*
[Better Approach] - Using Max-Heap - (n * log n) Time and O(n) Space
The idea is to use priority queue or heap data structure to make sure that heap has largest item of the current window.

Create a max heap of the first k items
Now iterate one by one. While the next item to be added is greater than the heap top, remove the top. 
We mainly make sure that the greater items of the previous window are not there in a heap.
*/

#include <bits/stdc++.h>
using namespace std;

// Method to find the maximum for each
// and every contiguous subarray of size k.
vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
    int n = arr.size();

    // to store the results
    vector<int> res;

    // to store the max value
    priority_queue<pair<int, int> > heap;

    // Initialize the heap with the first k elements
    for (int i = 0; i < k; i++)
        heap.push({ arr[i], i });

    // The maximum element in the first window
    res.push_back(heap.top().first);

    // Process the remaining elements
    for (int i = k; i < arr.size(); i++) {

        // Add the current element to the heap
        heap.push({ arr[i], i });

        // Remove elements that are outside the current
        // window
        while (heap.top().second <= i - k)
            heap.pop();

        // The maximum element in the current window
        res.push_back(heap.top().first);
    }

    return res;
}

int main() {
    vector<int> arr = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    return 0;
}

/*
[Expected Approach] - Using Deque - O(n) Time and O(k) Space
Create a Deque, dq of capacity k, that stores only useful elements of current window of k elements. 
An element is useful if it is in current window and is greater than all other elements on right side of it in current window. 
Process all array elements one by one and maintain dq to contain useful elements of current window and these useful elements are maintained in sorted order. 
The element at front of the dq is the largest and element at rear/back of dq is the smallest of current window.

Step-by-Step Algorithm:

Create a deque to store only useful elements of current window.
Run a loop and insert the first k elements in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Now, run a loop from k to the end of the array.
Print the front element of the deque.
Remove the element from the front of the queue if they are out of the current window.
Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Print the maximum element of the last window.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> maxi(k);
        vector<int> ans;
        
        for(int i=0; i<k; i++){

            while(!maxi.empty() && arr[maxi.back()] <= arr[i])
                maxi.pop_back();
    
            maxi.push_back(i);
        }
        
        ans.push_back(arr[maxi.front()]);
        
        for(int i=k; i<n; i++){
            //Next window
            //removal 
            while(!maxi.empty() && i - maxi.front() >=k) {
                maxi.pop_front();
            }
    
            
            //addition
            while(!maxi.empty() && arr[maxi.back()] <= arr[i])
                maxi.pop_back();
    
            
    
            maxi.push_back(i);
            
    
            ans.push_back(arr[maxi.front()]);
        }
        
        return ans;
        
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends