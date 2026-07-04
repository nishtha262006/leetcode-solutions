// LeetCode 476 - Number Complement

// Difficulty: Easy

// Approach:

// 1. Find the number of bits required to represent the given number.
// 2. Create a bitmask with all those bits set to 1.
// 3. Compute the complement by performing:

//    * `num XOR mask`
// 4. Return the resulting value.

// Time Complexity: O(log n)
// Space Complexity: O(1)

// * Only the bits required to represent the number are processed.


class Solution {
public:
    int findComplement(int num) {

        int mask = 1;

        while(mask < num) {
            mask = (mask << 1) | 1;
        }

        return mask ^ num;
    }
};