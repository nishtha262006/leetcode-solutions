// LeetCode 1464 - Maximum Product of Two Elements in an Array

// Difficulty: Easy

// Approach:

// 1. Traverse the array to find the largest and second largest elements.
// 2. Initialize two variables to keep track of these maximum values.
// 3. For each element:

//    * If it is greater than the current largest element:

//      * Update the second largest with the previous largest.
//      * Update the largest element.
//    * Otherwise, if it is greater than the second largest:

//      * Update the second largest element.
// 4. Compute the result using the formula:

//    * `(largest - 1) × (secondLargest - 1)`
// 5. Return the computed product.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = number of elements in the array.
// * The array is traversed only once using constant extra space.



class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int max1 = 0;
        int max2 = 0;

        for(int num : nums) {

            if(num > max1) {

                max2 = max1;
                max1 = num;
            }

            else if(num > max2) {

                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};