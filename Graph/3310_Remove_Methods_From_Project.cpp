// LeetCode 3310 - Remove Methods From Project

// Difficulty: Medium

// Approach:

// 1. Represent the method invocations as a directed graph using an adjacency list.
// 2. Perform a DFS (or BFS) starting from the buggy method `k`:

//    * Mark every reachable method as **suspicious**.
// 3. Check every invocation:

//    * If a non-suspicious method invokes a suspicious method, the suspicious group cannot be removed.
//    * In this case, return all methods.
// 4. Otherwise:

//    * Return all methods that are **not** marked as suspicious.

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

// * n = number of methods.
// * m = number of invocation relationships.
// * Each method and invocation is processed at most once.



class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<bool> suspicious(n, false);
        vector<bool> vis(n, false);

        vector<vector<int>> g(n), f(n);

        for (auto &e : invocations) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            f[a].push_back(b);
            f[b].push_back(a);
        }

        function<void(int)> dfs = [&](int u) {
            suspicious[u] = true;
            for (int v : g[u]) {
                if (!suspicious[v])
                    dfs(v);
            }
        };

        dfs(k);

        function<void(int)> dfs2 = [&](int u) {
            vis[u] = true;
            for (int v : f[u]) {
                if (!vis[v]) {
                    suspicious[v] = false;
                    dfs2(v);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !vis[i])
                dfs2(i);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};