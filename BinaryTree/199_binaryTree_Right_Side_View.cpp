// LeetCode 199 - Binary Tree Right Side View

// Difficulty: Medium

// Approach:

// Use Breadth First Search (BFS) with a queue.
// Process the tree level by level.
// For each level:
// Traverse all nodes present at that level.
// Keep track of the last node processed.
// The last node of each level represents the rightmost node visible from the right side.
// Add that node's value to the result.
// Continue until all levels have been processed.
// Return the list of visible nodes.

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

                for(int i =0;i<size;i++){
                    TreeNode*node = q.front();
                    q.pop();

                    if(i==size-1){
                        result.push_back(node->val);
                    }
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
        }
        return result;
    }
};