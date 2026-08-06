// LeetCode 3345 - Smallest Divisible Digit Product I

// Difficulty: Easy

// Approach:

// 1. Start checking numbers from `n`.
// 2. For each number:

//    * Compute the product of its digits.
// 3. Check whether the digit product is divisible by `t`.
// 4. If it is divisible:

//    * Return the current number.
// 5. Otherwise:

//    * Increment the number and repeat the process.

// Time Complexity: O(k × d)
// Space Complexity: O(1)

// * k = number of integers checked until the answer is found.
// * d = number of digits in each integer.



class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; ; i++){
            int product = 1;
            int x = i;
            while(x>0){
                product *=(x%10);
                x/=10;
            }
            if(product%t ==0)
            return i ;
        }
    }
};