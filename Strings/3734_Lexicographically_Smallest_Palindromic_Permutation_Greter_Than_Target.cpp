// LeetCode 3734 - Lexicographically Smallest Palindromic Permutation Greater Than Target

// Difficulty: Hard.

// Approach
// Count the frequency of every character in s.
// A palindrome is possible only if at most one character has an odd frequency.
// A palindrome is completely determined by its left half and its middle character.
// Build the left half so that it is as close as possible to target.
// Try to keep the left half equal to target for as long as possible.
// If we get stuck, backtrack from the right side:
// Restore the character used at that position.
// Find the smallest available character strictly greater than target[i].
// Once found, fill the remaining half in ascending order.
// Mirror the left half to construct the palindrome.
// Return it if it is strictly greater than target; otherwise return "".

// The key insight is that only the left half needs to be chosen; the right half is forced by the palindrome condition

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // A palindrome can have at most one odd frequency
        int odd = 0;
        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Count characters available for the left half
        vector<int> half(26, 0);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;

        // Build left half
        string left;

        for (int pos = 0; pos < halfLen; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Try this character
                half[c]--;

                string candidate = left + char('a' + c);

                // Put remaining characters in DESCENDING order.
                // This gives the largest possible completion.
                string largest = candidate;

                for (int x = 25; x >= 0; x--) {
                    largest += string(half[x], char('a' + x));
                }

                // Construct the palindrome
                string palindrome = largest;

                if (mid != -1) {
                    palindrome += char('a' + mid);
                }

                for (int i = (int)largest.size() - 1; i >= 0; i--) {
                    palindrome += largest[i];
                }

                // If even the largest completion is NOT greater,
                // this character cannot work.
                if (palindrome > target) {
                    left += char('a' + c);
                    break;
                }

                // Undo
                half[c]++;
            }

            // If we couldn't choose any character
            if ((int)left.size() != pos + 1) {
                return "";
            }
        }

        // Construct final palindrome
        string ans = left;

        if (mid != -1) {
            ans += char('a' + mid);
        }

        for (int i = halfLen - 1; i >= 0; i--) {
            ans += left[i];
        }

        return ans > target ? ans : "";
    }
};