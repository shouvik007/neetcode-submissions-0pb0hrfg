class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>v(word1.size(),vector<int>(word2.size(),-1));
        return dfs(0,0,word1,word2,v);
    }
    int dfs(int i ,  int j , string word1, string word2, vector<vector<int>>& v) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(i == n1){
            return n2-j;
        }
        if(j==n2){
            return n1-i;
        }
        if(v[i][j]!=-1){
            return v[i][j];
        }
        if(i == n1){
            return n2-j;
        }
        if(j==n2){
            return n1-i;
        }
        if(word1[i]==word2[j]){
            return dfs(i+1,j+1, word1, word2,v);
        }
        int res =0;
        res = min(
                    dfs(i+1,j,word1, word2,v), //delete;
                    dfs(i+1, j+1, word1, word2,v) //replace;
        );
        res = min(res,  dfs(i, j+1, word1, word2,v));
        v[i][j]= res+1;
        return v[i][j];
    }
};
