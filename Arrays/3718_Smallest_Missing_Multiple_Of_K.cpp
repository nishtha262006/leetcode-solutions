// LeetCode 3718 - Smallest Missing Multiple of K

// Difficulty: Easy

// Approach
// Put all elements of nums into a Hash Set.
// Start checking positive multiples of k:
// k
// 2k
// 3k
// 4k
// ...
// For each multiple, check whether it exists in the set.
// The first multiple that is not present is the answer.


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for (int x : nums) {
            s.insert(x);
        }

        for (int i = 1; ; i++) {
            int x = k * i;

            if (!s.count(x)) {
                return x;
            }
        }
    }
};