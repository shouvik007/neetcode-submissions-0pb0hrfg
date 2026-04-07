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
 vector<vector<int>> levelOrderRec(TreeNode* root, int level, vector<vector<int>>& res) {
        if(root==nullptr){
            return res;
        }
        if(res.size()<=level){
            res.push_back({});
        }
        res[level].push_back(root->val);
        levelOrderRec(root->left, level + 1, res);
        levelOrderRec(root->right, level + 1, res); 
        return res;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>ans;
        int level =0;
        res = levelOrderRec(root, level, res);
        int n = res.size();
        for(int i =0; i<res.size() ;i++){
             ans.push_back(res[i][res[i].size()-1]);
        }
        return ans;
    }
};
