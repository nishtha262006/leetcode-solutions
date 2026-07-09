// LeetCode 110 - Balanced Binary Tree

// Difficulty: Easy

// Approach:

// 1. Use Depth First Search (DFS) recursively.
// 2. Compute the height of the left and right subtrees for each node.
// 3. If the absolute difference between their heights is greater than 1:

//    * The tree is not balanced.
// 4. Recursively verify that both the left and right subtrees are also balanced.
// 5. Return true only if every node satisfies the balance condition.

// Time Complexity: O(n)
// Space Complexity: O(h)

// * n = number of nodes in the tree.
// * h = height of the tree.
// * In the worst case (skewed tree), h = n.




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int height(TreeNode* root) {

        if(root == NULL)
            return 0;

        int leftHeight = height(root->left);

        if(leftHeight == -1)
            return -1;

        int rightHeight = height(root->right);

        if(rightHeight == -1)
            return -1;

        if(abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        return height(root) != -1;
    }
};