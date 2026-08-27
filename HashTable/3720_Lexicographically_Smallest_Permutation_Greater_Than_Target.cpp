// LeetCode 3720 - Lexicographically Smallest Permutation Greater Than Target

// Difficulty: Medium.

// Approach
// We need to rearrange nums to form the smallest permutation that is strictly greater than target.
// Sort nums so that we can always choose the smallest possible character/value.
// Build the answer from left to right.
// At each position:
// Prefer using the smallest available value that keeps the prefix equal to target.
// If we cannot continue matching target, choose the smallest value greater than the corresponding target value.
// Once we choose a value greater than target[i], the remaining positions should be filled in ascending order to make the complete permutation lexicographically smallest.
// If no position allows us to make the permutation greater, return the appropriate result according to the problem constraints.


class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> left(26, 0);

        // Characters available in s
        // minus characters needed to make target
        for (int i = 0; i < n; i++) {
            left[s[i] - 'a']++;
            left[target[i] - 'a']--;
        }

        // Try to make target greater from right to left
        for (int i = n - 1; i >= 0; i--) {

            int x = target[i] - 'a';

            // Give target[i] back
            left[x]++;

            // Check whether target[0 ... i-1]
            // can be formed from s
            bool possible = true;

            for (int c = 0; c < 26; c++) {
                if (left[c] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Find smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {

                if (left[c] > 0) {

                    string ans = target.substr(0, i);

                    // Make the first different character larger
                    ans += char('a' + c);

                    left[c]--;

                    // Put remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (left[j] > 0) {
                            ans += char('a' + j);
                            left[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};