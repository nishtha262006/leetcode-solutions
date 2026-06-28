// LeetCode 6 - Zigzag Conversion

// Difficulty: Medium

// Approach:

// 1. Handle the special case where the number of rows is 1.
// 2. Create a string for each row.
// 3. Traverse the characters of the input string.
// 4. Place each character into the current row.
// 5. Change the direction:

//    * Move downward until the last row.
//    * Move upward diagonally until the first row.
// 6. Repeat until all characters are placed.
// 7. Concatenate all row strings to obtain the final result.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * Additional space is used to store the characters for each row.




class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = false;

        for(char ch : s) {

            rows[currentRow] += ch;

            if(currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            if(goingDown)
                currentRow++;
            else
                currentRow--;
        }

        string result = "";

        for(string row : rows) {
            result += row;
        }

        return result;
    }
};