class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto x:edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int minimum = INT_MAX;
        vector<int>ans;
        for(int i =0;i<adj.size();i++){
            vector<bool>vis(n,false);
            int height = dfs(i,vis, adj);
            if(height < minimum){
                minimum = height;
                ans.clear();
                ans.push_back(i);
            }
            else if(height == minimum){
                ans.push_back(i);
            }
        }
        return ans;
    }
    int dfs(int u,vector<bool>& vis,vector<vector<int>>& adj) {
        if(vis[u]==true){
            return 0;
        }
        int x =0;
        vis[u]=true;
        for(auto v:adj[u]){
            if(!vis[v]){
                x = max(x,1+dfs(v,vis,adj));
            }
        }
        return x;
    }
};