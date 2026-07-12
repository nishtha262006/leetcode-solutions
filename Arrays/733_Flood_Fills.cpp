// LeetCode 733 - Flood Fill

// Difficulty: Easy

// Approach:

// 1. Use Depth First Search (DFS) or Breadth First Search (BFS).
// 2. Store the original color of the starting pixel.
// 3. If the original color is already the target color:

//    * Return the image.
// 4. Starting from the given pixel:

//    * Change its color to the target color.
//    * Visit all four adjacent pixels (up, down, left, right).
// 5. Continue only if:

//    * The pixel is within the image boundaries.
//    * Its color matches the original color.
// 6. Return the modified image after all connected pixels are updated.

// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

// * m = number of rows.
// * n = number of columns.
// * In the worst case, every pixel is visited once.

class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c,
             int oldColor, int newColor) {

        int rows = image.size();
        int cols = image[0].size();

        // Out of bounds
        if(r < 0 || c < 0 || r >= rows || c >= cols)
            return;

        // Different color
        if(image[r][c] != oldColor)
            return;

        // Change color
        image[r][c] = newColor;

        // Visit neighbors
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc,
                                  int color) {

        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};







