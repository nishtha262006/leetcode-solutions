// LeetCode 3871  Count Commas in Range II

// Difficulty: Medium
// Topic: Math

// Approach

// The important observation is that a new comma appears every time we cross a power of 1000.

// Numbers from 1 to 999 have 0 commas.
// Numbers from 1000 onward have at least 1 comma.
// Numbers from 1,000,000 onward have at least 2 commas.
// Numbers from 1,000,000,000 onward have at least 3 commas.
// So, instead of checking every number, check the thresholds:
// 1000
// 1000000
// 1000000000
// 1000000000000
// ...
// For every threshold x <= n, all numbers from x to n contribute one additional comma.
// The number of such values is:
// n - x + 1
// Add this to the answer and multiply x by 1000 to move to the next comma position.

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long x = 1000; x <= n; x *= 1000) {
            ans += n - x + 1;
        }

        return ans;
    }
};