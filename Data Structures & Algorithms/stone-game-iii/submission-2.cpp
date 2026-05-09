class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        int res = dfs(0,1, stoneValue,dp);
        if(res<0){
            return "Bob";
        }
        else if(res>0){
            return "Alice";
        }
        else {
            return "Tie";
        }

    }
    int dfs(int i ,int alice, vector<int>& stoneValue, vector<vector<int>>&dp){
        int n = stoneValue.size();
        if(i>=n){
            return 0;
        }
       if(dp[i][alice] != INT_MIN){
            return dp[i][alice];
        }
        int score = 0;
        int res;
        if(alice == 1){
            res = INT_MIN;
        }
        else {
            res = INT_MAX;
        }
        for(int j = i; j<min(i+3,n);j++){
            if(alice== 1){
                score = score+stoneValue[j];
                res = max(res, score+dfs(j+1, 0, stoneValue,dp));
            }
            else {
                score = score - stoneValue[j];
                res = min(res, score+dfs(j+1,1,stoneValue,dp));
            }
        }
        dp[i][alice]=res;
        return res;

    }
};