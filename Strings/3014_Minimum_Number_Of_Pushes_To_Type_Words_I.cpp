// LeetCode 3014 - Minimum Number of Pushes to Type Word I

// Difficulty: Easy

// Approach:

// 1. Observe that the first 8 letters assigned to the keypad require only **1 push** each.
// 2. The next 8 letters require **2 pushes**, the next 8 require **3 pushes**, and the remaining letters require **4 pushes**.
// 3. Let `n` be the length of the word.
// 4. Iterate through each character position in the word:

//    * The number of pushes required for the `i`-th character is `(i / 8) + 1`.
// 5. Add the required pushes for every character.
// 6. Return the total number of pushes.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = length of the word.
// * Each character is processed exactly once.


class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        for(int i =0 ; i<word.size(); i++){
            ans +=(i/8)+1;
        }
        return ans;
    }
};