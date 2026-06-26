// LeetCode 151 - Reverse Words in a String

// Difficulty: Medium

// Approach:

// 1. Traverse the string and extract each word.
// 2. Ignore leading, trailing, and multiple spaces between words.
// 3. Store each valid word.
// 4. Reverse the order of the stored words.
// 5. Join the words with a single space.
// 6. Return the resulting string.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * Extra space is used to store the individual words.



class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);

        vector<string> words;

        string word;

        while(ss >> word) {
            words.push_back(word);
        }

        string result = "";

        for(int i = words.size() - 1; i >= 0; i--) {

            result += words[i];

            if(i != 0) {
                result += " ";
            }
        }

        return result;
    }
};