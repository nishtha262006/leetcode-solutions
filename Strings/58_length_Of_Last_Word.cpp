// Difficulty: Easy

// Approach:

// Start traversing the string from the end.
// Skip all trailing spaces.
// Count the characters of the last word until a space or the beginning of the string is reached.
// Return the count as the length of the last word.

// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int lengthOfLastWord(string s) {
        

        int i = s.size()-1;

        while( i>=0 && s[i] ==' '){
            i--;
        }
        int length=0;

        while(i>=0 && s[i] !=' '){
            length++;
            i--;
        }
        return length;
    }
};