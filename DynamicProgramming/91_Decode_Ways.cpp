LeetCode 91 - Decode Ways

Difficulty: Medium

Approach:

1. Use Dynamic Programming to count the number of ways to decode the string.
2. Create a DP array where `dp[i]` represents the number of ways to decode the first `i` characters.
3. Initialize:

   * `dp[0] = 1` (empty string has one valid decoding).
   * `dp[1]` depends on whether the first character is `'0'`.
4. For each position:

   * If the current digit is between `'1'` and `'9'`, add `dp[i-1]`.
   * If the last two digits form a valid number between `10` and `26`, add `dp[i-2]`.
5. Continue until the end of the string.
6. Return `dp[n]`.

Time Complexity: O(n)
Space Complexity: O(n)

* n = length of the input string.
* The DP array stores the number of decoding ways for each position.




class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--) {

            if(s[i] == '0')
                continue;

            dp[i] = dp[i + 1];

            if(i + 1 < n &&
              (s[i] == '1' ||
              (s[i] == '2' && s[i + 1] <= '6'))) {

                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};