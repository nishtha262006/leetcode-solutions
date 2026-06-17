// LeetCode 114 - Flatten Binary Tree to Linked List

// Difficulty: Medium

// Approach:

// Use Depth First Search (DFS) recursively.
// Flatten the left subtree.
// Flatten the right subtree.
// Store the original right subtree.
// Move the flattened left subtree to the right of the current node.
// Set the left child to NULL.
// Traverse to the end of the new right subtree.
// Attach the original right subtree to the end.
// Repeat for all nodes until the entire tree becomes a linked list.

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(root==NULL){//rott is null do nothing
            return;
        }
        flatten(root->left);//flatten left subtree
        flatten(root->right);//flaten right subtree

        TreeNode*temp = root->right;//save original right

        root->right = root->left;//move left to right
        root->left = NULL;//remove left

        TreeNode*curr= root;// find tail

        while(curr->right!=NULL){
            curr= curr->right;
        }
        curr->right=temp;//attach old right
    }
};