// LeetCode 167 - Two Sum II - Input Array Is Sorted

// Difficulty: Medium

// Approach:

// 1. Use the Two Pointers technique.
// 2. Initialize one pointer at the beginning and another at the end of the sorted array.
// 3. Calculate the sum of the two elements:

//    * If the sum equals the target, return their 1-based indices.
//    * If the sum is smaller than the target, move the left pointer to the right.
//    * If the sum is greater than the target, move the right pointer to the left.
// 4. Continue until the pair is found.
// 5. Return the required indices.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * The array is traversed once using two pointers without extra space.




class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while(left < right) {

            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left + 1, right + 1};
            }

            else if(sum < target) {
                left++;
            }

            else {
                right--;
            }
        }

        return {};
    }
};