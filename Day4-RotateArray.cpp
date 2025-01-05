/*
Given an array arr[]. 
Rotate the array to the left (counter-clockwise direction) by d steps, 
where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.

*/


//Approach - 1: 

// C++ Program to left rotate the array by d positions
// using temporary array

#include <bits/stdc++.h>
using namespace std;

// Function to rotate vector
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();

    // Handle case when d > n
    d %= n;
  
    // Storing rotated version of array
    vector<int> temp(n);

    // Copy last n - d elements to the front of temp
    for (int i = 0; i < n - d; i++)
        temp[i] = arr[d + i];

    // Copy the first d elements to the back of temp
    for (int i = 0; i < d; i++)
        temp[n - d + i] = arr[i];

    // Copying the elements of temp in arr
    // to get the final rotated vector
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;

    rotateArr(arr, d);

    // Print the rotated vector
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}