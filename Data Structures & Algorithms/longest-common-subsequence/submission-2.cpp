class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>v(m, vector<int>(n,-1));
        int res = 0;
        return findlcs(0,0,text1,text2, v);
    }
    int findlcs(int i , int j ,string a, string b, vector<vector<int>>&v ){
        if(i==a.size()||j==b.size()){
            return 0;
        }
        if(v[i][j]!=-1){
            return v[i][j];
        }
        else if(a[i]==b[j]){
            v[i][j]= 1+findlcs(i+1,j+1,a,b,v);
           
        }
        else {
            v[i][j]= max(findlcs(i+1,j,a,b,v),findlcs(i,j+1,a,b,v));
        }
         return v[i][j];
    }
};
