// LeetCode 940  Distinct Subsequences II

// Difficulty: Hard
// Topic: Dynamic Programming, Strings

// The task is to count the number of distinct non-empty subsequences of s, modulo 10^9 + 7.

//  Approach

// The main problem is duplicates.

// For example:

// s = "aaa"

// Possible non-empty subsequences are:

// "a", "a", "a", "aa", "aa", "aa", "aaa"

// But the distinct ones are only:

// "a", "aa", "aaa"
// Key idea

// Maintain:

// dp[c] = number of distinct subsequences that end with character c

// There are only 26 lowercase letters.

// When we encounter a character c:

// Every existing distinct subsequence can have c appended to it.
// c itself can also form a new subsequence.
// Therefore, the new subsequences ending in c are:
// total previous subsequences + 1
// Replace dp[c] with this value.

// Why replace instead of add?

// Because c has appeared before, and the subsequences created from its previous occurrence would otherwise be counted again.


class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        long long total = 0;

        for (char c : s) {
            int x = c - 'a';

            long long newSubseq = (total + 1) % MOD;

            total = (total + newSubseq - dp[x] + MOD) % MOD;

            dp[x] = newSubseq;
        }

        return total;
    }
};