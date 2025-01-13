/*
Find Smallest Missing Positive Number

Given an unsorted array arr[] with both positive and negative elements, 
the task is to find the smallest positive number missing from the array.

Note: You can modify the original array.

Examples:

Input: arr[] = {2, -3, 4, 1, 1, 7}
Output: 3
Explanation: 3 is the smallest positive number missing from the array.

Input: arr[] = {5, 3, 2, 5, 1}
Output: 4
Explanation: 4 is the smallest positive number missing from the array.

Input: arr[] = {-8, 0, -1, -4, -3}
Output: 1
Explanation: 1 is the smallest positive number missing from the array.
*/

/*
[Naive approach] By Sorting - O(n*log n) Time and O(n) Space
The idea is to sort the array and assume the missing number as 1. Now, iterate over the array and for each element arr[i],

If arr[i] == missing number, then increment missing number by 1.
If arr[i] < missing number, then continue to search for the missing number.
If arr[i] > missing number, then break and return the missing number

*/

// C++ program to find the first positive missing number 
// using Sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the first positive missing number
int missingNumber(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int res = 1;
    for (int i = 0; i < arr.size(); i++) {

        // If we have found 'res' in the array,
        // 'res' is no longer missing, so increment it
        if (arr[i] == res) 
            res++;

        // If the current element is larger than 'res',
        // 'res' cannot be found in the array,
        // so it is our final answer
        else if (arr[i] > res) 
            break;
    }
    return res;
}

int main() {
    vector<int> arr = {2, -3, 4, 1, 1, 7};

    cout << missingNumber(arr);
    return 0;
}

/*
[Better approach] Using Visited Array - O(n) Time and O(n) Space
The idea is to create a visited array, to keep track of which numbers from the original array were present. 
For each positive number in the input array, we mark its corresponding position in the visited array. 
After that, we go through the visited array to find the first position that isn’t visited. 
The first unvisited index tells us the first missing positive number.
Note that we are marking numbers within the range from 1 to n only.
*/

// C++ program to find the first missing positive number 
// using visited array

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &arr) {
    int n = arr.size();

    // To mark the occurrence of elements
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {

        // if element is in range from 1 to n
        // then mark it as visited
        if (arr[i] > 0 && arr[i] <= n)
            vis[arr[i] - 1] = true;
    }

    // Find the first element which is unvisited
    // in the original array
    for (int i = 1; i <= n; i++) {
        if (!vis[i - 1]) {
            return i;
        }
    }

    // if all elements from 1 to n are visited
    // then n + 1 will be first positive missing number
    return n + 1;
}

int main() {

    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr);
}

/*
[Expected Approach] Using Cycle Sort - O(n) Time and O(1) Space
The idea is similar to Cycle Sort and move each element in the array to its correct position based on its value. 
So for each number, say x, such that 1 <= x <= n, is placed at the (x - 1)th index.

Finally, iterate through the array and check if the numbers are in the expected indexes or not. 
The first place where the number doesn’t match its index gives us the first missing positive number. 
If all the numbers from 1 to n, are at their correct indexes, then the next number i.e., n + 1, is the smallest missing positive number.
*/

// C++ program to find the first missing positive number 
// using cycle sort

#include <iostream>
#include <vector>
using namespace std;

// Function for finding the first missing positive number
int missingNumber(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {

        // if arr[i] is within range [1, n] and arr[i] is
        // not placed at (arr[i]-1)th index in arr
        while (arr[i] >= 1 && arr[i] <= n
               && arr[i] != arr[arr[i] - 1]) {
                   
            // then swap arr[i] and arr[arr[i]-1]
            // to place arr[i] to its corresponding index
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // If any number is not at its corresponding index 
    // then it is the missing number
    for (int i = 1; i <= n; i++) {
        if (i != arr[i-1]) {
            return i;
        }
    }

    // If all number from 1 to n are present 
    // then n + 1 is smallest missing number
    return n + 1;
}

int main() {
    
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr);
    return 0;
}