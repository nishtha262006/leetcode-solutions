// LeetCode 543 - Diameter of Binary Tree
// Difficulty: Easy

// Approach:
// 1. Use Depth First Search (DFS) to calculate the height of each subtree.
// 2. For every node:
//    - Find the height of its left subtree.
//    - Find the height of its right subtree.
// 3. The diameter passing through that node is:
//    leftHeight + rightHeight
// 4. Keep track of the maximum diameter found so far.
// 5. Return the maximum diameter after traversing the entire tree.

// Time Complexity: O(n)
// Space Complexity: O(h)
// - h is the height of the tree.
// - In the worst case, h = n.

lass Solution {
public:
    int diameter = 0;// Global Diameter variable

    int height(TreeNode* root) {// height function

        if(root == NULL) {//base case
            return 0;
        }

        int leftHeight = height(root->left);//calculate left height
        int rightHeight = height(root->right);//calculate right height

        diameter = max(diameter, leftHeight + rightHeight);//update diameter

        return 1 + max(leftHeight, rightHeight);//return height
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};