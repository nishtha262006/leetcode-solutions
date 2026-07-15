// LeetCode 977 - Squares of a Sorted Array

// Difficulty: Easy

// Approach:

// 1. Use the Two Pointers technique.
// 2. Initialize:

//    * One pointer at the beginning of the array.
//    * Another pointer at the end of the array.
// 3. Compare the squares of the elements at both pointers.
// 4. Place the larger square at the end of the result array.
// 5. Move the corresponding pointer inward.
// 6. Repeat until all elements are processed.
// 7. Return the result array.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * n = number of elements in the array.
// * Each element is processed exactly once.




class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int index = n - 1;

        while(left <= right) {

            if(abs(nums[left]) > abs(nums[right])) {
                ans[index] = nums[left] * nums[left];
                left++;
            }
            else {
                ans[index] = nums[right] * nums[right];
                right--;
            }

            index--;
        }

        return ans;
    }
};