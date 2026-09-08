// LeetCode 3870 — Count Commas in Range
// Approach
// Numbers from 1 to 999 do not contain any commas.
// Every number from 1000 to n contains exactly one comma because n <= 100000.
// Therefore, we only need to count the numbers in the range [1000, n].

// The number of such values is:

// n - 1000 + 1 = n - 999

// If n < 1000, there are no numbers containing commas, so the answer is 0.
// Formula
// answer = max(0, n - 999)
// Complexity
// Time: O(1)
// Space: O(1)


class Solution {
public:
    int countCommas(int n) {
        return max(0,n-999);
    }
};