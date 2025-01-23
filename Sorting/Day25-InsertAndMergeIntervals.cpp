/*
Insert and Merge Interval

Given a set of non-overlapping intervals and a new interval, 
the task is to insert the interval at the correct position such that after insertion, the intervals remain sorted. 
If the insertion results in overlapping intervals, then merge the overlapping intervals. 
Assume that the set of non-overlapping intervals is sorted based on start time.

Examples: 

Input: intervals[][] = [[1, 3], [4, 5], [6, 7], [8, 10]], newInterval[] = [5, 6]
Output: [[1, 3], [4, 7], [8, 10]]
Explanation: The intervals [4, 5] and [6, 7] are overlapping with [5, 6]. So, they are merged into one interval [4, 7].
*/

// C# program to insert a new interval in sorted and 
// non-overlapping interval array using insertion and merging

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {

    // Sort intervals based on start values
    sort(intervals.begin(), intervals.end());
  
    vector<vector<int>> res;
  
    // Insert the first interval into the result
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
      
        // Find the last interval in the result
        vector<int>& last = res.back();
        vector<int>& curr = intervals[i];

        // If current interval overlaps with the last interval
        // in the result, merge them 
        if (curr[0] <= last[1]) 
            last[1] = max(last[1], curr[1]);
        else 
            res.push_back(curr);
    }

    return res;
}

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, 
                                             vector<int> &newInterval) {
    intervals.push_back(newInterval);
      return mergeOverlap(intervals);
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    
    vector<vector<int>> res = insertInterval(intervals, newInterval);
      for (vector<int> interval: res) {
          cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}


// C++ program to insert a new Interval in an array of sorted and 
// non-overlapping interval using Contiguous Interval Merging

#include <iostream>
#include <vector>
using namespace std;

// Function to insert and merge intervals
vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                   vector<int> &newInterval) {
    vector<vector<int>> res;
    int i = 0;
    int n = intervals.size();

    // Add all intervals that come before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // Merge all overlapping intervals with the new interval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    // Add all the remaining intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    
    vector<vector<int>> res = insertInterval(intervals, newInterval);
      for (vector<int> interval: res) {
          cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}