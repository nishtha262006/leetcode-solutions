
// LeetCode 198 - House Robber

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming.
// 2. At each house, decide between:

//    * Robbing the current house and adding its value to the maximum profit from two houses back.
//    * Skipping the current house and taking the maximum profit up to the previous house.
// 3. Store the maximum profit for each position.
// 4. Continue until all houses have been processed.
// 5. Return the maximum amount that can be robbed.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = number of houses.
// * Only a few variables are required to keep track of previous results.


class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {

            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[n-1];
    }
};