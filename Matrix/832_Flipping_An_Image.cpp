// LeetCode 832 - Flipping an Image

// Difficulty: Easy

// Approach:

// Traverse each row of the binary matrix.
// Reverse the row to perform the horizontal flip.
// Invert each element:
// Change 0 to 1.
// Change 1 to 0.
// Repeat for all rows.
// Return the modified matrix.

// Time Complexity: O(m × n)
// Space Complexity: O(1)


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& row:image){//traverse every row
            reverse(row.begin(), row.end());// reverse the row
                for(int j =0; j<row.size();j++){//visit every element
                    row[j] = 1-row[j];//invert the elements
                }
        }
        return image;//return answer 
    }
};