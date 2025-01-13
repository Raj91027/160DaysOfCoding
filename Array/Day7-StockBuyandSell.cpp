/*
Given an array prices[] of size n denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

Examples:

Input: prices[] = {100, 180, 260, 310, 40, 535, 695}
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 - 100 = 210
                       Buy the stock on day 4 and sell it on day 6 => 695 - 40 = 655
                       Maximum Profit  = 210 + 655 = 865

*/


#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int n = prices.size();
    int lMin = prices[0];  // Local Minima
    int lMax = prices[0];  // Local Maxima
    int res = 0;
  
    int i = 0;
    while (i < n - 1) {
      
        // Find local minima 
        while (i < n - 1 && prices[i] >= prices[i + 1]) { i++; }
        lMin = prices[i];
       
        // Local Maxima
        while (i < n - 1 && prices[i] <= prices[i + 1]) { i++; }
        lMax = prices[i];
      
        // Add current profit 
        res = res + (lMax - lMin);
    }
  
    return res;
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << maximumProfit(prices);
    return 0;
}

// C++ Program to find the max profit when multiple
// transactions are allowed

#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(const vector<int>& prices) {
    int res = 0;
  
    // Keep on adding the difference between
    // adjacent when the prices a
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) 
            res += prices[i] - prices[i - 1];
    }
    
    return res;
}

int main() {
    vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };
    cout << maximumProfit(prices) << endl;
    return 0;
}