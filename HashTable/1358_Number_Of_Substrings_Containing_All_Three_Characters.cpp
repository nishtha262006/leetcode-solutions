// LeetCode 1358 - Number of Substrings Containing All Three Characters

// Difficulty: Medium

// Approach:

// 1. Use the Sliding Window technique.
// 2. Maintain a window with two pointers.
// 3. Expand the right pointer and keep track of the frequency of 'a', 'b', and 'c'.
// 4. Whenever the current window contains at least one occurrence of all three characters:

//    * Every substring starting from the current left pointer and ending at or after the current right pointer is valid.
//    * Add `(n - right)` to the answer.
// 5. Shrink the window from the left while it still contains all three characters.
// 6. Continue until the entire string has been processed.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * Each character enters and leaves the sliding window at most once.




class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> freq(3, 0);

        int left = 0;
        int count = 0;
        int n = s.size();

        for(int right = 0; right < n; right++) {

            freq[s[right] - 'a']++;

            while(freq[0] > 0 &&
                  freq[1] > 0 &&
                  freq[2] > 0) {

                count += (n - right);

                freq[s[left] - 'a']--;
                left++;
            }
        }

        return count;
    }
};