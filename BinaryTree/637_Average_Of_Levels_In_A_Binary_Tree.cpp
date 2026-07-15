// LeetCode 637 - Average of Levels in Binary Tree

// Difficulty: Easy

// Approach:

// 1. Use Breadth First Search (BFS) with a queue.
// 2. Traverse the tree level by level.
// 3. For each level:

//    * Calculate the sum of all node values.
//    * Count the number of nodes.
// 4. Compute the average as:

//    * `sum / number of nodes`
// 5. Store the average for each level.
// 6. Return the list of averages.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * n = number of nodes in the tree.
// * The queue may store all nodes of a level in the worst case.



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
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> result;

        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            double sum = 0;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            result.push_back(sum / size);
        }

        return result;
    }
};