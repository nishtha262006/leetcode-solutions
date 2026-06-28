// LeetCode 109 - Convert Sorted List to Binary Search Tree

// Difficulty: Medium

// Approach:

// 1. Use the slow and fast pointer technique to find the middle node of the linked list.
// 2. The middle node becomes the root of the Binary Search Tree (BST).
// 3. Split the linked list into two halves:

//    * Left half forms the left subtree.
//    * Right half forms the right subtree.
// 4. Recursively repeat the process for both halves.
// 5. Continue until the linked list becomes empty.
// 6. Return the root of the height-balanced BST.

// Time Complexity: O(n log n)
// Space Complexity: O(log n)

// * Recursive calls use stack space.
// * The tree remains height-balanced.




class Solution {

public:

    TreeNode* sortedListToBST(ListNode* head) {

        if(head == NULL)

            return NULL;

        if(head->next == NULL)

            return new TreeNode(head->val);

        ListNode* prev = NULL;

        ListNode* slow = head;

        ListNode* fast = head;

        while(fast && fast->next) {

            prev = slow;

            slow = slow->next;

            fast = fast->next->next;

        }

        prev->next = NULL;

        TreeNode* root = new TreeNode(slow->val);

        root->left = sortedListToBST(head);

        root->right = sortedListToBST(slow->next);

        return root;

    }

};
        