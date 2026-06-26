// LeetCode 230 - Kth Smallest Element in a BST

// Difficulty: Medium

// Approach:

// 1. Perform an Inorder Traversal of the Binary Search Tree (BST).
// 2. Inorder traversal visits nodes in ascending order.
// 3. Keep a count of the visited nodes.
// 4. When the count becomes equal to k:

//    * The current node is the kth smallest element.
// 5. Return the value of that node.

// Time Complexity: O(n)
// Space Complexity: O(h)

// * h is the height of the BST.
// * In a balanced BST, h = log n.
// * In the worst case (skewed tree), h = n.




class Solution {
public:
    int count = 0;
    int answer = 0;

    void inorder(TreeNode* root, int k) {

        if(root == NULL) {
            return;
        }

        inorder(root->left, k);

        count++;

        if(count == k) {
            answer = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        inorder(root, k);

        return answer;
    }
};