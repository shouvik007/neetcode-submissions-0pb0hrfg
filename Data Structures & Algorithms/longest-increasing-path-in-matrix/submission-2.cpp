class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>v(matrix.size(),vector<int>(matrix[0].size(),-1));
        int res =INT_MIN;
        for(int i =0;i<matrix.size();i++){
            for(int j =0;j<matrix[0].size();j++){
                res = max(res, dfs(i,j,matrix, INT_MIN, v));
            }
        }
        return res;
    }
    int dfs(int i , int j ,vector<vector<int>>& matrix, int prev,vector<vector<int>>& v ) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(i<0||j<0||i>=m||j>=n||matrix[i][j]<=prev){
            return 0;
        }
        if(v[i][j]!=-1) {
            return v[i][j];
        }
        int res = 1;
        res = max(res, 1+dfs(i+1,j,matrix, matrix[i][j],v));
        res = max(res, 1+dfs(i-1,j,matrix, matrix[i][j],v ));
        res = max(res, 1+dfs(i,j+1,matrix, matrix[i][j],v));
        res = max(res, 1+dfs(i,j-1,matrix, matrix[i][j],v));
        v[i][j]=res;
        return v[i][j];

    }
};
