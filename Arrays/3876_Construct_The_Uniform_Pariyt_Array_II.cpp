// LeetCode 3876 — Construct Uniform Parity Array II

// Difficulty: Medium
// Topic: Array, Math

// 💡 Approach

// The key is to look at the smallest odd number.

// If all numbers are already of the same parity → true.
// Suppose the array contains both odd and even numbers.
// Let mn = smallest odd number.
// If there is an even number smaller than mn, the answer is false.
// Otherwise, the answer is true.



class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mn = INT_MAX;// thsi will store the smallest odd number but initially we dont know the samllest numbes o we initialized it as the largest number
        for(int x:nums1){//traverse the array
            if(x%2==1){//find off numbers
                mn =min(mn,x);//get the samllest number here
            }
        }
        for(int x:nums1){//traverse again
            if(x%2==0 && mn!=INT_MAX && x<mn){//if the number is even and check whether we found a odd number and check whether the number is smaller than mn 
                return false;//return false
            }
        }
        return true;//loop finish return true
    }
};