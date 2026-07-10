// LeetCode 704 - Binary Search

// Difficulty: Easy

// Approach:

// 1. Initialize two pointers:

//    * `left` at the beginning of the array.
//    * `right` at the end of the array.
// 2. While `left <= right`:

//    * Calculate the middle index.
//    * If the middle element equals the target, return its index.
//    * If the target is greater than the middle element, search the right half.
//    * Otherwise, search the left half.
// 3. If the target is not found, return `-1`.

// Time Complexity: O(log n)
// Space Complexity: O(1)

// * The search space is halved in each iteration, making Binary Search highly efficient.





class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return mid;
            }

            else if(nums[mid] < target) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};