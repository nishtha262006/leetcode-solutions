// LeetCode 100 - Same Tree

// Difficulty: Easy

// Approach:

// 1. Use Depth First Search (DFS) recursively.
// 2. If both nodes are NULL:

//    * Return true.
// 3. If one node is NULL or their values are different:

//    * Return false.
// 4. Recursively compare:

//    * The left subtrees.
//    * The right subtrees.
// 5. If both left and right subtrees are identical, return true.
// 6. Otherwise, return false.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both nodes are NULL
        if(p == NULL && q == NULL)
            return true;

        // One node is NULL
        if(p == NULL || q == NULL)
            return false;

        // Values are different
        if(p->val != q->val)
            return false;

        // Compare left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};