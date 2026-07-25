// LeetCode 139 - Word Break

// Difficulty: Medium

// Approach:

// 1. Use Dynamic Programming to determine whether the string can be segmented into valid dictionary words.
// 2. Create a boolean DP array where `dp[i]` indicates whether the substring `s[0...i-1]` can be segmented.
// 3. Initialize:

//    * `dp[0] = true` (an empty string is always valid).
// 4. For each position `i` from `1` to `n`:

//    * Check all possible previous positions `j` from `0` to `i-1`.
//    * If `dp[j]` is `true` and the substring `s[j...i-1]` exists in the dictionary:

//      * Set `dp[i] = true`.
//      * Stop checking further for the current `i`.
// 5. Continue until the DP array is filled.
// 6. Return `dp[n]`.

// Time Complexity: O(n²)
// Space Complexity: O(n)

// * n = length of the string.
// * A hash set is used for efficient dictionary lookups.



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for(int i = 1; i <= n; i++) {

            for(int j = 0; j < i; j++) {

                if(dp[j] && st.count(s.substr(j, i - j))) {

                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};