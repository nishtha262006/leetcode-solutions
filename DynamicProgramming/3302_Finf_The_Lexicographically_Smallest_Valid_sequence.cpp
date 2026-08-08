// LeetCode 3302 - Find the Lexicographically Smallest Valid Sequence

// Difficulty: Medium

// Approach:

// 1. We need to select indices from `word1` that form `word2` with **at most one character mismatch**.
// 2. Precompute a suffix array:

//    * `suf[i]` = number of characters of `word2` that can still be matched starting from `word1[i]`.
// 3. Traverse `word1` from left to right while matching `word2`.
// 4. At each position:

//    * If `word1[i] == word2[j]`, we can select this index normally.
//    * If they differ, we can use our **one allowed mismatch**.
// 5. Before using a mismatch, check whether the remaining part of `word2` can be matched after this position using `suf`.
// 6. Always choose the earliest possible index because the required answer is the **lexicographically smallest index sequence**.
// 7. If we successfully select `word2.length()` indices, return them; otherwise return an empty vector.

// Time Complexity: O(n + m)
// Space Complexity: O(n)

// * `n = word1.length()`
// * `m = word2.length()`
// * The suffix preprocessing and greedy scan are linear.




class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        // suf[i] = number of characters of word2
        // that can be matched starting from word1[i]
        vector<int> suf(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {

            if (word1[i] == word2[j]) {
                suf[i] = suf[i + 1] + 1;
                j--;
            }
            else {
                suf[i] = suf[i + 1];
            }
        }

        // If even without mismatch we cannot match enough,
        // we may still use one mismatch.
        vector<int> ans;

        int i = 0;
        j = 0;
        bool usedMismatch = false;

        while (i < n && j < m) {

            // Exact match
            if (word1[i] == word2[j]) {

                ans.push_back(i);
                i++;
                j++;
            }

            // Use the one mismatch
            else if (!usedMismatch &&
                     (m - j - 1 <= suf[i + 1])) {

                ans.push_back(i);
                usedMismatch = true;
                i++;
                j++;
            }

            else {
                i++;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};