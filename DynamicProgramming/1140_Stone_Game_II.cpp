// LeetCode 1140 - Stone Game II

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming with the game state represented by:
//    - `i` = current index
//    - `M` = maximum number of piles that can be taken in the current move

// 2. From position `i`, the current player can take between `1` and `2*M` piles.

// 3. Calculate the suffix sum so that we can quickly find the total number of stones remaining from index `i`.

// 4. Define `dp[i][M]` as the maximum number of stones the current player can collect starting from index `i` with the current value of `M`.

// 5. Try every possible number of piles `X` from `1` to `2*M`:
//    - Take those `X` piles.
//    - The opponent then gets the best possible result from the remaining piles.
//    - Therefore:
//      `dp[i][M] = max(dp[i][M], suffix[i] - dp[i+X][max(M,X)])`

// 6. Return `dp[0][1]`.

// Time Complexity: O(n³)
// Space Complexity: O(n²)

// - `n` = number of piles.
// - There are O(n²) states and each state may try O(n) possible moves.


class Solution {
public:

    int solve(int i, int M, vector<int>& piles,
              vector<vector<int>>& dp,
              vector<int>& suffix) {

        int n = piles.size();

        // Can take all remaining piles
        if(i >= n)
            return 0;

        if(2 * M >= n - i)
            return suffix[i];

        if(dp[i][M] != -1)
            return dp[i][M];

        int best = 0;

        for(int x = 1; x <= 2 * M; x++) {

            int newM = max(M, x);

            int opponent =
                solve(i + x, newM, piles, dp, suffix);

            int current =
                suffix[i] - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(0, 1, piles, dp, suffix);
    }
};