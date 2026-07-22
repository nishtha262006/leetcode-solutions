// LeetCode 322 - Coin Change

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming to compute the minimum number of coins required for each amount.
// 2. Create a DP array where `dp[i]` represents the minimum coins needed to make amount `i`.
// 3. Initialize:

//    * `dp[0] = 0`
//    * All other entries to a large value (representing infinity).
// 4. For each amount from `1` to the target amount:

//    * Try every available coin.
//    * If the coin can contribute to the current amount, update the DP value using:

//      * `dp[i] = min(dp[i], dp[i - coin] + 1)`
// 5. After filling the DP array:

//    * If `dp[amount]` is still infinity, return `-1`.
//    * Otherwise, return `dp[amount]`.

// Time Complexity: O(n × amount)
// Space Complexity: O(amount)

// * n = number of coin denominations.
// * A one-dimensional DP array is used to store intermediate results.



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {

            for(int coin : coins) {

                if(coin <= i) {

                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if(dp[amount] == amount + 1)
            return -1;

        return dp[amount];
    }
};