class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(0,0,s,p);
    }
    bool dfs(int i , int j , string s, string p){
        int n = s.size();
        int m = p.size();
        if(i==n && j==m){
            return true;
        }
        bool match   = false;
          if(i<n && (s[i]==p[j]  || p[j]=='.')){
            match = true;
        }  
        if(j+1<m && p[j+1]=='*'){
            return dfs(i,j+2,s,p) || (match && dfs(i+1,j,s,p));
        }
        if(match){
            return dfs(i+1,j+1, s,p);
        }
        return false;
    }
};
