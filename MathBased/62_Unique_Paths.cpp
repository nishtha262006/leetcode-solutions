// LeetCode 62 - Unique Paths

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming.
// 2. Create a 2D DP table where `dp[i][j]` represents the number of unique paths to reach cell `(i, j)`.
// 3. Initialize:

//    * The first row with 1, since it can only be reached by moving right.
//    * The first column with 1, since it can only be reached by moving down.
// 4. For every other cell:

//    * `dp[i][j] = dp[i-1][j] + dp[i][j-1]`
// 5. Return the value stored in the bottom-right cell.

// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

// * m = number of rows.
// * n = number of columns.



class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++) {

            for(int j = 1; j < n; j++) {

                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};