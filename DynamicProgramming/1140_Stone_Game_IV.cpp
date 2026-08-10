// LeetCode 1510 - Stone Game IV

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming to determine whether the current player can force a win.
// 2. Create a boolean DP array where `dp[i]` represents whether the player whose turn it is can win when there are `i` stones remaining.
// 3. Initialize:

//    * `dp[0] = false` because there are no stones to take.
// 4. For every number `i` from `1` to `n`:

//    * Try every perfect square `j*j <= i`.
//    * If `dp[i - j*j] == false`, then the current player can take `j*j` stones and leave a losing position for the opponent.
//    * Therefore, set `dp[i] = true`.
// 5. If no perfect square leads to a losing state, `dp[i] = false`.
// 6. Return `dp[n]`.

// Time Complexity: O(n√n)
// Space Complexity: O(n)

// * `n` = number of stones.
// * For every state, we try all possible perfect squares.



class Solution {
public:
    bool winnerSquareGame(int n) {

        vector<bool> dp(n + 1, false);

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j * j <= i; j++) {

                if(dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};