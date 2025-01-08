/*
Stock Buy and Sell - Max one Transaction Allowed

Given an array prices[] of length N, representing the prices of the stocks on different days, 
the task is to find the maximum profit possible by buying and selling the stocks 
on different days when at most one transaction is allowed. 
Here one transaction means 1 buy + 1 Sell.

Note: Stock must be bought before being sold.

Examples:

Input: prices[] = {7, 10, 1, 3, 6, 9, 2}
Output: 8
Explanation: Buy for price 1 and sell for price 9.
*/

/*
[Naive Approach] By exploring all possible pairs - O(n^2) Time and O(1) Space
The idea is to use two nested loops to explore all the possible ways to buy and sell stock. 
The outer loop decides the day to buy the stock and the inner loop decides the day to sell the stock. 
The maximum difference between the selling price and buying price between every pair of days will be our answer.


*/

// C++ Program to solve stock buy and sell by  
// exploring all possible pairs

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {  
    int n = prices.size();
    int res = 0;
  
    // Explore all possible ways to buy and sell stock
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            res = max(res, prices[j] - prices[i]);
        }
    }
    return res;
}

int main() {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}

/*
[Expected Approach] One Traversal Solution - O(n) Time and O(1) Space
In order to maximize the profit, we need to minimize the cost price and maximize the selling price. 
So at every step, we keep track of the minimum buy price of stock encountered so far. 
For every price, we subtract with the minimum so far and if we get more profit than the current result, 
we update the result.
*/

// C++ Program to solve stock buy and sell
// using one traversal

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
  
    int minSoFar = prices[0], res = 0;
  
    for (int i = 1; i < prices.size(); i++) {

        // Update the minimum value seen so
        // far if we see smaller
        minSoFar = min(minSoFar, prices[i]);
       
        // Update result if we get more profit                
        res = max(res, prices[i] - minSoFar);
    }
    return res;
}

int main() {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}