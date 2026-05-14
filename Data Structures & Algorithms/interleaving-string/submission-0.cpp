class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
        vector<vector<int>>res(s1.size()+1,vector<int>(s2.size()+1,-1));
        return dfs(0,0,s1, s2,s3,"",res);
    }
    bool dfs(int i , int j,string& s1, string& s2, string& s3, string curr,vector<vector<int>>& dp ){
        if(curr == s3){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool chosse1 = false;
        bool chosse2 = false;
        if(i<s1.size()){
            if(s1[i]==s3[curr.size()]){
                chosse1 = (dfs(i+1,j,s1,s2,s3,curr+s1[i],dp));
            }
        }
        if(j<s2.size()){
            if(s2[j]==s3[curr.size()]){
                chosse2 = dfs(i,j+1,s1,s2,s3,curr+s2[j],dp);
            }
        }
        return dp[i][j]= chosse1||chosse2;
    }

};
