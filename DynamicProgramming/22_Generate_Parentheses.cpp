// LeetCode 22 - Generate Parentheses

// Difficulty: Medium

// Approach:

// 1. Use **Backtracking** to generate all valid combinations.
// 2. Maintain:

//    * The current string being built.
//    * The number of opening parentheses used.
//    * The number of closing parentheses used.
// 3. At each step:

//    * Add `'('` if the number of opening parentheses is less than `n`.
//    * Add `')'` if the number of closing parentheses is less than the number of opening parentheses.
// 4. When the current string reaches a length of `2 × n`:

//    * Store it as a valid combination.
// 5. Continue exploring all valid possibilities recursively.
// 6. Return the list of generated parentheses strings.

// Time Complexity: O(4ⁿ / √n)
// Space Complexity: O(n)

// * The number of valid combinations is the **n-th Catalan Number**.
// * The recursion stack requires at most `O(n)` space.




class Solution {
public:

    vector<string> ans;

    void solve(string curr, int open, int close, int n) {

        if(curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if(open < n) {
            solve(curr + "(", open + 1, close, n);
        }

        if(close < open) {
            solve(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {

        solve("", 0, 0, n);

        return ans;
    }
};