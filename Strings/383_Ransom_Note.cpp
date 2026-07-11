// LeetCode 383 - Ransom Note

// Difficulty: Easy

// Approach:

// 1. Count the frequency of each character in the magazine string.
// 2. Traverse each character of the ransom note.
// 3. For each character:

//    * Check if it is available in the frequency count.
//    * If not, return false.
//    * Otherwise, decrease its frequency.
// 4. If all characters are successfully matched, return true.

// Time Complexity: O(n + m)
// Space Complexity: O(1)

// * n = length of the ransom note.
// * m = length of the magazine.
// * Since there are only 26 lowercase English letters, the extra space is constant.




class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> freq(26, 0);

        // Count characters in magazine
        for(char ch : magazine){
            freq[ch - 'a']++;
        }

        // Use characters for ransom note
        for(char ch : ransomNote){

            freq[ch - 'a']--;

            if(freq[ch - 'a'] < 0){
                return false;
            }
        }

        return true;
    }
};