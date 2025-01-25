/*
Merge Two Sorted Arrays Without Extra Space

Given two sorted arrays a[] and b[] of size n and m respectively, 
the task is to merge both the arrays and rearrange the elements such 
that the smallest n elements are in a[] and the remaining m elements are in b[]. 
All elements in a[] and b[] should be in sorted order.
*/

/*
Examples: 

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output: a[] = [2, 2, 3, 4], b[] = [7, 10] 
Explanation: Combined sorted array = [2, 2, 3, 4, 7, 10], array a[] 
contains smallest 4 elements: 
2, 2, 3 and 4, and array b[] contains remaining 2 elements: 7, 10.
*/

//Using insertion sort
// C++ Code to Merge two sorted arrays a[] and b[] without 
// extra space using insert of insertion sort

#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) {
      
      // Traverse b[] starting from the last element
    for (int i = b.size() - 1; i >= 0; i--) {
          
        // If b[i] is smaller than the largest element of a[]
        if (a.back() > b[i]) {
          
              // Place b[i] in the correct position in a[], 
            // and move last element of a[] to b[]
            int last = a.back();
              int j = a.size() - 2;
            while (j >= 0 && a[j] > b[i]) {
                a[j + 1] = a[j];
                j--;
            }
          
            a[j + 1] = b[i];
            b[i] = last;
        }
    }
}

int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele: a)
        cout << ele << " ";
    cout << "\n";
    for (int ele: b)
        cout << ele << " ";
    return 0;
}

//Using nth smallest element

// C++ program to merge two sorted arrays a[] and b[]
// without extra space using n-th smallest number

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Find m-th smallest element
// Do a binary search in a[] to find the right index idx
// in a[] such that all combined elements in a[idx..m-1]
// and b[m-idx...n-1] are greater than or equal to all
// the remaining elements (a[0..idx-1] and b[m-idx-1..n-1])
// in both the arrays.
int kthSmallest(vector<int> &a, vector<int> &b, int k) {
    int n = a.size(), m = b.size();
    int lo = 0, hi = n, idx = 0;
    while (lo <= hi) {
        int mid1 = (lo + hi) / 2;
        int mid2 = k - mid1;
       
        // We don't have mid2 elements in b[], so pick more
        // elements from a[]
        if (mid2 > m) {
            lo = mid1 + 1;
            continue;
        }

        // Find elements to the left and right of partition in a[]
        int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);

        // Find elements to the left and right of partition in b[]
        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == m ? INT_MAX : b[mid2]);

        // If it is a valid partition
        if (l1 <= r2 && l2 <= r1) {
            idx = mid1;
            break;
        }

        // Check if we need to take lesser elements from a[]
        if (l1 > r2)
            hi = mid1 - 1;

        // Check if we need to take more elements from a[]
        else
            lo = mid1 + 1;
    }
    return idx;
}

void mergeArrays(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int m = b.size();
    int idx = kthSmallest(a, b, n);

    // Move all smaller elements in a[]
    for (int i = idx; i < n; i++) {
        swap(a[i], b[i - idx]);
    }

    // Sort both a[] and b[]
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele : a)
        cout << ele << " ";
    cout << "\n";
    for (int ele : b)
        cout << ele << " ";
    return 0;
}

//Swap ans sort

// C++ program to merge two sorted arrays a[] and b[] 
// without extra space Using swap and sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) {
    int i = a.size() - 1, j = 0;

      // swap smaller elements from b[] 
      // with larger elements from a[]
    while (i >= 0 && j < b.size() && a[i] > b[j]) {
          swap(a[i--], b[j++]);
    }

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele: a)
        cout << ele << " ";
    cout << "\n";
    for (int ele: b)
        cout << ele << " ";
    return 0;
}

//Using gap Method
// Merge two sorted arrays a[] and b[] with O(1) extra space.
// using Gap method of shell sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int gap = (n + m + 1) / 2;

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < n + m) {

            // If both pointers are in the first array a[]
            if (j < n && a[i] > a[j]) {
                swap(a[i], a[j]);
            } 
          
            // If first pointer is in a[] and 
            // the second pointer is in b[]
            else if (i < n && j >= n && a[i] > b[j - n]) {
                swap(a[i], b[j - n]);
            } 
          
            // Both pointers are in the second array b
            else if (i >= n && b[i - n] > b[j - n]) {
                swap(b[i - n], b[j - n]);
            }
            i++;
            j++;
        }

        // After operating for gap of 1 break the loop
        if (gap == 1) break;

        // Calculate the next gap
        gap = (gap + 1) / 2;
    }
}

int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele: a)
        cout << ele << " ";
    cout << "\n";
    for (int ele: b)
        cout << ele << " ";
    return 0;
}