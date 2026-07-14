// LeetCode 463 - Island Perimeter

// Difficulty: Easy

// Approach:

// 1. Traverse every cell in the grid.
// 2. For each land cell (`1`):

//    * Add 4 to the perimeter.
// 3. Check the adjacent cells:

//    * If the cell above is land, subtract 2.
//    * If the cell to the left is land, subtract 2.
// 4. Continue until all cells are processed.
// 5. Return the total perimeter.

// Time Complexity: O(m × n)
// Space Complexity: O(1)

// * m = number of rows.
// * n = number of columns.
// * Each cell is visited exactly once.





class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int perimeter = 0;

        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 1) {

                    perimeter += 4;

                    // Up
                    if(i > 0 && grid[i-1][j] == 1)
                        perimeter--;

                    // Down
                    if(i < rows-1 && grid[i+1][j] == 1)
                        perimeter--;

                    // Left
                    if(j > 0 && grid[i][j-1] == 1)
                        perimeter--;

                    // Right
                    if(j < cols-1 && grid[i][j+1] == 1)
                        perimeter--;
                }
            }
        }

        return perimeter;
    }
};