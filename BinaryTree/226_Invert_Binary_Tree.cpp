// LeetCode 226 - Invert Binary Tree

// Difficulty: Easy

// Approach:

// 1. Use Depth First Search (DFS) recursively.
// 2. If the current node is NULL:

//    * Return NULL.
// 3. Swap the left and right child of the current node.
// 4. Recursively invert the left subtree.
// 5. Recursively invert the right subtree.
// 6. Return the root of the inverted tree.

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
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
            return NULL;

        // Swap left and right child
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Invert left subtree
        invertTree(root->left);

        // Invert right subtree
        invertTree(root->right);

        return root;
    }
};