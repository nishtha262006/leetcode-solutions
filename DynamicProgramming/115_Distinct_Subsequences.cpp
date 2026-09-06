// LeetCode 115 — Distinct Subsequences

// Difficulty: Hard
// Topic: Dynamic Programming, Strings

// We are given two strings s and t. We need to count how many different subsequences of s are equal to t.

// 💡 Approach — Dynamic Programming

// Define:

// dp[i][j] = number of ways to form the first j characters of t using the first i characters of s.

// There are two situations.

// Case 1: Characters don't match

// If:

// s[i-1] != t[j-1]

// we cannot use the current character of s, so:

// dp[i][j] = dp[i-1][j]

// Case 2: Characters match

// If:

// s[i-1] == t[j-1]

// we have two choices:

// Don't use this character → dp[i-1][j]
// Use this character → dp[i-1][j-1]

// Therefore:

// dp[i][j] = dp[i-1][j] + dp[i-1][j-1]

//  Base Case

// An empty t can always be created from any prefix of s in exactly 1 way: choose nothing.


class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<unsigned long long>> dp(m + 1,
            vector<unsigned long long>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                dp[i][j] = dp[i - 1][j];

                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};