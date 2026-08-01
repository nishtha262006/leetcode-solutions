// LeetCode 486 - Predict the Winner

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming to determine the maximum score difference the current player can achieve.
// 2. Create a DP table where `dp[i][j]` represents the maximum score difference the current player can obtain from the subarray `nums[i...j]`.
// 3. Initialize:

//    * `dp[i][i] = nums[i]`, since only one number is available.
// 4. For each subarray of increasing length:

//    * If the current player picks the left number:

//      * Score difference = `nums[i] - dp[i + 1][j]`
//    * If the current player picks the right number:

//      * Score difference = `nums[j] - dp[i][j - 1]`
//    * Store the maximum of the two choices.
// 5. After filling the table:

//    * If `dp[0][n - 1] >= 0`, Player 1 can win or tie.
//    * Otherwise, Player 1 loses.
// 6. Return the result.

// Time Complexity: O(n²)
// Space Complexity: O(n²)

// * n = number of elements in the array.
// * Every subarray is computed exactly once.



class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for(int len = 2; len <= n; len++) {

            for(int i = 0; i <= n - len; i++) {

                int j = i + len - 1;

                dp[i][j] = max(
                    nums[i] - dp[i + 1][j],
                    nums[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};