// LeetCode 49 - Group Anagrams

// Difficulty: Medium

// Approach:

// 1. Use a hash map to group words.
// 2. For each string in the input:

//    * Sort its characters to create a unique key.
// 3. Store the original string in the vector corresponding to its sorted key.
// 4. After processing all strings, collect all the grouped values from the hash map.
// 5. Return the grouped anagrams.

// Time Complexity: O(n × k log k)
// Space Complexity: O(n × k)

// * n = number of strings.
// * k = maximum length of a string.
// * Sorting each string takes O(k log k).



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string str : strs) {

            string key = str;
            sort(key.begin(), key.end());

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};