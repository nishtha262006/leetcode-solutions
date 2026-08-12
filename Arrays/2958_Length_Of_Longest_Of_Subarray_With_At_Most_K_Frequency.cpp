// LeetCode 2958 - Length of Longest Subarray With at Most K Frequency

// Difficulty: Medium

// Approach
// Use the Sliding Window + Hash Map technique.
// Maintain two pointers:
// left = start of the window
// right = end of the window
// Store the frequency of every number in the current window using a Hash Map.
// Move right through the array and increase the frequency of nums[right].
// If the frequency of nums[right] becomes greater than k:
// Move left forward.
// Decrease the frequency of nums[left].
// Continue until every number has frequency <= k.
// At every valid window, update the maximum length.
// Return the maximum length.


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;

            while(freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};