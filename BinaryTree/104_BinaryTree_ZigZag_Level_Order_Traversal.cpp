// LeetCode 103 - Binary Tree Zigzag Level Order Traversal

// Difficulty: Medium

// Approach:

// Use Breadth First Search (BFS) with a queue.
// Process the tree level by level.
// For each level:
// Store all node values in a temporary vector.
// If the current level is odd, reverse the vector.
// Add the processed level to the result.
// Alternate the traversal direction for each level:
// Left to Right
// Right to Left
// Continue until all levels have been processed.
// Return the zigzag level order traversal.

// Time Complexity: O(n)
// Space Complexity: O(n)

// In the worst case, the queue may contain all nodes of a level.



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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        

        vector<vector<int>>result;

        if(root==NULL){
            return result;
        }

        queue<TreeNode*>q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size= q.size();
            vector<int>level;

            for(int i = 0; i<size;i++){

                TreeNode* node = q.front();

                q.pop();

                level.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(!leftToRight){
                reverse(level.begin() , level.end());
            }
            result.push_back(level);

            leftToRight = !leftToRight;
        }
        return result;
    }
};