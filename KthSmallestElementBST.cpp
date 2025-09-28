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
    int prevOrder = 0;

    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return -1;

        // Left subtree
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1) return leftAns;

        // Visit current node
        prevOrder++;
        if (prevOrder == k) return root->val;

        // Right subtree
        int rightAns = kthSmallest(root->right, k);
        if (rightAns != -1) return rightAns;

        return -1;
    }
};

