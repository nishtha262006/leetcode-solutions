// LeetCode 434 - Number of Segments in a String

// Difficulty: Easy

// Approach:

// Traverse the string character by character.
// A segment starts when:
// The current character is not a space.
// And either it is the first character of the string or the previous character is a space.
// Count every such segment start.
// Continue until the end of the string.
// Return the total number of segments.

// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int countSegments(string s) {
        int count = 0;// store value
        for(int i =0;i<s.size();i++){//visit every character

            if(s[i] !=' ' && (i == 0||s[i-1] == ' ')){//check word start

                count++;// increament count
            }
            
        }
        return count;// return count
    }
};