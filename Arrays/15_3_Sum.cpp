// LeetCode 15 - 3Sum

// Difficulty: Medium

// Approach:

// 1. Sort the array in non-decreasing order.
// 2. Iterate through the array, fixing one element at a time.
// 3. For each fixed element:

//    * Use two pointers (left and right) to find two numbers whose sum equals the negative of the fixed element.
// 4. If a valid triplet is found:

//    * Add it to the result.
//    * Skip duplicate elements to avoid repeated triplets.
// 5. Move the pointers based on the current sum:

//    * If the sum is too small, move the left pointer.
//    * If the sum is too large, move the right pointer.
// 6. Return all unique triplets.

// Time Complexity: O(n²)
// Space Complexity: O(1)

// * Sorting takes **O(n log n)**.
// * The two-pointer search runs in **O(n²)** overall.
// * The output list is not counted as extra space.





class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate left values
                    while(left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate right values
                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }

                else if(sum < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return ans;
    }
};