
// LeetCode 450 - Delete Node in a BST

// Difficulty: Medium

// Approach:

// 1. Use the properties of a Binary Search Tree (BST).
// 2. Search for the node with the given key.
// 3. Once found, handle three cases:

//    * Node has no children:

//      * Delete the node and return NULL.
//    * Node has one child:

//      * Return the existing child.
//    * Node has two children:

//      * Find the inorder successor (smallest value in the right subtree).
//      * Replace the node's value with the successor's value.
//      * Delete the successor node from the right subtree.
// 4. Return the updated BST.

// Time Complexity: O(h)
// Space Complexity: O(h)

// * h is the height of the BST.
// * In a balanced BST, h = log n.
// * In the worst case (skewed tree), h = n.



class Solution {
public:

    TreeNode* findMin(TreeNode* root) {

        while(root->left != NULL) {
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL) {
            return NULL;
        }

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        else {

            // No child
            if(root->left == NULL &&
               root->right == NULL) {

                delete root;
                return NULL;
            }

            // One child (right)
            else if(root->left == NULL) {

                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // One child (left)
            else if(root->right == NULL) {

                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Two children
            TreeNode* successor =
                findMin(root->right);

            root->val = successor->val;

            root->right =
                deleteNode(root->right,
                           successor->val);
        }

        return root;
    }
};