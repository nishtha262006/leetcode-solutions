// LeetCode 199 - Binary Tree Right Side View

// Difficulty: Medium

// Approach:

// Use Breadth First Search (BFS) with a queue.
// Process the tree level by level.
// For each level:
// Traverse all nodes present at that level.
// Keep track of the last node processed.
// The last node of each level represents the rightmost node visible from the right side.
// Add that node's value to the result.
// Continue until all levels have been processed.
// Return the list of visible nodes.

// Time Complexity: O(n)
// Space Complexity: O(n)



class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left<right){

            if(s[left]!=s[right] ){
                char smaller = min(s[left], s[right]);

                s[left] = smaller;
                s[right] = smaller;
            }
            left++;
            right--;
        }
        return s ;
    }
};