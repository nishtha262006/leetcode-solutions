// LeetCode 101 - Symmetric Tree

// Difficulty: Easy

// Approach:

// 1. Use Depth First Search (DFS) recursively.
// 2. Compare the left and right subtrees simultaneously.
// 3. If both nodes are NULL:

//    * Return true.
// 4. If one node is NULL or their values are different:

//    * Return false.
// 5. Recursively compare:

//    * Left child of the first subtree with the right child of the second subtree.
//    * Right child of the first subtree with the left child of the second subtree.
// 6. If both comparisons return true, the tree is symmetric.
// 7. Return the final result.

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

    bool isMirror(TreeNode* left, TreeNode* right) {

        if(left == NULL && right == NULL)
            return true;

        if(left == NULL || right == NULL)
            return false;

        if(left->val != right->val)
            return false;

        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};