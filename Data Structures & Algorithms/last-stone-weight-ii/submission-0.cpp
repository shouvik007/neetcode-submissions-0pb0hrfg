class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalsum = 0;
        for(int i=0;i<stones.size();i++){
            totalsum += stones[i];
        }
        int target = totalsum/2;
        vector<vector<int>>v(stones.size(), vector<int>(target+1, -1));
        return dfs(0,0,totalsum , target, stones,v);
    }
    int dfs(int i , int curr, int totalsum, int target, vector<int>& stones, vector<vector<int>>&v){
        if(curr >= target || i>=stones.size()){
            return abs(curr - (totalsum-curr));
        }
        if(v[i][curr]!=-1){
            return v[i][curr];
        }
        v[i][curr] = min(
            dfs(i+1, curr,totalsum, target, stones,v),
            dfs(i+1, curr+stones[i],totalsum , target, stones,v)
        );
        return v[i][curr];
    }
};