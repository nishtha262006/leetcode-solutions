// LeetCode 112 - Path Sum
// Difficulty: Easy

// Approach:
// 1. Use Depth First Search (DFS) recursively.
// 2. At each node, subtract the node's value from targetSum.
// 3. If we reach a leaf node:
//    - Check if the remaining targetSum equals the leaf node's value.
//    - If yes, a valid path exists.
// 4. Recursively check the left and right subtrees.
// 5. Return true if any root-to-leaf path has the required sum.

// Time Complexity: O(n)
// Space Complexity: O(h)
// - h is the height of the tree.
// - In the worst case, h = n.
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){// if the root does not have any subtreee
            return false;// return false
        }
        targetSum -=root->val;// subtract the root value from the targetsum

        if(root->left == NULL && root->right == NULL){// if the root's left is null and the right's root is also null 
            return targetSum==0;// then the targetsum is 0
        }
        return hasPathSum(root->left, targetSum)||hasPathSum(root->right,targetSum);// can i find a valid path in the left subtree
    }
};