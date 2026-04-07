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
    int goodNodes(TreeNode* root) {
        int max = INT_MIN;
        return goodNodesHelper(root, max);
    }

    int goodNodesHelper(TreeNode* root, int max) {
        if (root == nullptr) {
            return 0;
        }
        if (max > root->val) {
            return 0 + goodNodesHelper(root->left, max) + goodNodesHelper(root->right, max);
        }
        max = root->val;
        return 1 + goodNodesHelper(root->left, max) + goodNodesHelper(root->right, max);
    }
};
