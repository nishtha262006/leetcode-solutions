/*
LeetCode 94 - Binary Tree Inorder Traversal
Difficulty: Easy

Approach:
1. Use recursion to perform Inorder Traversal.
2. Visit the left subtree first.
3. Process the current node by adding its value to the result.
4. Visit the right subtree.
5. Continue until all nodes have been traversed.

Traversal Order:
Left → Root → Right

Time Complexity: O(n)
Space Complexity: O(n)
- O(h) recursive call stack where h is the height of the tree.
- In the worst case, h = n.
*/

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
    void inorder(TreeNode* root, vector<int>& result) {
        if(root == NULL) {
            return;
        }

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};