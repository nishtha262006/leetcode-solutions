
// LeetCode 1927 - Sum Game

// Difficulty: Medium

// Approach

// The key is to compare the sum of digits on the two sides of ?.

// Let:

// leftSum = sum of known digits in the first half
// rightSum = sum of known digits in the second half
// leftQ = number of ? in the first half
// rightQ = number of ? in the second half

// Alice wins if she can make the two halves have different sums.


class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int cnt1 = 0, cnt2 = 0;
        int s1 = 0, s2 = 0;

        // Left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                cnt1++;
            } else {
                s1 += num[i] - '0';
            }
        }

        // Right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                cnt2++;
            } else {
                s2 += num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice wins
        if ((cnt1 + cnt2) % 2 == 1) {
            return true;
        }

        // Check whether Bob can force equality
        return s1 - s2 != 9 * (cnt2 - cnt1) / 2;
    }
};