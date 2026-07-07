// LeetCode 238 - Product of Array Except Self

// Difficulty: Medium

// Approach:

// 1. Create an output array to store the result.
// 2. Traverse the array from left to right:

//    * Store the product of all elements to the left of each index.
// 3. Traverse the array from right to left:

//    * Maintain the product of all elements to the right.
//    * Multiply it with the corresponding left product already stored in the output array.
// 4. Return the output array.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * The output array is not counted as extra space.
// * Only a few additional variables are used.



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> answer(n);

        // Prefix products
        answer[0] = 1;

        for(int i = 1; i < n; i++) {
            answer[i] = answer[i-1] * nums[i-1];
        }

        // Suffix products
        int suffix = 1;

        for(int i = n-1; i >= 0; i--) {

            answer[i] *= suffix;

            suffix *= nums[i];
        }

        return answer;
    }
};