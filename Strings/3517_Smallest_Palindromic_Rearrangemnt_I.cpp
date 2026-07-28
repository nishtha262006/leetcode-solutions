// LeetCode 3517 - Smallest Palindromic Rearrangement I

// Difficulty: Medium

// Approach:

// 1. Count the frequency of each character in the given palindromic string.
// 2. Build the first half of the answer by iterating from `'a'` to `'z'`:

//    * Add `frequency / 2` occurrences of each character.
// 3. If a character has an odd frequency, store it as the middle character.
// 4. Construct the final palindrome by concatenating:

//    * The first half.
//    * The middle character (if any).
//    * The reverse of the first half.
// 5. Return the constructed string, which is the lexicographically smallest palindromic rearrangement.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = length of the string.
// * The character set contains only 26 lowercase English letters, so the extra space is constant.


class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> cnt(26, 0);

        for(char c : s)
            cnt[c - 'a']++;

        string left = "";
        string middle = "";

        for(char c = 'a'; c <= 'z'; c++) {

            int idx = c - 'a';

            left.append(cnt[idx] / 2, c);

            if(cnt[idx] % 2 == 1)
                middle = c;
        }

        string right = left;

        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};