// LeetCode 404 - Sum of Left Leaves
// Difficulty: Easy

// Approach:
// 1. Traverse the binary tree using DFS recursion.
// 2. For each node:
//    - Check if its left child exists and is a leaf node.
//    - If yes, add its value to the sum.
// 3. Recursively traverse the left and right subtrees.
// 4. Return the total sum of all left leaves.

// Time Complexity: O(n)
// Space Complexity: O(h)
// - h is the height of the tree.
// - In the worst case, h = n.


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum =0;
        if(root->left&& root->left->left==NULL && root->left->right ==NULL){
            sum=+root->left->val;
        }
        sum+= sumOfLefLeaves(root->left);
        sum+= sumOfLeftLeaves(root->right);
        return sum;
    }
};