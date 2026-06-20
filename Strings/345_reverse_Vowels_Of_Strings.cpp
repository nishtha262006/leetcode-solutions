
// LeetCode 345 - Reverse Vowels of a String

// Difficulty: Easy

// Approach:

// Use the Two Pointers technique.
// Initialize one pointer at the beginning and one at the end of the string.
// Move the left pointer forward until it finds a vowel.
// Move the right pointer backward until it finds a vowel.
// Swap the vowels at the two pointers.
// Continue until the pointers meet.
// Return the modified string.

// Time Complexity: O(n)
// Space Complexity: O(1)

// The string is modified in-place using only two pointers.



class Solution {
public:

    bool isVowel(char c) {

        return c=='a' || c=='e' ||
               c=='i' || c=='o' ||
               c=='u' || c=='A' ||
               c=='E' || c=='I' ||
               c=='O' || c=='U';
    }

    string reverseVowels(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            while(left < right &&
                  !isVowel(s[left])) {
                left++;
            }

            while(left < right &&
                  !isVowel(s[right])) {
                right--;
            }

            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};