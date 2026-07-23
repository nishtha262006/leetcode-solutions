// LeetCode 279 - Perfect Squares

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming to find the minimum number of perfect squares needed for every value up to `n`.
// 2. Create a DP array where `dp[i]` represents the minimum number of perfect squares that sum to `i`.
// 3. Initialize:

//    * `dp[0] = 0`
//    * All other entries to a large value.
// 4. For every number from `1` to `n`:

//    * Try every perfect square less than or equal to the current number.
//    * Update:

//      * `dp[i] = min(dp[i], dp[i - square] + 1)`
// 5. Continue until the DP array is filled.
// 6. Return `dp[n]`.

// Time Complexity: O(n√n)
// Space Complexity: O(n)

// * n = target number.
// * For each value, all possible perfect squares are considered.



class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j * j <= i; j++) {

                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};