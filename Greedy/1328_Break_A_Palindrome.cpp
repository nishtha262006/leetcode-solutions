// LeetCode 1328 - Break a Palindrome

// Difficulty: Medium

// Approach:

// 1. If the palindrome has only one character:

//    * It is impossible to make it non-palindromic.
//    * Return an empty string.
// 2. Traverse the first half of the palindrome.
// 3. Find the first character that is not `'a'`:

//    * Replace it with `'a'`.
//    * Return the modified string.
// 4. If every character in the first half is `'a'`:

//    * Replace the last character with `'b'`.
// 5. Return the resulting string.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * The string is modified in-place without using extra space.



class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n = palindrome.size();

        if(n == 1)
            return "";

        for(int i = 0; i < n / 2; i++) {

            if(palindrome[i] != 'a') {

                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome[n - 1] = 'b';

        return palindrome;
    }
};