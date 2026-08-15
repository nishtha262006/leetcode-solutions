// LeetCode 3702 - Longest Subsequence With Non-Zero Bitwise XOR

// Difficulty: Medium

// Approach

// This one has a very nice interview trick — no DP or subsequence generation needed.

// Calculate the XOR of all elements.
// If total XOR is non-zero:
// We can take the entire array.
// Answer = n.
// If total XOR is 0:
// If all elements are 0, every possible subsequence has XOR 0.
// Answer = 0.
// Otherwise, there is at least one non-zero element.
// Remove any one non-zero element.
// Since totalXOR = 0, the remaining XOR becomes that removed element, which is non-zero.
// Therefore, answer = n - 1.


class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool hasNonZero = false;
        for(int x : nums){
            xr ^= x;
            if(x!=0)
                hasNonZero = true;
        }
        if(xr!=0)
            return n ;
        if(hasNonZero)
            return n-1;
        return 0;
    }
};