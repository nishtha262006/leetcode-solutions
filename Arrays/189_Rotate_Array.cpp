//LeetCode 189 - Rotate Array
Difficulty: Medium

Approach:
1. Rotating the array to the right by k steps means:
   - The last k elements move to the front.
   - The remaining elements shift to the right.
2. Use the reversal algorithm:
   - Reverse the entire array.
   - Reverse the first k elements.
   - Reverse the remaining n-k elements.
3. This rotates the array in-place without using extra space.

Time Complexity: O(n)
Space Complexity: O(1)




class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();//get array size
        k = k%n;//handle large k 

        reverse(nums.begin(),nums.end());// reverse all elements

        reverse(nums.begin(),nums.begin() +k);// reverse the first k elements

        reverse(nums.begin()+k, nums.end());// reverse the remaining elements
    }
};