// LeetCode 701 - Insert into a Binary Search Tree

// Difficulty: Medium

// Approach:

// 1. Utilize the properties of a Binary Search Tree (BST).
// 2. If the root is NULL:

//    * Create a new node with the given value and return it.
// 3. Compare the value with the current node:

//    * If the value is smaller, insert it into the left subtree.
//    * If the value is greater, insert it into the right subtree.
// 4. Recursively continue until the correct position is found.
// 5. Return the root of the modified BST.

// Time Complexity: O(h)
// Space Complexity: O(h)

// * h is the height of the BST.
// * In a balanced BST, h = log n.
// * In the worst case (skewed tree), h = n.




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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        

        if(root==NULL){
            return new TreeNode(val);// if root null insert new node
        }

        if(val<root->val){
            root->left = insertIntoBST(root->left , val);//val is smaller than root val move left then
        }
        else{
            root->right = insertIntoBST(root->right , val);// else move to right subtree
        }
        return root;// finally return root
    }
};