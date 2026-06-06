// LeetCode 53 - Maximum Subarray
// Difficulty: Medium

// Approach:
// 1. Use Kadane's Algorithm.
// 2. Maintain a running sum of the current subarray.
// 3. At each element:
//    - Either start a new subarray from the current element.
//    - Or extend the existing subarray.
// 4. Keep track of the maximum sum seen so far.
// 5. The maximum sum obtained is the answer.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum =0;//Store running sum of current subarray
        int maxSum = nums[0];//stores best answer found

        for(int num:nums){//visit every element
            currentSum +=num;//Extend current subarray
            maxSum = max(maxSum, currentSum);// if current subarray is better than previous answer,update

            if(currentSum<0){//negative sums only hurt future subarrays
                currentSum=0;// so discard them
            }
        }
        return maxSum;// return maxSum
    }
};