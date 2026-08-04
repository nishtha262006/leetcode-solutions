// LeetCode 3731 - Find Missing Elements

// Difficulty: Easy

// Approach:

// 1. Find the smallest and largest elements in the array.
// 2. Store all elements in a Hash Set for O(1) lookup.
// 3. Traverse every integer between the minimum and maximum values.
// 4. For each number:

//    * If it is not present in the Hash Set, add it to the answer list.
// 5. Return the list of missing elements in sorted order.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * n = number of elements in the array.
// * Each element is inserted into the hash set once, and each number in the range is checked once.




class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for(int i = mn + 1; i < mx; i++) {

            if(!st.count(i))
                ans.push_back(i);
        }

        return ans;
    }
};