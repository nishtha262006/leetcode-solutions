// LeetCode 744 - Find Smallest Letter Greater Than Target

// Difficulty: Easy

// Approach:

// 1. Use Binary Search on the sorted array of letters.
// 2. Initialize two pointers:

//    * `left` at the beginning.
//    * `right` at the end.
// 3. While `left <= right`:

//    * Find the middle index.
//    * If the middle letter is greater than the target:

//      * Store it as the current answer.
//      * Continue searching in the left half for a smaller valid letter.
//    * Otherwise:

//      * Search in the right half.
// 4. If no letter greater than the target is found:

//    * Return the first letter in the array (wrap-around condition).
// 5. Return the answer.

// Time Complexity: O(log n)
// Space Complexity: O(1)

// * Binary Search halves the search space in each iteration.




class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int left = 0;
        int right = letters.size() - 1;

        char ans = letters[0];

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(letters[mid] > target) {
                ans = letters[mid];
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};