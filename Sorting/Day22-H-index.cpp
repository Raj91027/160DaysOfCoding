/*
H-Index

Given an array citations[] of size n such that citations[i] is the number of citations a researcher received for ith paper, 
the task is to find the H-index. H-index(H) is the largest value such that the researcher has published at least H papers that have been cited at least H times.

'H' stands for Hirsch index as it was proposed by the J.E. Hirsch in 2005. The H-index is defined as the author-level metric that 
attempts to measure both the productivity and the citation impact of the publication of the scientist or the scholar.

Examples:

Input: citations[] = [5, 0, 2, 0, 2]
Output: 2
Explanation: There are at least 2 papers (5, 2, 2) with at least 2 citations.
*/


/*
A simple solution is to first sort the array in descending order. 
Initialize idx = 0 to find the H-Index and iterate through the papers from left to right 
and if citations[idx] > idx, then all the papers from 0 to idx have at least (idx + 1) citations. 
So, keep on incrementing idx till citations[idx] > idx. Finally, if we reach the end of array or citations[idx] <= idx, return idx.

*/

// C++ Program to find H-index by sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int> &citations) {

    // Sort the citations in descending order
    sort(citations.begin(), citations.end(), greater<int>());

    int n = citations.size();
    int idx = 0;

    // Keep incrementing idx till citations[idx] > idx
    while(idx < n && citations[idx] > idx) {
        idx += 1;
    }
    return idx;
}

int main() {
    vector<int> citations = {6, 0, 3, 5, 3};
    cout << hIndex(citations) << "\n";
    return 0;
}

/*

[Expected Approach] Using Counting Sort - O(n) Time and O(n) Space
The idea is similar to Counting Sort and maintain an array of size n + 1, say freq[] 
to count the frequency of citations of each paper. So, freq[i] will store the number of papers having i citations. 
To handle the case when number of citations > n, we can simply replace them with n. 
This is because the value of H-Index can be at most n as we have total n papers only.

After counting the frequency of citations, start from last index n and for each index i, 
keep track of the count of papers having at least i citations. 
If at any index i, the count of papers having at least i citations becomes >= i, then we can simply return i as the H-Index. 
We started from the last index n because we want to maximize the H-Index
*/

// C++ Program to find H-index using Counting Sort

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int> &citations) {

    int n = citations.size();
    vector<int> freq(n + 1);

    // Count the frequency of citations
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n)
            freq[n] += 1;
        else
            freq[citations[i]] += 1;
    }

    int idx = n;
    
    // Variable to keep track of the count of papers
    // having at least idx citations
    int s = freq[n]; 
    while (s < idx) {
        idx--;
        s += freq[idx];
    }
  
    // Return the largest index for which the count of 
    // papers with at least idx citations becomes >= idx
    return idx;
}

int main() {
    vector<int> citations = {6, 0, 3, 5, 3};
    cout << hIndex(citations) << "\n";
    return 0;
}