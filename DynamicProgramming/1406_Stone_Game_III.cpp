// LeetCode 1406 - Stone Game III

// Difficulty: Hard

// Approach:

// 1. Use Dynamic Programming to compute the maximum score difference the current player can achieve.
// 2. Create a DP array where `dp[i]` represents the maximum score difference starting from index `i`.
// 3. Traverse the array from right to left.
// 4. At each position, consider taking:

//    * 1 stone
//    * 2 stones
//    * 3 stones
// 5. For each choice:

//    * Add the values of the chosen stones.
//    * Subtract `dp[nextIndex]` since the opponent will also play optimally.
//    * Store the maximum score difference.
// 6. After filling the DP array:

//    * If `dp[0] > 0`, return `"Alice"`.
//    * If `dp[0] < 0`, return `"Bob"`.
//    * Otherwise, return `"Tie"`.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * n = number of stones.
// * Each position considers at most three possible moves.



class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n + 1, INT_MIN);

        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {

            int take = 0;

            for(int k = 0; k < 3 && i + k < n; k++) {

                take += stoneValue[i + k];

                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }

        if(dp[0] > 0)
            return "Alice";

        if(dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};