// LeetCode 122 - Best Time to Buy and Sell Stock II

// Difficulty: Medium

// Approach:

// 1. Traverse the stock prices from left to right.
// 2. Compare each day's price with the previous day's price.
// 3. If the current price is higher than the previous price:

//    * Add the difference to the total profit.
// 4. Ignore days where the price decreases or remains the same.
// 5. Continue until all prices have been processed.
// 6. Return the total maximum profit.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = number of days.
// * The array is traversed once using only a few variables.





class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {

            if(prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};