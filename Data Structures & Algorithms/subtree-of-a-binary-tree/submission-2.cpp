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
bool isSameSubTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr){
            return true;
        }
        else if(p==nullptr||q==nullptr) {
            return false;
        }
        if(p->val==q->val){
            return (isSameSubTree(p->left,q->left)&&isSameSubTree(p->right,q->right));
        }
        else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;
        }
        else {
            if(isSameSubTree(root,subRoot)) {
                return true;
            } 
            else {
               return((isSubtree(root->right, subRoot)) || (isSubtree(root->left, subRoot)));
            }
        }
    }
};
