// LeetCode 2108 - Find First Palindromic String in the Array

// Difficulty: Easy

// Approach:

// Traverse each string in the array one by one.
// For every string:
// Check whether it is a palindrome.
// Compare characters from both ends moving toward the center.
// If a palindrome is found:
// Return that string immediately.
// If no palindromic string exists in the array:
// Return an empty string.

// Time Complexity: O(n × m)
// Space Complexity: O(1)

// n = number of strings in the array.
// m = average length of a string.



class Solution {
public:

    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    string firstPalindrome(vector<string>& words) {

        for(string word : words) {

            if(isPalindrome(word)) {
                return word;
            }
        }

        return "";
    }
};