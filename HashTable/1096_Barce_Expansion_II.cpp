class Solution {
public:
    set<string> st;

    void dfs(string exp) {
        // No more braces
        int j = exp.find('}');

        if (j == string::npos) {
            st.insert(exp);
            return;
        }

        // Find matching '{'
        int i = exp.rfind('{', j);

        // Part before '{'
        string left = exp.substr(0, i);

        // Part after '}'
        string right = exp.substr(j + 1);

        // Content inside braces
        string inside = exp.substr(i + 1, j - i - 1);

        // Split by comma
        string current = "";

        for (int k = 0; k <= inside.size(); k++) {

            if (k == inside.size() || inside[k] == ',') {

                dfs(left + current + right);

                current = "";
            }
            else {
                current += inside[k];
            }
        }
    }

    vector<string> braceExpansionII(string expression) {
        dfs(expression);

        return vector<string>(st.begin(), st.end());
    }
};