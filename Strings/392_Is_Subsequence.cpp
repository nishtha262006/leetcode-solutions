// LeetCode 392 - Is Subsequence

// Difficulty: Easy

// Approach:

// 1. Use the Two Pointers technique.
// 2. Initialize one pointer for string `s` and another for string `t`.
// 3. Traverse string `t`:

//    * If the current characters of both strings match, move the pointer of `s`.
//    * Always move the pointer of `t`.
// 4. If the pointer of `s` reaches the end of the string:

//    * All characters of `s` appear in order in `t`.
//    * Return true.
// 5. Otherwise, return false.

// Time Complexity: O(n + m)
// Space Complexity: O(1)

// * n = length of `s`.
// * m = length of `t`.




class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0;
        int j = 0;

        while(i < s.size() && j < t.size()) {

            if(s[i] == t[j]) {
                i++;
            }

            j++;
        }

        return i == s.size();
    }
};