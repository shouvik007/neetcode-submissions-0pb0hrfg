class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n, -1);
        return ifreach(nums, n , 0,vis);
    }
    bool ifreach(vector<int>& nums ,int n , int i, vector<int>& dp){
        if(i>=n-1 ){
            return true;
        }
        if (dp[i] != -1) return dp[i];
            for(int j =1;j<=nums[i];j++){
                if(ifreach(nums, n, i+j,dp)){
                    return dp[j]= 1;
                }
            }

        return dp[i] = 0;
    }
};
