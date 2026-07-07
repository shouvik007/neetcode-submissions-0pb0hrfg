class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        vector<bool> vis(nums.size(), false);
        backtrack(ans,curr, nums, vis );
        return ans;
    }
    void backtrack( vector<vector<int>>& ans, vector<int>&curr,vector<int>&nums, vector<bool>& vis){
        if(curr.size()== nums.size()) {
            ans.push_back(curr);
            return ;
        }
        for(int i = 0; i<nums.size(); i++){
            if(vis[i]) {
                continue;
            }
            vis[i] =true;
           curr.push_back(nums[i]);
           backtrack(ans, curr, nums,vis); 
           curr.pop_back();
           vis[i]=false;
        }
    }
};
