// LeetCode 102 - Binary Tree Level Order Traversal

// Difficulty: Medium

// Approach:

// Use Breadth First Search (BFS) with a queue.
// Start by pushing the root node into the queue.
// Process nodes level by level:
// Determine the number of nodes at the current level.
// Remove each node from the queue.
// Store its value in a temporary vector.
// Add its left and right children to the queue if they exist.
// After processing a level, add the temporary vector to the result.
// Continue until the queue becomes empty.
// Return the level order traversal of the tree.

// Time Complexity: O(n)
// Space Complexity: O(n)


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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            vector<int> level;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) {
                    q.push(node->left);
                }

                if(node->right) {
                    q.push(node->right);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};