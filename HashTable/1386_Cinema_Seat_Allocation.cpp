// LeetCode 1386 - Cinema Seat Allocation

// Difficulty: Medium

// Approach
// Each family needs 4 consecutive seats.
// The only possible groups of 4 seats are:
// Left: 2,3,4,5
// Middle: 4,5,6,7
// Right: 6,7,8,9
// Use a HashMap to store reserved seats only for rows that have reservations.
// For each row, use a bitmask to represent which seats are reserved.
// Check:
// If both left and right groups are free → add 2.
// Otherwise, if left, middle, or right group is free → add 1.
// Otherwise → add 0.
// Rows with no reservations can always accommodate 2 families, so initially add:
// (n - number of rows with reservations) × 2





class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats of every row as a bitmask
        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << (col - 1));
        }

        int ans = (n - mp.size()) * 2;

        // Check only rows having reservations
        for (auto& [row, mask] : mp) {

            // seats 2,3,4,5
            bool left = (mask & 0b0000011110) == 0;

            // seats 6,7,8,9
            bool right = (mask & 0b0111100000) == 0;

            // If both sides are available -> 2 families
            if (left && right) {
                ans += 2;
            }

            // Otherwise, if either side is available
            else if (left || right) {
                ans += 1;
            }

            // Neither side available, try middle
            else if ((mask & 0b0001111000) == 0) {
                ans += 1;
            }
        }

        return ans;
    }
};