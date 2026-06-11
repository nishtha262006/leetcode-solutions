// LeetCode 287 - Find the Duplicate Number
// Difficulty: Medium

// Approach:
// 1. Treat the array as a linked list:
//    - Each index points to nums[index].
// 2. Use Floyd's Cycle Detection Algorithm (Tortoise and Hare).
// 3. First phase:
//    - Move slow by one step.
//    - Move fast by two steps.
//    - They will eventually meet inside the cycle.
// 4. Second phase:
//    - Reset slow to the beginning.
//    - Move both pointers one step at a time.
//    - The point where they meet again is the duplicate number.
// 5. Return the duplicate number.

// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        slow = 0;

        while(slow!=fast){
            slow= nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};