class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> res;
        dfs(0, nums, target, res, ans);
        return ans;
    }
    void dfs(int i, vector<int>& nums, int target, vector<int>& res, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            if (target == 0) {
                ans.push_back(res);
            }
            return;
        }
        if (nums[i] <= target) {
            res.push_back(nums[i]);
            dfs(i, nums, target - nums[i], res, ans);
            res.pop_back();
        }
        dfs(i + 1, nums, target, res, ans);
    }
};