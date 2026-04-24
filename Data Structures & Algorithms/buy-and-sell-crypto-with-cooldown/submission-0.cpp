class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>v(prices.size(),vector<int>(2,-1));
        return dfs(0,prices,1,v);
    }
    int dfs(int i,vector<int>& prices,int bos, vector<vector<int>>&dp ){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][bos]!=-1){
            return dp[i][bos];
        }
        if(bos==1){
            dp[i][bos]=max((-prices[i]+dfs(i+1, prices,0,dp)), (0+dfs(i+1, prices,1,dp)));
        }
        else if(bos == 0){
            dp[i][bos]= max((prices[i]+dfs(i+2, prices, 1, dp)), (0+dfs(i+1, prices, 0, dp)));
        }
        return dp[i][bos];
    }
};
