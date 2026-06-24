// LeetCode 796 - Rotate String

// Difficulty: Easy

// Approach:

// 1. Check if the lengths of both strings are equal.
// 2. If the lengths are different, return false.
// 3. Concatenate the original string with itself:

//    * doubled = s + s
// 4. If goal is a substring of doubled:

//    * It means goal can be obtained by rotating s.
// 5. Otherwise, return false.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * An additional string of length 2n is created for checking rotations.





class Solution {
public:
    bool rotateString(string s, string goal) {
        

        if(s.size()!=goal.size()){// size should be same 
            return false;// otherwise false
        }
        string doubled = s+s;// create doubled string 

        return doubled.find(goal) !=string::npos;// find the goal in doubled != npos means not found
    }
};