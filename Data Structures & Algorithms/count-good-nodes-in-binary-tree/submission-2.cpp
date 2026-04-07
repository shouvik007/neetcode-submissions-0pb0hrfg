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
 int count =0;
    int goodNodes(TreeNode* root) {
        int currmax = root->val;
        find(root, root->val);
        return count;
    }
    void find(TreeNode* root, int currmax){
        if(root==nullptr){
            return;
        }
        if(root->val>=currmax) {
            count++;
            currmax = root->val;
            find(root->left, currmax);
            find(root->right, currmax);
        }
        else {
            find(root->left, currmax);
            find(root->right, currmax);
        }
        
    }
};
