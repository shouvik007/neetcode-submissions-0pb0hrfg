class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size()<t.size()){
            return 0;
        }
        vector<vector<int>>v(s.size(),vector<int>(t.size(),-1));
        return dfs(0,0,s,t,v);
    }
    int dfs(int i , int j , string s , string t, vector<vector<int>>& v){
        if(j>=t.size()){
            return 1;
        }
        if(i>=s.size()){
            return 0;
        }
        if(v[i][j]!=-1){
            return v[i][j];
        }
        int res = dfs(i+1, j, s, t,v);
        if(s[i]==t[j]){
            res +=dfs(i+1, j+1, s,t,v);
            
        }
        v[i][j]=res;
        return v[i][j];
    }
};
