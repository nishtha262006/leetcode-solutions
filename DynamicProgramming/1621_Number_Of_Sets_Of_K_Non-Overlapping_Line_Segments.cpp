// LeetCode 1621 — Number of Sets of K Non-Overlapping Line Segments
// Approach
// We need to choose exactly k non-overlapping line segments from n points.
// A segment is determined by its two endpoints.
// Since two consecutive segments are allowed to share an endpoint, the problem can be converted into selecting 2k endpoints where repeated adjacent endpoints are allowed.
// This is equivalent to choosing 2k elements from n + k - 1 positions.
// Therefore, the answer can be calculated using the combination formula:
// C(n + k - 1, 2k)
// Since the answer can be very large, calculate the combination modulo 10^9 + 7.
// Use modular inverses to perform division under the modulo.


class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        long long ans = 1;

        for (int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;
            ans = ans * modInverse(i, MOD) % MOD;
        }

        return ans;
    }

    long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod);
    }

    long long power(long long a, long long b, long long mod) {
        long long result = 1;

        while (b > 0) {
            if (b & 1) {
                result = result * a % mod;
            }

            a = a * a % mod;
            b >>= 1;
        }

        return result;
    }
};