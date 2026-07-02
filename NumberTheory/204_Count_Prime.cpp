// LeetCode 204 - Count Primes

// Difficulty: Medium

// Approach:

// 1. Use the Sieve of Eratosthenes algorithm.
// 2. Create a boolean array to mark prime numbers.
// 3. Initially, assume all numbers from 2 to n−1 are prime.
// 4. Starting from 2:

//    * If the current number is prime, mark all of its multiples as non-prime.
// 5. Continue until the square of the current number exceeds n.
// 6. Count all numbers that remain marked as prime.
// 7. Return the total count.

// Time Complexity: O(n log log n)
// Space Complexity: O(n)

// * The sieve efficiently eliminates non-prime numbers by marking their multiples.



class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2)
            return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i * i < n; i++) {

            if(isPrime[i]) {

                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        for(int i = 2; i < n; i++) {

            if(isPrime[i])
                count++;
        }

        return count;
    }
};