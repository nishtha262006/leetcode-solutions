// LeetCode 2996 - Smallest Missing Integer Greater Than Sequential Prefix Sum

// Difficulty: Easy

// Approach:

// 1. Start from the first element and calculate the **longest sequential prefix sum**.
// 2. A sequential prefix means consecutive values where:

//    * `nums[i] == nums[i-1] + 1`
// 3. Add these sequential elements to obtain the prefix sum.
// 4. Put all elements of the array into a **Hash Set**.
// 5. Starting from the prefix sum:

//    * If the number already exists in the set, increment it.
//    * Continue until finding a number that does not exist.
// 6. Return that number.

// ### Example

// ```text
// nums = [1,2,3,2,5]

// Sequential prefix:
// 1 → 1 + 2 → 1 + 2 + 3 = 6

// Starting from 6:
// 6 is not present

// Answer = 6
// ```

// Time Complexity: O(n)
// Space Complexity: O(n)

// * The array is traversed to calculate the prefix sum.
// * A Hash Set provides O(1) average lookup.



class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        unordered_set<int> st(nums.begin(), nums.end());

        while(st.count(sum))
            sum++;

        return sum;
    }
};