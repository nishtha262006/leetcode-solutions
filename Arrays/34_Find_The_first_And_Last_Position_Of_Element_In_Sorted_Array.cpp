// //
// //LeetCode 34 - Find First and Last Position of Element in Sorted Array
// Difficulty: Medium

// Approach:
// 1. Use Binary Search twice.
// 2. First Binary Search:
//    - Find the first occurrence of the target.
//    - If target is found, continue searching in the left half.
// 3. Second Binary Search:
//    - Find the last occurrence of the target.
//    - If target is found, continue searching in the right half.
// 4. Return the indices of the first and last occurrences.
// 5. If the target is not present, return {-1, -1}.

// Time Complexity: O(log n)
// Space Complexity: O(1)


class Solution {
public:

    int firstPosition(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        int ans = -1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {

                ans = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) {

                left = mid + 1;
            }
            else {

                right = mid - 1;
            }
        }

        return ans;
    }

    int lastPosition(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        int ans = -1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {

                ans = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target) {

                left = mid + 1;
            }
            else {

                right = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        return {
            firstPosition(nums, target),
            lastPosition(nums, target)
        };
    }
};