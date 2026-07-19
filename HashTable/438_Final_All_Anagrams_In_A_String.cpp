// LeetCode 438 - Find All Anagrams in a String

// Difficulty: Medium

// Approach:

// 1. Use the Sliding Window technique with two frequency arrays (or hash maps).
// 2. Store the frequency of characters in the pattern string.
// 3. Create a window of the same size as the pattern in the main string.
// 4. As the window slides:

//    * Add the new character entering the window.
//    * Remove the character leaving the window.
// 5. Compare the window frequency with the pattern frequency.
// 6. If they match, store the starting index of the current window.
// 7. Continue until the end of the string and return all starting indices.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = length of the input string.
// * Since only lowercase English letters are used, the frequency array size remains constant.


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if(s.size() < p.size())
            return ans;

        vector<int> pCount(26,0);
        vector<int> window(26,0);

        for(char c : p)
            pCount[c-'a']++;

        int left = 0;

        for(int right=0; right<s.size(); right++) {

            window[s[right]-'a']++;

            if(right-left+1 > p.size()) {

                window[s[left]-'a']--;
                left++;
            }

            if(window == pCount)
                ans.push_back(left);
        }

        return ans;
    }
};