// LeetCode 125 - Valid Palindrome

// Difficulty: Easy

// Approach:

// 1. Use the Two Pointers technique.
// 2. Initialize one pointer at the beginning and another at the end of the string.
// 3. Ignore all non-alphanumeric characters.
// 4. Compare characters in a case-insensitive manner.
// 5. If the characters do not match, return false.
// 6. Move both pointers toward the center.
// 7. If all valid characters match, return true.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * The string is traversed once using two pointers without extra space.




class Solution {
public:
    bool isPalindrome(string s) {
        

        int left =0;
        int right = s.size()-1;

        while(left<right){
            while(left<right && !isalnum(s[left])){
                left++;
            }

            while(left<right && !isalnum(s[right])){
                right--;
            }

            if(tolower(s[left]) !=tolower(s[left])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};