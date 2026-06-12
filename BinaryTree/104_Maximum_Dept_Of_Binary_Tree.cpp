// LeetCode 104 - Maximum Depth of Binary Tree

// Difficulty: Easy

// Approach:

// Use Depth First Search (DFS) recursively.
// If the current node is NULL, return 0.
// Recursively find the depth of the left subtree.
// Recursively find the depth of the right subtree.
// The depth of the current node is:
// 1 + max(leftDepth, rightDepth)
// Return the maximum depth of the tree.

// Time Complexity: O(n)
// Space Complexity: O(h)

// h is the height of the tree.
// In the worst case, h = n.

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int leftDepth = maxDepth(root->left);

        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};