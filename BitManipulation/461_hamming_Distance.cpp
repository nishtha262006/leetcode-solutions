// LeetCode 461 - Hamming Distance

// Difficulty: Easy

// Approach:

// 1. Compute the XOR of the two integers.
// 2. In the XOR result:

//    * A bit is 1 if the corresponding bits of the two numbers are different.
// 3. Count the number of set bits (1s) in the XOR result.
// 4. Return the count as the Hamming Distance.

// Time Complexity: O(32)
// Space Complexity: O(1)

// * Since integers have a fixed number of bits, the algorithm runs in constant time.






class Solution {
public:
    int hammingDistance(int x, int y) {

        int xorValue = x ^ y;
        int count = 0;

        while(xorValue) {

            count += (xorValue & 1);

            xorValue >>= 1;
        }

        return count;
    }
};