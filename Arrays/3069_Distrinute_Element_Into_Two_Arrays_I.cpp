// LeetCode 3069 - Distribute Elements Into Two Arrays I

// Difficulty: Easy

// Approach
// Create two arrays:
// arr1
// arr2
// Put the first element of nums into arr1.
// Put the second element into arr2.
// For every remaining element:
// Compare the last element of arr1 and arr2.
// If arr1.back() > arr2.back(), add the current element to arr1.
// Otherwise, add it to arr2.
// Finally, concatenate arr2 to arr1.
// Return the resulting array.


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};