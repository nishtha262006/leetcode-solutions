// LeetCode 994 - Rotting Oranges

// Difficulty: Medium

// Approach:

// 1. Use Breadth First Search (BFS) to simulate the spread of rot.
// 2. Traverse the grid:

//    * Add all initially rotten oranges to a queue.
//    * Count the number of fresh oranges.
// 3. Process the queue level by level:

//    * Each level represents one minute.
//    * Spread the rot to adjacent fresh oranges (up, down, left, right).
//    * Mark newly rotten oranges and add them to the queue.
// 4. Decrease the fresh orange count as oranges become rotten.
// 5. Continue until the queue is empty.
// 6. If fresh oranges remain, return `-1`; otherwise, return the total minutes taken.

// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

// * m = number of rows, n = number of columns.
// * Each cell is visited at most once during the BFS traversal.



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2)
                    q.push({i,j});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;

        int minutes = 0;

        vector<vector<int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()) {

            int size = q.size();
            bool rotted = false;

            while(size--) {

                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for(auto d : dir) {

                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                        continue;

                    if(grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    fresh--;
                    rotted = true;

                    q.push({nr,nc});
                }
            }

            if(rotted)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};