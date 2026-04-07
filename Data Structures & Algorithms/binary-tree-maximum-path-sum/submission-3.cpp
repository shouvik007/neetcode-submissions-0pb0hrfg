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
int res =INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int getmax(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftmax= getmax(root->left);
        int rightmax= getmax(root->right);
        int path = root->val+max(leftmax,rightmax);
        return max(0,path);

    }
    void dfs(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        int leftmax=getmax(root->left);
        int rightmax= getmax(root->right);
        res = max(res, root->val+leftmax+rightmax);
        dfs(root->left);
        dfs(root->right);
    }
};
