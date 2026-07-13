// LeetCode 242 - Valid Anagram

// Difficulty: Easy

// Approach:

// 1. If the lengths of the two strings are different:

//    * Return false.
// 2. Use a hash map (or frequency array) to count the occurrences of each character in the first string.
// 3. Traverse the second string:

//    * Decrease the frequency of each character.
//    * If any frequency becomes negative, return false.
// 4. If all character frequencies match, return true.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = length of the strings.
// * Since there are only 26 lowercase English letters, the extra space is constant.




class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
            return false;

        vector<int> freq(26, 0);

        for(char ch : s)
            freq[ch - 'a']++;

        for(char ch : t)
            freq[ch - 'a']--;

        for(int count : freq) {
            if(count != 0)
                return false;
        }

        return true;
    }
};