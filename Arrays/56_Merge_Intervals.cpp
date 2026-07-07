// LeetCode 56 - Merge Intervals

// Difficulty: Medium

// Approach:

// 1. Sort the intervals based on their starting values.
// 2. Initialize the result with the first interval.
// 3. Traverse the remaining intervals:

//    * If the current interval overlaps with the last interval in the result:

//      * Merge them by updating the ending value to the maximum of both end values.
//    * Otherwise:

//      * Add the current interval to the result.
// 4. Return the merged list of intervals.

// Time Complexity: O(n log n)
// Space Complexity: O(n)

// * Sorting the intervals takes **O(n log n)** time.
// * The result vector stores the merged intervals.




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] <= ans.back()[1]) {

                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {

                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};