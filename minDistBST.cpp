
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
#include <climits>
class Solution {
public:
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {
        if (root == NULL) return INT_MAX;

        int ans = INT_MAX;

        // Left subtree
        if (root->left != NULL) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        // Current node diff
        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        // Right subtree
        if (root->right != NULL) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }

        return ans;
    }
};
