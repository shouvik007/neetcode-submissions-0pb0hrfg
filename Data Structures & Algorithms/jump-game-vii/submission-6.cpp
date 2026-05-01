class Solution {
   public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int>vis(n, -1);
        return dfs(s, minJump, maxJump, 0,vis);
    }
    bool dfs(string s, int minjump, int maxjump, int curr,vector<int>&v) {
        if (curr == s.size() - 1) {
            return true;
        }
        if(v[curr]!=-1){
         return v[curr];
        }
        if (s[curr] == '0') {
            for (int k = minjump; k <= maxjump; k++) {
                int next = curr + k;
                if (next < s.size() && s[next]!='1') {
                    if (dfs(s, minjump, maxjump, next, v)) {
                        return v[curr] = 1;
                    }
                }
            }
        }
        return v[curr]=0;
    }
};
