// Difficulty: Easy
// Topic: Array, Prefix/Suffix Minimum

//  Approach

// For every index i, we need:

// max(nums[0...i]) → maximum on the left
// min(nums[i...n-1]) → minimum on the right

// Then:

// instability = leftMax - rightMin

// If this value is <= k, i is stable. We need the smallest such index



class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        int prefixMax = INT_MIN;

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            int instability = prefixMax - suffixMin[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};