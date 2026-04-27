class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return dfs(0,-1, nums,dp);
    }
    int dfs(int i , int j , vector<int>& nums,vector<vector<int>>& dp ) {
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }
        int lis = dfs(i+1, j, nums,dp);
        if(j==-1 || nums[j]<nums[i]){
            lis = max(lis , 1+dfs(i+1, i, nums,dp));
        }
        return dp[i][j+1] = lis;
    }
};
