// LeetCode 3483 — Unique 3-Digit Even Numbers

// Difficulty: Easy
// Topic: Array, Hash Set, Enumeration

// Approach
// We need to form a 3-digit even number using three digits from the array.
// The hundreds digit cannot be 0, otherwise the number would not be three digits.
// The units digit must be even (0, 2, 4, 6, 8).
// Use three nested loops to choose the hundreds, tens, and units digits.
// Make sure we don't use the same array position more than once.
// Insert every valid number into a set.
// The set automatically removes duplicate numbers when the input contains repeated digits.
// Return the size of the set.

// Since digits.length <= 10, checking all possible triples is easily fast enough.


class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;

        int n = digits.size();

        for (int i = 0; i < n; i++) {
            if (digits[i] % 2 != 0) continue;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    if (digits[k] == 0) continue;

                    int num = digits[k] * 100 + digits[j] * 10 + digits[i];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};