class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>v(n,vector<int>(n,-1));
        int a= max_s(piles, 0, n-1,v);
        int b = max_s(piles, 1, n-2,v);
        if(a>b){
            return true;
        }
        else {
            return false;
        }
    }
    int max_s(vector<int>& piles, int left , int right, vector<vector<int>>&dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        dp[left][right]=(max(
           (piles[left]+max_s(piles,left+2,right,dp) ) ,( piles[right]+max_s(piles, left, right-2,dp ))
        ));
        return dp[left][right];
    }
};