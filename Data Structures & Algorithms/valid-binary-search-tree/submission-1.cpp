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
    bool valid(TreeNode* root, int min , int maxi) {
        if(root==nullptr){
            return true;
        }
        if(root->val<min || root->val>maxi){
            return false;
        }
        return 
            valid(root->left, min, root->val-1)&& 
            valid(root->right, root->val+1, maxi);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, INT_MIN, INT_MAX);
    }
};
