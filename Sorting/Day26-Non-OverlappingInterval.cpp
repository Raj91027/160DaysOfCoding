/*
Non-Overlapping Intervals

Given a list of intervals with starting and ending values, 
the task is to find the minimum number of intervals that are required 
to be removed to make remaining intervals non-overlapping.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: Removal of [1, 3] makes the ranges non-overlapping.
*/

// C++ program to minimum number of intervals required to
// be removed to make remaining intervals non-overlapping
// Using sorting by starting value

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minRemoval(vector<vector<int>>& intervals) {
      int cnt = 0;
  
    // Sort by minimum starting point
    sort(intervals.begin(), intervals.end());

    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {

        // If the current starting point is less than
        // the previous interval's ending point
        // (ie. there is an overlap)
        if (intervals[i][0] < end) {
          
            // Increase cnt and remove the interval
            // with the higher ending point
              cnt++;
            end = min(intervals[i][1], end);
        }
          
          // Incase of no overlapping, this interval is 
          // not removed and 'end' will be updated
        else
            end = intervals[i][1];
    }

    return cnt;
}

int main() {
    vector<vector<int> > intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << minRemoval(intervals) << endl;
}

/*
Sorting by the Ending Values - O(n*log n) Time and O(1) Space
To understand this approach, think of it as trying to keep intervals short so we have more space for other intervals, 
without overlap. By sorting intervals by their end times, we can easily check if the next interval overlaps with the previous one. 
If there’s an overlap, we remove the interval with the later end time, so it doesn’t block the next intervals from fitting in. 
This way, we end up with the minimum number of removals needed to make all intervals non-overlapping.

*/

// C++ program to minimum number of intervals required 
// to be removed to make remaining intervals non-overlapping
// Using sorting by ending value

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// comparator function
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int minRemoval(vector<vector<int> >& intervals) {
    int cnt = 0;
  
    // Sort by minimum ending point
    sort(intervals.begin(), intervals.end(), compare);

    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        // if there is an overlap increase the count
        if (intervals[i][0] < end)
            cnt++;

        // else increment the ending point
        else
            end = intervals[i][1];
    }

    // return the count
    return cnt;
}

int main() {
    vector<vector<int>> intervals = 
                    {{1, 2}, {2, 3}, {3, 5}, {1, 4}};
    cout << minRemoval(intervals) << endl;
}