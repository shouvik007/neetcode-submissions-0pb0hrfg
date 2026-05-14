class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1, vector<int>(p.size()+1, -1));
        return dfs(0,0,s,p,dp);
    }
    bool dfs(int i , int j , string s, string p,vector<vector<int>>& dp){
        int n = s.size();
        int m = p.size();
        if( j==m){
            return i==n;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool match   = false;
          if(i<n && (s[i]==p[j]  || p[j]=='.')){
            match = true;
        }  
        bool ans = false;
        if(j+1<m && p[j+1]=='*'){
            ans= dfs(i,j+2,s,p,dp) || (match && dfs(i+1,j,s,p,dp));
        }
        else if(match){
            ans= dfs(i+1,j+1, s,p,dp);
        }
        return dp[i][j] = ans;
    }
};
