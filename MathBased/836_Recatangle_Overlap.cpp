// LeetCode 836 — Rectangle Overlap

// Difficulty: Easy
// Topic: Math, Geometry

// Approach

// We are given two axis-aligned rectangles:

// [x1, y1, x2, y2]

// where (x1, y1) is the bottom-left corner and (x2, y2) is the top-right corner. The rectangles overlap only if their intersection has positive area. If they only touch at an edge or corner, the answer is false.

// Step-by-Step

// We can check the width and height of their common area.

// 1. Find the overlapping x-range

// The left boundary of the overlap is:

// max(rec1[0], rec2[0])

// The right boundary is:

// min(rec1[2], rec2[2])

// So the overlapping width is:

// min(rec1[2], rec2[2]) - max(rec1[0], rec2[0])
// 2. Find the overlapping y-range

// Similarly:

// min(rec1[3], rec2[3]) - max(rec1[1], rec2[1])

// gives the overlapping height.

// 3. Check whether both are positive

// For a positive area, both width and height must be greater than 0.

// width > 0 && height > 0

// If either is 0, the rectangles only touch and do not overlap.


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) &&
               max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }
};