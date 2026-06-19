// LeetCode 129 - Sum Root to Leaf Numbers

// Difficulty: Medium

// Approach:

// Use Depth First Search (DFS) recursively.
// Maintain the number formed along the current root-to-node path.
// At each node:
// Update the current number as:
// currentNumber = currentNumber * 10 + node->val
// If a leaf node is reached:
// Return the current number.
// Recursively calculate the sum from the left and right subtrees.
// Return the total sum of all root-to-leaf numbers.

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
int dfs(TreeNode *root, int currentNumber){

        if(root==NULL){
            return 0;
        }

        currentNumber = currentNumber *10+root->val;

        if(root->left == NULL && root->right== NULL){
            return currentNumber;
        }

        return dfs(root->left, currentNumber)+dfs(root->right, currentNumber);
    }
        int sumNumbers(TreeNode*root){
            return dfs(root,0);
        
    }
};