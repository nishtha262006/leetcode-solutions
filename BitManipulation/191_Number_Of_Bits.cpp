// LeetCode 191 - Number of 1 Bits

// Difficulty: Easy

// Approach:

// 1. Initialize a counter to store the number of set bits.
// 2. Traverse the bits of the given integer.
// 3. In each iteration:

//    * Check whether the least significant bit is 1.
//    * If it is, increment the counter.
// 4. Right shift the number by one bit.
// 5. Repeat until all bits have been processed.
// 6. Return the total count of set bits.

// Time Complexity: O(32)
// Space Complexity: O(1)

// * Since an integer has a fixed number of bits (32), the algorithm runs in constant time.



class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;//initial count = 0
        while(n>0){
            if(n&1)// check the last bit
                count++;//if 1 increase the count
            n>>=1;//right shift
        }
        return count;//final answer
        
    }
};