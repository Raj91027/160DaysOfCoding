/*
Allocate Minimum Pages

Given an array arr[] and an integer k, where arr[i] denotes the number of pages of a 
book and k denotes total number of students. All the books need to be allocated to 
k students in contiguous manner, with each student getting at least one book.

The task is to minimize the maximum number of pages allocated to a student. 
If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Books can be distributed in following ways:

[12] and [34, 67, 90] - The maximum pages assigned to a student is 34 + 67 + 90 = 191.
[12, 34] and [67, 90] - The maximum pages assigned to a student is 67 + 90 = 157.
[12, 34, 67] and [90] - The maximum pages assigned to a student is 12 + 34 + 67 = 113.
*/

// C++ program to find the minimum page limit by iterating
// over all possible page limits

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Function to check if books can be allocated to
// all k students without exceeding 'pageLimit'
bool check(vector<int> &arr, int k, int pageLimit) {
    
    // Starting from the first student
    int cnt = 1;
    int pageSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        
        // If adding the current book exceeds the page 
        // limit, assign the book to the next student
        if(pageSum + arr[i] > pageLimit) {
            cnt++;
            pageSum = arr[i];
        }
        else {
            pageSum += arr[i];
        }
    }
    
      // If books can assigned to less than k students then
    // it can be assigned to exactly k students as well
    return (cnt <= k);
}

int findPages(vector<int> &arr, int k) {
    
    // If number of students are more than total books
    // then allocation is not possible
    if(k > arr.size())
        return -1;
        
    // Minimum and maximum possible page limits
    int minPageLimit = *max_element(arr.begin(), arr.end());
    int maxPageLimit = accumulate(arr.begin(), arr.end(), 0);
    
    // Iterating over all possible page limits
    for(int i = minPageLimit; i <= maxPageLimit; i++) {
        
        // Return the first page limit with we can
        // allocate books to all k students
        if(check(arr, k, i))
            return i;
    }
    
    return -1;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << findPages(arr, k);
    return 0;
}

/*
[Expected Approach] Using Binary Search
The maximum number of pages(page limit) that a student can be allocated has a monotonic property:

If, at a page limit p, books cannot be allocated to all k students, then we need to reduce the page 
limit to ensure more students receive books.
If, at a page limit p, we can allocate books to more than k students, 
then we need to increase the page limit so that fewer students are allocated books.
Therefore, we can apply binary search to minimize the maximum pages a student can be allocated. 
To check the number of students that can be allotted books for any page limit, we start assigning books to the 
first student until the page limit is reached, then move to the next student.
*/

// C++ program to find the minimum page limit by iterating
// over all possible page limits

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Function to check if books can be allocated to
// all k students without exceeding 'pageLimit'
bool check(vector<int> &arr, int k, int pageLimit) {
    
    // Starting from the first student
    int cnt = 1;
    int pageSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        
        // If adding the current book exceeds the page 
        // limit, assign the book to the next student
        if(pageSum + arr[i] > pageLimit) {
            cnt++;
            pageSum = arr[i];
        }
        else {
            pageSum += arr[i];
        }
    }
    
    // If books can assigned to less than k students then
    // it can be assigned to exactly k students as well
    return (cnt <= k);
}

int findPages(vector<int> &arr, int k) {
    
    // If number of students are more than total books
    // then allocation is not possible
    if(k > arr.size())
        return -1;
        
    // Search space for Binary Search
    int lo = *max_element(arr.begin(), arr.end());
    int hi = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        
        if(check(arr, k, mid)){
            res = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    
    return res;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << findPages(arr, k);
    return 0;
}