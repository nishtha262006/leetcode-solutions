// LeetCode 835 — Image Overlap

// Difficulty: Medium
// Topic: Matrix, Brute Force

// Approach

// We need to find the maximum number of overlapping 1s when one binary image is shifted over the other.

// Consider every possible shift of img2 relative to img1.
// For each shift, compare the overlapping cells of the two images.
// Count how many positions contain 1 in both images.
// Keep track of the maximum overlap.
// Since the matrix size is small (n <= 30), we can simply try all possible horizontal and vertical shifts.



class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        map<pair<int, int>, int> cnt;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j] == 1) {

                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {

                            if (img2[x][y] == 1) {

                                int dx = x - i;
                                int dy = y - j;

                                cnt[{dx, dy}]++;

                                ans = max(ans, cnt[{dx, dy}]);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};