// LeetCode 236 - Lowest Common Ancestor of a Binary Tree

// Difficulty: Medium

// Approach:

// Use Depth First Search (DFS) recursively.
// If the current node is NULL, return NULL.
// If the current node matches either p or q, return the current node.
// Recursively search for p and q in the left and right subtrees.
// If both left and right recursive calls return non-NULL values:
// The current node is the Lowest Common Ancestor (LCA).
// If only one side returns a non-NULL value:
// Return that value.
// Continue until the LCA is found.

// Time Complexity: O(n)
// Space Complexity: O(h)

// h is the height of the tree.
// In the worst case, h = n.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        if(root==NULL){
            return NULL;
        }
        if(root==p|| root==q){
            return root;
        }
        TreeNode*left= lowestCommonAncestor(root->left,p,q);

        TreeNode*right = lowestCommonAncestor(root->right,p,q);

        if(left &&right){
            return root;
        }
        if(left){
            return left;
        }
        return right;
    }
};