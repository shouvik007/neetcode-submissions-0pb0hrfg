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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l =0;
        int h = inorder.size()-1;
        int preindex = 0;
        return build(preorder, inorder,preindex, l, h);
    }
    int findNode(vector<int>& inorder, int target ){
        for(int i =0;i<inorder.size();i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &preindex, int l, int h ) {
        if (l > h) return NULL;
        TreeNode* root =new TreeNode(); 
        root->val = preorder[preindex];
        int inorder_find_root = findNode(inorder,preorder[preindex]);
        preindex ++;
        root->left= build(preorder,inorder,preindex,l,inorder_find_root-1);
        root->right= build(preorder,inorder,preindex,inorder_find_root+1,h);
        return root;
    }
};
