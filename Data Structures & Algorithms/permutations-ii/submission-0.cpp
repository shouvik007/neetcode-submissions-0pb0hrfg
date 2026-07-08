class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>vis(nums.size(), false);
        sort(nums.begin(), nums.end());
        permutation(ans, temp, vis, nums);
        return ans;
    }
    void permutation(
        vector<vector<int>>& ans,
        vector<int>& temp,
        vector<bool> &vis,
        vector<int>& nums
    ) {
        if(temp.size()==nums.size()){
            
            ans.push_back(temp);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(vis[i] ==true) {
                continue;
            }
             if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])
                continue;
            vis[i]=true;
            temp.push_back(nums[i]);
            permutation(ans, temp, vis, nums);
            vis[i]=false;
            temp.pop_back();
        }
    }
};