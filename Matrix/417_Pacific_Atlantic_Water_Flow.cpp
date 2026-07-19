// LeetCode 417 - Pacific Atlantic Water Flow

// Difficulty: Medium

// Approach:

// 1. Treat the Pacific and Atlantic oceans as separate starting points.
// 2. Perform DFS (or BFS) from all cells adjacent to the Pacific Ocean and mark all reachable cells.
// 3. Perform DFS (or BFS) from all cells adjacent to the Atlantic Ocean and mark all reachable cells.
// 4. During traversal:

//    * Move only to neighboring cells with height **greater than or equal to** the current cell.
//    * This simulates the reverse flow of water.
// 5. Find all cells that are reachable from both oceans.
// 6. Return the list of these coordinates.

// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

// * m = number of rows, n = number of columns.
// * Each cell is visited at most once for each ocean.





class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int row, int col) {

        visited[row][col] = true;

        for(auto d : dir) {
            int nr = row + d[0];
            int nc = col + d[1];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if(visited[nr][nc])
                continue;

            if(heights[nr][nc] < heights[row][col])
                continue;

            dfs(heights, visited, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));

        for(int i=0;i<m;i++) {
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic,i,n-1);
        }

        for(int j=0;j<n;j++) {
            dfs(heights,pacific,0,j);
            dfs(heights,atlantic,m-1,j);
        }

        vector<vector<int>> ans;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {

                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};