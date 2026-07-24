// LeetCode 55 - Jump Game

// Difficulty: Medium

// Approach:

// 1. Use a Greedy approach to keep track of the farthest index that can be reached.
// 2. Initialize a variable `maxReach = 0`.
// 3. Traverse the array from left to right.
// 4. If the current index is greater than `maxReach`, the current position is unreachable, so return `false`.
// 5. Update:

//    * `maxReach = max(maxReach, currentIndex + nums[currentIndex])`
// 6. If `maxReach` reaches or exceeds the last index at any point, return `true`.
// 7. If the traversal completes, return whether the last index is reachable.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = number of elements in the array.
// * The array is traversed only once using constant extra space.



class Solution {
public:
    bool canJump(vector<int>& nums) {

        int reach = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(i > reach)
                return false;

            reach = max(reach, i + nums[i]);

            if(reach >= nums.size() - 1)
                return true;
        }

        return true;
    }
};