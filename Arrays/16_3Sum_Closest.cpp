// LeetCode 16 - 3Sum Closest

// Difficulty: Medium

// Approach:

// 1. Sort the array in non-decreasing order.
// 2. Initialize the answer with the sum of the first three elements.
// 3. Traverse the array and fix one element at a time.
// 4. Use two pointers:

//    * One pointer just after the fixed element.
//    * One pointer at the end of the array.
// 5. Calculate the current sum of the three elements.
// 6. If the current sum is closer to the target than the previous answer, update the answer.
// 7. If the current sum is less than the target, move the left pointer to increase the sum.
// 8. If the current sum is greater than the target, move the right pointer to decrease the sum.
// 9. If the current sum equals the target, return it immediately since it is the closest possible.
// 10. After all possibilities are checked, return the closest sum found.

// Time Complexity: O(n²)
// Space Complexity: O(1)

// * n = number of elements in the array.
// * Sorting takes **O(n log n)**, and the two-pointer traversal takes **O(n²)**.



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(abs(target - sum) < abs(target - closest))
                    closest = sum;

                if(sum < target)
                    left++;

                else if(sum > target)
                    right--;

                else
                    return sum;
            }
        }

        return closest;
    }
};