// LeetCode 3090 - Maximum Length Substring With Two Occurrences

// Difficulty: Easy

// Approach
// Use the Sliding Window + Frequency Map technique.
// Maintain two pointers:
// left = start of the window
// right = end of the window
// Store the frequency of each character in the current window.
// Move right through the string and increase the character frequency.
// If any character appears more than 2 times:
// Move left forward.
// Decrease the frequency of s[left].
// Continue until every character appears at most twice.
// After every valid window, update the maximum length.
// Return the maximum length.


class Solution {
public:
    int maximumLengthSubstring(string s) {

        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            while(freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};