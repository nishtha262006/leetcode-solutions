// LeetCode 11 - Container With Most Water

// Difficulty: Medium

// Approach:

// 1. Use the Two Pointers technique.
// 2. Initialize:

//    * One pointer at the beginning of the array.
//    * Another pointer at the end.
// 3. Calculate the area formed by the two lines:

//    * Width = distance between the pointers.
//    * Height = minimum of the two heights.
// 4. Update the maximum area if the current area is larger.
// 5. Move the pointer with the smaller height inward, since moving the taller one cannot increase the area.
// 6. Repeat until the two pointers meet.
// 7. Return the maximum area found.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = number of elements in the height array.
// * The array is traversed only once using two pointers.



class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int ans = 0;

        while(left < right) {

            int width = right - left;

            int h = min(height[left], height[right]);

            ans = max(ans, width * h);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};