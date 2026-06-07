// LeetCode 111 - Minimum Depth of Binary Tree
// Difficulty: Easy

// Approach:
// 1. Use recursion to find the minimum depth.
// 2. If the current node is NULL, return 0.
// 3. If a node has only one child:
//    - The path must continue through the existing child.
// 4. If a node has both children:
//    - Take the minimum depth of the left and right subtrees.
// 5. Add 1 for the current node.
// 6. The result is the minimum number of nodes from the root
//    to the nearest leaf node.

// Time Complexity: O(n)
// Space Complexity: O(h)
// - h is the height of the tree.
// - In the worst case, h = n.


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){//base case
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){//leaf node
            return 1;
        }
        if(root->left==NULL){//leftchild missing
            return 1+minDepth(root->right);
        }
        if(root->right ==NULL){//right child missing 
            return 1+minDepth(root->left);
        }
        return 1+min(minDepth(root->left),minDepth(root->right));//both child exist
    }
};