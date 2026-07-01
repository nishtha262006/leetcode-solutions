// LeetCode 1250 - Check If It Is a Good Array

// Difficulty: Hard

// Approach:

// 1. Compute the Greatest Common Divisor (GCD) of all the elements in the array.
// 2. Traverse the array and continuously update the current GCD.
// 3. After processing all elements:

//    * If the final GCD is 1, return true.
//    * Otherwise, return false.
// 4. This is based on Bézout's Identity:

//    * An array is good if and only if the GCD of all its elements is 1.

// Time Complexity: O(n × log m)
// Space Complexity: O(1)

// * n = number of elements in the array.
// * m = maximum value in the array.



class Solution {
public://if the gcd of all numbers i 1 then we can always form 1 using integer combination of those numbers
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];//initialize gcd

        for(int i =0; i<nums.size();i++){//traverse the array
        g = gcd(g,nums[i]);//update gcd
        }
        return g==1;//return answer
    }

};