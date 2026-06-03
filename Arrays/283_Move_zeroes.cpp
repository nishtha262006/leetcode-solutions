LeetCode 283 - Move Zeroes
Difficulty: Easy

Approach:
1. Use a pointer to track the position where the next non-zero element should be placed.
2. Traverse the array.
3. Whenever a non-zero element is found, swap it with the element at the pointer position.
4. Move the pointer forward.
5. By the end, all non-zero elements are at the front and all zeroes are moved to the end.

Time Complexity: O(n)
Space Complexity: O(1)


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j =0;//pointer for non -zero position
        for(int i=0;i<nums.size();i++){//traverse the array
            if(nums[i]!=0){//if current element is zero
                swap(nums[i],nums[j]);//if yes
                j++;
            }
        }
    }
};