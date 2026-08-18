// LeetCode 3471 - Find the Largest Almost Missing Integer

// Difficulty: Easy

// The key observation is:

// If k == n, there is only one subarray → simply return the maximum element.
// If k == 1, every element forms its own subarray → find the largest element that appears exactly once.
// If 1 < k < n, only the first and last elements can appear in exactly one size-k subarray. So just check whether nums[0] and nums[n-1] occur only once in the entire array.


// class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(51, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // Case 1
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 2
        if (k == 1) {
            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 3
        int ans = -1;

        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};