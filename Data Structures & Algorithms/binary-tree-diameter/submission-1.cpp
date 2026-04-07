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
    int height(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        else {
            return max(1+height(root->left), 1+height(root->right));
        }
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int leftd = diameterOfBinaryTree(root->left);
        int rightd = diameterOfBinaryTree(root->right);
        int currdiameter = height(root->left)+height(root->right);
        return max(currdiameter, max(leftd,rightd)); 
    }
};
