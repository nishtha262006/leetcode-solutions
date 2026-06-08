// LeetCode 2470 - Number of Subarrays With LCM Equal to K
// Difficulty: Medium

// Approach:
// 1. Iterate through each index as the starting point of a subarray.
// 2. For each starting index:
//    - Continuously calculate the LCM of the current subarray.
// 3. If the LCM becomes equal to k:
//    - Increment the answer count.
// 4. If the LCM exceeds k or k is not divisible by the current LCM:
//    - Stop extending the current subarray since it can never become k.
// 5. Continue until all possible subarrays are checked.

// Time Complexity: O(n² × log(max(nums)))
// Space Complexity: O(1)


class Solution {
public:

    int subarrayLCM(vector<int>& nums, int k) {

        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            long long currentLCM = 1;

            for(int j = i; j < n; j++) {

                currentLCM = lcm(currentLCM,
                                 (long long)nums[j]);

                if(currentLCM == k) {
                    count++;
                }

                if(currentLCM > k) {
                    break;
                }
            }
        }

        return count;
    }
};