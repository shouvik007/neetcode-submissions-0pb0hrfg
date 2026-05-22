class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
    
        sort(nums.begin(), nums.end());
        dfs(0, nums, target, subset, res, 0);
        return res;
    }

    void dfs(int startIdx, const vector<int>& nums, int target, vector<int>& subset, vector<vector<int>>& res, int count) {

        if (count > target) {
            return;
        }
        if (count == target) {
            res.push_back(subset);
            return;
        }

        for (int i = startIdx; i < nums.size(); i++) {
            if (i > startIdx && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]);
            dfs(i + 1, nums, target, subset, res, count + nums[i]);
            subset.pop_back();
        }
    }
};