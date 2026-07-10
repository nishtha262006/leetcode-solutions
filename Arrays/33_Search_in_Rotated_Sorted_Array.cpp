// LeetCode 33 - Search in Rotated Sorted Array

// Difficulty: Medium

// Approach:

// 1. Use Binary Search on the rotated sorted array.
// 2. Initialize two pointers:

//    * `left` at the beginning.
//    * `right` at the end.
// 3. While `left <= right`:

//    * Find the middle index.
//    * If the middle element is the target, return its index.
// 4. Determine which half of the array is sorted:

//    * If the left half is sorted:

//      * Check if the target lies within it.
//      * Otherwise, search the right half.
//    * Else, the right half is sorted:

//      * Check if the target lies within it.
//      * Otherwise, search the left half.
// 5. If the target is not found, return `-1`.

// Time Complexity: O(log n)
// Space Complexity: O(1)

// * Binary Search reduces the search space by half in each iteration.





class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
                return mid;

            // Left half is sorted
            if(nums[left] <= nums[mid]) {

                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};