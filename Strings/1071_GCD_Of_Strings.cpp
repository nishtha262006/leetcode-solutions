// LeetCode 1071 - Greatest Common Divisor of Strings

// Difficulty: Easy

// Approach:

// 1. Check whether the two strings can be formed by repeating the same base pattern:

//    * If `str1 + str2` is not equal to `str2 + str1`, return an empty string.
// 2. Compute the Greatest Common Divisor (GCD) of the lengths of the two strings.
// 3. The first `gcd(length1, length2)` characters of either string form the greatest common divisor string.
// 4. Return that substring.

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

// * n = length of `str1`.
// * m = length of `str2`.



class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str1+str2 != str2+str1)
            return "";
            int len = gcd(str1.size() , str2.size());
            return str1.substr(0, len);
    }
};