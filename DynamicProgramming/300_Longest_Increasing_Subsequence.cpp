// LeetCode 300 - Longest Increasing Subsequence

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming to find the length of the longest increasing subsequence.
// 2. Create a DP array where `dp[i]` represents the length of the longest increasing subsequence ending at index `i`.
// 3. Initialize every element of the DP array to `1`, since each element alone forms a subsequence of length `1`.
// 4. For each index `i`:

//    * Check all previous indices `j < i`.
//    * If `nums[j] < nums[i]`, update:

//      * `dp[i] = max(dp[i], dp[j] + 1)`
// 5. Keep track of the maximum value in the DP array.
// 6. Return the maximum length obtained.

// Time Complexity: O(n²)
// Space Complexity: O(n)

// * n = number of elements in the array.
// * An optimized solution using Binary Search exists with **O(n log n)** time complexity.



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1);

        int ans = 1;

        for(int i = 1; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i]) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};