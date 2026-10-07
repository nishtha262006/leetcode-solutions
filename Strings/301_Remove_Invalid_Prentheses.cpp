class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int index, int leftCount, int rightCount,
             int leftRemove, int rightRemove, string curr) {

        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 &&
                leftCount == rightCount) {
                ans.insert(curr);
            }
            return;
        }

        char ch = s[index];

        // Remove current '('
        if (ch == '(' && leftRemove > 0) {
            dfs(s, index + 1, leftCount, rightCount,
                leftRemove - 1, rightRemove, curr);
        }

        // Remove current ')'
        if (ch == ')' && rightRemove > 0) {
            dfs(s, index + 1, leftCount, rightCount,
                leftRemove, rightRemove - 1, curr);
        }

        // Keep current character
        if (ch == '(') {
            dfs(s, index + 1, leftCount + 1, rightCount,
                leftRemove, rightRemove, curr + ch);
        }
        else if (ch == ')') {
            // Cannot keep ')' if there is no '(' to match it
            if (leftCount > rightCount) {
                dfs(s, index + 1, leftCount, rightCount + 1,
                    leftRemove, rightRemove, curr + ch);
            }
        }
        else {
            // Normal character
            dfs(s, index + 1, leftCount, rightCount,
                leftRemove, rightRemove, curr + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum number of '(' and ')' to remove
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        dfs(s, 0, 0, 0,
            leftRemove, rightRemove, "");

        return vector<string>(ans.begin(), ans.end());
    }
};