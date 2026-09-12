// LeetCode 3414 — Maximum Score of Non-overlapping Intervals

// Difficulty: Hard
// Topic: Dynamic Programming, Binary Search, Sorting

// We can choose at most 4 non-overlapping intervals. Each interval is [left, right, weight]. We want the maximum total weight, and if multiple answers have the same weight, return the lexicographically smallest list of original indices.

// Approach
// Store each interval along with its original index.
// Sort the intervals by their starting position.
// Define:
// dp(i, k)

// where:

// i = current interval
// k = number of intervals we can still choose
// the result stores both the maximum weight and the indices chosen.
// At every interval, we have two choices:
// Skip the current interval.
// Take the current interval.
// If we take interval i, the next interval must have:
// next.left > current.right

// because intervals sharing an endpoint are considered overlapping. Use binary search to find this next interval efficiently.
// 6. Compare the two choices:

// Larger weight → choose it.
// Equal weight → choose the lexicographically smaller index list.
// Since we can select at most 4 intervals, there are only 5 × n DP states.
// Complexity
// Time: O(n log n)
// Space: O(n)

// The log n factor comes from binary searching for the next compatible interval.


class Solution {
public:
    struct State {
        long long weight;
        vector<int> indices;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: Skip current interval
                State skip = dp[i + 1][k];

                // Find first interval with start > current end
                int lo = i + 1;
                int hi = n;

                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;

                    if (a[mid][0] > a[i][1])
                        hi = mid;
                    else
                        lo = mid + 1;
                }

                int next = lo;

                // Option 2: Take current interval
                State take = dp[next][k - 1];

                take.weight += a[i][2];
                take.indices.push_back((int)a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                // Choose the better option
                if (take.weight > skip.weight) {
                    dp[i][k] = take;
                }
                else if (take.weight < skip.weight) {
                    dp[i][k] = skip;
                }
                else {
                    if (take.indices < skip.indices)
                        dp[i][k] = take;
                    else
                        dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].indices;
    }
};