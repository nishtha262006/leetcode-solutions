// LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree

// Difficulty: Medium

// Approach:

// 1. Utilize the properties of a Binary Search Tree (BST).
// 2. Start from the root node.
// 3. Compare the values of p and q with the current node:

//    * If both are smaller, move to the left subtree.
//    * If both are greater, move to the right subtree.
// 4. Otherwise:

//    * The current node is the point where the paths to p and q diverge.
//    * Therefore, it is the Lowest Common Ancestor (LCA).
// 5. Return the current node.

// Time Complexity: O(h)
// Space Complexity: O(1)

// * h is the height of the BST.
// * In a balanced BST, h = log n.
// * In the worst case (skewed tree), h = n.



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
        

        if(p->val <root->val && q->val<root->val){
            return lowestCommonAncestor(root->left , p,q);//goleft
        }
        if(p->val>root->val && q->val >root->val){
            return lowestCommonAncestor(root->right , p,q);//go right
        }
        return root;// else return root
    }
};