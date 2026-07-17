// LeetCode 560 - Subarray Sum Equals K

// Difficulty: Medium

// Approach:

// 1. Use a Hash Map to store the frequency of prefix sums.
// 2. Initialize the map with `0 → 1` to handle subarrays starting from index `0`.
// 3. Traverse the array while maintaining the current prefix sum.
// 4. For each element:

//    * Update the prefix sum.
//    * Check if `(prefixSum - k)` exists in the map.
//    * If it exists, add its frequency to the answer.
// 5. Store the current prefix sum in the map by increasing its frequency.
// 6. Return the total count of subarrays whose sum equals `k`.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * n = number of elements in the array.
// * The hash map stores prefix sums encountered during traversal.



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for(int num : nums) {

            prefixSum += num;

            if(mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};