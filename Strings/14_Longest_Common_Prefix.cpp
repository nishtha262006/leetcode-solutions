// LeetCode 14 - Longest Common Prefix

// Difficulty: Easy

// Approach:

// 1. Assume the first string is the common prefix.
// 2. Compare each character of the first string with the corresponding character in all other strings.
// 3. If any string ends or a mismatch is found:

//    * Return the prefix obtained so far.
// 4. If all characters match, continue checking.
// 5. Return the complete first string if it is the common prefix for all strings.

// Time Complexity: O(n × m)
// Space Complexity: O(1)

// * n = number of strings.
// * m = length of the shortest string.





class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        

        if(strs.empty()){
            return "";
        }
        for(int i =0; i<strs[0].size(); i++){
            char current = strs[0][i];

            for(int j =1; j<strs.size();j++){

                if(i>=strs[j].size()|| strs[j][i] != current){

                    return strs[0].substr(0,i);
                }
            }
        }

        return strs[0];
    }
};