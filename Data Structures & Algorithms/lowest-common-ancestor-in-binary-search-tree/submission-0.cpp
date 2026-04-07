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
    vector<TreeNode*>vp;
    vector<TreeNode*>vq;
    void storeParent(TreeNode* root, TreeNode* child,vector<TreeNode*>& v) {
        if(root==nullptr ) {
            return;
        }
        v.push_back(root);
        if(root->val == child->val){
            return;
        }
        else if(root->val>child->val) {
            storeParent(root->left,child,v);
        }
        else if(root->val<child->val) {
            storeParent(root->right,child,v);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==nullptr||q==nullptr){
            return nullptr;
        }
        vp.clear();
        vq.clear();
        storeParent(root,p,vp);
        storeParent(root,q,vq);
        int i = 0;
        TreeNode* lca = nullptr;
        
        while (i < vp.size() && i < vq.size()) {
            if (vp[i] == vq[i]) {
                lca = vp[i]; // Update last seen common ancestor
                i++;
            } else {
                break; // Paths have diverged
            }
        }
        
        return lca;
        
    }
};
