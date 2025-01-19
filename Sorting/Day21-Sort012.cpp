/*
Sort an array of 0s, 1s and 2s - Dutch National Flag Problem

Given an array arr[] consisting of only 0s, 1s, and 2s. 
The task is to sort the array, i.e., put all 0s first, then all 1s and all 2s in last.

This problem is the same as the famous "Dutch National Flag problem". The problem was proposed by Edsger Dijkstra. 
The problem is as follows:

Given n balls of colour red, white or blue arranged in a line in random order. You have to arrange all 
the balls such that the balls with the same colours are adjacent with the order of the balls, with the 
order of the colours being red, white and blue 
(i.e., all red coloured balls come first then the white coloured balls and then the blue coloured balls). 

*/

// C++ Program to sort an array of 0s, 1s and 2s
// by counting the occurrence of 0s, 1s and 2s

#include <iostream>
#include <vector>
using namespace std;

// Function to sort the array of 0s, 1s and 2s
void sort012(vector<int> &arr) {
    int n = arr.size();
    int c0 = 0, c1 = 0, c2 = 0;

    // Count 0s, 1s and 2s
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            c0 += 1;
        else if (arr[i] == 1)
            c1 += 1;
        else
            c2 += 1;
    }

    int idx = 0;
    
    // Place all the 0s
    for (int i = 0; i < c0; i++)
        arr[idx++] = 0;

    // Place all the 1s
    for (int i = 0; i < c1; i++)
        arr[idx++] = 1;

    // Place all the 2s
    for (int i = 0; i < c2; i++)
        arr[idx++] = 2;
}

int main() {
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    sort012(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}


// C++ program to sort an array of 0s, 1s and 2s 
// using Dutch National Flag Algorithm

#include <iostream>
#include <vector>
using namespace std;

// Function to sort an array of 0s, 1s and 2s
void sort012(vector<int> &arr) {
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        if (arr[mid] == 0)
            swap(arr[lo++], arr[mid++]);
        else if (arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[hi--]);
    }
}

int main() {
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    int n = arr.size();

    sort012(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}