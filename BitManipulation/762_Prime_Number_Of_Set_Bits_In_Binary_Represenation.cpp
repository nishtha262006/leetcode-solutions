// LeetCode 762 - Prime Number of Set Bits in Binary Representation

// Difficulty: Easy

// Approach:

// 1. Iterate through every number in the given range.
// 2. For each number:

//    * Count the number of set bits (1s) in its binary representation.
// 3. Check whether the count of set bits is a prime number.
// 4. If the count is prime, increment the answer.
// 5. After processing all numbers, return the total count.

// Time Complexity: O(n × log m)
// Space Complexity: O(1)

// * n = number of integers in the range.
// * m = maximum value in the range.
// * Counting set bits takes O(log m) time for each number.



class Solution {
public:

    bool isPrime(int n) {

        if(n < 2)
            return false;

        for(int i = 2; i * i <= n; i++) {

            if(n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {

        int count = 0;

        for(int i = left; i <= right; i++) {

            int bits = __builtin_popcount(i);

            if(isPrime(bits))
                count++;
        }

        return count;
    }
};