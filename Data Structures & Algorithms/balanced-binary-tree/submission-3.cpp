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
    int countheight(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int lefth = 1+countheight(root->left);
        int righth= 1+countheight(root->right);
        return max(lefth, righth);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        if (abs(countheight(root->left)-countheight(root->right))>1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
