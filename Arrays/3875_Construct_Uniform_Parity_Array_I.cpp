// LeetCode 3875 - Construct Uniform Parity Array I

// Difficulty: Easy

// Approach:

// 1. The key observation is that the answer is **always `true`**.
// 2. If all elements in `nums1` already have the same parity:

//    * If they are all even, keep them unchanged.
//    * If they are all odd, keep them unchanged.
// 3. If `nums1` contains both odd and even numbers:

//    * For every element, choose another element having the opposite parity.
//    * Subtracting numbers with different parity always gives an odd number:

//      * `odd - even = odd`
//      * `even - odd = odd`
// 4. Therefore, we can always construct `nums2` with all elements odd.
// 5. Hence, regardless of the input, the answer is always `true`.

// Time Complexity: O(1)
// Space Complexity: O(1)

// * No traversal or extra data structure is required because the result is always `true`.



class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
        //the result will never be false 
        //here there are two situation where the nums1 can be even/odd or the combination of atleast one odd and one even
        // when the nums1 is completely odd or even the answer is simple
        // when it is the combination of atleast one odd and one ven then there we subtract the number with the opposite parity to get the desired result
        //here we only want to check whether the condition is true or false
        //so here the condition can never be false as one of the both desired condition will always be present
        //therefore the answer to this is always true 
    }
};