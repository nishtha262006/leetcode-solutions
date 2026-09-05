// LeetCode 3904 — Smallest Stable Index II

// Difficulty: Medium
// Topic: Array, Prefix/Suffix

// 💡 Approach

// For every index i, we need:

// max(nums[0..i]) - min(nums[i..n-1]) <= k

// Doing this from scratch for every index would be O(n²).

// Instead:

// Build a suffix minimum array.
// right[i] = minimum element from i to the end.
// Traverse from left to right.
// Maintain left = maximum element seen so far.
// At index i, calculate:
// left - right[i]
// If it is <= k, return i.
// If no index works, return -1.

// This is O(n) and works for n <= 10^5


class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> right(n);

        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        int left = 0;

        for (int i = 0; i < n; i++) {
            left = max(left, nums[i]);

            if (left - right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};