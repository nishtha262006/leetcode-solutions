// LeetCode 200 - Number of Islands

// Difficulty: Medium

// Approach:

// 1. Traverse every cell in the grid.
// 2. Whenever an unvisited land cell (`'1'`) is found:

//    * Increment the island count.
//    * Perform a DFS (or BFS) starting from that cell.
// 3. During the traversal:

//    * Mark all connected land cells as visited.
//    * Explore the four directions (up, down, left, right).
// 4. Continue until all cells have been processed.
// 5. Return the total number of islands.

// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

// * m = number of rows, n = number of columns.
// * In the worst case, the recursion stack or queue may contain all land cells.



class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {

        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0')
            return;

        grid[row][col] = '0';

        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1') {

                    islands++;

                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};