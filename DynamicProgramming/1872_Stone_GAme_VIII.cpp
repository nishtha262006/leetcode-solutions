// LeetCode 1872 - Stone Game VIII

// Difficulty: Hard

// Approach

// This is a Game Theory + Dynamic Programming problem, but there is a useful optimization.

// First calculate the prefix sums of the array.
// Alice must take at least the first two stones, so initially consider the prefix sum of the first two elements.
// Work from the right side toward the left.
// Let dp represent the maximum score difference the current player can achieve.
// For each prefix sum:
// The player can either take the current prefix.
// Or keep the previously calculated best result.
// The transition becomes:
// dp = max(dp, prefix[i] - dp);
// The final value gives the maximum score difference Alice can guarantee.
// If the result is positive, Alice wins.

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // If we take all stones
        int dp = stones[n - 1];

        // Work backwards
        for (int i = n - 2; i > 0; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};