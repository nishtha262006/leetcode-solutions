// LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length

// Difficulty: Medium

// Approach:

// 1. Use the Sliding Window technique.
// 2. Count the number of vowels in the first window of size k.
// 3. Store this count as the current maximum.
// 4. Slide the window one character at a time:

//    * Remove the leftmost character from the count if it is a vowel.
//    * Add the new rightmost character to the count if it is a vowel.
// 5. Update the maximum vowel count after each window.
// 6. Return the maximum number of vowels found in any substring of length k.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * Each character is processed at most twice while sliding the window.




class Solution {
public:

    bool isVowel(char ch) {
        return ch=='a' || ch=='e' ||
               ch=='i' || ch=='o' ||
               ch=='u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // First window
        for(int i=0; i<k; i++) {

            if(isVowel(s[i]))
                count++;
        }

        int ans = count;

        // Slide window
        for(int i=k; i<s.size(); i++) {

            if(isVowel(s[i-k]))
                count--;

            if(isVowel(s[i]))
                count++;

            ans = max(ans, count);
        }

        return ans;
    }
};