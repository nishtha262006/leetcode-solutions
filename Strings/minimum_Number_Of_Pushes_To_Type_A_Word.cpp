// LeetCode 3016 - Minimum Number of Pushes to Type Word II

// Difficulty: Medium

// Approach:

// 1. Count the frequency of every character in the word.
// 2. Sort the frequencies in descending order.
// 3. Assign the most frequent characters to the keypad positions requiring the fewest pushes:

//    * First 8 characters → **1 push**
//    * Next 8 characters → **2 pushes**
//    * Next 8 characters → **3 pushes**
//    * Remaining characters → **4 pushes**
// 4. For each frequency:

//    * Multiply the frequency by its assigned number of pushes.
//    * Add the result to the total.
// 5. Return the minimum total number of pushes.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = length of the word.
// * The alphabet size is fixed (26 lowercase letters), so sorting the frequencies is effectively constant time.



class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);

        for(char c :word)
            freq[c-'a']++;
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;
        for(int i =0; i<26; i++){
            if(freq[i] ==0)
                break;
            ans +=freq[i] *((i/8)+1);
        }
        return ans;
    }
};