// LeetCode 2904 - Shortest and Lexicographically Smallest Beautiful String

// Difficulty: Medium

// Approach
// Use the Sliding Window / Two Pointers technique.
// Maintain:
// left → start of the window
// right → end of the window
// ones → number of 1s in the current window
// Expand right through the string.
// Whenever ones > k, move left forward until the window has at most k ones.
// When ones == k, remove leading 0s from the window because they don't affect the number of ones and only make the substring longer.
// The resulting window is the shortest beautiful substring ending at right.
// Compare it with the current answer:
// Smaller length → update.
// Same length → choose the lexicographically smaller string.



class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1') {
                ones++;
            }

            // Too many 1s
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // Remove unnecessary leading zeros
            while (ones == k && s[left] == '0') {
                left++;
            }

            // We have exactly k ones
            if (ones == k) {
                string curr = s.substr(left, right - left + 1);

                if (ans == "" ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};