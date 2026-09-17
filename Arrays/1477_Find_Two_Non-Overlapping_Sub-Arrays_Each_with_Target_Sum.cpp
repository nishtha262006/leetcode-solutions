// LeetCode 1477 — Find Two Non-overlapping Sub-arrays Each With Target Sum

// Difficulty: Medium
// Topic: Sliding Window, Prefix Sum, Dynamic Programming

// Approach
// We need to find two non-overlapping subarrays whose sums are exactly equal to target.
// Since all elements in arr are positive, we can use a sliding window to find every subarray with sum equal to target.
// Maintain:
// left → starting index of the window
// sum → current window sum
// Whenever sum == target, we have found a valid subarray.
// Store the minimum length of a valid subarray ending at or before the current position.
// For the current valid subarray [left, right], we need a previous subarray ending before left.
// Therefore, keep:
// best[i] = minimum length of a valid subarray
//           ending at or before index i
// If a previous valid subarray exists before left, combine its length with the current subarray length.
// Keep the minimum total length.
// If no two valid non-overlapping subarrays exist, return -1.


class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        int ans = INF;
        int minLen = INF;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // Check if a subarray ending at i has sum = target
            if (mp.count(sum - target)) {
                int start = mp[sum - target] + 1;
                int len = i - start + 1;

                // best[start - 1] = shortest valid subarray
                // completely before this one
                if (start > 0 && best[start - 1] != INF) {
                    ans = min(ans, len + best[start - 1]);
                }

                minLen = min(minLen, len);
            }

            // Store the shortest valid subarray ending at or before i
            best[i] = minLen;

            // Store the latest index for this prefix sum
            mp[sum] = i;
        }

        return ans == INF ? -1 : ans;
    }
};