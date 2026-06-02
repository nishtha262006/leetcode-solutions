//LeetCode 35 - Search Insert Position
Difficulty: Easy

Approach:
1. Use Binary Search on the sorted array.
2. Find the middle element.
3. If the target is found, return its index.
4. If the target is greater, search in the right half.
5. If the target is smaller, search in the left half.
6. If the target is not found, return the position where it should be inserted.

Time Complexity: O(log n)
Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0;//initialize
        int right = nums.size()-1;

        while(left<=right){// keep searching while there are elemnts left
            int mid = left +(right-left)/2;//find middle it avoild overloading ratehr than mid= (left+right)/2

            if(nums[mid] == target){// if target found
                return mid;// return mid
            }
            else if(nums[mid]<target){// if target is greater than mid
                left = mid+1;//move left
            }
            else{
                right = mid-1;// else right
            }
        }
        return left;// return left value
    }
};