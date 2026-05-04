class Solution {
public:
    int integerBreak(int n) {
        vector<int>v(n+1,-1);
        v[0]=1;
        return dfs(n,n,v);
    }
    int dfs(int curr, int ori, vector<int>&v){
        if(curr==1){
            v[curr]=1;
            return 1;
        }
        if(v[curr]!=-1){
            return v[curr];
        }
        int res = (curr==ori)? 0:curr;
        for(int i =1;i<curr;i++){
            int val = dfs(i, ori,v)*dfs(curr-i, ori,v);
            res = max(val,res);
        }
        v[curr]=res;
        return v[curr];
    }
};