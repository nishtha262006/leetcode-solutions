// LeetCode 98 - Validate Binary Search Tree

// Difficulty: Medium

// Approach:

// 1. Use Depth First Search (DFS) recursively.
// 2. Maintain a valid range for each node using lower and upper bounds.
// 3. For every node:

//    * Its value must be greater than the lower bound.
//    * Its value must be less than the upper bound.
// 4. Recursively validate:

//    * The left subtree with the current node as the upper bound.
//    * The right subtree with the current node as the lower bound.
// 5. If every node satisfies the BST property, return true.
// 6. Otherwise, return false.

// Time Complexity: O(n)
// Space Complexity: O(h)

// * h is the height of the tree.
// * In a balanced BST, h = log n.
// * In the worst case (skewed tree), h = n.




class Solution {
public:

    bool validate(TreeNode* root, long minVal, long maxVal) {

        if(root == NULL) {
            return true;
        }

        if(root->val <= minVal ||
           root->val >= maxVal) {
            return false;
        }

        return validate(root->left,
                        minVal,
                        root->val)
            &&
               validate(root->right,
                        root->val,
                        maxVal);
    }

    bool isValidBST(TreeNode* root) {

        return validate(root,
                        LONG_MIN,
                        LONG_MAX);
    }
};