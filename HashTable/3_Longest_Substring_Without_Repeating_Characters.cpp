
// LeetCode 3 - Longest Substring Without Repeating Characters

// Difficulty: Medium

// Approach:

// 1. Use the Sliding Window technique with two pointers.
// 2. Maintain a hash map (or set) to keep track of characters in the current window.
// 3. Expand the right pointer by adding characters.
// 4. If a duplicate character is encountered:

//    * Move the left pointer forward until the duplicate is removed.
// 5. Update the maximum length of the current valid window after each iteration.
// 6. Return the maximum length found.

// Time Complexity: O(n)
// Space Complexity: O(min(n, m))

// * n = length of the string.
// * m = size of the character set.
// * Each character is added and removed from the window at most once.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> seen;

        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < s.size(); right++) {

            while(seen.count(s[right])) {

                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};