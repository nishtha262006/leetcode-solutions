// LeetCode 136 - Single Number

// Difficulty: Easy

// Approach:

// 1. Initialize a variable `result` to 0.
// 2. Traverse all elements in the array.
// 3. Perform the XOR operation between `result` and each element.
// 4. Since:

//    * `x ^ x = 0`
//    * `x ^ 0 = x`
//    * XOR is commutative and associative,
//      all duplicate elements cancel each other out.
// 5. The remaining value is the element that appears only once.
// 6. Return the result.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * The array is traversed once, and only one extra variable is used.



class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for(int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};