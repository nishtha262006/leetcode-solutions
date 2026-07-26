// LeetCode 628 - Maximum Product of Three Numbers

// Difficulty: Easy

// Approach:

// 1. Sort the array in non-decreasing order.
// 2. Observe that the maximum product can come from either:

//    * The three largest numbers.
//    * The two smallest (possibly negative) numbers and the largest number.
// 3. Compute:

//    * Product of the last three elements.
//    * Product of the first two elements and the last element.
// 4. Return the maximum of the two computed products.

// Time Complexity: O(n log n)
// Space Complexity: O(1)

// * n = number of elements in the array.
// * Sorting dominates the time complexity.



class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int option1 = nums[n-1] * nums[n-2] * nums[n-3];

        int option2 = nums[0] * nums[1] * nums[n-1];

        return max(option1, option2);
    }
};