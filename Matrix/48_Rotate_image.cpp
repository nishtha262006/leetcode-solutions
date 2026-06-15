// LeetCode 48 - Rotate Image

// Difficulty: Medium

// Approach:

// Rotate the matrix by 90 degrees clockwise in-place.
// First, transpose the matrix:
// Swap matrix[i][j] with matrix[j][i].
// Then, reverse each row of the matrix.
// The combination of transpose and row reversal results in a 90-degree clockwise rotation.
// Return the modified matrix.

// Time Complexity: O(n²)
// Space Complexity: O(1)


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        

        int n = matrix.size();//get the matrix size

        //step 1 transpose
        for(int i =0;i<n;i++){//visit every row
            for(int j = i+1;j<n;j++){//start after diagonal

                swap(matrix[i][j] , matrix[j][i]);//swap rows to columns
            }
        }
        //step 2 reverse each row

        for(int i =0;i<n;i++){//process every row
            reverse(matrix[i].begin(), matrix[i].end());//reverse the ro which means the start goes to the end and the end goes to the start
        }
    }
};