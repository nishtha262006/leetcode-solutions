// LeetCode 435 - Non-overlapping Intervals

// Difficulty: Medium

// Approach:

// 1. Sort the intervals based on their ending time.
// 2. Initialize:

//    * `count = 0` to track the number of intervals removed.
//    * `end` as the end time of the first interval.
// 3. Traverse the remaining intervals:

//    * If the current interval starts before `end`, it overlaps.

//      * Increment `count` (remove the current interval).
//    * Otherwise:

//      * Update `end` to the current interval's end time.
// 4. Continue until all intervals have been processed.
// 5. Return `count`.

// Time Complexity: O(n log n)
// Space Complexity: O(1)

// * n = number of intervals.
// * Sorting dominates the time complexity.



class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), cmp);

        int removed = 0;

        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] < prevEnd) {

                removed++;
            }
            else {

                prevEnd = intervals[i][1];
            }
        }

        return removed;
    }
};