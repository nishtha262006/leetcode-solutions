// LeetCode 2948 - Make Lexicographically Smallest Array by Swapping Elements

// Difficulty: Medium

// Approach
// We can swap two elements if their absolute difference is at most limit.
// Sort the array while keeping each element's original index.
// After sorting, consecutive values can belong to the same connected group if their difference is <= limit.
// For every such group:
// Collect all original indices.
// Sort those indices.
// Put the group's smallest values into the smallest indices.
// This produces the lexicographically smallest possible array.


class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> idx(n);

        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        // Sort indices according to nums values
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            int j = i + 1;

            // Find one connected group
            while (j < n &&
                   nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

            // Get original indices of this group
            vector<int> positions;

            for (int k = i; k < j; k++) {
                positions.push_back(idx[k]);
            }

            // Smallest indices first
            sort(positions.begin(), positions.end());

            // Smallest values -> smallest indices
            for (int k = i; k < j; k++) {
                ans[positions[k - i]] = nums[idx[k]];
            }

            i = j;
        }

        return ans;
    }
};