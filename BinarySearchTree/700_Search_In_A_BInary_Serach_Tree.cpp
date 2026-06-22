// LeetCode 700 - Search in a Binary Search Tree

// Difficulty: Easy

// Approach:

// 1. Utilize the properties of a Binary Search Tree (BST).
// 2. Start from the root node.
// 3. Compare the target value with the current node's value:

//    * If equal, return the current node.
//    * If the target is smaller, move to the left subtree.
//    * If the target is greater, move to the right subtree.
// 4. Continue until the target is found or a NULL node is reached.
// 5. Return the node containing the target value or NULL if it does not exist.

// Time Complexity: O(h)
// Space Complexity: O(h)

// * h is the height of the BST.
// * In a balanced BST, h = log n.
// * In the worst case (skewed tree), h = n.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if(root == NULL || root->val == val) {
            return root;
        }

        if(val < root->val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};